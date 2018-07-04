#ifndef __PB_SPUTNIK_MASK_H__
#define __PB_SPUTNIK_MASK_H__

#include "inc/Pb.Sputnik.Box.h"
#include "inc/Pb.Sputnik.FaceAttribute.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define MAX_PIX_CONFIDENCE_CNT 256

typedef struct __mask {
  int x;
  int y;
  int w;
  int h;
  // resolution of pix_conf, e.g. resolution=2 means one pix_confidence associate to 2x2 pixels
  int resolution;
  // [0, 100]. 100 means belonging to instance.
  int pix_confidence_cnt;
  int pix_confidence[MAX_PIX_CONFIDENCE_CNT];
} mask_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_MASK_H__*/
