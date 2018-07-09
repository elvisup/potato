#ifndef __PB_INGENIC_SPUTNIK_MEGREPLY_H__
#define __PB_INGENIC_SPUTNIK_MEGREPLY_H__

#include "inc/Pb.Sputnik.FaceReply.h"
#include "inc/Pb.Sputnik.TokenRequest.h"
#include "inc/Pb.Sputnik.FaceRequest.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

int Pb_Ingenic_Sputnik_MegReply_Get_Request_ID(int id);
int Pb_Ingenic_Sputnik_MegReply_Get_ErrorMsg(char *err_msg);
int Pb_Ingenic_Sputnik_MegReply_Get_FaceReply(face_reply_t *facerpy);
int Pb_Ingenic_Sputnik_MegReply_Get_TokenActivationReply(token_activation_reply_t *token_actrpy);
int Pb_Ingenic_Sputnik_MegReply_Get_DeleteTokenReply(delete_token_reply_t *deltoken_rpy);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_INGENIC_SPUTNIK_MEGREPLY_H__*/
