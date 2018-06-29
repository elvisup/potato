#ifndef __PB_SPUTNIK_FACEATTRIBUTE_H__
#define __PB_SPUTNIK_FACEATTRIBUTE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __face_landmark {
  char landmark_description[256];
  int lefteye_pupil_x;
  int lefteye_pupil_y;
  int righteye_pupil_x;
  int righteye_pupil_y;
  int nose_tip_x;
  int nose_tip_y;
  int left_mouth_corner_x;
  int left_mouth_corner_y;
  int right_mouth_corner_x;
  int right_mouth_corner_y;
  int lefteye_right_corner_x;
  int lefteye_right_corner_y;
  int righteye_left_corner_x;
  int righteye_left_corner_y;
} face_landmark_t;

typedef struct __face_attribute {
	unsigned int blur;
	unsigned int age;
	unsigned int gender;
	int pitch;
	int yaw;
	int roll;
	unsigned int post_filter_score;
	face_landmark_t landmark;
	unsigned int minority;
} face_attribute_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_FACEATTRIBUTE_H__*/
