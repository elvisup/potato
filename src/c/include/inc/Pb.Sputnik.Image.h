#ifndef __PB_SPUTNIK_IMAGE_H__
#define __PB_SPUTNIK_IMAGE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __image {
  int h;
  int w;
  int c;
  char* data;
} image_t;

enum image_encode_format {
  IEF_UNKNOWN = 0,
  IEF_PNG = 1,
  IEF_JPG = 2,
  IEF_BMP = 3,
};

typedef struct __encoded_image {
  char* blob;
  image_encode_format encode_format;
  char description[128];
} encoded_image_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_IMAGE_H__*/
