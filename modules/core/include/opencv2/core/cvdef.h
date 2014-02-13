/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/


#include <float.h>

#ifndef __OPENCV_CORE_CVDEF_H__
#define __OPENCV_CORE_CVDEF_H__

#if !defined _CRT_SECURE_NO_DEPRECATE && defined _MSC_VER && _MSC_VER > 1300
#  define _CRT_SECURE_NO_DEPRECATE /* to avoid multiple Visual Studio warnings */
#endif

// undef problematic defines sometimes defined by system headers (windows.h in particular)
#undef small
#undef min
#undef max
#undef abs
#undef Complex

#if defined __ICL
#  define CV_ICC   __ICL
#elif defined __ICC
#  define CV_ICC   __ICC
#elif defined __ECL
#  define CV_ICC   __ECL
#elif defined __ECC
#  define CV_ICC   __ECC
#elif defined __INTEL_COMPILER
#  define CV_ICC   __INTEL_COMPILER
#endif

#if defined CV_ICC && !defined CV_ENABLE_UNROLLED
#  define CV_ENABLE_UNROLLED 0
#else
#  define CV_ENABLE_UNROLLED 1
#endif

#if (defined WIN32 || defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined CVAPI_EXPORTS
#  define CV_EXPORTS __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4
#  define CV_EXPORTS __attribute__ ((visibility ("default")))
#else
#  define CV_EXPORTS
#endif

#ifndef CV_INLINE
#  if defined __cplusplus
#    define CV_INLINE static inline
#  elif defined _MSC_VER
#    define CV_INLINE __inline
#  else
#    define CV_INLINE static
#  endif
#endif

#ifndef CV_EXTERN_C
#  ifdef __cplusplus
#    define CV_EXTERN_C extern "C"
#  else
#    define CV_EXTERN_C
#  endif
#endif

/* CPU features and intrinsics support */
#define CV_CPU_NONE    0
#define CV_CPU_MMX     1
#define CV_CPU_SSE     2
#define CV_CPU_SSE2    3
#define CV_CPU_SSE3    4
#define CV_CPU_SSSE3   5
#define CV_CPU_SSE4_1  6
#define CV_CPU_SSE4_2  7
#define CV_CPU_POPCNT  8
#define CV_CPU_AVX    10
#define CV_CPU_NEON   11
// when adding to this list remember to update the enum in core/utility.cpp
#define CV_HARDWARE_MAX_FEATURE 255

// do not include SSE/AVX/NEON headers for NVCC compiler
#ifndef __CUDACC__

#if defined __SSE2__ || defined _M_X64  || (defined _M_IX86_FP && _M_IX86_FP >= 2)
#  include <emmintrin.h>
#  define CV_SSE 1
#  define CV_SSE2 1
#  if defined __SSE3__ || (defined _MSC_VER && _MSC_VER >= 1500)
#    include <pmmintrin.h>
#    define CV_SSE3 1
#  endif
#  if defined __SSSE3__  || (defined _MSC_VER && _MSC_VER >= 1500)
#    include <tmmintrin.h>
#    define CV_SSSE3 1
#  endif
#  if defined __SSE4_1__ || (defined _MSC_VER && _MSC_VER >= 1500)
#    include <smmintrin.h>
#    define CV_SSE4_1 1
#  endif
#  if defined __SSE4_2__ || (defined _MSC_VER && _MSC_VER >= 1500)
#    include <nmmintrin.h>
#    define CV_SSE4_2 1
#  endif
#  if defined __AVX__ || (defined _MSC_FULL_VER && _MSC_FULL_VER >= 160040219)
// MS Visual Studio 2010 (2012?) has no macro pre-defined to identify the use of /arch:AVX
// See: http://connect.microsoft.com/VisualStudio/feedback/details/605858/arch-avx-should-define-a-predefined-macro-in-x64-and-set-a-unique-value-for-m-ix86-fp-in-win32
#    include <immintrin.h>
#    define CV_AVX 1
#    if defined(_XCR_XFEATURE_ENABLED_MASK)
#      define __xgetbv() _xgetbv(_XCR_XFEATURE_ENABLED_MASK)
#    else
#      define __xgetbv() 0
#    endif
#  endif
#endif

#if (defined WIN32 || defined _WIN32) && defined(_M_ARM)
# include <Intrin.h>
# include "arm_neon.h"
# define CV_NEON 1
# define CPU_HAS_NEON_FEATURE (true)
#elif defined(__ARM_NEON__)
#  include <arm_neon.h>
#  define CV_NEON 1
#endif

#endif // __CUDACC__

#ifndef CV_SSE
#  define CV_SSE 0
#endif
#ifndef CV_SSE2
#  define CV_SSE2 0
#endif
#ifndef CV_SSE3
#  define CV_SSE3 0
#endif
#ifndef CV_SSSE3
#  define CV_SSSE3 0
#endif
#ifndef CV_SSE4_1
#  define CV_SSE4_1 0
#endif
#ifndef CV_SSE4_2
#  define CV_SSE4_2 0
#endif
#ifndef CV_AVX
#  define CV_AVX 0
#endif
#ifndef CV_NEON
#  define CV_NEON 0
#endif

/* primitive types */
/*
  schar  - signed 1 byte integer
  uchar  - unsigned 1 byte integer
  short  - signed 2 byte integer
  ushort - unsigned 2 byte integer
  int    - signed 4 byte integer
  uint   - unsigned 4 byte integer
  int64  - signed 8 byte integer
  uint64 - unsigned 8 byte integer
*/

#if !defined _MSC_VER && !defined __BORLANDC__
#  if defined __cplusplus && __cplusplus >= 201103L
#    include <cstdint>
     typedef std::uint32_t uint;
#  else
#    include <stdint.h>
     typedef uint32_t uint;
#  endif
#else
   typedef unsigned uint;
#endif

typedef signed char schar;

#ifndef __IPL_H__
   typedef unsigned char uchar;
   typedef unsigned short ushort;
#endif

#if defined _MSC_VER || defined __BORLANDC__
   typedef __int64 int64;
   typedef unsigned __int64 uint64;
#  define CV_BIG_INT(n)   n##I64
#  define CV_BIG_UINT(n)  n##UI64
#else
   typedef int64_t int64;
   typedef uint64_t uint64;
#  define CV_BIG_INT(n)   n##LL
#  define CV_BIG_UINT(n)  n##ULL
#endif

/* special informative macros for wrapper generators */
#define CV_EXPORTS_W CV_EXPORTS
#define CV_EXPORTS_W_SIMPLE CV_EXPORTS
#define CV_EXPORTS_AS(synonym) CV_EXPORTS
#define CV_EXPORTS_W_MAP CV_EXPORTS
#define CV_IN_OUT
#define CV_OUT
#define CV_PROP
#define CV_PROP_RW
#define CV_WRAP
#define CV_WRAP_AS(synonym)

/* fundamental constants */
#define CV_PI   3.1415926535897932384626433832795
#define CV_LOG2 0.69314718055994530941723212145818

/****************************************************************************************\
*                                  Matrix type (Mat)                                     *
\****************************************************************************************/
// CV_CN_MAX reserves 9 bits for the channel numbers.
#define CV_CN_MAX     (1 << 9)
// CV_CN_SHIFT resrves the first 4 bits for the Data Types (CV_8U, etc)
#define CV_CN_SHIFT   4
// CV_DEPTH_MAX is the maximum number of Data types allowed.
#define CV_DEPTH_MAX  (1 << CV_CN_SHIFT)
// The order is
// {CV_2U, CV_4U, CV_8U, CV_8S, CV_16U, CV_16S, CV_32U, CV_32S, CV_64U, CV_64S, CV_32F, CV_64F, CV_USRTYPE1, CV_USRTYPE2, CV_USRTYPE3, CV_USRTYPE4}

#define CV_8U   2
#define CV_8U_DEPTH_BITS_LOG2 3
#define CV_8U_DEPTH_BYTES_LOG2 0
#define CV_8U_TYPE  std::uint8_t
#define CV_8U_MAX   UINT8_MAX
#define CV_8U_MIN   0

#define CV_8S   3
#define CV_8S_DEPTH_BITS_LOG2 3
#define CV_8S_DEPTH_BYTES_LOG2 0
#define CV_8S_TYPE  std::int8_t
#define CV_8S_MAX   INT8_MAX
#define CV_8S_MIN   INT8_MIN

#define CV_16U  4
#define CV_16U_DEPTH_BITS_LOG2 4
#define CV_16U_DEPTH_BYTES_LOG2 1
#define CV_16U_TYPE  std::uint16_t
#define CV_16U_MAX   UINT16_MAX
#define CV_16U_MIN   0

#define CV_16S  5
#define CV_16S_DEPTH_BITS_LOG2 4
#define CV_16S_DEPTH_BYTES_LOG2 1
#define CV_16S_TYPE  std::int16_t
#define CV_16S_MAX   INT16_MAX
#define CV_16S_MIN   INT16_MIN

#define CV_32U  6
#define CV_32U_DEPTH_BITS_LOG2 5
#define CV_32U_DEPTH_BYTES_LOG2 2
#define CV_32U_TYPE  std::uint32_t
#define CV_32U_MAX   UINT32_MAX
#define CV_32U_MIN   0

#define CV_32S  7
#define CV_32S_DEPTH_BITS_LOG2 5
#define CV_32S_DEPTH_BYTES_LOG2 2
#define CV_32S_TYPE  std::int32_t
#define CV_32S_MAX   INT32_MAX
#define CV_32S_MIN   INT32_MIN

#define CV_64U  8
#define CV_64U_DEPTH_BITS_LOG2 6
#define CV_64U_DEPTH_BYTES_LOG2 3
#define CV_64U_TYPE  std::uint64_t
#define CV_64U_MAX   UINT64_MAX
#define CV_64U_MIN   0

#define CV_64S  9
#define CV_64S_DEPTH_BITS_LOG2 6
#define CV_64S_DEPTH_BYTES_LOG2 3
#define CV_64S_TYPE  std::int64_t
#define CV_64S_MAX   INT64_MAX
#define CV_64S_MIN   INT64_MIN

#define CV_32F  10
#define CV_32F_DEPTH_BITS_LOG2 5
#define CV_32F_DEPTH_BYTES_LOG2 2
#define CV_32F_TYPE  float
#define CV_32F_MAX   FLT_MAX
#define CV_32F_MIN   FLT_MIN

#define CV_64F  11
#define CV_64F_DEPTH_BITS_LOG2 6
#define CV_64F_DEPTH_BYTES_LOG2 3
#define CV_64F_TYPE  double
#define CV_64F_MAX   DBL_MAX
#define CV_64F_MIN   DBL_MIN

#define CV_USRTYPE1 12
#define CV_USRTYPE2 13
#define CV_USRTYPE3 14
#define CV_USRTYPE4 15


#define CV_2U   0
#define CV_2U_DEPTH_BITS_LOG2   1
#define CV_2U_DEPTH_BYTES_LOG2   0
#define CV_2U_TYPE cv::cv_2bitType
#define CV_2U_MAX   0xf
#define CV_2U_MIN   0x0


#define CV_4U   1
#define CV_4U_DEPTH_BITS_LOG2 2
#define CV_4U_DEPTH_BYTES_LOG2 0
#define CV_4U_TYPE cv::cv_4bitType
#define CV_4U_MAX   0xff
#define CV_4U_MIN   0x00

// CV_MAT_DEPTH_MASK bit mask which keeps only the right-most CV_CN_SHIFT bits. Keeps the user from screwing up when using CV_MAKETYPE.
#define CV_MAT_DEPTH_MASK     (CV_DEPTH_MAX - 1)
#define CV_MAT_DEPTH(type)    ((type) & CV_MAT_DEPTH_MASK) // CV_MAT_DEPTH(flags) applies the mask to the bits in flags.

#define CV_DEPTH_BYTES_MAGIC ( \
(CV_64F_DEPTH_BYTES_LOG2 << (CV_64F *2))|(CV_32F_DEPTH_BYTES_LOG2 << (CV_32F *2))|\
(CV_64S_DEPTH_BYTES_LOG2 << (CV_64S *2))|(CV_64U_DEPTH_BYTES_LOG2 << (CV_64U *2))|\
(CV_32S_DEPTH_BYTES_LOG2 << (CV_32S *2))|(CV_32U_DEPTH_BYTES_LOG2 << (CV_32U *2))|\
(CV_16S_DEPTH_BYTES_LOG2 << (CV_16S *2))|(CV_16U_DEPTH_BYTES_LOG2 << (CV_16U *2))|\
(CV_8S_DEPTH_BYTES_LOG2  << (CV_8S  *2))|(CV_8U_DEPTH_BYTES_LOG2  << (CV_8U  *2))|\
(CV_4U_DEPTH_BYTES_LOG2  << (CV_4U  *2))|(CV_2U_DEPTH_BYTES_LOG2  << (CV_2U  *2)) )

#define CV_MAT_DEPTH_BYTES(type) (1 << ( (CV_DEPTH_BYTES_MAGIC >> (CV_MAT_DEPTH(type)*2)) &3) )
#define CV_DEPTH_BYTES(type)     CV_MAT_DEPTH_BYTES(type) // Depreciated

#define CV_DEPTH_BITS_MAGIC ( \
(uint64_t(CV_64F_DEPTH_BITS_LOG2) << (CV_64F *3))|(uint64_t(CV_32F_DEPTH_BITS_LOG2) << (CV_32F *3))|\
(uint64_t(CV_64S_DEPTH_BITS_LOG2) << (CV_64S *3))|(uint64_t(CV_64U_DEPTH_BITS_LOG2) << (CV_64U *3))|\
(uint64_t(CV_32S_DEPTH_BITS_LOG2) << (CV_32S *3))|(uint64_t(CV_32U_DEPTH_BITS_LOG2) << (CV_32U *3))|\
(uint64_t(CV_16S_DEPTH_BITS_LOG2) << (CV_16S *3))|(uint64_t(CV_16U_DEPTH_BITS_LOG2) << (CV_16U *3))|\
(uint64_t(CV_8S_DEPTH_BITS_LOG2)  << (CV_8S  *3))|(uint64_t(CV_8U_DEPTH_BITS_LOG2)  << (CV_8U  *3))|\
(uint64_t(CV_4U_DEPTH_BITS_LOG2)  << (CV_4U  *3))|(uint64_t(CV_2U_DEPTH_BITS_LOG2)  << (CV_2U  *3)) )

#define CV_MAT_DEPTH_BITS(type)   (1 << ( (CV_DEPTH_BITS_MAGIC >> ((CV_MAT_DEPTH(type))*3)) & 7) )
#define CV_DEPTH_BITS(type)       CV_MAT_DEPTH_BITS(type) // Depreciated

// CV_MAKETYPE(depth,cn) generated an integer using the right-most CV_CN_SHIFT bits for the depth and the rest for the channels.
#define CV_MAKETYPE(depth,cn) (CV_MAT_DEPTH(depth) + (((cn)-1) << CV_CN_SHIFT))
#define CV_MAKE_TYPE CV_MAKETYPE

#define CV_2UC1 CV_MAKETYPE(CV_2U,1)
#define CV_2UC2 CV_MAKETYPE(CV_2U,2)
#define CV_2UC3 CV_MAKETYPE(CV_2U,3)
#define CV_2UC4 CV_MAKETYPE(CV_2U,4)
#define CV_2UC(n) CV_MAKETYPE(CV_2U,(n))

#define CV_4UC1 CV_MAKETYPE(CV_4U,1)
#define CV_4UC2 CV_MAKETYPE(CV_4U,2)
#define CV_4UC3 CV_MAKETYPE(CV_4U,3)
#define CV_4UC4 CV_MAKETYPE(CV_4U,4)
#define CV_4UC(n) CV_MAKETYPE(CV_4U,(n))

#define CV_8UC1 CV_MAKETYPE(CV_8U,1)
#define CV_8UC2 CV_MAKETYPE(CV_8U,2)
#define CV_8UC3 CV_MAKETYPE(CV_8U,3)
#define CV_8UC4 CV_MAKETYPE(CV_8U,4)
#define CV_8UC(n) CV_MAKETYPE(CV_8U,(n))

#define CV_8SC1 CV_MAKETYPE(CV_8S,1)
#define CV_8SC2 CV_MAKETYPE(CV_8S,2)
#define CV_8SC3 CV_MAKETYPE(CV_8S,3)
#define CV_8SC4 CV_MAKETYPE(CV_8S,4)
#define CV_8SC(n) CV_MAKETYPE(CV_8S,(n))

#define CV_16UC1 CV_MAKETYPE(CV_16U,1)
#define CV_16UC2 CV_MAKETYPE(CV_16U,2)
#define CV_16UC3 CV_MAKETYPE(CV_16U,3)
#define CV_16UC4 CV_MAKETYPE(CV_16U,4)
#define CV_16UC(n) CV_MAKETYPE(CV_16U,(n))

#define CV_16SC1 CV_MAKETYPE(CV_16S,1)
#define CV_16SC2 CV_MAKETYPE(CV_16S,2)
#define CV_16SC3 CV_MAKETYPE(CV_16S,3)
#define CV_16SC4 CV_MAKETYPE(CV_16S,4)
#define CV_16SC(n) CV_MAKETYPE(CV_16S,(n))

#define CV_32UC1 CV_MAKETYPE(CV_32U,1)
#define CV_32UC2 CV_MAKETYPE(CV_32U,2)
#define CV_32UC3 CV_MAKETYPE(CV_32U,3)
#define CV_32UC4 CV_MAKETYPE(CV_32U,4)
#define CV_32UC(n) CV_MAKETYPE(CV_32U,(n))

#define CV_32SC1 CV_MAKETYPE(CV_32S,1)
#define CV_32SC2 CV_MAKETYPE(CV_32S,2)
#define CV_32SC3 CV_MAKETYPE(CV_32S,3)
#define CV_32SC4 CV_MAKETYPE(CV_32S,4)
#define CV_32SC(n) CV_MAKETYPE(CV_32S,(n))

#define CV_64UC1 CV_MAKETYPE(CV_64U,1)
#define CV_64UC2 CV_MAKETYPE(CV_64U,2)
#define CV_64UC3 CV_MAKETYPE(CV_64U,3)
#define CV_64UC4 CV_MAKETYPE(CV_64U,4)
#define CV_64UC(n) CV_MAKETYPE(CV_64U,(n))

#define CV_64SC1 CV_MAKETYPE(CV_64S,1)
#define CV_64SC2 CV_MAKETYPE(CV_64S,2)
#define CV_64SC3 CV_MAKETYPE(CV_64S,3)
#define CV_64SC4 CV_MAKETYPE(CV_64S,4)
#define CV_64SC(n) CV_MAKETYPE(CV_64S,(n))

#define CV_32FC1 CV_MAKETYPE(CV_32F,1)
#define CV_32FC2 CV_MAKETYPE(CV_32F,2)
#define CV_32FC3 CV_MAKETYPE(CV_32F,3)
#define CV_32FC4 CV_MAKETYPE(CV_32F,4)
#define CV_32FC(n) CV_MAKETYPE(CV_32F,(n))

#define CV_64FC1 CV_MAKETYPE(CV_64F,1)
#define CV_64FC2 CV_MAKETYPE(CV_64F,2)
#define CV_64FC3 CV_MAKETYPE(CV_64F,3)
#define CV_64FC4 CV_MAKETYPE(CV_64F,4)
#define CV_64FC(n) CV_MAKETYPE(CV_64F,(n))

// To get back the information put into CV_MAKETYPE( depth_Type, cn) use
// int depth_Type = CV_MAT_DEPTH(CV_##tC#)
// int cn = CV_MAT_CN(CV_##tC#)
// To get info on the type itself use
// int bit_Depth  = CV_MAT_DEPTH_BITS(CV_##tC#)
// int byte_Depth = CV_MAT_DEPTH_BYTES(CV_##tC#)
// int channels = CV_MAT_CN(CV_##tC#)

// #define CV_MAT_DEPTH_BITS(flags)      CV_DEPTH_BITS(((flags) & CV_MAT_DEPTH_MASK))
// #define CV_MAT_DEPTH_BYTES(flags)     CV_DEPTH_BYTES(((flags) & CV_MAT_DEPTH_MASK))

#define CV_AUTO_STEP  0x7fffffff
#define CV_WHOLE_ARR  cvSlice( 0, 0x3fffffff )

#define CV_MAT_CN_MASK          ((CV_CN_MAX - 1) << CV_CN_SHIFT)
#define CV_MAT_CN(flags)        ((((flags) & CV_MAT_CN_MASK) >> CV_CN_SHIFT) + 1)
#define CV_MAT_TYPE_MASK        (CV_DEPTH_MAX*CV_CN_MAX - 1)
#define CV_MAT_TYPE(flags)      ((flags) & CV_MAT_TYPE_MASK)
#define CV_MAT_CONT_FLAG_SHIFT  14
#define CV_MAT_CONT_FLAG        (1 << CV_MAT_CONT_FLAG_SHIFT)
#define CV_IS_MAT_CONT(flags)   ((flags) & CV_MAT_CONT_FLAG)
#define CV_IS_CONT_MAT          CV_IS_MAT_CONT
#define CV_SUBMAT_FLAG_SHIFT    15
#define CV_SUBMAT_FLAG          (1 << CV_SUBMAT_FLAG_SHIFT)
#define CV_IS_SUBMAT(flags)     ((flags) & CV_MAT_SUBMAT_FLAG)

#define CV_MAGIC_MASK       0xFFFF0000
#define CV_MAT_MAGIC_VAL    0x42420000
#define CV_TYPE_NAME_MAT    "opencv-matrix"


/* Size of each channel item,
 0x124489 = 1000 0100 0100 0010 0010 0001 0001 ~ array of sizeof(arr_type_elem) */
// #define CV_ELEM_SIZE1(type) \
// ((((sizeof(size_t)<<28)|0x8442211) >> CV_MAT_DEPTH(type)*4) & 15)

//#define CV_ELEM_SIZE1(type) CV_DEPTH_BYTES(type)

// Size of each channel item
#define CV_ELEM_SIZE1 CV_DEPTH_BYTES

// In case the channels are packed into fewer than one byte each we calculate : bits_used = channels * bits_per_channel
#define CV_ELEM_SIZE_BITS(type) ( CV_MAT_CN(type) * CV_MAT_DEPTH_BITS(type) )
// then bytes = Ceiling( bits_used / 8)
#define CV_ELEM_SIZE_BYTES(type) ( CV_MAT_CN(type) * CV_MAT_DEPTH_BYTES(type) )
// #define CV_ELEM_SIZE_BYTES(type) ((CV_ELEM_SIZE_BITS(type) >> 3) + ( (CV_ELEM_SIZE_BITS(type) & 7) ? 1 : 0 ))

#define CV_ELEM_SIZE CV_ELEM_SIZE_BYTES


/****************************************************************************************\
*                                      fast math                                         *
\****************************************************************************************/

#if defined __BORLANDC__
#  include <fastmath.h>
#elif defined __cplusplus
#  include <cmath>
#else
#  include <math.h>
#endif

#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))
#endif

#ifdef HAVE_TEGRA_OPTIMIZATION
#  include "tegra_round.hpp"
#endif

CV_INLINE int cvRound( double value )
{
#if ((defined _MSC_VER && defined _M_X64) || (defined __GNUC__ && defined __x86_64__ && defined __SSE2__ && !defined __APPLE__)) && !defined(__CUDACC__)
    __m128d t = _mm_set_sd( value );
    return _mm_cvtsd_si32(t);
#elif defined _MSC_VER && defined _M_IX86
    int t;
    __asm
    {
        fld value;
        fistp t;
    }
    return t;
#elif defined _MSC_VER && defined _M_ARM && defined HAVE_TEGRA_OPTIMIZATION
    TEGRA_ROUND(value);
#elif defined CV_ICC || defined __GNUC__
#  ifdef HAVE_TEGRA_OPTIMIZATION
    TEGRA_ROUND(value);
#  else
    return (int)lrint(value);
#  endif
#else
    double intpart, fractpart;
    fractpart = modf(value, &intpart);
    if ((fabs(fractpart) != 0.5) || ((((int)intpart) % 2) != 0))
        return (int)(value + (value >= 0 ? 0.5 : -0.5));
    else
        return (int)intpart;
#endif
}

CV_INLINE int cvFloor( double value )
{
#if (defined _MSC_VER && defined _M_X64 || (defined __GNUC__ && defined __SSE2__ && !defined __APPLE__)) && !defined(__CUDACC__)
    __m128d t = _mm_set_sd( value );
    int i = _mm_cvtsd_si32(t);
    return i - _mm_movemask_pd(_mm_cmplt_sd(t, _mm_cvtsi32_sd(t,i)));
#elif defined __GNUC__
    int i = (int)value;
    return i - (i > value);
#else
    int i = cvRound(value);
    float diff = (float)(value - i);
    return i - (diff < 0);
#endif
}

CV_INLINE int cvCeil( double value )
{
#if (defined _MSC_VER && defined _M_X64 || (defined __GNUC__ && defined __SSE2__&& !defined __APPLE__)) && !defined(__CUDACC__)
    __m128d t = _mm_set_sd( value );
    int i = _mm_cvtsd_si32(t);
    return i + _mm_movemask_pd(_mm_cmplt_sd(_mm_cvtsi32_sd(t,i), t));
#elif defined __GNUC__
    int i = (int)value;
    return i + (i < value);
#else
    int i = cvRound(value);
    float diff = (float)(i - value);
    return i + (diff < 0);
#endif
}

CV_INLINE int cvIsNaN( double value )
{
    union { uint64 u; double f; } ieee754;
    ieee754.f = value;
    return ((unsigned)(ieee754.u >> 32) & 0x7fffffff) +
           ((unsigned)ieee754.u != 0) > 0x7ff00000;
}

CV_INLINE int cvIsInf( double value )
{
    union { uint64 u; double f; } ieee754;
    ieee754.f = value;
    return ((unsigned)(ieee754.u >> 32) & 0x7fffffff) == 0x7ff00000 &&
           (unsigned)ieee754.u == 0;
}




/****************************************************************************************\
*          exchange-add operation for atomic operations on reference counters            *
\****************************************************************************************/

#if defined __INTEL_COMPILER && !(defined WIN32 || defined _WIN32)
   // atomic increment on the linux version of the Intel(tm) compiler
#  define CV_XADD(addr, delta) (int)_InterlockedExchangeAdd(const_cast<void*>(reinterpret_cast<volatile void*>(addr)), delta)
#elif defined __GNUC__
#  if defined __clang__ && __clang_major__ >= 3 && !defined __ANDROID__ && !defined __EMSCRIPTEN__ && !defined(__CUDACC__)
#    ifdef __ATOMIC_ACQ_REL
#      define CV_XADD(addr, delta) __c11_atomic_fetch_add((_Atomic(int)*)(addr), delta, __ATOMIC_ACQ_REL)
#    else
#      define CV_XADD(addr, delta) __atomic_fetch_add((_Atomic(int)*)(addr), delta, 4)
#    endif
#  else
#    if defined __ATOMIC_ACQ_REL && !defined __clang__
       // version for gcc >= 4.7
#      define CV_XADD(addr, delta) (int)__atomic_fetch_add((unsigned*)(addr), (unsigned)(delta), __ATOMIC_ACQ_REL)
#    else
#      define CV_XADD(addr, delta) (int)__sync_fetch_and_add((unsigned*)(addr), (unsigned)(delta))
#    endif
#  endif
#elif defined _MSC_VER && !defined RC_INVOKED
#  include <intrin.h>
#  define CV_XADD(addr, delta) (int)_InterlockedExchangeAdd((long volatile*)addr, delta)
#else
   CV_INLINE CV_XADD(int* addr, int delta) { int tmp = *addr; *addr += delta; return tmp; }
#endif


/****************************************************************************************\
*                                  CV_NORETURN attribute                                 *
\****************************************************************************************/

#ifndef CV_NORETURN
#  if defined(__GNUC__)
#    define CV_NORETURN __attribute__((__noreturn__))
#  elif defined(_MSC_VER) && (_MSC_VER >= 1300)
#    define CV_NORETURN __declspec(noreturn)
#  else
#    define CV_NORETURN /* nothing by default */
#  endif
#endif

#endif // __OPENCV_CORE_CVDEF_H__
