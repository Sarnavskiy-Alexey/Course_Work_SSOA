#include "Common.h"

// интерфейсные переменные заголовков bmp и dib
BMP_HEADER bmp_h;
DIB_HEADER dib_h;
T_BMP_DATA bmp_dat = nullptr;
T_BMP_DATA_real bmp_dat_real = nullptr;

void Read_BMP()
{
    std::ifstream bmp_file;
    bmp_file.open("../BMP_Compression/rainbow24.bmp");

    // если файл открыт, то считываем данные из файла
    if (bmp_file.is_open())
    {
        Read_BMP_headers(bmp_file);

        unsigned long int rows_size = dib_h.image_width * (dib_h.number_of_bits_per_pixel / 8.0);
        const short line_offset = rows_size % 4;
        std::cout << "line_offset: " << line_offset << std::endl;

        // считывание данных
        bmp_dat = Init_Matrix_2D<T_BMP_DATA, T_DATA>(bmp_dat, dib_h.image_height, dib_h.image_width);
        bmp_dat_real = Init_Matrix_2D<T_BMP_DATA_real, T_DATA_real>(bmp_dat_real, dib_h.image_height, dib_h.image_width);

        for (size_t j = 0; j < dib_h.image_height; j++)
        {
            for (size_t i = 0; i < dib_h.image_width; i++)
            {
                bmp_dat[i][j] = 0;
                Read_One_BMP_Par(bmp_file, 3, bmp_dat[i][j]);
                bmp_dat_real[i][j] = static_cast<double>(bmp_dat[i][j]);
            }
            unsigned short tmp = 0;
            Read_One_BMP_Par(bmp_file, line_offset, tmp);
        }

        bmp_file.close();
    }
    else
    {
        std::cout << "Can't find file to pars!\n";
    }
}
