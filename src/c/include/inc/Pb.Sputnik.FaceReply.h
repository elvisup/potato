#ifndef __PB_SPUTNIK_FACEREPLY_H__
#define __PB_SPUTNIK_FACEREPLY_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#include <inc/Pb.Sputnik.Box.h>
#include <inc/Pb.Sputnik.Image.h>
#include <inc/Pb.Sputnik.FaceAttribute.h>
#include <inc/Pb.Sputnik.TokenReply.h>

#define TOKEN_SCORES_CNT 256
typedef struct __token_score {
  int token;
  double score;
} token_score_t;

enum FaceAttributeReplyStatus {
  ARS_UNKNOWN = 0,
  ARS_SUCCESS = 1,
  ARS_NO_FACE = 2,
  ARS_NO_MODEL = 3,  // No model loaded for the task.
};

typedef struct __face_attribute_reply {
  FaceAttributeReplyStatus status;
  face_attribute_t attribute;
} face_attribute_reply_t;

enum FaceQuality {
  FQ_UNKNOWN = 0,
  FQ_GOOD = 1,
  FQ_TOO_SMALL = 2,
  FQ_TOO_LARGE_PITCH = 3,
  FQ_TOO_LARGE_YAW = 4,
  FQ_TOO_LARGE_ROLL = 5,
  FQ_TOO_BLUR = 6,
  FQ_NO_FACE = 7,
};

enum FaceTokenReplyStatus {
  FTRS_UNKNOWN = 0,
  FTRS_SUCCESS = 1,
  FTRS_NO_FACE = 2,
  FTRS_MULTIPLE_FACES = 3,
  FTRS_LOW_QUALITY_FACE = 4,
  FTRS_TIMEOUT = 5,  // Wait for too long.
  FTRS_NO_MODEL = 6,  // No model loaded for the task.
};

typedef struct __face_feature_version {
  char model_version[256];
  char method[256];
} face_feature_version_t;

typedef struct  __face_token_reply {
  FaceTokenReplyStatus status;
  FaceQuality face_quality;
  int token;  // only when `add_new_token` is true
  int blob_size;
  char* blob; // feature file (only when `add_new_token` is true)
} face_token_reply_t;

typedef struct __face_recognition_reply {
  face_token_reply_t token_reply;
  int token_scores_cnt;
  token_score_t scores[TOKEN_SCORES_CNT];//repeated
  face_feature_version_t feature_version;
} face_recognition_reply_t;

typedef struct __face_reply {
  face_attribute_reply_t face_attribute_reply;
  face_recognition_reply_t face_recognition_reply;
} face_reply_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_FACEREPLY_H__*/
