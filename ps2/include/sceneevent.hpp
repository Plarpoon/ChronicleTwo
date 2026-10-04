#pragma once

#include "common.h"

#include <libvu0.h>

#include "map.hpp"
#include "mapload.hpp"

/**
 * @file
 * Declares the description of an event that the player has reached in a
 * scene: the event point of a map, a villager to talk to or a game object,
 * which a scene keeps while it runs the event and hands to the event editor.
 */

/**
 *
 * Event the player has reached, with the settings, placement and owner of the point that starts it.
 *
 */
struct CSceneEventData {
    CFuncPoint::EventData event;      /**< Settings of the event point, or the event number of a villager or game object. */
    sceVu0FVECTOR         position;   /**< Position of the event point or game object. */
    sceVu0FVECTOR         rotation;   /**< Rotation of the event point, zero for a game object. */
    sceVu0FVECTOR         scale;      /**< Scale of the event point. */
    MapEventInfo          map_event;  /**< Event point found on a map, with the matrix that places it. */
    s32                   chara_no;   /**< Character number of the villager talked to. */
    s32                   chara_slot; /**< Scene character slot of the villager talked to. */
    s32                   gameobj_no; /**< Index of the game object position within its map's entry. */
    s32                   unk_cc;
};

STATIC_ASSERT(sizeof(CSceneEventData) == 0xD0);
