#include <string>
#include <frame_result.pb.h>
#include <Pb.Ingenic.Sputnik.FrameResult.h>

using namespace std;
sputnik::pb::FrameResult sputnik_pb_frame_result;

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Sputnik_FrameResult_Data_Deserialize(char *serialize_data)
{
	if (serialize_data == NULL)
		return -1;

	sputnik_pb_frame_result.ParseFromString(serialize_data);  

	return 0;
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Frame_ID(void)
{
	return sputnik_pb_frame_result.frame_id();
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Version(char *version)
{
	if (version == NULL)
		return -1;

	string data;
	data = sputnik_pb_frame_result.version();  
	strcpy(version, data.c_str());

	return 0;
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Items_Cnt(void)
{
	return sputnik_pb_frame_result.items_size();
}

int Pb_Ingenic_Sputnik_FrameResult_Get_Items(int index, items_attr_t *attr)
{
	if((sputnik_pb_frame_result.items_size() - 1) < index )
		return -1;

	sputnik::pb::Item items = sputnik_pb_frame_result.items(index);
	attr->items_type = items.type();
	attr->items_video_channel_id = items.video_channel_id();
	attr->items_frame_id = items.frame_id();
	attr->items_track_id = items.track_id();
	attr->items_track_update = items.track_update();
	attr->items_track_die = items.track_die();
	attr->items_track_show = items.track_show();
	attr->items_track_push = items.track_push();
	attr->items_timestamp_millis = items.timestamp_millis();

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
