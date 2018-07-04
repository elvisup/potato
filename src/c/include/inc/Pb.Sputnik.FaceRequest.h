#ifndef __PB_SPUTNIK_FACEREQUEST_H__
#define __PB_SPUTNIK_FACEREQUEST_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __face_attribute_request {
	bool predict_blur;
	bool predict_age_gender;
	bool predict_pose;
	bool predict_landmark;
	bool predict_postfilter;
} face_attribute_request_t;

typedef struct __face_pose_requirement {
	int min_pitch_deg; // Face with pitch smaller than this will not be recognized.
	int max_pitch_deg; // Face with pitch larger than this will not be recognized.
	int min_yaw_deg;   // Face with yaw smaller than this will not be recognized.
	int max_yaw_deg;   // Face with yaw larger than this will not be recognized.
	int min_roll_deg;  // Face with roll smaller than this will not be recognized.
	int max_roll_deg;  // Face with roll larger than this will not be recognized.
} face_pose_requirement_t;

typedef struct __face_blur_requirement {
	int max_blur; // Face with blur value larger than this will not be recognized.
} face_blur_requirement_t;

typedef struct __face_token_request {
	bool add_new_token;
	char model[128];
	char strategy[128];
	bool already_aligned;
	int min_face_pixels; // Face smaller than this will not be recognized.
	face_pose_requirement_t pose_requirement;
	face_blur_requirement_t blur_requirement;
} face_token_request_t;

typedef struct __face_recognition_request {
	int max_num_scores; // Only return this number of top matching tokens. 0 to skip recognition
	int precision; // A number in [0, 100], indicating desired precision. 100 for high precision.
	face_token_request_t token_request;
} face_recognition_request_t;

typedef struct __face_request {
	bool image_encode;
	image_t raw_image;
	encoded_image_t encoded_image;
	box_t box_in_image; // Optional, the face box in the image.
	face_landmark_t landmark; // Optional, landmark of the face.
	face_attribute_request_t attribute_request;
	face_recognition_request_t recognition_request;
	int priority;  // A number in [0, 100]. A higher priority request can interrupt a lower priority request. The interrupted lower priority request will be discarded.
} face_request_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_FACEREQUEST_H__*/
