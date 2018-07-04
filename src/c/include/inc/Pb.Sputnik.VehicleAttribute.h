#ifndef __PB_SPUTNIK_VEHICLEATTRIBUTE_H__
#define __PB_SPUTNIK_VEHICLEATTRIBUTE_H__

#include "Pb.Sputnik.Box.h"
#include "Pb.Sputnik.PlateAttribute.h"
#include "Pb.Sputnik.Direction.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define MAX_PLATE_PREDICTS_CNT 256
#define MAX_TYPE_PREDICTS_CNT  256
#define MAX_COLOR_PREDICTS_CNT  256

enum VehicleType {
  CAR = 0,
  SUV = 1,
  MICROBUS = 2,
  MINIBUS = 3,
  BUS = 4,
  PICKUP = 5,
  TRUCK = 6,
};

enum VehicleColor {
  BLUE   = 0,
  YELLOW = 1,
  BLACK  = 2,
  WHITE  = 3,
  GREEN  = 4,
  RED    = 5,
  GRAY   = 6,
  PURPLE = 7,
  PINK   = 8,
  BROWN  = 9,
  CYAN   = 10,
  COLORFUL = 11,
};


// Next field 16
typedef struct __plate_predict {
	box_t plate_relative_box;
	plate_attribute_t plate_attribute;
} plate_predict_t;

typedef struct __vehicle_type_predict {
	VehicleType vehicle_type;
	// [0, 100]. 100 means very confident.
	int type_confidence;
} vehicle_type_predict_t;

typedef struct __vehicle_color_predict {
	VehicleColor vehicle_color;
	// [0, 100]. 100 means very confident.
	int color_confidence;
} vehicle_color_predict_t;

typedef struct __vehicle_attribute {
	// A vehicle can have multiple plates.
	int plate_predicts_cnt;
	plate_predict_t plate_predicts[MAX_PLATE_PREDICTS_CNT];

	int type_predicts_cnt;
	vehicle_type_predict_t type_predicts[MAX_TYPE_PREDICTS_CNT];

	int color_predicts_cnt;
	vehicle_color_predict_t color_predicts[MAX_COLOR_PREDICTS_CNT];

	char trademark_utf8[256];
	int trademark_utf8_confidence;

	// [0, 100]. 100 means likely to be plateless .
	int vehicle_plateless;

	// [0, 100]. 100 means likely to be moving.
	int vehicle_moving;

	Direction move_direction;
	int move_direction_confidence;

	Direction pointing_direction;
	int pointing_direction_confidence;

	Facing vehicle_facing;
	int vehicle_facing_confidence;
} vehicle_attribute_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_VEHICLEATTRIBUTE_H__*/
