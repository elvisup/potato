#ifndef __PB_SPUTNIK_TOKENREQUEST_H__
#define __PB_SPUTNIK_TOKENREQUEST_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct __token_activation {
	int token;
	bool active; // The new status of the token.
} token_activation_t;

typedef struct __token_activation_request {
	token_activation_t token_activations;
} token_activation_request_t;

typedef struct __delete_token_request {
	int delete_tokens;
} delete_token_request_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*__PB_SPUTNIK_TOKENREQUEST_H__*/
