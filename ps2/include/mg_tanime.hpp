#pragma once

#include "common.h"

/**
 * @file
 * Declares the engine's texture animation: records that copy, scroll or sway
 * a rectangle of one texture into another every frame, chained into named
 * groups that a texture block plays, plus the list and rectangle templates
 * the records are held and drawn with.
 */

class mgCMemory;
class mgCTexture;
struct sceVif1Packet;

/**
 *
 * Number of animation groups one mgCTextureAnime holds.
 *
 */
enum {
    MG_TEX_ANIME_GROUP_MAX = 24, /**< Groups held by every mgCTextureAnime. */
};

/**
 *
 * Ways a texture-animation record moves its source rectangle into the destination.
 *
 */
enum mgTEX_ANIME_TYPE {
    MG_TEX_ANIME_TYPE_NONE = -1,  /**< Record holds no animation. */
    MG_TEX_ANIME_TYPE_COPY = 0,   /**< Copies the source rectangle onto the destination unchanged. */
    MG_TEX_ANIME_TYPE_SCROLL = 1, /**< Scrolls the source rectangle through the destination, wrapping round. */
    MG_TEX_ANIME_TYPE_WAVE = 2,   /**< Sways the source rectangle back and forth along a sine wave. */
};

/**
 *
 * Settings of a texture-animation record that leave a drawing state switched off.
 *
 */
enum {
    MG_TEX_ANIME_ALPHA_BLEND_OFF = 4,  /**< alpha_blend value that draws without alpha blending. */
    MG_TEX_ANIME_ALPHA_TEST_OFF = -1,  /**< alpha_test value that draws without an alpha test. */
    MG_TEX_ANIME_WAIT_FOREVER = -1,    /**< wait value that keeps a record playing for good. */
};

/**
 *
 * Axis-aligned rectangle given by its two inclusive corners.
 *
 */
template <class T>
class mgRect {
public:
    T left;   /**< Left edge. */
    T top;    /**< Top edge. */
    T right;  /**< Right edge, inclusive. */
    T bottom; /**< Bottom edge, inclusive. */

    /**
     *
     * Sets all four edges of the rectangle.
     *
     * @mangled Set__9mgRect_i_Fiiii
     * @address 0x13EA00
     * @size 0x20
     */
    void Set(T new_left, T new_top, T new_right, T new_bottom) {
        left = new_left;
        top = new_top;
        right = new_right;
        bottom = new_bottom;
    }
};

STATIC_ASSERT(sizeof(mgRect<int>) == 0x10);

/**
 *
 * Node of a doubly linked list that carries one object by value.
 *
 */
template <class T>
class CList {
public:
    CList<T> *next; /**< Following node, or NULL at the end of the list. */
    CList<T> *prev; /**< Preceding node, or NULL at the start of the list. */
    T data;         /**< Object the node carries. */

    /**
     *
     * Creates an unlinked node around a newly constructed object.
     *
     */
    CList() { Initialize(); }

    /**
     *
     * Gives the object the node carries.
     *
     */
    T *pGetData() { return &data; }

    /**
     *
     * Unlinks the node from its neighbours.
     *
     * @mangled Initialize__24CList_15mgCTexAnimeData_Fv
     * @address 0x13DAC0
     * @size 0x10
     */
    virtual void Initialize() { next = prev = 0; }
};

/**
 *
 * One step of a texture animation: a rectangle of a source texture moved into a destination texture, and how long it plays.
 *
 */
class mgCTexAnimeData {
public:
    s8 type;                  /**< How the rectangle is moved, an mgTEX_ANIME_TYPE. */
    s8 group;                 /**< Animation group the record is entered into. */
    s8 link_group;            /**< Group enabled while this record plays, or -1 for none. */
    u8 clut_copy;             /**< Non-zero copies the source's palette to the destination even when the rectangle is not the whole texture. */
    mgCTexture *src_tex;      /**< Texture the rectangle is taken from. */
    mgCTexture *dest_tex;     /**< Texture the rectangle is drawn into. */
    s16 src_x;                /**< Left edge of the source rectangle, in sixteenths of a texel. */
    s16 src_y;                /**< Top edge of the source rectangle, in sixteenths of a texel. */
    s16 src_w;                /**< Width of the source rectangle, in sixteenths of a texel. */
    s16 src_h;                /**< Height of the source rectangle, in sixteenths of a texel. */
    s16 dest_x;               /**< Left edge of the destination rectangle, in sixteenths of a texel. */
    s16 dest_y;               /**< Top edge of the destination rectangle, in sixteenths of a texel. */
    s16 dest_w;               /**< Width of the destination rectangle, in sixteenths of a texel. */
    s16 dest_h;               /**< Height of the destination rectangle, in sixteenths of a texel. */
    s16 period_x;             /**< Frames one horizontal cycle lasts; the sign gives the scroll direction and zero stops it. */
    s16 period_y;             /**< Frames one vertical cycle lasts; the sign gives the scroll direction and zero stops it. */
    s16 phase_x;              /**< Frame reached in the current horizontal cycle. */
    s16 phase_y;              /**< Frame reached in the current vertical cycle. */
    s16 amplitude_x;          /**< Horizontal sway of a wave record, in ten-thousandths of the destination width. */
    s16 amplitude_y;          /**< Vertical sway of a wave record, in ten-thousandths of the destination height. */
    s16 wait;                 /**< Frames the record plays before the group moves on; zero also plays the next record, -1 holds forever. */
    s16 bug_patch;            /**< Non-zero ends the record after exactly wait frames rather than one frame later. */
    u8 bilinear;              /**< Non-zero filters a drawn rectangle bilinearly. */
    u8 alpha_blend;           /**< Alpha blending mode a drawn rectangle uses, or 4 for none. */
    s8 alpha_test;            /**< Alpha test method a drawn rectangle uses, or -1 for none. */
    u8 alpha_ref;             /**< Reference value of the alpha test. */
    u8 r;                     /**< Red the drawn rectangle is tinted with, 0x80 for unchanged. */
    u8 g;                     /**< Green the drawn rectangle is tinted with, 0x80 for unchanged. */
    u8 b;                     /**< Blue the drawn rectangle is tinted with, 0x80 for unchanged. */
    u8 a;                     /**< Alpha the drawn rectangle is drawn with, 0x80 for opaque. */

    /**
     *
     * Creates an empty record with default drawing settings.
     *
     * @mangled __ct__15mgCTexAnimeDataFv
     * @address 0x13C340
     * @size 0x30
     */
    mgCTexAnimeData();

    /**
     *
     * Empties the record and restores the default drawing settings.
     *
     * @mangled Initialize__15mgCTexAnimeDataFv
     * @address 0x13C370
     * @size 0x90
     */
    void Initialize();
};

STATIC_ASSERT(sizeof(mgCTexAnimeData) == 0x34);
STATIC_ASSERT(sizeof(CList<mgCTexAnimeData>) == 0x40);

/**
 *
 * Plays the texture-animation groups of one texture block, each a chain of records stepped through frame by frame.
 *
 */
class mgCTextureAnime {
public:
    /**
     *
     * Holds every texture animation on its current frame while it is not zero.
     *
     * @mangled stop_anime__15mgCTextureAnime
     * @address 0x37CD98
     * @size 0x4
     */
    static s32 stop_anime;

    s32 group_num;                                        /**< Number of groups in use by the arrays below. */
    s32 enable[MG_TEX_ANIME_GROUP_MAX];                   /**< Non-zero for each group that plays. */
    CList<mgCTexAnimeData> *list[MG_TEX_ANIME_GROUP_MAX]; /**< First record of each group. */
    CList<mgCTexAnimeData> *now[MG_TEX_ANIME_GROUP_MAX];  /**< Record each group is playing. */
    char *name[MG_TEX_ANIME_GROUP_MAX];                   /**< Name each group is looked up by, or NULL. */
    s32 frame[MG_TEX_ANIME_GROUP_MAX];                    /**< Frames each group's current record has played. */

    /**
     *
     * Draws the current record of every playing group whose textures lie in the given texture block, and advances the groups a frame.
     *
     * @mangled TexAnime__15mgCTextureAnimeFiP13sceVif1Packet
     * @address 0x13C400
     * @size 0x1460
     */
    void TexAnime(int texb, sceVif1Packet *packet);

    /**
     *
     * Empties every group.
     *
     * @mangled Initialize__15mgCTextureAnimeFv
     * @address 0x13D860
     * @size 0x70
     */
    void Initialize();

    /**
     *
     * Creates a player with every group empty.
     *
     * @mangled __ct__15mgCTextureAnimeFv
     * @address 0x13D8D0
     * @size 0x30
     */
    mgCTextureAnime();

    /**
     *
     * Names a group so that it can be looked up.
     *
     * @mangled SetGroupName__15mgCTextureAnimeFiPc
     * @address 0x13D900
     * @size 0x40
     */
    void SetGroupName(int group, char *group_name);

    /**
     *
     * Gives the first group with no records, or -1 when every group is in use.
     *
     * @mangled GetEmptyGroup__15mgCTextureAnimeFv
     * @address 0x13D940
     * @size 0x50
     */
    int GetEmptyGroup();

    /**
     *
     * Gives the group with the given name, or -1 when there is none.
     *
     * @mangled SearchGroupName__15mgCTextureAnimeFPc
     * @address 0x13D990
     * @size 0xB0
     */
    int SearchGroupName(char *group_name);

    /**
     *
     * Allocates an unlinked record node from the given memory.
     *
     * @mangled NewTexAnimeData__15mgCTextureAnimeFP9mgCMemory
     * @address 0x13DA40
     * @size 0x80
     */
    CList<mgCTexAnimeData> *NewTexAnimeData(mgCMemory *stack);

    /**
     *
     * Allocates a record node from the given memory and appends it to a group.
     *
     * @mangled NewTexAnimeGroupData__15mgCTextureAnimeFiP9mgCMemory
     * @address 0x13DAD0
     * @size 0x120
     */
    CList<mgCTexAnimeData> *NewTexAnimeGroupData(int group, mgCMemory *stack);

    /**
     *
     * Appends a copy of a record to the group it names, flipping its rectangles into the textures' vertical orientation.
     *
     * @mangled EnterTexAnime__15mgCTextureAnimeFP15mgCTexAnimeDataP9mgCMemory
     * @address 0x13DBF0
     * @size 0x1B0
     */
    int EnterTexAnime(mgCTexAnimeData *data, mgCMemory *stack);

    /**
     *
     * Stops a group and forgets its records and name.
     *
     * @mangled DeleteGroup__15mgCTextureAnimeFi
     * @address 0x13DDA0
     * @size 0x70
     */
    void DeleteGroup(int group);

    /**
     *
     * Stops every group and rewinds it to its first record.
     *
     * @mangled DisableAll__15mgCTextureAnimeFv
     * @address 0x13DE10
     * @size 0x60
     */
    void DisableAll();

    /**
     *
     * Starts a group playing.
     *
     * @mangled Enable__15mgCTextureAnimeFi
     * @address 0x13DE70
     * @size 0x40
     */
    void Enable(int group);

    /**
     *
     * Stops a group and rewinds it to its first record.
     *
     * @mangled Disable__15mgCTextureAnimeFi
     * @address 0x13DEB0
     * @size 0x40
     */
    void Disable(int group);

    /**
     *
     * Gives the first record of a group, or NULL for a group out of range.
     *
     * @mangled GetAnimeList__15mgCTextureAnimeFi
     * @address 0x13DEF0
     * @size 0x40
     */
    CList<mgCTexAnimeData> *GetAnimeList(int group);
};

STATIC_ASSERT(sizeof(mgCTextureAnime) == 0x1E4);
