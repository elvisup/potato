#ifndef __PB_INGENIC_SPUTNIK_MEGREQUEST_H__
#define __PB_INGENIC_SPUTNIK_MEGREQUEST_H__

#include "inc/Pb.Sputnik.Box.h"
#include "inc/Pb.Sputnik.FaceAttribute.h"
#include "inc/Pb.Sputnik.TokenRequest.h"
#include "inc/Pb.Sputnik.FaceRequest.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define REQUEST_TYPE_TOKEN_ACTIVATION 0
#define REQUEST_TYPE_DELETE_TOKEN     1
#define REQUEST_TYPE_FACE_REQUEST     2

typedef struct __meg_request {
	int request_id;
	token_activation_request_t token_activation_request;
	delete_token_request_t delete_token_request;
	face_request_t face_request;
	unsigned long long timestamp_millis;
} meg_request_t;

int Pb_Ingenic_Sputnik_MegRequest_Set_Request_ID(int id);
int Pb_Ingenic_Sputnik_MegRequest_Set_Timestamp_Millis(unsigned long long ts);
int Pb_Ingenic_Sputnik_MegRequest_Set_FaceRequest(face_request_t *face_req);
int Pb_Ingenic_Sputnik_MegRequest_Set_DeleteTokenRequest(delete_token_request_t *deltoken_req);
int Pb_Ingenic_Sputnik_MegRequest_Set_TokenActivationRequest(token_activation_request_t *token_act_req)
int Pb_Ingenic_Sputnik_MegRequest_Data_Serialize(char *serialize_data);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_INGENIC_SPUTNIK_MEGREQUEST_H__*/
