#include "conversions.hpp"

///////////////////////////////////////////////////////////////////////////////
namespace mbedcrypto {
namespace {
///////////////////////////////////////////////////////////////////////////////
template<typename Enum, typename Native>
struct enum_map {
    Enum    e;
    Native  n;
};

template<typename Enum, class Array>
auto to_native(Enum e, const Array& items) {
    for ( const auto& i : items ) {
        if ( i.e == e )
            return i.n;
    }

    throw std::logic_error("invalid conversion type");
}

template<typename Native, class Array>
auto from_native(Native n, const Array& items) {
    for ( const auto& i : items ) {
        if ( i.n == n )
            return i.e;
    }

    throw std::logic_error("invalid conversion type");
}

///////////////////////////////////////////////////////////////////////////////
const enum_map<hash_t, mbedtls_md_type_t> gHashes[] = {
    {hash_t::none,      MBEDTLS_MD_NONE},
    {hash_t::md2,       MBEDTLS_MD_MD2},
    {hash_t::md4,       MBEDTLS_MD_MD4},
    {hash_t::md5,       MBEDTLS_MD_MD5},
    {hash_t::sha1,      MBEDTLS_MD_SHA1},
    {hash_t::sha224,    MBEDTLS_MD_SHA224},
    {hash_t::sha256,    MBEDTLS_MD_SHA256},
    {hash_t::sha384,    MBEDTLS_MD_SHA384},
    {hash_t::sha512,    MBEDTLS_MD_SHA512},
    {hash_t::ripemd160, MBEDTLS_MD_RIPEMD160},
};

const enum_map<cipher_t, mbedtls_cipher_type_t> gCiphers[] = {
    {cipher_t::none,                MBEDTLS_CIPHER_NONE},
    {cipher_t::null,                MBEDTLS_CIPHER_NULL},
    {cipher_t::aes_128_ecb,         MBEDTLS_CIPHER_AES_128_ECB},
    {cipher_t::aes_192_ecb,         MBEDTLS_CIPHER_AES_192_ECB},
    {cipher_t::aes_256_ecb,         MBEDTLS_CIPHER_AES_256_ECB},
    {cipher_t::aes_128_cbc,         MBEDTLS_CIPHER_AES_128_CBC},
    {cipher_t::aes_192_cbc,         MBEDTLS_CIPHER_AES_192_CBC},
    {cipher_t::aes_256_cbc,         MBEDTLS_CIPHER_AES_256_CBC},
    {cipher_t::aes_128_cfb128,      MBEDTLS_CIPHER_AES_128_CFB128},
    {cipher_t::aes_192_cfb128,      MBEDTLS_CIPHER_AES_192_CFB128},
    {cipher_t::aes_256_cfb128,      MBEDTLS_CIPHER_AES_256_CFB128},
    {cipher_t::aes_128_ctr,         MBEDTLS_CIPHER_AES_128_CTR},
    {cipher_t::aes_192_ctr,         MBEDTLS_CIPHER_AES_192_CTR},
    {cipher_t::aes_256_ctr,         MBEDTLS_CIPHER_AES_256_CTR},
    {cipher_t::aes_128_gcm,         MBEDTLS_CIPHER_AES_128_GCM},
    {cipher_t::aes_192_gcm,         MBEDTLS_CIPHER_AES_192_GCM},
    {cipher_t::aes_256_gcm,         MBEDTLS_CIPHER_AES_256_GCM},
    {cipher_t::camellia_128_ecb,    MBEDTLS_CIPHER_CAMELLIA_128_ECB},
    {cipher_t::camellia_192_ecb,    MBEDTLS_CIPHER_CAMELLIA_192_ECB},
    {cipher_t::camellia_256_ecb,    MBEDTLS_CIPHER_CAMELLIA_256_ECB},
    {cipher_t::camellia_128_cbc,    MBEDTLS_CIPHER_CAMELLIA_128_CBC},
    {cipher_t::camellia_192_cbc,    MBEDTLS_CIPHER_CAMELLIA_192_CBC},
    {cipher_t::camellia_256_cbc,    MBEDTLS_CIPHER_CAMELLIA_256_CBC},
    {cipher_t::camellia_128_cfb128, MBEDTLS_CIPHER_CAMELLIA_128_CFB128},
    {cipher_t::camellia_192_cfb128, MBEDTLS_CIPHER_CAMELLIA_192_CFB128},
    {cipher_t::camellia_256_cfb128, MBEDTLS_CIPHER_CAMELLIA_256_CFB128},
    {cipher_t::camellia_128_ctr,    MBEDTLS_CIPHER_CAMELLIA_128_CTR},
    {cipher_t::camellia_192_ctr,    MBEDTLS_CIPHER_CAMELLIA_192_CTR},
    {cipher_t::camellia_256_ctr,    MBEDTLS_CIPHER_CAMELLIA_256_CTR},
    {cipher_t::camellia_128_gcm,    MBEDTLS_CIPHER_CAMELLIA_128_GCM},
    {cipher_t::camellia_192_gcm,    MBEDTLS_CIPHER_CAMELLIA_192_GCM},
    {cipher_t::camellia_256_gcm,    MBEDTLS_CIPHER_CAMELLIA_256_GCM},
    {cipher_t::des_ecb,             MBEDTLS_CIPHER_DES_ECB},
    {cipher_t::des_cbc,             MBEDTLS_CIPHER_DES_CBC},
    {cipher_t::des_ede_ecb,         MBEDTLS_CIPHER_DES_EDE_ECB},
    {cipher_t::des_ede_cbc,         MBEDTLS_CIPHER_DES_EDE_CBC},
    {cipher_t::des_ede3_ecb,        MBEDTLS_CIPHER_DES_EDE3_ECB},
    {cipher_t::des_ede3_cbc,        MBEDTLS_CIPHER_DES_EDE3_CBC},
    {cipher_t::blowfish_ecb,        MBEDTLS_CIPHER_BLOWFISH_ECB},
    {cipher_t::blowfish_cbc,        MBEDTLS_CIPHER_BLOWFISH_CBC},
    {cipher_t::blowfish_cfb64,      MBEDTLS_CIPHER_BLOWFISH_CFB64},
    {cipher_t::blowfish_ctr,        MBEDTLS_CIPHER_BLOWFISH_CTR},
    {cipher_t::arc4_128,            MBEDTLS_CIPHER_ARC4_128},
    {cipher_t::aes_128_ccm,         MBEDTLS_CIPHER_AES_128_CCM},
    {cipher_t::aes_192_ccm,         MBEDTLS_CIPHER_AES_192_CCM},
    {cipher_t::aes_256_ccm,         MBEDTLS_CIPHER_AES_256_CCM},
    {cipher_t::camellia_128_ccm,    MBEDTLS_CIPHER_CAMELLIA_128_CCM},
    {cipher_t::camellia_192_ccm,    MBEDTLS_CIPHER_CAMELLIA_192_CCM},
    {cipher_t::camellia_256_ccm,    MBEDTLS_CIPHER_CAMELLIA_256_CCM},
};

const enum_map<padding_t, mbedtls_cipher_padding_t> gPaddings[] = {
    {padding_t::pkcs7,         MBEDTLS_PADDING_PKCS7},
    {padding_t::one_and_zeros, MBEDTLS_PADDING_ONE_AND_ZEROS},
    {padding_t::zeros_and_len, MBEDTLS_PADDING_ZEROS_AND_LEN},
    {padding_t::zeros,         MBEDTLS_PADDING_ZEROS},
    {padding_t::none,          MBEDTLS_PADDING_NONE},
};

const enum_map<pk_t, mbedtls_pk_type_t> gPks[] = {
    {pk_t::none,       MBEDTLS_PK_NONE},
    {pk_t::rsa,        MBEDTLS_PK_RSA},
    {pk_t::eckey,      MBEDTLS_PK_ECKEY},
    {pk_t::eckey_dh,   MBEDTLS_PK_ECKEY_DH},
    {pk_t::ecdsa,      MBEDTLS_PK_ECDSA},
    {pk_t::rsa_alt,    MBEDTLS_PK_RSA_ALT},
    {pk_t::rsassa_pss, MBEDTLS_PK_RSASSA_PSS},
};
///////////////////////////////////////////////////////////////////////////////
} // namespace anon
///////////////////////////////////////////////////////////////////////////////

mbedtls_md_type_t
to_native(hash_t e) {
    return to_native(e, gHashes);
}

hash_t
from_native(mbedtls_md_type_t n) {
    return from_native(n, gHashes);
}

mbedtls_cipher_type_t
to_native(cipher_t e) {
    return to_native(e, gCiphers);
}

cipher_t
from_native(mbedtls_cipher_type_t n) {
    return from_native(n, gCiphers);
}

mbedtls_cipher_padding_t
to_native(padding_t e) {
    return to_native(e, gPaddings);
}

padding_t
from_native(mbedtls_cipher_padding_t n) {
    return from_native(n, gPaddings);
}

mbedtls_pk_type_t
to_native(pk_t e) {
    return to_native(e, gPks);
}

pk_t
from_native(mbedtls_pk_type_t n) {
    return from_native(n, gPks);
}

///////////////////////////////////////////////////////////////////////////////
} // namespace mbedcrypto
///////////////////////////////////////////////////////////////////////////////