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

#ifndef __OPENCV_CORE_TRAITS_HPP__
#define __OPENCV_CORE_TRAITS_HPP__

#include "opencv2/core/cvdef.h"
#include "opencv2/core/cvdef.hpp"

namespace cv
{
    
    
    
    


/*!
   Informative template class for OpenCV "scalars".

   The class is specialized for each primitive numerical type supported by OpenCV (such as unsigned char or float),
   as well as for more complex types, like cv::Complex<>, std::complex<>, cv::Vec<> etc.
   The common property of all such types (called "scalars", do not confuse it with cv::Scalar_)
   is that each of them is basically a tuple of numbers of the same type. Each "scalar" can be represented
   by the depth id (CV_8U ... CV_64F) and the number of channels.
   OpenCV matrices, 2D or nD, dense or sparse, can store "scalars",
   as long as the number of channels does not exceed CV_CN_MAX.
*/
template<typename _Tp> class DataType
{
public:
    typedef _Tp         value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 1,
           depth        = -1,
           channels     = 1,
           fmt          = 0,
           type = CV_MAKETYPE(depth, channels)
         };
};

    ;
    /*
     template<> class DataType<u2bit>
     {
     public:
     typedef u2bit value_type;
     typedef u4bit work_type;
     typedef value_type channel_type;
     typedef value_type vec_type;
     enum { generic_type = 0, depth = DataDepth<channel_type>::value, channels = 1,
     fmt=DataDepth<channel_type>::fmt,
     type = CV_MAKETYPE(depth, channels) };
     };
     
     template<> class DataType<u4bit>
     {
     public:
     typedef u4bit value_type;
     typedef uchar work_type;
     typedef value_type channel_type;
     typedef value_type vec_type;
     enum { generic_type = 0, depth = DataDepth<channel_type>::value, channels = 1,
     fmt=DataDepth<channel_type>::fmt,
     type = CV_MAKETYPE(depth, channels) };
     };
     */
    
    
template<> class DataType<bool>
{
public:
    typedef bool        value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_8U,
           channels     = 1,
           fmt          = (int)'u',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<uchar>
{
public:
    typedef uchar       value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_8U,
           channels     = 1,
           fmt          = (int)'u',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<schar>
{
public:
    typedef schar       value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_8S,
           channels     = 1,
           fmt          = (int)'c',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<char>
{
public:
    typedef schar       value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_8S,
           channels     = 1,
           fmt          = (int)'c',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<ushort>
{
public:
    typedef ushort      value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_16U,
           channels     = 1,
           fmt          = (int)'w',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<short>
{
public:
    typedef short       value_type;
    typedef int         work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_16S,
           channels     = 1,
           fmt          = (int)'s',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<int>
{
public:
    typedef int         value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_32S,
           channels     = 1,
           fmt          = (int)'i',
           type         = CV_MAKETYPE(depth, channels)
         };
};

    
template<> class DataType<unsigned>
{
public:
    typedef unsigned value_type;
    typedef value_type work_type;
    typedef value_type channel_type;
    typedef value_type vec_type;
    enum { generic_type = 0,
           depth        = CV_32U,
           channels     = 1,
           fmt          = (int)'u',
           type         = CV_MAKETYPE(depth, channels)
        };
};
    
    
template<> class DataType<float>
{
public:
    typedef float       value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_32F,
           channels     = 1,
           fmt          = (int)'f',
           type         = CV_MAKETYPE(depth, channels)
         };
};

template<> class DataType<double>
{
public:
    typedef double      value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;
    enum { generic_type = 0,
           depth        = CV_64F,
           channels     = 1,
           fmt          = (int)'d',
           type         = CV_MAKETYPE(depth, channels)
         };
};

    /*!
     A helper class for cv::DataType
     
     The class is specialized for each fundamental numerical data type supported by OpenCV.
     It provides DataDepth<T>::value constant.
     */
    
    /*
     template<typename _Tp> class CV_EXPORTS DataDepth {};
     
     template<> class DataDepth<bool> { public: enum { value = CV_8U, fmt=(int)'u' }; };
     */
    /*
     template<> class DataDepth<u2bit> { public: enum { value = CV_2U, fmt=(int)'u' }; };
     template<> class DataDepth<u4bit> { public: enum { value = CV_4U, fmt=(int)'u' }; };
     template<> class DataDepth<uchar> { public: enum { value = CV_8U, fmt=(int)'u' }; };
     template<> class DataDepth<schar> { public: enum { value = CV_8S, fmt=(int)'c' }; };
     template<> class DataDepth< char> { public: enum { value = CV_8S, fmt=(int)'c' }; };
     template<> class DataDepth<ushort> { public: enum { value = CV_16U, fmt=(int)'w' }; };
     template<> class DataDepth< short> { public: enum { value = CV_16S, fmt=(int)'s' }; };
     template<> class DataDepth<unsigned> { public: enum { value = CV_32U, fmt=(int)'i' }; };
     template<> class DataDepth< int> { public: enum { value = CV_32S, fmt=(int)'i' }; };
     template<> class DataDepth<unsigned long long int> { public: enum { value = CV_64U, fmt=(int)'i' }; };
     template<> class DataDepth<  signed long long int> { public: enum { value = CV_64S, fmt=(int)'i' }; };
     
     
     template<> class DataDepth<unsigned char> { public: enum { value = CV_8U, fmt=(int)'u' }; };
     template<> class DataDepth<  signed char> { public: enum { value = CV_8S, fmt=(int)'c' }; };
     template<> class DataDepth<unsigned short int> { public: enum { value = CV_16U, fmt=(int)'w' }; };
     template<> class DataDepth<  signed short int> { public: enum { value = CV_16S, fmt=(int)'s' }; };
     template<> class DataDepth<unsigned long int> { public: enum { value = CV_32U, fmt=(int)'i' }; };
     template<> class DataDepth<  signed long int> { public: enum { value = CV_32S, fmt=(int)'i' }; };
     template<> class DataDepth<unsigned long long int> { public: enum { value = CV_64U, fmt=(int)'i' }; };
     template<> class DataDepth<  signed long long int> { public: enum { value = CV_64S, fmt=(int)'i' }; };
     */
    template<typename _Tp> class DataDepth
    {
    public:
        enum
        {
            value = DataType<_Tp>::depth,
            fmt   = DataType<_Tp>::fmt
        };
    };
    template<> class DataDepth<uint8_t>  { public: enum { value = CV_8U,  fmt=(int)'u' }; }; // should be hhu
    template<> class DataDepth< int8_t>  { public: enum { value = CV_8S,  fmt=(int)'i' }; }; // should be hhi
    template<> class DataDepth<uint16_t> { public: enum { value = CV_16U, fmt=(int)'u' }; }; // should be hu
    template<> class DataDepth< int16_t> { public: enum { value = CV_16S, fmt=(int)'i' }; }; // should be hi
    template<> class DataDepth<uint32_t> { public: enum { value = CV_32U, fmt=(int)'u' }; };
    template<> class DataDepth< int32_t> { public: enum { value = CV_32S, fmt=(int)'i' }; };
    template<> class DataDepth<uint64_t> { public: enum { value = CV_64U, fmt=(int)'u' }; }; // should be llu
    template<> class DataDepth< int64_t> { public: enum { value = CV_64S, fmt=(int)'i' }; }; // should be lli
    
    template<> class DataDepth<float> { public: enum { value = CV_32F, fmt=(int)'f' }; };
    template<> class DataDepth<double> { public: enum { value = CV_64F, fmt=(int)'d' }; };
    template<typename _Tp> class DataDepth<_Tp*> { public: enum { value = CV_USRTYPE1, fmt=(int)'r' }; };
    
 
    
    
    /* void cv_Print_Data_Type(int type){
     printf("%llu",CV_DEPTH_BITS_MAGIC);
     printf("To get back the information put into CV_MAKETYPE( depth_Type, cn) use");
     printf("int depth_Type = %u", CV_MAT_DEPTH(type));
     printf("int cn = %u", CV_MAT_CN(type));
     printf("To get info on the type itself use");
     printf("int bit_Depth  = %u",   CV_MAT_DEPTH_BITS(type));
     printf("int byte_Depth = %u", CV_MAT_DEPTH_BYTES(type));
     printf("int channels = %u",  CV_MAT_CN(type));
     }
     
     */


template<int _depth> class TypeDepth
{
    enum { depth = CV_USRTYPE1 };
    typedef void value_type;
};

template<> class TypeDepth<CV_8U>
{
    enum { depth = CV_8U };
    typedef uchar value_type;
};

template<> class TypeDepth<CV_8S>
{
    enum { depth = CV_8S };
    typedef schar value_type;
};

template<> class TypeDepth<CV_16U>
{
    enum { depth = CV_16U };
    typedef ushort value_type;
};

template<> class TypeDepth<CV_16S>
{
    enum { depth = CV_16S };
    typedef short value_type;
};

template<> class TypeDepth<CV_32S>
{
    enum { depth = CV_32S };
    typedef int value_type;
};

template<> class TypeDepth<CV_32F>
{
    enum { depth = CV_32F };
    typedef float value_type;
};

template<> class TypeDepth<CV_64F>
{
    enum { depth = CV_64F };
    typedef double value_type;
};

} // cv

#endif // __OPENCV_CORE_TRAITS_HPP__
