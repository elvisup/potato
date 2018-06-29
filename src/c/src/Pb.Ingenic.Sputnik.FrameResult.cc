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
	attr->box.valid = items.has_box();
	if (attr->box.valid) {
		//printf("This items has box!\n");
		sputnik::pb::Box box = items.box();
		attr->box.x = box.x();
		attr->box.y = box.y();
		attr->box.w = box.w();
		attr->box.h = box.h();
	}

	//Face
	if (attr->items_type == 0) {
		sputnik::pb::FaceAttribute face_attr = items.face_attribute();
		attr->face_attr.blur = face_attr.blur();
		attr->face_attr.age = face_attr.age();
		attr->face_attr.gender = face_attr.gender();
		attr->face_attr.pitch = face_attr.pitch();
		attr->face_attr.yaw = face_attr.yaw();
		attr->face_attr.roll = face_attr.roll();
		attr->face_attr.post_filter_score = face_attr.post_filter_score();
		attr->face_attr.minority = face_attr.minority();

		sputnik::pb::FaceLandMark face_landmark = face_attr.landmark();

		//Face Landmark
		//attr->face_attr.landmark.landmark_description;
		attr->face_attr.landmark.lefteye_pupil_x = face_landmark.lefteye_pupil_x();
		attr->face_attr.landmark.lefteye_pupil_y = face_landmark.lefteye_pupil_y();
		attr->face_attr.landmark.righteye_pupil_x = face_landmark.righteye_pupil_x();
		attr->face_attr.landmark.righteye_pupil_y = face_landmark.righteye_pupil_y();
		attr->face_attr.landmark.nose_tip_x = face_landmark.nose_tip_x();
		attr->face_attr.landmark.nose_tip_y = face_landmark.nose_tip_y();
		attr->face_attr.landmark.left_mouth_corner_x = face_landmark.left_mouth_corner_x();
		attr->face_attr.landmark.left_mouth_corner_y = face_landmark.left_mouth_corner_y();
		attr->face_attr.landmark.right_mouth_corner_x = face_landmark.right_mouth_corner_x();
		attr->face_attr.landmark.right_mouth_corner_y = face_landmark.right_mouth_corner_y();
		attr->face_attr.landmark.lefteye_right_corner_x = face_landmark.lefteye_right_corner_x();
		attr->face_attr.landmark.lefteye_right_corner_y = face_landmark.lefteye_right_corner_y();
		attr->face_attr.landmark.righteye_left_corner_x = face_landmark.righteye_left_corner_x();
		attr->face_attr.landmark.righteye_left_corner_y = face_landmark.righteye_left_corner_y();
	}

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
