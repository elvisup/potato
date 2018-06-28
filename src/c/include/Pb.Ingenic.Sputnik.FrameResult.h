#ifndef __PB_INGENIC_SPUTNIK_FRAMERESULT_H__
#define __PB_INGENIC_SPUTNIK_FRAMERESULT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __items_attr {
	int items_type;
	/*
	 *Box box = 2;
	 */
	int items_video_channel_id;
	int items_frame_id;
	int items_track_id;
	bool items_track_update;
	bool items_track_die;
	bool items_track_show;
	bool items_track_push;

	/*
	 *oneof attribute {
	 *        FaceAttribute face_attribute = 9;
	 *        PlateAttribute plate_attribute = 10;
	 *        VehicleAttribute vehicle_attribute = 11;
	 *        HumanAttribute human_attribute = 13;
	 *}
	 *Image item_image = 12;
	 */
	/*
	 *Mask mask = 14;
	 */

	unsigned long long items_timestamp_millis;

	/*
	 *repeated TracePoint trace = 16;
	 */

	/*
	 *string item_text_utf8 = 17;
	 */

	/*
	 *bytes blob = 18;
	 */

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
