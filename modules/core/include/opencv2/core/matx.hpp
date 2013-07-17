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

#ifndef __OPENCV_CORE_MATX_HPP__
#define __OPENCV_CORE_MATX_HPP__

#ifndef __cplusplus
#  error matx.hpp header must be compiled as C++
#endif

#include "opencv2/core/cvdef.h"
#include "opencv2/core/base.hpp"
#include "opencv2/core/traits.hpp"

namespace cv
{
    using std::initializer_list;

////////////////////////////// Small Matrix ///////////////////////////

/*!
 A short numerical vector.

 This template class represents short numerical vectors (of 1, 2, 3, 4 ... elements)
 on which you can perform basic arithmetical operations, access individual elements using [] operator etc.
 The vectors are allocated on stack, as opposite to std::valarray, std::vector, cv::Mat etc.,
 which elements are dynamically allocated in the heap.

 The template takes 2 parameters:
 -# _Tp element type
 -# cn the number of elements

 In addition to the universal notation like Vec<float, 3>, you can use shorter aliases
 for the most popular specialized variants of Vec, e.g. Vec3f ~ Vec<float, 3>.
 */

struct CV_EXPORTS Matx_AddOp {};
struct CV_EXPORTS Matx_SubOp {};
struct CV_EXPORTS Matx_ScaleOp {};
struct CV_EXPORTS Matx_MulOp {};
struct CV_EXPORTS Matx_DivOp {};
struct CV_EXPORTS Matx_MatMulOp {};
struct CV_EXPORTS Matx_TOp {};

template<typename _Tp, int m, int n> class CV_EXPORTS Matx
{
public:
    enum { depth    = DataType<_Tp>::depth,
           rows     = m,
           cols     = n,
           channels = rows*cols,
           type     = CV_MAKETYPE(depth, channels),
           shortdim = (m < n ? m : n)
         };

    typedef _Tp                           value_type;
    typedef Matx<_Tp, m, n>               mat_type;
    typedef Matx<_Tp, shortdim, 1> diag_type;

    //! default constructor
    Matx();
    Matx(std::initializer_list<_Tp> initList)
    {
        //   CV_Assert(m*n == val.size()); // Generate error if initList.size() != m*n
        std::uninitialized_copy(initList.begin(), initList.end(), val);
    }

    Matx(_Tp v0); //!< 1x1 matrix
    Matx(_Tp v0, _Tp v1); //!< 1x2 or 2x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2); //!< 1x3 or 3x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3); //!< 1x4, 2x2 or 4x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4); //!< 1x5 or 5x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5); //!< 1x6, 2x3, 3x2 or 6x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6); //!< 1x7 or 7x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7); //!< 1x8, 2x4, 4x2 or 8x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8); //!< 1x9, 3x3 or 9x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9); //!< 1x10, 2x5 or 5x2 or 10x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3,
         _Tp v4, _Tp v5, _Tp v6, _Tp v7,
         _Tp v8, _Tp v9, _Tp v10, _Tp v11); //!< 1x12, 2x6, 3x4, 4x3, 6x2 or 12x1 matrix
    Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3,
         _Tp v4, _Tp v5, _Tp v6, _Tp v7,
         _Tp v8, _Tp v9, _Tp v10, _Tp v11,
         _Tp v12, _Tp v13, _Tp v14, _Tp v15); //!< 1x16, 4x4 or 16x1 matrix
    explicit Matx(const _Tp* vals); //!< initialize from a plain array

    static Matx all(_Tp alpha);
    static Matx zeros();
    static Matx ones();
    static Matx eye();
    static Matx diag(const diag_type& d);
    static Matx randu(_Tp a, _Tp b);
    static Matx randn(_Tp a, _Tp b);

    //! dot product computed with the default precision
    _Tp dot(const Matx<_Tp, m, n>& v) const;

    //! dot product computed in double-precision arithmetics
    double ddot(const Matx<_Tp, m, n>& v) const;

    //! convertion to another data type
    template<typename T2> operator Matx<T2, m, n>() const;

    //! change the matrix shape
    template<int m1, int n1> Matx<_Tp, m1, n1> reshape() const;

    //! extract part of the matrix
    template<int m1, int n1> Matx<_Tp, m1, n1> get_minor(int i, int j) const;

    //! extract the matrix row
    Matx<_Tp, 1, n> row(int i) const;

    //! extract the matrix column
    Matx<_Tp, m, 1> col(int i) const;

    //! extract the matrix diagonal
    diag_type diag() const;

    //! transpose the matrix
    Matx<_Tp, n, m> t() const;

    //! invert matrix the matrix
    Matx<_Tp, n, m> inv(int method=DECOMP_LU) const;

    //! solve linear system
    template<int l> Matx<_Tp, n, l> solve(const Matx<_Tp, m, l>& rhs, int flags=DECOMP_LU) const;
    Vec<_Tp, n> solve(const Vec<_Tp, m>& rhs, int method) const;

    //! multiply two matrices element-wise
    Matx<_Tp, m, n> mul(const Matx<_Tp, m, n>& a) const;

    //! divide two matrices element-wise
    Matx<_Tp, m, n> div(const Matx<_Tp, m, n>& a) const;

    //! element access
    const _Tp& operator ()(int i, int j) const;
    _Tp& operator ()(int i, int j);

    //! 1D element access
    const _Tp& operator ()(int i) const;
    _Tp& operator ()(int i);

    Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_AddOp);
    Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_SubOp);
    template<typename _T2> Matx(const Matx<_Tp, m, n>& a, _T2 alpha, Matx_ScaleOp);
    Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_MulOp);
    Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_DivOp);
    template<int l> Matx(const Matx<_Tp, m, l>& a, const Matx<_Tp, l, n>& b, Matx_MatMulOp);
    Matx(const Matx<_Tp, n, m>& a, Matx_TOp);

    _Tp val[m*n]; //< matrix elements
};

/*!
  \typedef
*/
typedef Matx<float, 1, 2> Matx12f;
typedef Matx<double, 1, 2> Matx12d;
typedef Matx<float, 1, 3> Matx13f;
typedef Matx<double, 1, 3> Matx13d;
typedef Matx<float, 1, 4> Matx14f;
typedef Matx<double, 1, 4> Matx14d;
typedef Matx<float, 1, 6> Matx16f;
typedef Matx<double, 1, 6> Matx16d;

typedef Matx<float, 2, 1> Matx21f;
typedef Matx<double, 2, 1> Matx21d;
typedef Matx<float, 3, 1> Matx31f;
typedef Matx<double, 3, 1> Matx31d;
typedef Matx<float, 4, 1> Matx41f;
typedef Matx<double, 4, 1> Matx41d;
typedef Matx<float, 6, 1> Matx61f;
typedef Matx<double, 6, 1> Matx61d;

typedef Matx<float, 2, 2> Matx22f;
typedef Matx<double, 2, 2> Matx22d;
typedef Matx<float, 2, 3> Matx23f;
typedef Matx<double, 2, 3> Matx23d;
typedef Matx<float, 3, 2> Matx32f;
typedef Matx<double, 3, 2> Matx32d;

typedef Matx<float, 3, 3> Matx33f;
typedef Matx<double, 3, 3> Matx33d;

typedef Matx<float, 3, 4> Matx34f;
typedef Matx<double, 3, 4> Matx34d;
typedef Matx<float, 4, 3> Matx43f;
typedef Matx<double, 4, 3> Matx43d;

typedef Matx<float, 4, 4> Matx44f;
typedef Matx<double, 4, 4> Matx44d;
typedef Matx<float, 6, 6> Matx66f;
typedef Matx<double, 6, 6> Matx66d;

/*!
  traits
*/
template<typename _Tp, int m, int n> class DataType< Matx<_Tp, m, n> >
{
public:
    typedef Matx<_Tp, m, n>                               value_type;
    typedef Matx<typename DataType<_Tp>::work_type, m, n> work_type;
    typedef _Tp                                           channel_type;
    typedef value_type                                    vec_type;

    enum { generic_type = 0,
           depth        = DataType<channel_type>::depth,
           channels     = m * n,
           fmt          = DataType<channel_type>::fmt + ((channels - 1) << 8),
           type         = CV_MAKETYPE(depth, channels)
         };
};

/*!
 Comma-separated Matrix Initializer
*/
template<typename _Tp, int m, int n> class MatxCommaInitializer
{
public:
    MatxCommaInitializer(Matx<_Tp, m, n>* _mtx);
    template<typename T2> MatxCommaInitializer<_Tp, m, n>& operator , (T2 val);
    Matx<_Tp, m, n> operator *() const;

    Matx<_Tp, m, n>* dst;
    int idx;
};

/*!
 Utility methods
*/
template<typename _Tp, int m> static double determinant(const Matx<_Tp, m, m>& a);
template<typename _Tp, int m, int n> static double trace(const Matx<_Tp, m, n>& a);
template<typename _Tp, int m, int n> static double norm(const Matx<_Tp, m, n>& M);
template<typename _Tp, int m, int n> static double norm(const Matx<_Tp, m, n>& M, int normType);



/////////////////////// Vec (used as element of multi-channel images /////////////////////

/*!
  A short numerical vector.

  This template class represents short numerical vectors (of 1, 2, 3, 4 ... elements)
  on which you can perform basic arithmetical operations, access individual elements using [] operator etc.
  The vectors are allocated on stack, as opposite to std::valarray, std::vector, cv::Mat etc.,
  which elements are dynamically allocated in the heap.

  The template takes 2 parameters:
  -# _Tp element type
  -# cn the number of elements

  In addition to the universal notation like Vec<float, 3>, you can use shorter aliases
  for the most popular specialized variants of Vec, e.g. Vec3f ~ Vec<float, 3>.
*/
template<typename _Tp, int cn> class CV_EXPORTS Vec : public Matx<_Tp, cn, 1>
{
public:
    typedef _Tp value_type;
    enum { depth    = Matx<_Tp, cn, 1>::depth,
           channels = cn,
           type     = CV_MAKETYPE(depth, channels)
         };

    //! default constructor
    Vec();
    Vec(std::initializer_list<_Tp> initList)
    {
        std::uninitialized_copy(initList.begin(), initList.end(), this->val);
    }


    Vec(_Tp v0); //!< 1-element vector constructor
    Vec(_Tp v0, _Tp v1); //!< 2-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2); //!< 3-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3); //!< 4-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4); //!< 5-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5); //!< 6-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6); //!< 7-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7); //!< 8-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8); //!< 9-element vector constructor
    Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9); //!< 10-element vector constructor
    explicit Vec(const _Tp* values);

    Vec(const Vec<_Tp, cn>& v);

    static Vec all(_Tp alpha);

    //! per-element multiplication
    Vec mul(const Vec<_Tp, cn>& v) const;

    //! conjugation (makes sense for complex numbers and quaternions)
    Vec conj() const;

    /*!
      cross product of the two 3D vectors.

      For other dimensionalities the exception is raised
    */
    Vec cross(const Vec& v) const;
    //! convertion to another data type
    template<typename T2> operator Vec<T2, cn>() const;

    /*! element access */
    const _Tp& operator [](int i) const;
    _Tp& operator[](int i);
    const _Tp& operator ()(int i) const;
    _Tp& operator ()(int i);

    Vec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp);
    Vec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp);
    template<typename _T2> Vec(const Matx<_Tp, cn, 1>& a, _T2 alpha, Matx_ScaleOp);
};

/* \typedef
   Shorter aliases for the most popular specializations of Vec<T,n>
*/
typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef Vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<ushort, 2> Vec2w;
typedef Vec<ushort, 3> Vec3w;
typedef Vec<ushort, 4> Vec4w;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;
typedef Vec<int, 6> Vec6i;
typedef Vec<int, 8> Vec8i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<float, 6> Vec6f;

typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;
typedef Vec<double, 4> Vec4d;
typedef Vec<double, 6> Vec6d;

/*!
  traits
*/
template<typename _Tp, int cn> class DataType< Vec<_Tp, cn> >
{
public:
    typedef Vec<_Tp, cn>                               value_type;
    typedef Vec<typename DataType<_Tp>::work_type, cn> work_type;
    typedef _Tp                                        channel_type;
    typedef value_type                                 vec_type;

    enum { generic_type = 0,
           depth        = DataType<channel_type>::depth,
           channels     = cn,
           fmt          = DataType<channel_type>::fmt + ((channels - 1) << 8),
           type         = CV_MAKETYPE(depth, channels)
         };
};

/*!
 Comma-separated Vec Initializer
*/
template<typename _Tp, int m> class VecCommaInitializer : public MatxCommaInitializer<_Tp, m, 1>
{
public:
    VecCommaInitializer(Vec<_Tp, m>* _vec);
    template<typename T2> VecCommaInitializer<_Tp, m>& operator , (T2 val);
    Vec<_Tp, m> operator *() const;
};

/*!
 Utility methods
*/
template<typename _Tp, int cn> static Vec<_Tp, cn> normalize(const Vec<_Tp, cn>& v);



///////////////////////////////////// helper classes /////////////////////////////////////
namespace internal
{

template<typename _Tp, int m> struct Matx_DetOp
{
    double operator ()(const Matx<_Tp, m, m>& a) const
    {
        Matx<_Tp, m, m> temp = a;
        double p = LU(temp.val, m*sizeof(_Tp), m, 0, 0, 0);
        if( p == 0 )
            return p;
        for( int i = 0; i < m; i++ )
            p *= temp(i, i);
        return 1./p;
    }
};

template<typename _Tp> struct Matx_DetOp<_Tp, 1>
{
    double operator ()(const Matx<_Tp, 1, 1>& a) const
    {
        return a(0,0);
    }
};

template<typename _Tp> struct Matx_DetOp<_Tp, 2>
{
    double operator ()(const Matx<_Tp, 2, 2>& a) const
    {
        return a(0,0)*a(1,1) - a(0,1)*a(1,0);
    }
};

template<typename _Tp> struct Matx_DetOp<_Tp, 3>
{
    double operator ()(const Matx<_Tp, 3, 3>& a) const
    {
        return a(0,0)*(a(1,1)*a(2,2) - a(2,1)*a(1,2)) -
            a(0,1)*(a(1,0)*a(2,2) - a(2,0)*a(1,2)) +
            a(0,2)*(a(1,0)*a(2,1) - a(2,0)*a(1,1));
    }
};

template<typename _Tp> Vec<_Tp, 2> inline conjugate(const Vec<_Tp, 2>& v)
{
    return Vec<_Tp, 2>(v[0], -v[1]);
}

template<typename _Tp> Vec<_Tp, 4> inline conjugate(const Vec<_Tp, 4>& v)
{
    return Vec<_Tp, 4>(v[0], -v[1], -v[2], -v[3]);
}

} // internal



////////////////////////////////// Matx Implementation ///////////////////////////////////

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx()
{
    for(int i = 0; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0)
{
    val[0] = v0;
    for(int i = 1; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1)
{
    CV_StaticAssert(channels >= 2, "Matx should have at least 2 elaments.");
    val[0] = v0; val[1] = v1;
    for(int i = 2; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2)
{
    CV_StaticAssert(channels >= 3, "Matx should have at least 3 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2;
    for(int i = 3; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3)
{
    CV_StaticAssert(channels >= 4, "Matx should have at least 4 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    for(int i = 4; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4)
{
    CV_StaticAssert(channels >= 5, "Matx should have at least 5 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3; val[4] = v4;
    for(int i = 5; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5)
{
    CV_StaticAssert(channels >= 6, "Matx should have at least 6 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5;
    for(int i = 6; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6)
{
    CV_StaticAssert(channels >= 7, "Matx should have at least 7 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6;
    for(int i = 7; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7)
{
    CV_StaticAssert(channels >= 8, "Matx should have at least 8 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6; val[7] = v7;
    for(int i = 8; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8)
{
    CV_StaticAssert(channels >= 9, "Matx should have at least 9 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6; val[7] = v7;
    val[8] = v8;
    for(int i = 9; i < channels; i++) val[i] = _Tp(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9)
{
    CV_StaticAssert(channels >= 10, "Matx should have at least 10 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6; val[7] = v7;
    val[8] = v8; val[9] = v9;
    for(int i = 10; i < channels; i++) val[i] = _Tp(0);
}


template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10, _Tp v11)
{
    CV_StaticAssert(channels == 12, "Matx should have at least 12 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6; val[7] = v7;
    val[8] = v8; val[9] = v9; val[10] = v10; val[11] = v11;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9, _Tp v10, _Tp v11, _Tp v12, _Tp v13, _Tp v14, _Tp v15)
{
    CV_StaticAssert(channels == 16, "Matx should have at least 16 elaments.");
    val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3;
    val[4] = v4; val[5] = v5; val[6] = v6; val[7] = v7;
    val[8] = v8; val[9] = v9; val[10] = v10; val[11] = v11;
    val[12] = v12; val[13] = v13; val[14] = v14; val[15] = v15;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n>::Matx(const _Tp* values)
{
    for( int i = 0; i < channels; i++ ) val[i] = values[i];
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n> Matx<_Tp, m, n>::all(_Tp alpha)
{
    Matx<_Tp, m, n> M;
    for( int i = 0; i < m*n; i++ ) M.val[i] = alpha;
    return M;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n> Matx<_Tp,m,n>::zeros()
{
    return all(0);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n> Matx<_Tp,m,n>::ones()
{
    return all(1);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n> Matx<_Tp,m,n>::eye()
{
    Matx<_Tp,m,n> M;
    for(int i = 0; i < shortdim; i++)
        M(i,i) = 1;
    return M;
}

template<typename _Tp, int m, int n> inline
_Tp Matx<_Tp, m, n>::dot(const Matx<_Tp, m, n>& M) const
{
    _Tp s = 0;
    for( int i = 0; i < channels; i++ ) s += val[i]*M.val[i];
    return s;
}

template<typename _Tp, int m, int n> inline
double Matx<_Tp, m, n>::ddot(const Matx<_Tp, m, n>& M) const
{
    double s = 0;
    for( int i = 0; i < channels; i++ ) s += (double)val[i]*M.val[i];
    return s;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n> Matx<_Tp,m,n>::diag(const typename Matx<_Tp,m,n>::diag_type& d)
{
    Matx<_Tp,m,n> M;
    for(int i = 0; i < shortdim; i++)
        M(i,i) = d(i, 0);
    return M;
}

template<typename _Tp, int m, int n> template<typename T2>
inline Matx<_Tp, m, n>::operator Matx<T2, m, n>() const
{
    Matx<T2, m, n> M;
    for( int i = 0; i < m*n; i++ ) M.val[i] = saturate_cast<T2>(val[i]);
    return M;
}

template<typename _Tp, int m, int n> template<int m1, int n1> inline
Matx<_Tp, m1, n1> Matx<_Tp, m, n>::reshape() const
{
    CV_StaticAssert(m1*n1 == m*n, "Input and destnarion matrices must have the same number of elements");
    return (const Matx<_Tp, m1, n1>&)*this;
}

template<typename _Tp, int m, int n>
template<int m1, int n1> inline
Matx<_Tp, m1, n1> Matx<_Tp, m, n>::get_minor(int i, int j) const
{
    CV_DbgAssert(0 <= i && i+m1 <= m && 0 <= j && j+n1 <= n);
    Matx<_Tp, m1, n1> s;
    for( int di = 0; di < m1; di++ )
        for( int dj = 0; dj < n1; dj++ )
            s(di, dj) = (*this)(i+di, j+dj);
    return s;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, 1, n> Matx<_Tp, m, n>::row(int i) const
{
    CV_DbgAssert((unsigned)i < (unsigned)m);
    return Matx<_Tp, 1, n>(&val[i*n]);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, 1> Matx<_Tp, m, n>::col(int j) const
{
    CV_DbgAssert((unsigned)j < (unsigned)n);
    Matx<_Tp, m, 1> v;
    for( int i = 0; i < m; i++ )
        v.val[i] = val[i*n + j];
    return v;
}

template<typename _Tp, int m, int n> inline
typename Matx<_Tp, m, n>::diag_type Matx<_Tp, m, n>::diag() const
{
    diag_type d;
    for( int i = 0; i < shortdim; i++ )
        d.val[i] = val[i*n + i];
    return d;
}

template<typename _Tp, int m, int n> inline
const _Tp& Matx<_Tp, m, n>::operator()(int i, int j) const
{
    CV_DbgAssert( (unsigned)i < (unsigned)m && (unsigned)j < (unsigned)n );
    return this->val[i*n + j];
}

template<typename _Tp, int m, int n> inline
_Tp& Matx<_Tp, m, n>::operator ()(int i, int j)
{
    CV_DbgAssert( (unsigned)i < (unsigned)m && (unsigned)j < (unsigned)n );
    return val[i*n + j];
}

template<typename _Tp, int m, int n> inline
const _Tp& Matx<_Tp, m, n>::operator ()(int i) const
{
    CV_StaticAssert(m == 1 || n == 1, "Single index indexation requires matrix to be a column or a row");
    CV_DbgAssert( (unsigned)i < (unsigned)(m+n-1) );
    return val[i];
}

template<typename _Tp, int m, int n> inline
_Tp& Matx<_Tp, m, n>::operator ()(int i)
{
    CV_StaticAssert(m == 1 || n == 1, "Single index indexation requires matrix to be a column or a row");
    CV_DbgAssert( (unsigned)i < (unsigned)(m+n-1) );
    return val[i];
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_AddOp)
{
    for( int i = 0; i < channels; i++ )
        val[i] = saturate_cast<_Tp>(a.val[i] + b.val[i]);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_SubOp)
{
    for( int i = 0; i < channels; i++ )
        val[i] = saturate_cast<_Tp>(a.val[i] - b.val[i]);
}

template<typename _Tp, int m, int n> template<typename _T2> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, n>& a, _T2 alpha, Matx_ScaleOp)
{
    for( int i = 0; i < channels; i++ )
        val[i] = saturate_cast<_Tp>(a.val[i] * alpha);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_MulOp)
{
    for( int i = 0; i < channels; i++ )
        val[i] = saturate_cast<_Tp>(a.val[i] * b.val[i]);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b, Matx_DivOp)
{
    for( int i = 0; i < channels; i++ )
        val[i] = saturate_cast<_Tp>(a.val[i] / b.val[i]);
}

template<typename _Tp, int m, int n> template<int l> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, m, l>& a, const Matx<_Tp, l, n>& b, Matx_MatMulOp)
{
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < n; j++ )
        {
            _Tp s = 0;
            for( int k = 0; k < l; k++ )
                s += a(i, k) * b(k, j);
            val[i*n + j] = s;
        }
}

template<typename _Tp, int m, int n> inline
Matx<_Tp,m,n>::Matx(const Matx<_Tp, n, m>& a, Matx_TOp)
{
    for( int i = 0; i < m; i++ )
        for( int j = 0; j < n; j++ )
            val[i*n + j] = a(j, i);
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n> Matx<_Tp, m, n>::mul(const Matx<_Tp, m, n>& a) const
{
    return Matx<_Tp, m, n>(*this, a, Matx_MulOp());
}
    
    template<typename _Tp, int m, int n> inline cv::Matx<_Tp, m, 1> MaxInRow(Matx<_Tp, m, n> src){
        Matx<_Tp, m, 1> dst;
        for( int i = 0; i < m; i++ ){
            dst(i,0) = src(i,0);
            for( int j = 1; j < n; j++ )
            {
                if (dst(i,0) < src(i,j)) {
                    dst(i,0) = src(i,j);
                }
            }
        }
        return dst;
    }
    
    
    template<typename _Tp, int m, int n> inline cv::Matx<_Tp, m, 1> MinInRow(Matx<_Tp, m, n> src){
        Matx<_Tp, m, 1> dst;
        for( int i = 0; i < m; i++ ){
            dst(i,0) = src(i,0);
            for( int j = 1; j < n; j++ )
            {
                if (dst(i,0) > src(i,j)) {
                    dst(i,0) = src(i,j);
                }
            }
        }
        return dst;
    }
    

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n> Matx<_Tp, m, n>::div(const Matx<_Tp, m, n>& a) const
{
    return Matx<_Tp, m, n>(*this, a, Matx_DivOp());
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, n, m> Matx<_Tp, m, n>::t() const
{
    return Matx<_Tp, n, m>(*this, Matx_TOp());
}

template<typename _Tp, int m, int n> inline
Vec<_Tp, n> Matx<_Tp, m, n>::solve(const Vec<_Tp, m>& rhs, int method) const
{
    Matx<_Tp, n, 1> x = solve((const Matx<_Tp, m, 1>&)(rhs), method);
    return (Vec<_Tp, n>&)(x);
}

template<typename _Tp, int m> static inline
double determinant(const Matx<_Tp, m, m>& a)
{
    return internal::Matx_DetOp<_Tp, m>()(a);
}

template<typename _Tp, int m, int n> static inline
double trace(const Matx<_Tp, m, n>& a)
{
    _Tp s = 0;
    for( int i = 0; i < std::min(m, n); i++ )
        s += a(i,i);
    return s;
}

template<typename _Tp, int m, int n> static inline
double norm(const Matx<_Tp, m, n>& M)
{
    return std::sqrt(normL2Sqr<_Tp, double>(M.val, m*n));
}

template<typename _Tp, int m, int n> static inline
double norm(const Matx<_Tp, m, n>& M, int normType)
{
    return normType == NORM_INF ? (double)normInf<_Tp, typename DataType<_Tp>::work_type>(M.val, m*n) :
        normType == NORM_L1 ? (double)normL1<_Tp, typename DataType<_Tp>::work_type>(M.val, m*n) :
        std::sqrt((double)normL2Sqr<_Tp, typename DataType<_Tp>::work_type>(M.val, m*n));
}



//////////////////////////////// matx comma initializer //////////////////////////////////

template<typename _Tp, typename _T2, int m, int n> static inline
MatxCommaInitializer<_Tp, m, n> operator << (const Matx<_Tp, m, n>& mtx, _T2 val)
{
    MatxCommaInitializer<_Tp, m, n> commaInitializer((Matx<_Tp, m, n>*)&mtx);
    return (commaInitializer, val);
}

template<typename _Tp, int m, int n> inline
MatxCommaInitializer<_Tp, m, n>::MatxCommaInitializer(Matx<_Tp, m, n>* _mtx)
    : dst(_mtx), idx(0)
{}

template<typename _Tp, int m, int n> template<typename _T2> inline
MatxCommaInitializer<_Tp, m, n>& MatxCommaInitializer<_Tp, m, n>::operator , (_T2 value)
{
    CV_DbgAssert( idx < m*n );
    dst->val[idx++] = saturate_cast<_Tp>(value);
    return *this;
}

template<typename _Tp, int m, int n> inline
Matx<_Tp, m, n> MatxCommaInitializer<_Tp, m, n>::operator *() const
{
    CV_DbgAssert( idx == n*m );
    return *dst;
}



/////////////////////////////////// Vec Implementation ///////////////////////////////////

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec() {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0)
    : Matx<_Tp, cn, 1>(v0) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1)
    : Matx<_Tp, cn, 1>(v0, v1) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2)
    : Matx<_Tp, cn, 1>(v0, v1, v2) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7, v8) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(_Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9)
    : Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(const _Tp* values)
    : Matx<_Tp, cn, 1>(values) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(const Vec<_Tp, cn>& m)
    : Matx<_Tp, cn, 1>(m.val) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp op)
    : Matx<_Tp, cn, 1>(a, b, op) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn>::Vec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp op)
    : Matx<_Tp, cn, 1>(a, b, op) {}

template<typename _Tp, int cn> template<typename _T2> inline
Vec<_Tp, cn>::Vec(const Matx<_Tp, cn, 1>& a, _T2 alpha, Matx_ScaleOp op)
    : Matx<_Tp, cn, 1>(a, alpha, op) {}

template<typename _Tp, int cn> inline
Vec<_Tp, cn> Vec<_Tp, cn>::all(_Tp alpha)
{
    Vec v;
    for( int i = 0; i < cn; i++ ) v.val[i] = alpha;
    return v;
}

template<typename _Tp, int cn> inline
Vec<_Tp, cn> Vec<_Tp, cn>::mul(const Vec<_Tp, cn>& v) const
{
    Vec<_Tp, cn> w;
    for( int i = 0; i < cn; i++ ) w.val[i] = saturate_cast<_Tp>(this->val[i]*v.val[i]);
    return w;
}

template<> inline
Vec<float, 2> Vec<float, 2>::conj() const
{
    return internal::conjugate(*this);
}

template<> inline
Vec<double, 2> Vec<double, 2>::conj() const
{
    return internal::conjugate(*this);
}

template<> inline
Vec<float, 4> Vec<float, 4>::conj() const
{
    return internal::conjugate(*this);
}

template<> inline
Vec<double, 4> Vec<double, 4>::conj() const
{
    return internal::conjugate(*this);
}

template<typename _Tp, int cn> inline
Vec<_Tp, cn> Vec<_Tp, cn>::cross(const Vec<_Tp, cn>&) const
{
    CV_StaticAssert(cn == 3, "for arbitrary-size vector there is no cross-product defined");
    return Vec<_Tp, cn>();
}

template<> inline
Vec<float, 3> Vec<float, 3>::cross(const Vec<float, 3>& v) const
{
    return Vec<float,3>(val[1]*v.val[2] - val[2]*v.val[1],
                     val[2]*v.val[0] - val[0]*v.val[2],
                     val[0]*v.val[1] - val[1]*v.val[0]);
}

template<> inline
Vec<double, 3> Vec<double, 3>::cross(const Vec<double, 3>& v) const
{
    return Vec<double,3>(val[1]*v.val[2] - val[2]*v.val[1],
                     val[2]*v.val[0] - val[0]*v.val[2],
                     val[0]*v.val[1] - val[1]*v.val[0]);
}

template<typename _Tp, int cn> template<typename T2> inline
Vec<_Tp, cn>::operator Vec<T2, cn>() const
{
    Vec<T2, cn> v;
    for( int i = 0; i < cn; i++ ) v.val[i] = saturate_cast<T2>(this->val[i]);
    return v;
}

template<typename _Tp, int cn> inline
const _Tp& Vec<_Tp, cn>::operator [](int i) const
{
    CV_DbgAssert( (unsigned)i < (unsigned)cn );
    return this->val[i];
}

template<typename _Tp, int cn> inline
_Tp& Vec<_Tp, cn>::operator [](int i)
{
    CV_DbgAssert( (unsigned)i < (unsigned)cn );
    return this->val[i];
}

template<typename _Tp, int cn> inline
const _Tp& Vec<_Tp, cn>::operator ()(int i) const
{
    CV_DbgAssert( (unsigned)i < (unsigned)cn );
    return this->val[i];
}

template<typename _Tp, int cn> inline
_Tp& Vec<_Tp, cn>::operator ()(int i)
{
    CV_DbgAssert( (unsigned)i < (unsigned)cn );
    return this->val[i];
}

template<typename _Tp, int cn> inline
Vec<_Tp, cn> normalize(const Vec<_Tp, cn>& v)
{
    double nv = norm(v);
    return v * (nv ? 1./nv : 0.);
}



//////////////////////////////// matx comma initializer //////////////////////////////////


template<typename _Tp, typename _T2, int cn> static inline
VecCommaInitializer<_Tp, cn> operator << (const Vec<_Tp, cn>& vec, _T2 val)
{
    VecCommaInitializer<_Tp, cn> commaInitializer((Vec<_Tp, cn>*)&vec);
    return (commaInitializer, val);
}

template<typename _Tp, int cn> inline
VecCommaInitializer<_Tp, cn>::VecCommaInitializer(Vec<_Tp, cn>* _vec)
    : MatxCommaInitializer<_Tp, cn, 1>(_vec)
{}

template<typename _Tp, int cn> template<typename _T2> inline
VecCommaInitializer<_Tp, cn>& VecCommaInitializer<_Tp, cn>::operator , (_T2 value)
{
    CV_DbgAssert( this->idx < cn );
    this->dst->val[this->idx++] = saturate_cast<_Tp>(value);
    return *this;
}

template<typename _Tp, int cn> inline
Vec<_Tp, cn> VecCommaInitializer<_Tp, cn>::operator *() const
{
    CV_DbgAssert( this->idx == cn );
    return *this->dst;
}

    //////////////////////////////// sVec /////////////////////////////////
    
    template<typename _Tp> _Tp gComDivisor(_Tp u, _Tp v) {
        if (v)
            return gComDivisor<_Tp>(v, u % v);
        else
            return u < 0 ? -u : u; /* abs(u) */
    };
    
    template<typename _Tp> _Tp gComDivisor(_Tp a, _Tp b, _Tp c){
        return gComDivisor<_Tp>(gComDivisor<_Tp>(a, b), c);
    };
    
    
    template<typename _Tp> _Tp gComDivisor(_Tp a, _Tp* b, unsigned int size_b){
        if (size_b >= 2){
            gComDivisor<_Tp>(a, b[0]);
            return gComDivisor<_Tp>(gComDivisor<_Tp>(a, b[0]), b++, size_b-1);
        }
        else if(size_b == 1) {
            return gComDivisor<_Tp>(a, b[0]);
        }
        else {
            return a;
        }
    };
    
    template<typename _Tp> _Tp gComDivisor(_Tp* b, unsigned int size_b){
        //  std::cout << "b[0] = " << b[0] << " b[size_b-1] = " << b[size_b-1]<< " size_b = " << size_b << "\n";
        switch (size_b) {
            case 0:
                return _Tp();
                break;
            case 1:
                return b[0];
                break;
            case 2:
                return gComDivisor<_Tp>(b[0],b[1]);
                break;
            case 3:
                return gComDivisor<_Tp>(gComDivisor<_Tp>(b[0],b[1]),b[2]);
                break;
            case 4:
                return gComDivisor<_Tp>(gComDivisor<_Tp>(b[0],b[1]), gComDivisor<_Tp>(b[2],b[3]));
                break;
            default:
                //    std::cout << "gComDivisor<_Tp>(gComDivisor<_Tp>("<< b << ", " << size_b/2 << "), gComDivisor<_Tp>( b + " << (size_b)/2 << ", " << (size_b+1)/2 << "))\n" ;
                return gComDivisor<_Tp>(gComDivisor<_Tp>(b,size_b/2), gComDivisor<_Tp>(b+(size_b)/2,(size_b+1)/2));
                break;
        }
    };
    
    //
    //    unsigned NUM_BITS_U = ((sizeof(unsigned) << 3) - 1);
    //
    //#if CV_SSE2
    //#define POS_OF_HIGHESTBITclz(a) (NUM_BITS_U - __builtin_clz(a)) /* only works for a != 0 */
    //#define NUM_OF_HIGHESTBITclz(a) ((a) ? (1U << POS_OF_HIGHESTBITclz(a)) : 0)
    //#endif
    
    /*   template<typename _Tp> unsigned int mostSignificantBit(_Tp x)
     {
     static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
     unsigned int r = 0;
     switch (sizeof(_Tp)) {
     case 8:
     if (x & 0xFFFFFFFF00000000) { r += 32/1; x >>= 32/1; }
     case 4:
     if (x & 0x00000000FFFF0000) { r += 32/2; x >>= 32/2; }
     case 2:
     if (x & 0x000000000000FF00) { r += 32/4; x >>= 32/4; }
     case 1:
     if (x & 0x00000000000000F0) { r += 32/8; x >>= 32/8; }
     }
     return r + bval[x];
     }
     */
    unsigned int CV_INLINE mostSignificantBit(uint64_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0xFFFFFFFF00000000) { r += 32/1; x >>= 32/1; }
        if (x & 0x00000000FFFF0000) { r += 32/2; x >>= 32/2; }
        if (x & 0x000000000000FF00) { r += 32/4; x >>= 32/4; }
        if (x & 0x00000000000000F0) { r += 32/8; x >>= 32/8; }
        return r + bval[x];
    }
    unsigned int CV_INLINE  mostSignificantBit(uint32_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0xFFFF0000) { r += 16/1; x >>= 16/1; }
        if (x & 0x0000FF00) { r += 16/2; x >>= 16/2; }
        if (x & 0x000000F0) { r += 16/4; x >>= 16/4; }
        return r + bval[x];
    }
    
    unsigned int CV_INLINE  mostSignificantBit(uint16_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0xFF00) { r += 8/1; x >>= 8/1; }
        if (x & 0x00F0) { r += 8/2; x >>= 8/2; }
        return r + bval[x];
    }
    
    unsigned int CV_INLINE  mostSignificantBit(uint8_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0xF0) { r += 4/1; x >>= 4/1; }
        return r + bval[x];
    }
    
    unsigned int CV_INLINE  mostSignificantBit(int64_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0x7FFFFFFF00000000) { r += 32/1; x >>= 32/1; }
        if (x & 0x00000000FFFF0000) { r += 32/2; x >>= 32/2; }
        if (x & 0x000000000000FF00) { r += 32/4; x >>= 32/4; }
        if (x & 0x00000000000000F0) { r += 32/8; x >>= 32/8; }
        return r + bval[x];
    }
    unsigned int CV_INLINE  mostSignificantBit(int32_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0x7FFF0000) { r += 16/1; x >>= 16/1; }
        if (x & 0x0000FF00) { r += 16/2; x >>= 16/2; }
        if (x & 0x000000F0) { r += 16/4; x >>= 16/4; }
        return r + bval[x];
    }
    
    unsigned int CV_INLINE  mostSignificantBit(int16_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0x7F00) { r += 8/1; x >>= 8/1; }
        if (x & 0x00F0) { r += 8/2; x >>= 8/2; }
        return r + bval[x];
    }
    
    unsigned int CV_INLINE  mostSignificantBit(int8_t x)
    {
        static const unsigned int bval[] = {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
        unsigned int r = 0;
        if (x & 0x70) { r += 4/1; x >>= 4/1; }
        return r + bval[x];
    }
    
    
    /* f : number to convert.
     * num, denom: returned parts of the rational.
     * max_denom: max denominator value.  Note that machine floating point number
     *     has a finite resolution (10e-16 ish for 64 bit double), so specifying
     *     a "best match with minimal error" is often wrong, because one can
     *     always just retrieve the significand and return that divided by
     *     2**52, which is in a sense accurate, but generally not very useful:
     *     1.0/7.0 would be "2573485501354569/18014398509481984", for example.
     */
    void CV_INLINE rat_approx(double f, int64_t max_denom, int64_t *num, int64_t *denom)
    {
        /*  a: continued fraction coefficients. */
        int64_t a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
        int64_t x, d, n = 1;
        int i, neg = 0;
        
        if (max_denom <= 1) { *denom = 1; *num = (int64_t) f; return; }
        
        if (f < 0) { neg = 1; f = -f; }
        
        while (f != floor(f)) { n <<= 1; f *= 2; }
        d = f;
        
        /* continued fraction and check denominator each step */
        for (i = 0; i < 64; i++) {
            a = n ? d / n : 0;
            if (i && !a) break;
            
            x = d; d = n; n = x % n;
            
            x = a;
            if (k[1] * a + k[0] >= max_denom) {
                x = (max_denom - k[0]) / k[1];
                if (x * 2 >= a || k[1] >= max_denom)
                    i = 65;
                else
                    break;
            }
            
            h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
            k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
        }
        *denom = k[1];
        *num = neg ? -h[1] : h[1];
    }
    
    // A data structure which allows a vector to be expressed as a float scalar times an integer vector.
    // _Tp must be an integer type char, short, long, long long - signed or unsigned.
    
    template<typename _Tp, int cn> class CV_EXPORTS sVec : public Matx<_Tp, cn, 1>
    {
    public:
        typedef _Tp value_type;
        enum { depth = DataDepth<_Tp>::value, channels = cn, type = CV_MAKETYPE(depth, channels) };
        float scale;
        
        //! default constructor
        sVec();
        sVec(float _scale, _Tp v0); //!< 1-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1); //!< 2-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2); //!< 3-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3); //!< 4-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4); //!< 5-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5); //!< 6-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6); //!< 7-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7); //!< 8-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8); //!< 9-element vector constructor
        sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9); //!< 10-element vector constructor
        explicit sVec(float _scale, const _Tp* values);
        
        sVec(const sVec<_Tp, cn>& v);
        // sVec(const Matx<float, cn, 1>& m); // Constructors -- sVec from a float Matx
        sVec(const Matx<float, cn, 1>& vec, int64_t max_denom = 255); // Constructors -- sVec from a float Matx
        static sVec all(_Tp alpha);
        
        sVec(float _scale, Vec< _Tp, cn> _vec   ) : Matx<_Tp, cn, 1>(_vec.val), scale(_scale){};
        sVec(float _scale, Matx<_Tp, cn, 1> _vec) : Matx<_Tp, cn, 1>(_vec.val), scale(_scale){};
        sVec(float _scale, std::initializer_list<_Tp> initList): scale(_scale), Matx<_Tp, cn, 1>(initList){}
        
        // Conjugation (makes sense for complex numbers and quaternions)
        sVec conj() const;
        // Cross product of the two 3D vectors. For other dimensionalities the exception is raised
        sVec cross(const sVec& v) const;
        // Convertion to another data type
        // Type conversion - sVec -> sVec
        template<typename T2> operator sVec<T2, cn>() const;
        // Type conversion - sVec -> Matx
        operator Matx<float, cn, 1>() const;
        // Type conversion - sVec -> 4-element CvScalar.
        operator CvScalar() const;
        
        
        // Element Access
        
        const  _Tp& operator [](int i) const;        // Element Access - Access Rvalue - Vector element type _Tp
        _Tp& operator [](int i);              // Element Access - Access Lvalue - Vector element type _Tp
        const float operator ()(int i) const;
        
        
        
        // Operator Overloading - Matx_AddOp
        sVec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp op);
        sVec(const sVec<_Tp, cn   >& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp op);
        sVec(const Matx<_Tp, cn, 1>& a, const sVec<_Tp, cn   >& b, Matx_AddOp op);
        sVec(const sVec<_Tp, cn   >& a, const sVec<_Tp, cn   >& b, Matx_AddOp op);
        
        // Operator Overloading - Matx_SubOp
        sVec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp op);
        sVec(const sVec<_Tp, cn   >& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp op);
        sVec(const Matx<_Tp, cn, 1>& a, const sVec<_Tp, cn   >& b, Matx_SubOp op);
        sVec(const sVec<_Tp, cn   >& a, const sVec<_Tp, cn   >& b, Matx_SubOp op);
        
        // Operator Overloading - Matx_ScaleOp
        
        template<typename _T2> sVec(const Matx<_Tp, cn, 1>& a, _T2 alpha, Matx_ScaleOp op);
        template<typename _T2> sVec(const sVec<_Tp, cn>& a, _T2 alpha, Matx_ScaleOp op);
        
        
        // Direct product with a Vec or sVec.
        
        sVec<_Tp, cn> mul(const  Vec<_Tp, cn>& v) const;
        sVec<_Tp, cn> mul(const sVec<_Tp, cn>& v) const;
        
        // The dotProduct
        sVec<_Tp, 1> dotProd(const sVec<_Tp, cn> v) const;
        
        // Methods
        
        void factor(){
            // Test for all negative.
            if (this->allNegative()) {
                for (int i=0; i<cn; i++) {this->val[i] *= -1;}
                scale = -1.0 * scale;
            }
            int common = gComDivisor<_Tp>(this->val, cn);
            if (common>1){
                for (int i=0; i<cn; i++) {this->val[i] /= common;}
                scale = scale*common;
            };
        };
        
        bool allNegative(){
            for(int i=0;i<cn;i++)
            {
                if(this->val[i] > 0) return false;
            }
            return true;
        }
        
        bool allPositive(){
            for(int i=0;i<cn;i++)
            {
                if(this->val[i] < 0) return false;
            }
            return true;
        }
        
        // max and min return the max and min values in the vector part of the type.
        _Tp max(){
            _Tp maxVal = this->val[0];
            for (int i=1; i<cn; i++) { if (this->val[i] > maxVal) maxVal=this->val[i];}
            return maxVal;
        }
        
        _Tp min(){
            _Tp minVal = this->val[0];
            for (int i=1; i<cn; i++) { if (this->val[i] > minVal) minVal=this->val[i];}
            return minVal;
        }
        
        std::string toString(){
            std::string output = std::to_string(this->scale) + "  / " + std::to_string(this->val[0]) + " \\   / " + std::to_string(this(0)) + " \\ \n";
            for (int i=1; i<cn-1; i++) {
                output += "          | " + std::to_string(this->val[i]) + " | = | " + std::to_string(this(i)) + " | \n";
            }
            output += "          \\ " + std::to_string(this->val[cn-1]) + " /   \\ " + std::to_string(this(cn-1)) + " / \n";
            return output;
        }
        
        void print();
        
    };
    
    
    /////////////////////////// short scaled vector (sVec) /////////////////////////////
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec()
    :scale(1.0), Matx<_Tp, cn, 1>()
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0)
    : scale(_scale), Matx<_Tp, cn, 1>(v0)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7, v8)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, _Tp v0, _Tp v1, _Tp v2, _Tp v3, _Tp v4, _Tp v5, _Tp v6, _Tp v7, _Tp v8, _Tp v9)
    : scale(_scale), Matx<_Tp, cn, 1>(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9)
    {}
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(float _scale, const _Tp* values)
    : scale(_scale), Matx<_Tp, cn, 1>(values)
    {}
    
    // Constructors -- sVec from an sVec
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& m)
    : Matx<_Tp, cn, 1>(m.val), scale(m.scale)
    {}
    // Constructors -- sVec from a float Matx
    template<typename _Tp, int cn> inline cv::sVec<_Tp, cn>::sVec(const Matx<float, cn, 1>& vec, int64_t max_denom)
    {
        cv::sVec<int64_t, cn> output_num;
        cv::sVec<int64_t, cn> output_den;
        int64_t out_num, out_den;
        double float_in;
        for (int i=0; i<cn; i++) {
            float_in = (double) vec(i);
            rat_approx(float_in, max_denom, &out_num, &out_den );
            output_num[i] = out_num;
            output_den[i] = out_den;
        }
        output_num.factor();
        output_den.factor();
        int64_t den_prod = output_den[0];
        for(int i=1;i<cn;i++){
            den_prod *= output_den[i];
        }
        
        for(int i=0;i<cn;i++){
            output_num[i] *= den_prod/output_den[i];
        }
        output_num.scale *= 1.0/(output_den.scale * den_prod);
        output_num.factor();
        
        const uint64_t saturateType = (((1 << ((sizeof(_Tp) << 3)-1)) -1 ) << 1) + 1;
        int exposure = (int) (output_num.max() / saturateType);
        scale = output_num.scale * (exposure + 1);
        for(int i=0;i<cn;i++){
            Matx<_Tp,cn,1>::val[i] = (_Tp) (output_num[i]/(exposure + 1)) ;
        }
    }
    
    /* template<typename _Tp, int cn> inline sVec<_Tp, cn>::sVec(const Matx<float, cn, 1>& m)
     {
     const unsigned long long int saturateType = (1 << (sizeof(_Tp) << 3))-1;
     float maxVal = m(0,0);
     for (int i=1; i<cn; i++) { if (m(i,0) > maxVal) maxVal = m(i,0);}
     scale = maxVal/saturateType;
     Matx<_Tp,cn,1>(m, saturateType/maxVal, Matx_ScaleOp());
     }
     */
    
    // Operator Overloading - Matx_AddOp
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp op)
    : sVec<_Tp, cn>(1.0, Matx<_Tp, cn, 1>(a, b, op)){}
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& a, const Matx<_Tp, cn, 1>& b, Matx_AddOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>((Matx<float, cn, 1>) a, b, op)){}
    
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const Matx<_Tp, cn, 1>& a, const sVec<_Tp, cn>& b, Matx_AddOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>(a, (Matx<float, cn, 1>) b, op)){}
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& a, const sVec<_Tp, cn>& b, Matx_AddOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>( (Matx<float, cn, 1>) a, (Matx<float, cn, 1>) b, op)){}
    
    
    // Operator Overloading - Matx_SubOp
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const Matx<_Tp, cn, 1>& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp op)
    : sVec<_Tp, cn>(1.0, Matx<_Tp, cn, 1>(a, b, op)){}
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& a, const Matx<_Tp, cn, 1>& b, Matx_SubOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>((Matx<float, cn, 1>) a, b, op)){}
    
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const Matx<_Tp, cn, 1>& a, const sVec<_Tp, cn>& b, Matx_SubOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>(a, (Matx<float, cn, 1>) b, op)){}
    
    template<typename _Tp, int cn> inline
    sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& a, const sVec<_Tp, cn>& b, Matx_SubOp op)
    : sVec<_Tp, cn>(Matx<float, cn, 1>( (Matx<float, cn, 1>) a, (Matx<float, cn, 1>) b, op)){}
    
    // Operator Overloading - Matx_ScaleOp
    
    template<typename _Tp, int cn> template<typename _T2> inline
    sVec<_Tp, cn>::sVec(const Matx<_Tp, cn, 1>& a, _T2 alpha, Matx_ScaleOp op)
    : scale(alpha), Matx<_Tp, cn, 1>(a)
    {}
    
    template<typename _Tp, int cn> template<typename _T2> inline
    sVec<_Tp, cn>::sVec(const sVec<_Tp, cn>& a, _T2 alpha, Matx_ScaleOp op)
    : scale(alpha * a.scale), Matx<_Tp, cn, 1>(a.val)
    {}
    
    // Set all values to alpha
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn> sVec<_Tp, cn>::all(_Tp alpha)
    {
        sVec v;
        v.scale = (float) alpha;
        for( int i = 0; i < cn; i++ ) v.val[i] = 1;
        return v;
    }
    
    // Direct product with a Vec or sVec.
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn> sVec<_Tp, cn>::mul(const Vec<_Tp, cn>& v) const
    {
        Vec<_Tp, cn> w;
        w.scale = this->scale;
        for( int i = 0; i < cn; i++ ) w.val[i] = saturate_cast<_Tp>(this->val[i]*v.val[i]);
        return w;
    }
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn> sVec<_Tp, cn>::mul(const sVec<_Tp, cn>& v) const
    {
        Vec<_Tp, cn> w;
        w.scale = this->scale * v.scale;
        for( int i = 0; i < cn; i++ ) w.val[i] = saturate_cast<_Tp>(this->val[i]*v.val[i]);
        return w;
    }
    
    // Conjugate sVec.
    
    template<typename _Tp> sVec<_Tp, 2> conjugate(const sVec<_Tp, 2>& v)
    {
        return sVec<_Tp, 2>(v.scale, Matx<_Tp, 2, 1>(v[0], -v[1]));
    }
    
    template<typename _Tp> sVec<_Tp, 4> conjugate(const sVec<_Tp, 4>& v)
    {
        return sVec<_Tp, 4>(v.scale, Matx<_Tp, 4, 1>(v[0], -v[1], -v[2], -v[3]));
    }
    
    template<> inline sVec<float, 2> sVec<float, 2>::conj() const
    {
        return conjugate(*this);
    }
    
    template<> inline sVec<double, 2> sVec<double, 2>::conj() const
    {
        return conjugate(*this);
    }
    
    template<> inline sVec<float, 4> sVec<float, 4>::conj() const
    {
        return conjugate(*this);
    }
    
    template<> inline sVec<double, 4> sVec<double, 4>::conj() const
    {
        return conjugate(*this);
    }
    // Type conversion - sVec -> sVec
    template<typename _Tp, int cn> template<typename _T2>
    inline sVec<_Tp, cn>::operator sVec<_T2, cn>() const
    {
        sVec<_T2, cn> v;
        if (sizeof(_T2)>sizeof(_Tp)){
            v.scale = this->scale;
            for( int i = 0; i < cn; i++ ) v.val[i] = saturate_cast<_T2>(this->val[i]);
        }
        else{
            _Tp max = this->max(); // The largest value in the vector.
            int bitPos = mostSignificantBit(max);
            int bitShift = bitPos - ((sizeof(_T2) << 3)-1); // the number of bits which will not fit into T2.
            if (bitShift <= 0) {
                v.scale = this->scale;
                for( int i = 0; i < cn; i++ ) v.val[i] = saturate_cast<_T2>(this->val[i]);
            } else {
                int bitScale = 1<<bitShift;
                v.scale = bitScale * this->scale;
                for( int i = 0; i < cn; i++ ) v.val[i] = saturate_cast<_T2>(this->val[i]/bitScale);
            }
        }
        return v;
    }
    // Type conversion - sVec -> Matx
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::operator Matx<float, cn, 1>() const
    {
        return Matx<float, cn, 1>(Matx<_Tp, cn, 1>(this->val), this->scale, Matx_ScaleOp());
    }
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn>::operator CvScalar() const
    {
        CvScalar s = {{0,0,0,0}};
        int i;
        for( i = 0; i < std::min(cn, 4); i++ ) s.val[i] = this->scale * this->val[i];
        for( ; i < 4; i++ ) s.val[i] = 0;
        return s;
    }
    
    template<typename _Tp, int cn>  void sVec<_Tp, cn>::print(){
        printf("Test sVec \n");
        printf("    / %s \\  / %s \\ \n",std::to_string(this->val[0]),std::to_string(this->val[0]*scale));
        for (int i=1; i<cn-1; i++) {
            printf("%s| %s |= | %s | \n",std::to_string(scale),std::to_string(this->val[1]),std::to_string(this->val[1]*scale));
        }
        printf("    \\ %s /  \\ %s / \n",std::to_string(this->val[2]),std::to_string(this->val[2]*scale));
    }
    
    
    // Element Access
    // Element Access - Access Rvalue - Vector element
    template<typename _Tp, int cn> inline const _Tp& sVec<_Tp, cn>::operator [](int i) const
    {
        CV_DbgAssert( (unsigned)i < (unsigned)cn );
        return this->val[i];
    }
    
    // Element Access - Access Lvalue - Vector element
    template<typename _Tp, int cn> inline _Tp& sVec<_Tp, cn>::operator [](int i)
    {
        CV_DbgAssert( (unsigned)i < (unsigned)cn );
        return this->val[i];
    }
    // Element Access - Access Rvalue - Scaled Vector element
    template<typename _Tp, int cn> inline const float sVec<_Tp, cn>::operator ()(int i) const
    {
        CV_DbgAssert( (unsigned)i < (unsigned)cn );
        return this->scale * this->val[i];
    }
    
    template<typename _Tp1, typename _Tp2, int cn> static inline sVec<_Tp1, cn>&
    operator += (sVec<_Tp1, cn>& a, const sVec<_Tp2, cn>& b)
    {
        a = sVec<_Tp1, cn>( (Matx<float, cn, 1>) a + (Matx<float, cn, 1>) b);
        return a;
    }
    
    template<typename _Tp1, typename _Tp2, int cn> static inline sVec<_Tp1, cn>&
    operator -= (sVec<_Tp1, cn>& a, const sVec<_Tp2, cn>& b)
    {
        a = sVec<_Tp1, cn>( (Matx<float, cn, 1>) a - (Matx<float, cn, 1>) b);
        return a;
    }
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator + (const sVec<_Tp, cn>& a, const sVec<_Tp, cn>& b)
    {
        return sVec<_Tp, cn>(a, b, Matx_AddOp());
    }
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator - (const sVec<_Tp, cn>& a, const sVec<_Tp, cn>& b)
    {
        return sVec<_Tp, cn>(a, b, Matx_SubOp());
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator *= (sVec<_Tp, cn>& a, int alpha)
    {
        a.scale *= alpha;
        return a;
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator *= (sVec<_Tp, cn>& a, float alpha)
    {
        a.scale *= alpha;
        return a;
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator *= (sVec<_Tp, cn>& a, double alpha)
    {
        a.scale *= alpha;
        return a;
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator /= (sVec<_Tp, cn>& a, int alpha)
    {
        a.scale /= alpha;
        return a;
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator /= (sVec<_Tp, cn>& a, float alpha)
    {
        a.scale /= alpha;
        return a;
    }
    
    template<typename _Tp, int cn> static inline
    sVec<_Tp, cn>& operator /= (sVec<_Tp, cn>& a, double alpha)
    {
        a.scale /= alpha;
        return a;
    }
    
    // Operators -  sVec = num * sVec
    
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator * (const sVec<_Tp, cn>& a, double alpha)
    {
        return sVec<_Tp, cn>(a.scale * alpha, Matx<_Tp, cn,1>(a.val));
    }
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator * (double alpha, const sVec<_Tp, cn>& a)
    {
        return sVec<_Tp, cn>(a.scale * alpha, Matx<_Tp, cn,1>(a.val));
    }
    
    template<typename _Tp, int n> static inline
    sVec<_Tp, n> operator * (const sVec<_Tp, n>& b, const float a){
        return sVec<_Tp, n>(a * b.scale, Matx<_Tp, n, 1>(b.val));
    };
    
    template<typename _Tp, int n> static inline
    sVec<_Tp, n> operator * (const float a, const sVec<_Tp, n>& b){
        return sVec<_Tp, n>(a * b.scale, Matx<_Tp, n, 1>(b.val));
    };
    
    template<typename _Tp, int n> static inline
    sVec<_Tp, n> operator * (const int a, const sVec<_Tp, n>& b){
        return sVec<_Tp, n>(a * b.scale, Matx<_Tp, n, 1>(b.val));
    };
    
    template<typename _Tp, int n> static inline
    sVec<_Tp, n> operator * (const sVec<_Tp, n>& b, const int a){
        return sVec<_Tp, n>(a * b.scale, Matx<_Tp, n, 1>(b.val));
    };
    
    // Operators -  sVec = sVec * Vec
    template<typename _Tp, int n> static inline
    sVec<_Tp, 1> operator * (const sVec<_Tp, n>& a, const Matx<_Tp, n, 1>& b)
    {
        _Tp dotProd = 0;
        for (int i=0; i < n; i++) {
            dotProd += a.val[i] * b[i];
        }
        return sVec<_Tp, 1>(a.scale, dotProd);
    }
    
    // Operators -  sVec = Vec * sVec
    template<typename _Tp, int n> static inline
    sVec<_Tp, 1> operator * ( const Matx<_Tp, n, 1>& b, const sVec<_Tp, n>& a)
    {
        _Tp dotProd = 0;
        for (int i=0; i < n; i++) {
            dotProd += a.val[i] * b[i];
        }
        return sVec<_Tp, 1>(a.scale, dotProd);
    }
    
    // Operators -  sVec = sVec * sVec
    template<typename _Tp, int n> static inline
    sVec<_Tp, 1> operator * (const sVec<_Tp, n>& a, const sVec<_Tp, n>& b)
    {
        _Tp dotProd = 0;
        for (int i=0; i < n; i++) {
            dotProd += a.val[i] * b[i];
        }
        return sVec<_Tp, 1>(a.scale * b.scale, dotProd);
    }
    // Operators -  sVec / number
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator / (const sVec<_Tp, cn>& a, int alpha)
    {
        return sVec<_Tp, cn>(a.scale / alpha, Matx<_Tp, cn,1>(a.val));
    }
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator / (const sVec<_Tp, cn>& a, float alpha)
    {
        return sVec<_Tp, cn>(a.scale / alpha, Matx<_Tp, cn,1>(a.val));
    }
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator / (const sVec<_Tp, cn>& a, double alpha)
    {
        return sVec<_Tp, cn>(a.scale / alpha, Matx<_Tp, cn,1>(a.val));
    }
    
    // Operators -  -sVec
    
    template<typename _Tp, int cn> static inline sVec<_Tp, cn>
    operator - (const sVec<_Tp, cn>& a)
    {
        return sVec<_Tp, cn>(-a.scale, Matx<_Tp, cn,1>(a.val));
    }
    /*
     template<typename _Tp> inline Vec<_Tp, 4> operator * (const Vec<_Tp, 4>& v1, const Vec<_Tp, 4>& v2)
     {
     return Vec<_Tp, 4>(saturate_cast<_Tp>(v1[0]*v2[0] - v1[1]*v2[1] - v1[2]*v2[2] - v1[3]*v2[3]),
     saturate_cast<_Tp>(v1[0]*v2[1] + v1[1]*v2[0] + v1[2]*v2[3] - v1[3]*v2[2]),
     saturate_cast<_Tp>(v1[0]*v2[2] - v1[1]*v2[3] + v1[2]*v2[0] + v1[3]*v2[1]),
     saturate_cast<_Tp>(v1[0]*v2[3] + v1[1]*v2[2] - v1[2]*v2[1] + v1[3]*v2[0]));
     }
     
     template<typename _Tp> inline Vec<_Tp, 4>& operator *= (Vec<_Tp, 4>& v1, const Vec<_Tp, 4>& v2)
     {
     v1 = v1 * v2;
     return v1;
     }
     */
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn> sVec<_Tp, cn>::cross(const sVec<_Tp, cn>&) const
    {
        CV_Error(CV_StsError, "for arbitrary-size vector there is no cross-product defined");
        return sVec<_Tp, cn>();
    }
    
    template<> inline sVec<int, 3> sVec<int, 3>::cross(const sVec<int, 3>& v) const
    {
        return sVec<int, 3>(this->scale * v.scale,
                            Matx<int, 3, 1>(
                                            saturate_cast<int>(val[1]*v.val[2] - val[2]*v.val[1]),
                                            saturate_cast<int>(val[2]*v.val[0] - val[0]*v.val[2]),
                                            saturate_cast<int>(val[0]*v.val[1] - val[1]*v.val[0]) )
                            );
    }
    
    template<typename _Tp> static inline sVec<_Tp, 3> cross(const sVec<_Tp, 3>& a, const sVec<_Tp, 3>& b)
    {
        return sVec<_Tp, 3>(a.scale * b.scale,
                            Matx<_Tp, 3, 1>(
                                            saturate_cast<_Tp>(a.val[1]*b.val[2] - a.val[2]*b.val[1]),
                                            saturate_cast<_Tp>(a.val[2]*b.val[0] - a.val[0]*b.val[2]),
                                            saturate_cast<_Tp>(a.val[0]*b.val[1] - a.val[1]*b.val[0]) )
                            );
    }
    /*
     template<typename _Tp> inline sVec<_Tp, 3> sVec<_Tp, 3>::cross(const sVec<_Tp, 3>& v) const
     {
     return sVec<_Tp, 3>(this->scale * v.scale,
     Matx<_Tp, 3, 1>(
     saturate_cast<_Tp>(val[1]*v.val[2] - val[2]*v.val[1]),
     saturate_cast<_Tp>(val[2]*v.val[0] - val[0]*v.val[2]),
     saturate_cast<_Tp>(val[0]*v.val[1] - val[1]*v.val[0]) )
     );
     }
     */
    
    template<typename _Tp, int cn> inline sVec<_Tp, cn> normalize(const sVec<_Tp, cn>& v)
    {
        float nv = norm(v);
        return sVec<_Tp, cn>((nv ? 1./nv : 0.), Matx<_Tp, cn, 1>(v.val));
    }
    /*
     template<typename _Tp, typename _T2, int cn> static inline
     VecCommaInitializer<_Tp, cn> operator << (const Vec<_Tp, cn>& vec, _T2 val)
     {
     VecCommaInitializer<_Tp, cn> commaInitializer((Vec<_Tp, cn>*)&vec);
     return (commaInitializer, val);
     }
     
     template<typename _Tp, int cn> inline
     VecCommaInitializer<_Tp, cn>::VecCommaInitializer(Vec<_Tp, cn>* _vec)
     : MatxCommaInitializer<_Tp, cn, 1>(_vec)
     {}
     
     template<typename _Tp, int cn> template<typename _T2> inline
     VecCommaInitializer<_Tp, cn>& VecCommaInitializer<_Tp, cn>::operator , (_T2 value)
     {
     CV_DbgAssert( this->idx < cn );
     this->dst->val[this->idx++] = saturate_cast<_Tp>(value);
     return *this;
     }
     
     template<typename _Tp, int cn> inline
     Vec<_Tp, cn> VecCommaInitializer<_Tp, cn>::operator *() const
     {
     CV_DbgAssert( this->idx == cn );
     return *this->dst;
     }
     */
    
    /*   template<typename _Tp> struct RGBA2Rot
     {
     typedef _Tp channel_type;
     
     Matx<float, 3, 5> Ms4d3;
     
     // The transform to the new color space is (T vec - 255 TMin)/TRange. 255 is the range of 8bit RGB and can be replaced directly with a different range for 16 and 32 bit RGB spaces. The division by TRange is the direct element wise division and can safely be rounded to recast in the required bit depth.
     
     RGBA2Rot(Matx<int, 3, 3>& T, Vec<int, 3>&  TRange, Vec<int,3>& TMin)// NOTE: MatX constructor should be able to be constructed using the {} notation using C++11 features
     {
     Ms4d3 = \
     {((float)T(0, 0)/(float)TRange[0]), ((float)T(0, 1)/(float)TRange[1]), ((float)T(0, 2)/(float)TRange[2]), 1.0, ((float)TMin[0]/(float)TRange[0]), \
     ((float)T(1, 0)/(float)TRange[0]), ((float)T(1, 1)/(float)TRange[1]), ((float)T(1, 2)/(float)TRange[2]), 1.0, ((float)TMin[1]/(float)TRange[1]), \
     ((float)T(2, 0)/(float)TRange[0]), ((float)T(2, 1)/(float)TRange[1]), ((float)T(2, 2)/(float)TRange[2]), 1.0, ((float)TMin[2]/(float)TRange[2])
     };
     }
     
     void operator()(const _Tp* src, _Tp* dst, int n) const
     {
     //        cv::transform(*src, *dst, Ms4d3);
     }
     };
     */
    
    /*
     template <typename T> void MaxInRow(InputArray _src, OutputArray _dst){
     Mat src = _src.getMat();
     _dst.create(src.rows, 1, src.type());
     Mat dst = _dst.getMat();
     dst = src.col(0);
     
     for( int i = 0; i < src.rows; i++ ){
     const T* srcRow = src.ptr<T>(i);
     for( int j = 1; j < src.cols; j++ )
     {
     dst.at<T>(i,0) = std::max(dst.at<T>(i,0),srcRow[j]);
     }
     }
     
     }
     
     template <typename T> void MinInRow(InputArray _src, OutputArray _dst){
     Mat src = _src.getMat();
     _dst.create(src.rows, 1, src.type());
     Mat dst = _dst.getMat();
     dst = src.col(0);
     
     for( int i = 0; i < src.rows; i++ ){
     const T* srcRow = src.ptr<T>(i);
     for( int j = 1; j < src.cols; j++ )
     {
     dst.at<T>(i,0) = std::min(dst.at<T>(i,0),srcRow[j]);
     }
     }
     
     }
     */
    
    


///////////////////////////// Matx out-of-class operators ////////////////////////////////

template<typename _Tp1, typename _Tp2, int m, int n> static inline
Matx<_Tp1, m, n>& operator += (Matx<_Tp1, m, n>& a, const Matx<_Tp2, m, n>& b)
{
    for( int i = 0; i < m*n; i++ )
        a.val[i] = saturate_cast<_Tp1>(a.val[i] + b.val[i]);
    return a;
}

template<typename _Tp1, typename _Tp2, int m, int n> static inline
Matx<_Tp1, m, n>& operator -= (Matx<_Tp1, m, n>& a, const Matx<_Tp2, m, n>& b)
{
    for( int i = 0; i < m*n; i++ )
        a.val[i] = saturate_cast<_Tp1>(a.val[i] - b.val[i]);
    return a;
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator + (const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b)
{
    return Matx<_Tp, m, n>(a, b, Matx_AddOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator - (const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b)
{
    return Matx<_Tp, m, n>(a, b, Matx_SubOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n>& operator *= (Matx<_Tp, m, n>& a, int alpha)
{
    for( int i = 0; i < m*n; i++ )
        a.val[i] = saturate_cast<_Tp>(a.val[i] * alpha);
    return a;
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n>& operator *= (Matx<_Tp, m, n>& a, float alpha)
{
    for( int i = 0; i < m*n; i++ )
        a.val[i] = saturate_cast<_Tp>(a.val[i] * alpha);
    return a;
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n>& operator *= (Matx<_Tp, m, n>& a, double alpha)
{
    for( int i = 0; i < m*n; i++ )
        a.val[i] = saturate_cast<_Tp>(a.val[i] * alpha);
    return a;
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (const Matx<_Tp, m, n>& a, int alpha)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (const Matx<_Tp, m, n>& a, float alpha)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (const Matx<_Tp, m, n>& a, double alpha)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (int alpha, const Matx<_Tp, m, n>& a)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (float alpha, const Matx<_Tp, m, n>& a)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator * (double alpha, const Matx<_Tp, m, n>& a)
{
    return Matx<_Tp, m, n>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int m, int n> static inline
Matx<_Tp, m, n> operator - (const Matx<_Tp, m, n>& a)
{
    return Matx<_Tp, m, n>(a, -1, Matx_ScaleOp());
}

template<typename _Tp, int m, int n, int l> static inline
Matx<_Tp, m, n> operator * (const Matx<_Tp, m, l>& a, const Matx<_Tp, l, n>& b)
{
    return Matx<_Tp, m, n>(a, b, Matx_MatMulOp());
}

template<typename _Tp, int m, int n> static inline
Vec<_Tp, m> operator * (const Matx<_Tp, m, n>& a, const Vec<_Tp, n>& b)
{
    Matx<_Tp, m, 1> c(a, b, Matx_MatMulOp());
    return (const Vec<_Tp, m>&)(c);
}

template<typename _Tp, int m, int n> static inline
bool operator == (const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b)
{
    for( int i = 0; i < m*n; i++ )
        if( a.val[i] != b.val[i] ) return false;
    return true;
}

template<typename _Tp, int m, int n> static inline
bool operator != (const Matx<_Tp, m, n>& a, const Matx<_Tp, m, n>& b)
{
    return !(a == b);
}



////////////////////////////// Vec out-of-class operators ////////////////////////////////

template<typename _Tp1, typename _Tp2, int cn> static inline
Vec<_Tp1, cn>& operator += (Vec<_Tp1, cn>& a, const Vec<_Tp2, cn>& b)
{
    for( int i = 0; i < cn; i++ )
        a.val[i] = saturate_cast<_Tp1>(a.val[i] + b.val[i]);
    return a;
}

template<typename _Tp1, typename _Tp2, int cn> static inline
Vec<_Tp1, cn>& operator -= (Vec<_Tp1, cn>& a, const Vec<_Tp2, cn>& b)
{
    for( int i = 0; i < cn; i++ )
        a.val[i] = saturate_cast<_Tp1>(a.val[i] - b.val[i]);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator + (const Vec<_Tp, cn>& a, const Vec<_Tp, cn>& b)
{
    return Vec<_Tp, cn>(a, b, Matx_AddOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator - (const Vec<_Tp, cn>& a, const Vec<_Tp, cn>& b)
{
    return Vec<_Tp, cn>(a, b, Matx_SubOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator *= (Vec<_Tp, cn>& a, int alpha)
{
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*alpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator *= (Vec<_Tp, cn>& a, float alpha)
{
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*alpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator *= (Vec<_Tp, cn>& a, double alpha)
{
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*alpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator /= (Vec<_Tp, cn>& a, int alpha)
{
    double ialpha = 1./alpha;
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*ialpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator /= (Vec<_Tp, cn>& a, float alpha)
{
    float ialpha = 1.f/alpha;
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*ialpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn>& operator /= (Vec<_Tp, cn>& a, double alpha)
{
    double ialpha = 1./alpha;
    for( int i = 0; i < cn; i++ )
        a[i] = saturate_cast<_Tp>(a[i]*ialpha);
    return a;
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (const Vec<_Tp, cn>& a, int alpha)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (int alpha, const Vec<_Tp, cn>& a)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (const Vec<_Tp, cn>& a, float alpha)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (float alpha, const Vec<_Tp, cn>& a)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (const Vec<_Tp, cn>& a, double alpha)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator * (double alpha, const Vec<_Tp, cn>& a)
{
    return Vec<_Tp, cn>(a, alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator / (const Vec<_Tp, cn>& a, int alpha)
{
    return Vec<_Tp, cn>(a, 1./alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator / (const Vec<_Tp, cn>& a, float alpha)
{
    return Vec<_Tp, cn>(a, 1.f/alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator / (const Vec<_Tp, cn>& a, double alpha)
{
    return Vec<_Tp, cn>(a, 1./alpha, Matx_ScaleOp());
}

template<typename _Tp, int cn> static inline
Vec<_Tp, cn> operator - (const Vec<_Tp, cn>& a)
{
    Vec<_Tp,cn> t;
    for( int i = 0; i < cn; i++ ) t.val[i] = saturate_cast<_Tp>(-a.val[i]);
    return t;
}

template<typename _Tp> inline Vec<_Tp, 4> operator * (const Vec<_Tp, 4>& v1, const Vec<_Tp, 4>& v2)
{
    return Vec<_Tp, 4>(saturate_cast<_Tp>(v1[0]*v2[0] - v1[1]*v2[1] - v1[2]*v2[2] - v1[3]*v2[3]),
                       saturate_cast<_Tp>(v1[0]*v2[1] + v1[1]*v2[0] + v1[2]*v2[3] - v1[3]*v2[2]),
                       saturate_cast<_Tp>(v1[0]*v2[2] - v1[1]*v2[3] + v1[2]*v2[0] + v1[3]*v2[1]),
                       saturate_cast<_Tp>(v1[0]*v2[3] + v1[1]*v2[2] - v1[2]*v2[1] + v1[3]*v2[0]));
}

template<typename _Tp> inline Vec<_Tp, 4>& operator *= (Vec<_Tp, 4>& v1, const Vec<_Tp, 4>& v2)
{
    v1 = v1 * v2;
    return v1;
}

} // cv

#endif // __OPENCV_CORE_MATX_HPP__
