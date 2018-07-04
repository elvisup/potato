#ifndef __PB_SPUTNIK_PLATEATTRIBUTE_H__
#define __PB_SPUTNIK_PLATEATTRIBUTE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define MAX_PLATE_NUMBERS 256
#define MAX_PLATE_TOKEN_NUMBERS 256
#define MAX_PLATE_COLOR_PREDICT_CNT 256

enum PlateColorType {
	PLATE_BLUE = 0,
	PLATE_YELLOW = 1,
	PLATE_BLACK = 2,
	PLATE_WHITE = 3,
	PLATE_GREEN = 4,
	PLATE_SMALL_NEW_ENERGY = 5,
	PLATE_LARGE_NEW_ENERGY = 6,

	// absence
	PLATE_ABSENCE = 7,
};

typedef struct __plate_token {
  char str_utf8[256];
  // [0, 100]. 100 means very confident.
  int confidence;
} plate_token_t;

typedef struct __plate_textpredict {
	char str_utf8[256];
	// [0, 100]. 100 means very confident.
	int confidence;
	int tokens_cnt;
	plate_token_t tokens[MAX_PLATE_TOKEN_NUMBERS];
} plate_textpredict_t;

typedef struct __plate_color_predict {
	PlateColorType color_type;
	// [0, 100]. 100 means very confident.
	int color_confidence;
} plate_color_predict_t;

typedef struct __four_points {
	int left_top_x;
	int left_top_y;
	int right_top_x;
	int right_top_y;
	int right_bottom_x;
	int right_bottom_y;
	int left_bottom_x;
	int left_bottom_y;
} four_points_t;

typedef struct __plate_attribute {
  // 100 * radian.
  int roll;

  int plate_numbers_cnt;
  plate_textpredict_t plate_numbers[MAX_PLATE_NUMBERS];
  int quality;

  int plate_color_predict_cnt;
  plate_color_predict_t color_predicts[MAX_PLATE_COLOR_PREDICT_CNT];

  four_points_t fout_points;
  // [0, 100]. 100 for two line, 0 for one line.
  int plate_style;
  // [0, 100]. 100 means likely to be adversary-occlusion .
  int adversary_occlusion;

} plate_attribute_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_PLATEATTRIBUTE_H__*/
