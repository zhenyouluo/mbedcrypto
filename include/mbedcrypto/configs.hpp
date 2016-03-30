/** @file configs.hpp
 *
 * @copyright (C) 2016
 * @date 2016.03.07
 * @version 1.0.0
 * @author amir zamani <azadkuh@live.com>
 *
 */

#ifndef MBEDCRYPTO_CONFIGS_HPP
#define MBEDCRYPTO_CONFIGS_HPP

#include <string>
///////////////////////////////////////////////////////////////////////////////
namespace mbedcrypto {

/// std::string is able to hold both TEXT and Binary data.
/// as encryption is frequently being used with both text strings and binaries,
///  std::string is more convenient than std::vector<unsigned char> or
///  std::basic_string<unsigned char>.
/// although std::vector<unsigned char> is a better options for binary contents.
using buffer_t = std::string;

} // namespace mbedcrypto
///////////////////////////////////////////////////////////////////////////////
// win32 shared lib stuff for future updates, not implented yet
#if defined(WIN32)
#   if defined(MBEDCRYPTO_DYNAMIC)
#       if defined(MBEDCRYPTO_EXPORT)
#           define MBEDCRYPTO_API __declspec(dllexport)
#       else // MBEDCRYPTO_EXPORT
#           define MBEDCRYPTO_API __declspec(dllimport)
#       endif // MBEDCRYPTO_EXPORT
#   else // MBEDCYPTO_DYNAMIC
#       define MBEDCRYPTO_API
#   endif // MBEDCRYPTO_DYNAMIC
#else // WIN32
#   define MBEDCRYPTO_API
#endif // WIN32
///////////////////////////////////////////////////////////////////////////////
#endif // MBEDCRYPTO_CONFIGS_HPP
