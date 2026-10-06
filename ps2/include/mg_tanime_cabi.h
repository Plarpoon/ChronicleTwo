#pragma once

/**
 * @file
 * Declares the unmangled data used by the texture animation script loader.
 */

class mgCTextureAnime;
class mgCTextureManager;
class mgCMemory;
struct SPI_TAG_PARAM;

extern "C" {
extern SPI_TAG_PARAM      tex_tag[];     /**< Tags accepted by texture animation scripts. */
extern int                mgBugPatch;    /**< Default bug patch mode. */
extern mgCTextureAnime   *pTexAnime;     /**< Texture animation receiving the current record. */
extern mgCTextureAnime   *pLoadTexAnime; /**< Texture animation receiving loaded records. */
extern int                now_group;     /**< Group receiving the current record. */
extern mgCTextureManager *TexManager;    /**< Texture manager used by the loader. */
extern mgCMemory         *TexAnimeStack; /**< Memory used by the loader. */
extern char              *group_name;    /**< Name of the current group. */
extern int                ta_enable;     /**< Whether the current group starts enabled. */
extern int                now_texb;      /**< Texture block of the current record. */
extern int                texBugPatch;   /**< Timing patch mode requested by the script. */
}
