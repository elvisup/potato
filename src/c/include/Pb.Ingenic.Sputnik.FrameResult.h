#ifndef __PB_INGENIC_SPUTNIK_FRAMERESULT_H__
#define __PB_INGENIC_SPUTNIK_FRAMERESULT_H__

#include "inc/Pb.Sputnik.Box.h"
#include "inc/Pb.Sputnik.Mask.h"
#include "inc/Pb.Sputnik.Image.h"
#include "inc/Pb.Sputnik.FaceAttribute.h"
#include "inc/Pb.Sputnik.PlateAttribute.h"
#include "inc/Pb.Sputnik.TracePoint.h"
#include "inc/Pb.Sputnik.VehicleAttribute.h"
#include "inc/Pb.Sputnik.HumanAttribute.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define MAX_TRACEPOINT_CNT 256

enum ItemType {
  // Human face
  FACE = 0,
  // License plate
  PLATE = 1,
  // Vehicle
  VEHICLE = 2,
  // Human
  HUMAN = 3,
};

typedef struct __items_attr {
	int items_type;
	box_t box;
	int items_video_channel_id;
	int items_frame_id;
	int items_track_id;
	bool items_track_update;
	bool items_track_die;
	bool items_track_show;
	bool items_track_push;

	face_attribute_t face_attr;
	plate_attribute_t plate_attribute;
	vehicle_attribute_t vehicle_attribute;
	human_attribute_t human_attribute;

	image_t item_image;
	mask_t mask;

	unsigned long long items_timestamp_millis;

	int trace_point_cnt;
	trace_point_t trace[MAX_TRACEPOINT_CNT];

	char item_text_utf8[256];

	int blob_size;
	char *blob;

} items_attr_t;

int Pb_Ingenic_Sputnik_FrameResult_Data_Deserialize(char *serialize_data);
int Pb_Ingenic_Sputnik_FrameResult_Get_Frame_ID(void);
int Pb_Ingenic_Sputnik_FrameResult_Get_Version(char *version);
int Pb_Ingenic_Sputnik_FrameResult_Get_Items_Cnt(void);
int Pb_Ingenic_Sputnik_FrameResult_Get_Items(int index, items_attr_t *attr);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_INGENIC_SPUTNIK_FRAMERESULT_H__*/
