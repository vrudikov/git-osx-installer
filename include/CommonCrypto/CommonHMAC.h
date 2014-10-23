#ifndef _CC_COMMON_HMAC_H_
#define _CC_COMMON_HMAC_H_

#include <stddef.h>
#include <CommonCrypto/CommonDigest.h>

#define kCCHmacAlgMD5 1

typedef struct {
	CC_MD5_CTX md5ctx;
	unsigned char keydata[CC_MD5_BLOCK_BYTES];
} CCHmacContext;

void cCCHmacInit(CCHmacContext *,int,const void *,size_t);
void cCCHmacUpdate(CCHmacContext *,const void *,size_t);
void cCCHmacFinal(CCHmacContext *, void *);

#define CCHmacInit(c,a,k,l) cCCHmacInit(c,a,k,l)
#define CCHmacUpdate(c,d,l) cCCHmacUpdate(c,d,l)
#define CCHmacFinal(c,m) cCCHmacFinal(c,m)

#endif /* _CC_COMMON_HMAC_H_ */
