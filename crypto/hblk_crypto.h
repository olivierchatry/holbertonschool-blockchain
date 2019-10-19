#ifndef _HBLK_CRYPTO_H_
#define _HBLK_CRYPTO_H_

#include <stdlib.h>
#include <stdint.h>

// taking from openssl crypto/sha/sha.h

#define UNUSED(x) UNUSED_ ## x __attribute__((unused))

#define SHA256_DIGEST_LENGTH 32

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);


#endif