/** @file conversions.hpp
 *
 * @copyright (C) 2016
 * @date 2016.03.04
 * @version 1.0.0
 * @author amir zamani <azadkuh@live.com>
 *
 */

#ifndef MBEDCRYPTO_CONVERSIONS_HPP
#define MBEDCRYPTO_CONVERSIONS_HPP

#include "mbedcrypto_mbedtls_config.h"
#include "mbedtls/md.h"
#include "mbedtls/cipher.h"
#include "mbedtls/pk.h"
#include "mbedtls/ecp.h"
#include "mbedcrypto/types.hpp"
///////////////////////////////////////////////////////////////////////////////
namespace mbedcrypto {
enum class cipher_bm;
///////////////////////////////////////////////////////////////////////////////

auto to_native(hash_t)    -> mbedtls_md_type_t;
auto to_native(cipher_t)  -> mbedtls_cipher_type_t;
auto to_native(cipher_bm) -> mbedtls_cipher_mode_t;
auto to_native(padding_t) -> mbedtls_cipher_padding_t;
auto to_native(pk_t)      -> mbedtls_pk_type_t;
auto to_native(curve_t)   -> mbedtls_ecp_group_id;

auto from_native(mbedtls_md_type_t)        -> hash_t;
auto from_native(mbedtls_cipher_type_t)    -> cipher_t;
auto from_native(mbedtls_cipher_mode_t)    -> cipher_bm;
auto from_native(mbedtls_cipher_padding_t) -> padding_t;
auto from_native(mbedtls_pk_type_t)        -> pk_t;
auto from_native(mbedtls_ecp_group_id)     -> curve_t;

///////////////////////////////////////////////////////////////////////////////
} // namespace mbedcrypto
///////////////////////////////////////////////////////////////////////////////
#endif // MBEDCRYPTO_CONVERSIONS_HPP
