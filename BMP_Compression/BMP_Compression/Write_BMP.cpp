#include "Common.h"

T_DATA_real* SVD_Alpha;
T_BMP_DATA_real SVD_U;
T_BMP_DATA_real SVD_VT;
T_BMP_DATA_real SVD_Alpha_2D;
T_BMP_DATA bmp_data_to_out;

void Write_BMP()
{
    // объявление переменных
    SVD_U = Init_Matrix_2D<T_BMP_DATA_real, T_DATA_real>(SVD_U, dib_h.image_height, dib_h.image_height);
    SVD_Alpha = Init_Matrix_1D(SVD_Alpha, dib_h.image_width);
    SVD_Alpha_2D = Init_Matrix_2D<T_BMP_DATA_real, T_DATA_real>(SVD_Alpha_2D, dib_h.image_height, dib_h.image_width);
    SVD_VT = Init_Matrix_2D<T_BMP_DATA_real, T_DATA_real>(SVD_VT, dib_h.image_width, dib_h.image_width);
    bmp_data_to_out = Init_Matrix_2D<T_BMP_DATA, T_DATA>(bmp_data_to_out, dib_h.image_width, dib_h.image_width);
    bool result = false;
    alglib::real_2d_array bmp_dat_real_alg;
    alglib::real_1d_array SVD_Alpha_real;
    alglib::real_2d_array SVD_U_real;
    alglib::real_2d_array SVD_VT_real;
    std::ofstream fo;

    // присвоение данных из картинки переменной
    bmp_dat_real_alg.setlength(dib_h.image_height, dib_h.image_width);
    for(size_t i = 0; i < dib_h.image_height; i++)
    {
        for (size_t j = 0; j < dib_h.image_width; j++)
        {
            bmp_dat_real_alg[i][j] = bmp_dat_real[i][j];
        }
    }

    // SVD-разложение
    result = alglib::rmatrixsvd(bmp_dat_real_alg, dib_h.image_height, dib_h.image_width, 2, 2, 2, SVD_Alpha_real, SVD_U_real, SVD_VT_real);

//    std::cout << "bmp_dat_real_alg:\n";
//    for (int i = 0; i < bmp_dat_real_alg.rows(); i++)
//    {
//        std::cout << i + 1 << ". ";
//        for (int j = 0; j < bmp_dat_real_alg.cols(); j++)
//        {
//            std::cout.precision(10);
//            std::cout << bmp_dat_real_alg[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;

//    std::cout << "bmp_dat:\n";
//    for (size_t i = 0; i < dib_h.image_height; i++)
//    {
//        std::cout << i + 1 << ". ";
//        for (size_t j = 0; j < dib_h.image_width; j++)
//        {
//            std::cout << bmp_dat[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;

//    std::cout << "SVD_Alpha:\n";
//    for (int i = 0; i < SVD_Alpha_real.length(); i++)
//    {
//        std::cout << std::dec << i + 1 << ". " << SVD_Alpha_real[i] << std::endl;
//    }
//    std::cout << std::endl << std::endl;

    for (size_t i = 0; i < dib_h.image_height; i++)
    {
        for (size_t j = 0; j < dib_h.image_height; j++)
        {
            SVD_U[i][j] = SVD_U_real[i][j];
        }
    }

    for (size_t i = 0; i < dib_h.image_width; i++)
    {
        SVD_Alpha[i] = SVD_Alpha_real[i];
    }

    for (size_t i = 0; i < dib_h.image_height; i++)
    {
        for (size_t j = 0; j < dib_h.image_width; j++)
        {
            if (i == j)
            {
                SVD_Alpha_2D[i][j] = SVD_Alpha_real[i];
            }
            else
            {
                SVD_Alpha_2D[i][j] = 0.0;
            }
        }
    }

    for (size_t i = 0; i < dib_h.image_width; i++)
    {
        for (size_t j = 0; j < dib_h.image_width; j++)
        {
            SVD_VT[i][j] = SVD_VT_real[i][j];
        }
    }

    T_BMP_DATA_real bmp_dat_new = nullptr;
    T_BMP_DATA_real bmp_dat_new_2 = nullptr;

//    std::cout << "SVD_Alpha_2D";
//    for (int i = 0; i < dib_h.image_height; i++)
//    {
//        std::cout << i + 1 << ". ";
//        for (int j = 0; j < dib_h.image_width; j++)
//        {
//            if (i == j)
//            {
//                std::cout << SVD_Alpha_2D[i][j] << std::endl;
//            }
//        }
//    }

//    for (int i = 47; i < 50; i++)
//    {
//        SVD_Alpha_2D[i][i] = 0.0;
//    }
//    std::cout << std::endl;

    std::cout << "SVD_Alpha_2D some nulls:\n";
    for (size_t i = 0; i < dib_h.image_height; i++)
    {
        std::cout << i + 1 << ". ";
        for (size_t j = 0; j < dib_h.image_width; j++)
        {
            if (i == j)
            {
                std::cout << SVD_Alpha_2D[i][j] << std::endl;
            }
        }
    }

    bmp_dat_new = Matrix_Product(SVD_U, SVD_Alpha_2D, dib_h.image_height, dib_h.image_height, dib_h.image_width);
    bmp_dat_new_2 = Matrix_Product(bmp_dat_new, SVD_VT, dib_h.image_height, dib_h.image_width, dib_h.image_width);

//    std::cout << "bmp_dat_new:\n";
//    for (size_t i = 0; i < dib_h.image_height; i++)
//    {
//        std::cout << i + 1 << ". ";
//        for (size_t j = 0; j < dib_h.image_width; j++)
//        {
//            bmp_data_to_out[i][j] = static_cast<T_DATA>(bmp_dat_new[i][j]);
//            std::cout << bmp_data_to_out[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }




    fo.open("../BMP_Compression/newfo2.bmp");
    if (fo.is_open())
    {
        for (size_t i = 0; i < dib_h.image_height; i++)
        {
            for (size_t j = 0; j < dib_h.image_width; j++)
            {
                bmp_data_to_out[i][j] = static_cast<T_DATA>(bmp_dat_new_2[i][j]);
            }
        }

//        std::cout << "bmp_dat_new_2:\n";
//        for (size_t i = 0; i < dib_h.image_height; i++)
//        {
//            std::cout << i + 1 << ". ";
//            for (size_t j = 0; j < dib_h.image_width; j++)
//            {
//                std::cout << bmp_data_to_out[i][j] << " ";
//            }
//            std::cout << "\n";
//        }

        Write_One_BMP_Par(fo, 1, bmp_h.B);
        Write_One_BMP_Par(fo, 1, bmp_h.M);
        Write_One_BMP_Par(fo, 4, bmp_h.file_size);
        Write_One_BMP_Par(fo, 4, bmp_h.application_specific);
        Write_One_BMP_Par(fo, 4, bmp_h.begin_of_data);

        Write_One_BMP_Par(fo, 4, dib_h.DIB_number_of_bytes);
        Write_One_BMP_Par(fo, 4, dib_h.image_width);
        Write_One_BMP_Par(fo, 4, dib_h.image_height);
        Write_One_BMP_Par(fo, 2, dib_h.color_planes);
        Write_One_BMP_Par(fo, 2, dib_h.number_of_bits_per_pixel);
        Write_One_BMP_Par(fo, 4, dib_h.BI_RGB_compression);
        Write_One_BMP_Par(fo, 4, dib_h.size_of_raw_bitmap_data);
        Write_One_BMP_Par(fo, 4, dib_h.pixels_metre_hor);
        Write_One_BMP_Par(fo, 4, dib_h.pixels_metre_ver);
        Write_One_BMP_Par(fo, 4, dib_h.number_of_colors);
        Write_One_BMP_Par(fo, 4, dib_h.important_colors);

        unsigned long int rows_size = dib_h.image_width * (dib_h.number_of_bits_per_pixel / 8.0);
        const short line_offset = (4 - rows_size % 4) % 4;

        for (size_t j = 0; j < dib_h.image_width; j++)
        {
            for (size_t i = 0; i < dib_h.image_height; i++)
            {
                Write_One_BMP_Par(fo, 3, bmp_data_to_out[i][j]);
            }
            unsigned char offset = 0;
            Write_One_BMP_Par(fo, line_offset, offset);
        }

        fo.close();
    }
    else
    {
        std::cout << "Can't find file!\n";
    }

    bmp_dat_new = Delete_Matrix_2D<T_BMP_DATA_real>(bmp_dat_new, dib_h.image_height);
    bmp_dat_new_2 = Delete_Matrix_2D<T_BMP_DATA_real>(bmp_dat_new_2, dib_h.image_height);
    SVD_VT = Delete_Matrix_2D<T_BMP_DATA_real>(SVD_VT, dib_h.image_width);
    SVD_U = Delete_Matrix_2D<T_BMP_DATA_real>(SVD_U, dib_h.image_height);
    SVD_Alpha = Delete_Matrix_1D(SVD_Alpha);
    bmp_dat = Delete_Matrix_2D<T_BMP_DATA>(bmp_dat, dib_h.image_height);
    bmp_dat_real = Delete_Matrix_2D<T_BMP_DATA_real>(bmp_dat_real, dib_h.image_height);
}
