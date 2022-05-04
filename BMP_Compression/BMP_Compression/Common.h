#ifndef COMMON_H
#define COMMON_H

#include "pch.h"

// объявление типов данных
typedef struct
{
    unsigned char B;
    unsigned char M;
    unsigned long file_size;
    unsigned long application_specific;
    unsigned long begin_of_data;
} BMP_HEADER;

typedef struct
{
    unsigned long DIB_number_of_bytes;
    unsigned long image_width;
    unsigned long image_height;
    unsigned short color_planes;
    unsigned short number_of_bits_per_pixel;
    unsigned long BI_RGB_compression;
    unsigned long size_of_raw_bitmap_data;
    unsigned long pixels_metre_hor;
    unsigned long pixels_metre_ver;
    unsigned long number_of_colors;
    unsigned long important_colors;
} DIB_HEADER;

typedef int T_DATA;
typedef T_DATA** T_BMP_DATA;
typedef double T_DATA_real;
typedef T_DATA_real** T_BMP_DATA_real;

// -----------------------
// интерфейсные переменные
extern BMP_HEADER bmp_h;
extern DIB_HEADER dib_h;
extern T_BMP_DATA bmp_dat;
extern T_BMP_DATA_real bmp_dat_real;
extern T_DATA_real* SVD_Alpha;
extern T_BMP_DATA_real SVD_Alpha_2D;
extern T_BMP_DATA_real SVD_U;
extern T_BMP_DATA_real SVD_VT;

// ----------------------------
// интерфейсные шаблоны функций
template <typename T>
extern void Read_One_BMP_Par(std::ifstream& bmp_file, const short par_size, T& par);

template <typename T>
extern void Write_One_BMP_Par(std::ofstream& fo, const short par_size, const T& par);

template <typename T1, typename T2>
extern T1 Init_Matrix_2D(T1 mas, int rows, int columns);

template <typename T>
extern T Delete_Matrix_2D(T mas, int rows);

// --------------------
// интерфейсные функции
extern void Read_BMP();

extern void Write_BMP();

extern void Read_BMP_headers(std::ifstream& bmp_file);

extern double* Delete_Matrix_1D(double* mas);

extern double* Init_Matrix_1D(double* mas, int size);

extern T_BMP_DATA_real Matrix_Product(T_BMP_DATA_real m1, T_BMP_DATA_real m2, size_t left_size, size_t center_size, size_t right_size);

#endif // COMMON_H
