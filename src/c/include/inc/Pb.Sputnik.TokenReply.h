#ifndef __PB_SPUTNIK_TOKENREPLY_H__
#define __PB_SPUTNIK_TOKENREPLY_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

#define ACTIVE_TOKENS_CNT 256
#define PRESENT_TOKENS_CNT 256
enum TokenActivationReplyStatus {
  TAR_UNKNOWN = 0,
  TAR_SUCCESS = 1,
  TAR_FAILED = 2,
};

typedef struct __token_activation_reply {
  TokenActivationReplyStatus status;
  int active_tokens_cnt;
  int active_tokens[ACTIVE_TOKENS_CNT]; // Tokens that are active.
} token_activation_reply_t;

enum DeleteTokenReplyStatus {
  DFT_UNKNOWN = 0,
  DFT_SUCCESS = 1,
  DFT_FAILED = 2,
};

typedef struct __delete_token_reply {
  DeleteTokenReplyStatus status;
  int present_tokens_cnt;
  int present_tokens[PRESENT_TOKENS_CNT]; // #Tokens that are still present.
} delete_token_reply_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_TOKENREPLY_H__*/
