#include <string>
#include <meg_request.pb.h>
#include <frame_result.pb.h>
#include <token_request.pb.h>
#include <face_request.pb.h>
#include <Pb.Ingenic.Sputnik.FrameResult.h>
#include <inc/Pb.Sputnik.FaceRequest.h>
#include <inc/Pb.Sputnik.TokenRequest.h>
#include <inc/Pb.Sputnik.Image.h>

using namespace std;
sputnik::pb::MegRequest sputnik_pb_meg_request;
sputnik::pb::FaceRequest *face_request;
sputnik::pb::DeleteTokenRequest *delete_token_request;
sputnik::pb::TokenActivationRequest *token_activation_request;

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Sputnik_MegRequest_Set_Request_ID(int id)
{
	sputnik_pb_meg_request.set_request_id(id);
	return 0;
}

int Pb_Ingenic_Sputnik_MegRequest_Set_Timestamp_Millis(unsigned long long ts)
{
	sputnik_pb_meg_request.set_timestamp_millis(ts);
	return 0;
}

int Pb_Ingenic_Sputnik_MegRequest_Set_FaceRequest(face_request_t *face_req)
{
	face_request = sputnik_pb_meg_request.mutable_face_request();
	if (face_req->image_encode == true) {
		//Encode Image
		sputnik::pb::EncodedImage* encode_image = face_request->mutable_encoded_image();
		//TODO: this maybe need (char **blob)!!!
		encode_image->set_blob(face_req->encoded_image.blob);
		switch(face_req->encoded_image.encode_format) {
			case IEF_UNKNOWN: encode_image->set_encode_format(sputnik::pb::ImageEncodeFormat::IEF_UNKNOWN); break;
			case IEF_PNG: encode_image->set_encode_format(sputnik::pb::ImageEncodeFormat::IEF_PNG); break;
			case IEF_JPG: encode_image->set_encode_format(sputnik::pb::ImageEncodeFormat::IEF_JPG); break;
			case IEF_BMP: encode_image->set_encode_format(sputnik::pb::ImageEncodeFormat::IEF_BMP); break;
			default: encode_image->set_encode_format(sputnik::pb::ImageEncodeFormat::IEF_UNKNOWN); break;
		}
		//encode_image->set_description(face_req->encoded_image.description);
	} else {
		//Image
		sputnik::pb::Image* image = face_request->mutable_raw_image();
		//TODO: this maybe need (char **data)!!!
		image->set_data(face_req->raw_image.data);
		image->set_w(face_req->raw_image.w);
		image->set_h(face_req->raw_image.h);
		image->set_c(face_req->raw_image.c);
	}

	//BOX
	sputnik::pb::Box* box = face_request->mutable_box_in_image();
	box->set_x(face_req->box_in_image.x);
	box->set_y(face_req->box_in_image.y);
	box->set_w(face_req->box_in_image.w);
	box->set_h(face_req->box_in_image.h);

	//Landmark
	sputnik::pb::FaceLandMark* landmark = face_request->mutable_landmark();
	landmark->set_landmark_description(face_req->landmark.landmark_description);
	landmark->set_lefteye_pupil_x(face_req->landmark.lefteye_pupil_x);
	landmark->set_lefteye_pupil_y(face_req->landmark.lefteye_pupil_y);
	landmark->set_righteye_pupil_x(face_req->landmark.righteye_pupil_x);
	landmark->set_righteye_pupil_y(face_req->landmark.righteye_pupil_y);
	landmark->set_nose_tip_x(face_req->landmark.nose_tip_x);
	landmark->set_nose_tip_y(face_req->landmark.nose_tip_y);
	landmark->set_left_mouth_corner_x(face_req->landmark.left_mouth_corner_x);
	landmark->set_left_mouth_corner_y(face_req->landmark.left_mouth_corner_y);
	landmark->set_right_mouth_corner_x(face_req->landmark.right_mouth_corner_x);
	landmark->set_right_mouth_corner_y(face_req->landmark.right_mouth_corner_y);
	landmark->set_lefteye_right_corner_x(face_req->landmark.lefteye_right_corner_x);
	landmark->set_lefteye_right_corner_y(face_req->landmark.lefteye_right_corner_y);
	landmark->set_righteye_left_corner_x(face_req->landmark.righteye_left_corner_x);
	landmark->set_righteye_left_corner_y(face_req->landmark.righteye_left_corner_y);

	//ATTR REQUEST
	sputnik::pb::FaceAttributeRequest* face_attrreq = face_request->mutable_attribute_request();
	face_attrreq->set_predict_blur(face_req->attribute_request.predict_blur);
	face_attrreq->set_predict_age_gender(face_req->attribute_request.predict_age_gender);
	face_attrreq->set_predict_pose(face_req->attribute_request.predict_pose);
	face_attrreq->set_predict_landmark(face_req->attribute_request.predict_landmark);
	face_attrreq->set_predict_postfilter(face_req->attribute_request.predict_postfilter);

	//FACE RECOG REQ
	{
		sputnik::pb::FaceRecognitionRequest* face_recog_req = face_request->mutable_recognition_request();
		face_recog_req->set_max_num_scores(face_req->recognition_request.max_num_scores);
		face_recog_req->set_precision(face_req->recognition_request.precision);

		//TOKEN
		sputnik::pb::FaceTokenRequest* face_tokenreq = face_recog_req->mutable_token_request();
		face_tokenreq->set_add_new_token(face_req->recognition_request.token_request.add_new_token);
		face_tokenreq->set_model(face_req->recognition_request.token_request.model);
		face_tokenreq->set_strategy(face_req->recognition_request.token_request.strategy);
		face_tokenreq->set_already_aligned(face_req->recognition_request.token_request.already_aligned);
		face_tokenreq->set_min_face_pixels(face_req->recognition_request.token_request.min_face_pixels);
		face_tokenreq->set_add_new_token(face_req->recognition_request.token_request.add_new_token);

		//POSE
		sputnik::pb::FacePoseRequirement* face_pose_req = face_tokenreq->mutable_pose_requirement();
		face_pose_req->set_min_pitch_deg(face_req->recognition_request.token_request.pose_requirement.min_pitch_deg);
		face_pose_req->set_max_pitch_deg(face_req->recognition_request.token_request.pose_requirement.max_pitch_deg);
		face_pose_req->set_min_yaw_deg(face_req->recognition_request.token_request.pose_requirement.min_yaw_deg);
		face_pose_req->set_max_yaw_deg(face_req->recognition_request.token_request.pose_requirement.max_yaw_deg);
		face_pose_req->set_min_roll_deg(face_req->recognition_request.token_request.pose_requirement.min_roll_deg);
		face_pose_req->set_max_roll_deg(face_req->recognition_request.token_request.pose_requirement.max_roll_deg);

		//BLUR
		sputnik::pb::FaceBlurRequirement* face_blur_req = face_tokenreq->mutable_blur_requirement();
		face_blur_req->set_max_blur(face_req->recognition_request.token_request.blur_requirement.max_blur);
	}

	face_request->set_priority(face_req->priority);

	return 0;
}

int Pb_Ingenic_Sputnik_MegRequest_Set_DeleteTokenRequest(delete_token_request_t *deltoken_req)
{
	delete_token_request = sputnik_pb_meg_request.mutable_delete_token_request();
	delete_token_request->add_delete_tokens(deltoken_req->delete_tokens);

	return 0;
}

int Pb_Ingenic_Sputnik_MegRequest_Set_TokenActivationRequest(token_activation_request_t *token_act_req)
{
	token_activation_request = sputnik_pb_meg_request.mutable_token_activation_request();
	sputnik::pb::TokenActivation* token_act = token_activation_request->add_token_activations();
	token_act->set_token(token_act_req->token_activations.token);
	token_act->set_active(token_act_req->token_activations.active);

	return 0;
}

int Pb_Ingenic_Sputnik_MegRequest_Data_Serialize(char *serialize_data)
{
	if (serialize_data == NULL)
		return -1;

	string data;
	sputnik_pb_meg_request.SerializeToString(&data);
	strcpy(serialize_data, data.c_str());

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
