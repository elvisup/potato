#include <string>
#include <meg_reply.pb.h>
#include <frame_result.pb.h>
#include <token_reply.pb.h>
#include <face_request.pb.h>
#include <Pb.Ingenic.Sputnik.MegReply.h>
#include <inc/Pb.Sputnik.FaceReply.h>
#include <inc/Pb.Sputnik.TokenRequest.h>
#include <inc/Pb.Sputnik.Image.h>

using namespace std;
sputnik::pb::MegReply sputnik_pb_meg_reply;

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Sputnik_MegReply_Get_Request_ID(int id)
{
	return sputnik_pb_meg_reply.request_id();
}

int Pb_Ingenic_Sputnik_MegReply_Get_ErrorMsg(char *err_msg)
{
	if (!err_msg) {
		printf("%s:%d err_msg is NULL\n", __func__, __LINE__);
		return -1;
	}

	string error_message = sputnik_pb_meg_reply.error_message();
	memcpy(err_msg, error_message.c_str(), error_message.length());

	return 0;
}

int Pb_Ingenic_Sputnik_MegReply_Get_FaceReply(face_reply_t *facerpy)
{
	int i = 0, j = 0;
	if (!facerpy) {
		printf("%s:%d facerpy is NULL\n", __func__, __LINE__);
		return -1;
	}

	if (sputnik_pb_meg_reply.has_face_reply()) {
		printf("%s:%d meg_reply do not have face_reply\n", __func__, __LINE__);
		return -1;
	}

	sputnik::pb::FaceReply face_reply = sputnik_pb_meg_reply.face_reply();

	{
		if (face_reply.has_face_attribute_reply()) {
			sputnik::pb::FaceAttributeReply faceattr_rpy = face_reply.face_attribute_reply();
			switch(faceattr_rpy.status()) {
				case sputnik::pb::FaceAttributeReplyStatus::ARS_UNKNOWN:
					facerpy->face_attribute_reply.status = ARS_UNKNOWN; break;
				case sputnik::pb::FaceAttributeReplyStatus::ARS_SUCCESS:
					facerpy->face_attribute_reply.status = ARS_SUCCESS; break;
				case sputnik::pb::FaceAttributeReplyStatus::ARS_NO_FACE:
					facerpy->face_attribute_reply.status = ARS_NO_FACE; break;
				case sputnik::pb::FaceAttributeReplyStatus::ARS_NO_MODEL:
					facerpy->face_attribute_reply.status = ARS_NO_MODEL; break;
				default:
					facerpy->face_attribute_reply.status = ARS_UNKNOWN; break;
					break;
			}

			if (faceattr_rpy.has_attribute()) {
				sputnik::pb::FaceAttribute faceattr = faceattr_rpy.attribute();
				facerpy->face_attribute_reply.attribute.blur = faceattr.blur();
				facerpy->face_attribute_reply.attribute.age = faceattr.age();
				facerpy->face_attribute_reply.attribute.gender = faceattr.gender();
				facerpy->face_attribute_reply.attribute.pitch = faceattr.pitch();
				facerpy->face_attribute_reply.attribute.yaw = faceattr.yaw();
				facerpy->face_attribute_reply.attribute.roll = faceattr.roll();
				facerpy->face_attribute_reply.attribute.post_filter_score = faceattr.post_filter_score();

				if (faceattr.has_landmark()) {
					sputnik::pb::FaceLandMark faceattr_landmark = faceattr.landmark();

					string landmark_desc = faceattr_landmark.landmark_description();
					memcpy(facerpy->face_attribute_reply.attribute.landmark.landmark_description, landmark_desc.c_str(), landmark_desc.length());

					facerpy->face_attribute_reply.attribute.landmark.lefteye_pupil_x = faceattr_landmark.lefteye_pupil_x();
					facerpy->face_attribute_reply.attribute.landmark.lefteye_pupil_y = faceattr_landmark.lefteye_pupil_y();
					facerpy->face_attribute_reply.attribute.landmark.righteye_pupil_x = faceattr_landmark.righteye_pupil_x();
					facerpy->face_attribute_reply.attribute.landmark.righteye_pupil_y = faceattr_landmark.righteye_pupil_y();
					facerpy->face_attribute_reply.attribute.landmark.nose_tip_x = faceattr_landmark.nose_tip_x();
					facerpy->face_attribute_reply.attribute.landmark.nose_tip_y = faceattr_landmark.nose_tip_y();
					facerpy->face_attribute_reply.attribute.landmark.left_mouth_corner_x = faceattr_landmark.left_mouth_corner_x();
					facerpy->face_attribute_reply.attribute.landmark.left_mouth_corner_y = faceattr_landmark.left_mouth_corner_y();
					facerpy->face_attribute_reply.attribute.landmark.right_mouth_corner_x = faceattr_landmark.right_mouth_corner_x();
					facerpy->face_attribute_reply.attribute.landmark.right_mouth_corner_y = faceattr_landmark.right_mouth_corner_y();
					facerpy->face_attribute_reply.attribute.landmark.lefteye_right_corner_x = faceattr_landmark.lefteye_right_corner_x();
					facerpy->face_attribute_reply.attribute.landmark.lefteye_right_corner_y = faceattr_landmark.lefteye_right_corner_y();
					facerpy->face_attribute_reply.attribute.landmark.righteye_left_corner_x = faceattr_landmark.righteye_left_corner_x();
					facerpy->face_attribute_reply.attribute.landmark.righteye_left_corner_y = faceattr_landmark.righteye_left_corner_y();
				} else {
					printf("%s:%d face attr do not hava landmark\n", __func__, __LINE__);
				}

				facerpy->face_attribute_reply.attribute.minority = faceattr.minority();
			} else {
				printf("%s:%d FaceAttributeReply do not hava attr\n", __func__, __LINE__);
			}
		} else {
			printf("%s:%d do not have face_attribute_reply\n", __func__, __LINE__);
		}
	}

	{
		if (face_reply.has_face_recognition_reply()) {
			sputnik::pb::FaceRecognitionReply faceregrpy = face_reply.face_recognition_reply();

			//FaceTokenReply
			if (faceregrpy.has_token_reply()) {
				sputnik::pb::FaceTokenReply facetokenrpy =  faceregrpy.token_reply();
				switch(facetokenrpy.status()) {
					case sputnik::pb::FaceTokenReplyStatus::FTRS_UNKNOWN:
						facerpy->face_recognition_reply.token_reply.status = FTRS_UNKNOWN; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_SUCCESS:
						facerpy->face_recognition_reply.token_reply.status = FTRS_SUCCESS; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_NO_FACE:
						facerpy->face_recognition_reply.token_reply.status = FTRS_NO_FACE; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_MULTIPLE_FACES:
						facerpy->face_recognition_reply.token_reply.status = FTRS_MULTIPLE_FACES; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_LOW_QUALITY_FACE:
						facerpy->face_recognition_reply.token_reply.status = FTRS_LOW_QUALITY_FACE; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_TIMEOUT:
						facerpy->face_recognition_reply.token_reply.status = FTRS_TIMEOUT; break;
					case sputnik::pb::FaceTokenReplyStatus::FTRS_NO_MODEL:
						facerpy->face_recognition_reply.token_reply.status = FTRS_NO_MODEL; break;
					default:
						facerpy->face_recognition_reply.token_reply.status = FTRS_UNKNOWN; break;
				}
				switch(facetokenrpy.face_quality()) {
					case sputnik::pb::FaceQuality::FQ_UNKNOWN:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_UNKNOWN; break;
					case sputnik::pb::FaceQuality::FQ_GOOD:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_GOOD; break;
					case sputnik::pb::FaceQuality::FQ_TOO_SMALL:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_TOO_SMALL; break;
					case sputnik::pb::FaceQuality::FQ_TOO_LARGE_PITCH:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_TOO_LARGE_PITCH; break;
					case sputnik::pb::FaceQuality::FQ_TOO_LARGE_YAW:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_TOO_LARGE_YAW; break;
					case sputnik::pb::FaceQuality::FQ_TOO_LARGE_ROLL:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_TOO_LARGE_ROLL; break;
					case sputnik::pb::FaceQuality::FQ_TOO_BLUR:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_TOO_BLUR; break;
					case sputnik::pb::FaceQuality::FQ_NO_FACE:
						facerpy->face_recognition_reply.token_reply.face_quality = FQ_NO_FACE; break;
				}
				facerpy->face_recognition_reply.token_reply.token = facetokenrpy.token();

				if (facerpy->face_recognition_reply.token_reply.blob) {
					string face_tokenrpy_blob = facetokenrpy.blob();
					facerpy->face_recognition_reply.token_reply.blob_size = face_tokenrpy_blob.length();
					memcpy(facerpy->face_recognition_reply.token_reply.blob, face_tokenrpy_blob.c_str(), face_tokenrpy_blob.length());
				}
			} else {
				printf("%s:%d do not have face token reply!\n", __func__, __LINE__);
			}

			//TokenScore
			facerpy->face_recognition_reply.token_scores_cnt = faceregrpy.scores_size();
			if (facerpy->face_recognition_reply.token_scores_cnt > TOKEN_SCORES_CNT) {
				printf("meg_reply face_recognition_reply token_scores_cnt is: %d, > %d. set to %d\n", \
					facerpy->face_recognition_reply.token_scores_cnt, TOKEN_SCORES_CNT, TOKEN_SCORES_CNT);
				facerpy->face_recognition_reply.token_scores_cnt = TOKEN_SCORES_CNT;
			}

			for (i = 0; i < facerpy->face_recognition_reply.token_scores_cnt; i++) {
				sputnik::pb::TokenScore token_score = faceregrpy.scores(i);
				facerpy->face_recognition_reply.scores[i].token = token_score.token();
				facerpy->face_recognition_reply.scores[i].score = token_score.score();
			}

			//FaceFeatureVersion
			sputnik::pb::FaceFeatureVersion faceattr_ver = faceregrpy.feature_version();
			string fav_mver = faceattr_ver.model_version();
			memcpy(facerpy->face_recognition_reply.feature_version.model_version, fav_mver.c_str(), fav_mver.length());

			string fav_method = faceattr_ver.method();
			memcpy(facerpy->face_recognition_reply.feature_version.method, fav_method.c_str(), fav_method.length());

		} else {
			printf("%s:%d do not have face_attribute_reply\n", __func__, __LINE__);
		}
	}

	return 0;
}

int Pb_Ingenic_Sputnik_MegReply_Get_TokenActivationReply(token_activation_reply_t *token_actrpy)
{
	int i = 0;
	if (!token_actrpy) {
		printf("%s:%d token_actrpy is NULL\n", __func__, __LINE__);
		return -1;
	}

	if (sputnik_pb_meg_reply.has_token_activation_replay()) {
		printf("%s:%d meg_reply do not have token_activation_replay\n", __func__, __LINE__);
		return -1;
	}

	sputnik::pb::TokenActivationReply tokenactrpy = sputnik_pb_meg_reply.token_activation_replay();

	switch(tokenactrpy.status()) {
		case sputnik::pb::TokenActivationReplyStatus::TAR_UNKNOWN:
			token_actrpy->status = TAR_UNKNOWN; break;
		case sputnik::pb::TokenActivationReplyStatus::TAR_SUCCESS:
			token_actrpy->status = TAR_SUCCESS; break;
		case sputnik::pb::TokenActivationReplyStatus::TAR_FAILED:
			token_actrpy->status = TAR_FAILED; break;
		default:
			token_actrpy->status = TAR_UNKNOWN; break;
	}

	token_actrpy->active_tokens_cnt = tokenactrpy.active_tokens_size();

	if (token_actrpy->active_tokens_cnt > ACTIVE_TOKENS_CNT) {
		printf("meg_reply token_activation_replay active_tokens_cnt is: %d, > %d. set to %d\n", \
			token_actrpy->active_tokens_cnt, ACTIVE_TOKENS_CNT, ACTIVE_TOKENS_CNT);
		token_actrpy->active_tokens_cnt = ACTIVE_TOKENS_CNT;
	}

	for (i = 0; i < token_actrpy->active_tokens_cnt; i++) {
		token_actrpy->active_tokens[i] = tokenactrpy.active_tokens(i);
	}

	return 0;
}

int Pb_Ingenic_Sputnik_MegReply_Get_DeleteTokenReply(delete_token_reply_t *deltoken_rpy)
{
	int i = 0;
	if (!deltoken_rpy) {
		printf("%s:%d deltoken_rpy is NULL\n", __func__, __LINE__);
		return -1;
	}

	if (sputnik_pb_meg_reply.has_delete_token_reply()) {
		printf("%s:%d meg_reply do not have has_delete_token_reply\n", __func__, __LINE__);
		return -1;
	}

	sputnik::pb::DeleteTokenReply deltkrpy = sputnik_pb_meg_reply.delete_token_reply();
	switch(deltkrpy.status()) {
		case sputnik::pb::DeleteTokenReplyStatus::DFT_UNKNOWN:
			deltoken_rpy->status = DFT_UNKNOWN; break;
		case sputnik::pb::DeleteTokenReplyStatus::DFT_SUCCESS:
			deltoken_rpy->status = DFT_SUCCESS; break;
		case sputnik::pb::DeleteTokenReplyStatus::DFT_FAILED:
			deltoken_rpy->status = DFT_FAILED; break;
		default:
			deltoken_rpy->status = DFT_UNKNOWN; break;
	}

	deltoken_rpy->present_tokens_cnt = deltkrpy.present_tokens_size();
	if (deltoken_rpy->present_tokens_cnt > PRESENT_TOKENS_CNT) {
		printf("meg_reply delete token reply present_tokens_cnt is: %d, > %d. set to %d\n", \
			deltoken_rpy->present_tokens_cnt, PRESENT_TOKENS_CNT, PRESENT_TOKENS_CNT);
		deltoken_rpy->present_tokens_cnt = PRESENT_TOKENS_CNT;
	}

	for (i = 0; i < deltoken_rpy->present_tokens_cnt; i++) {
		deltoken_rpy->present_tokens[i] = deltkrpy.present_tokens(i);
	}

	return 0;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
