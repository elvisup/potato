#ifndef __PB_SPUTNIK_TRACEPOINT_H__
#define __PB_SPUTNIK_TRACEPOINT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __trace_point {
  int x;
  int y;
  unsigned long long timestamp_millis;
} trace_point_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_TRACEPOINT_H__*/
