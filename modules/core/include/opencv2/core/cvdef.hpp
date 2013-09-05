//
//  cvdef.hpp
//  OpenCV
//
//  Created by Jasper Shemilt on 05/09/2013.
//
//

#ifndef OpenCV_cvdef_hpp
#define OpenCV_cvdef_hpp

namespace cv
{
    
    struct cv_2bitType{
        union{
            struct{
                unsigned char val : 2;
                unsigned char     : 6;
            };
            unsigned char raw;
        };
        explicit constexpr cv_2bitType(unsigned char a_):raw(a_){};
        cv_2bitType()=default;
        operator CV_8U_TYPE() const {return CV_8U_TYPE(raw);};
        cv_2bitType& operator=(CV_8U_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_8S_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_16U_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_16S_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_32U_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_32S_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_64U_TYPE a_){raw = a_;return *this;}
        cv_2bitType& operator=(CV_64S_TYPE a_){raw = a_;return *this;}
    };
    
    struct cv_4bitType{
        union{
            struct{
                unsigned char val : 4;
                unsigned char     : 4;
            };
            unsigned char raw;
        };
#  if defined __cplusplus
        explicit constexpr cv_4bitType(unsigned char a_):val(a_){};
        cv_4bitType()=default;
        operator CV_8U_TYPE() const {return CV_8U_TYPE(raw);};
        cv_4bitType& operator=(CV_8U_TYPE  a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_8S_TYPE  a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_16U_TYPE a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_16S_TYPE a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_32U_TYPE a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_32S_TYPE a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_64U_TYPE a_){raw = a_;return *this;}
        cv_4bitType& operator=(CV_64S_TYPE a_){raw = a_;return *this;}
#  endif
    };
};


#  if defined __cplusplus
template<int t> struct cv_Data_Type{
    using type = unsigned char;
    const static int dataType = t;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(t);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(t);
    //    constexpr static type max  = CV_MAT_MAX(t);
    //    constexpr static type min  = CV_MAT_MIN(t);
    
};
template<> struct cv_Data_Type<CV_2U>{
    using type = CV_2U_TYPE;
    const static int dataType = CV_2U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_2U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_2U);
    constexpr static type max  = CV_2U_TYPE(CV_2U_MAX);
    constexpr static type min  = CV_2U_TYPE(CV_2U_MIN);
    const char* fmt = "hhu";
};
template<> struct cv_Data_Type<CV_4U>{
    using type = CV_4U_TYPE;
    const static int dataType = CV_4U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_4U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_4U);
    constexpr static type max  = CV_4U_TYPE(CV_4U_MAX);
    constexpr static type min  = CV_4U_TYPE(CV_4U_MIN);
    const char* fmt = "hhu";
};
template<> struct cv_Data_Type<CV_8U>{
    using type = CV_8U_TYPE;
    const static int dataType = CV_8U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_8U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_8U);
    constexpr static type max  = CV_8U_MAX;
    constexpr static type min  = CV_8U_MIN;
    const char* fmt = "hhu";
};
template<> struct cv_Data_Type<CV_8S>{
    using type = CV_8S_TYPE;
    const static int dataType = CV_8S;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_8S);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_8S);
    constexpr static type max  = CV_8S_MAX;
    constexpr static type min  = CV_8S_MIN;
    const char* fmt = "hhi";
};
template<> struct cv_Data_Type<CV_16U>{
    using type = CV_16U_TYPE;
    const static int dataType = CV_16U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_16U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_16U);
    constexpr static type max  = CV_16U_MAX;
    constexpr static type min  = CV_16U_MIN;
    const char* fmt = "hu";
};
template<> struct cv_Data_Type<CV_16S>{
    using type = CV_16S_TYPE;
    const static int dataType = CV_16S;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_16S);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_16S);
    constexpr static type max  = CV_16S_MAX;
    constexpr static type min  = CV_16S_MIN;
    const char* fmt = "hi";
};
template<> struct cv_Data_Type<CV_32U>{
    using type = CV_32U_TYPE;
    const static int dataType = CV_32U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_32U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_32U);
    constexpr static type max  = CV_32U_MAX;
    constexpr static type min  = CV_32U_MIN;
    const char* fmt = "u";
};
template<> struct cv_Data_Type<CV_32S>{
    using type = CV_32S_TYPE;
    const static int dataType = CV_32S;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_32S);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_32S);
    constexpr static type max  = CV_32S_MAX;
    constexpr static type min  = CV_32S_MIN;
    const char* fmt = "i";
};
template<> struct cv_Data_Type<CV_64U>{
    using type = CV_64U_TYPE;
    const static int dataType = CV_64U;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_64U);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_64U);
    constexpr static type max  = CV_64U_MAX;
    constexpr static type min  = CV_64U_MIN;
    const char* fmt = "llu";
};
template<> struct cv_Data_Type<CV_64S>{
    using type = CV_64S_TYPE;
    const static int dataType = CV_64S;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_64S);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_64S);
    const static type max  = CV_64S_MAX;
    const static type min  = CV_64S_MIN;
    const char* fmt = "lli";
};
template<> struct cv_Data_Type<CV_32F>{
    using type = CV_32F_TYPE;
    const static int dataType = CV_32F;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_32F);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_32F);
    constexpr static type max  = CV_32F_MAX;
    constexpr static type min  = CV_32F_MIN;
    const char* fmt = "f";
};
template<> struct cv_Data_Type<CV_64F>{
    using type = CV_64F_TYPE;
    const static int dataType = CV_64F;
    constexpr static int bitDepth  = CV_MAT_DEPTH_BITS(CV_64F);
    constexpr static int byteDepth = CV_MAT_DEPTH_BYTES(CV_64F);
    constexpr static type max  = CV_64F_MAX;
    constexpr static type min  = CV_64F_MIN;
    const char* fmt = "f";
};

template<int cv_data_type> using cv_Type = typename cv_Data_Type<cv_data_type>::type;

// Don't use cv_Data_Type directly; use Data_Type which works for both types and types with channels.

namespace cv {
    template<int t> struct Data_Type : cv_Data_Type<CV_MAT_DEPTH(t)>{
        constexpr static int channels  = CV_MAT_CN(t);
    };
}
#  endif


#endif
