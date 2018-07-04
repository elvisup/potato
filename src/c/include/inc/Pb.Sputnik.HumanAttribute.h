#ifndef __PB_INGENIC_SPUTNIK_HUNMANATTRIBUTE_H__
#define __PB_INGENIC_SPUTNIK_HUNMANATTRIBUTE_H__

#include "inc/Pb.Sputnik.Direction.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __human_attribute {
  // [0, 100]. 100 for female, 0 for male.
  int gender;

  // Age in years
  int age;

  // [0, 100]. 100 means with backpack
  int backpack;

  // [0, 100]. 100 means likely to move, 0 means likely to stop.
  int human_move;
  Direction move_direction;

  // [0, 100]. 100 means riding bike
  int ride_bike;

  // [0, 100]. 100 means riding motorbike
  int ride_motorbike;

  // [0, 100]. 100 means face is visible
  int human_face_visible;

  Facing human_facing;
  // [0, 100]. 100 means very confident.
  int human_facing_confidence;
} human_attribute_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_INGENIC_SPUTNIK_HUNMANATTRIBUTE_H__*/
