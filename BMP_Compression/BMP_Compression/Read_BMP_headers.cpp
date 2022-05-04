#include "Common.h"

void Read_BMP_headers(std::ifstream& bmp_file)
{
    // bmp header
    bmp_h.B = 0;
    Read_One_BMP_Par(bmp_file, 1, bmp_h.B);
    std::cout << "bmp_h.B: " << bmp_h.B << std::endl;

    bmp_h.M = 0;
    Read_One_BMP_Par(bmp_file, 1, bmp_h.M);
    std::cout << "bmp_h.M: " << bmp_h.M << std::endl;

    bmp_h.file_size = 0;
    Read_One_BMP_Par(bmp_file, 4, bmp_h.file_size);
    std::cout << "bmp_h.file_size: " << bmp_h.file_size << std::endl;

    bmp_h.application_specific = 0;
    Read_One_BMP_Par(bmp_file, 4, bmp_h.application_specific);
    std::cout << "bmp_h.application_specific: " << bmp_h.application_specific << std::endl;

    bmp_h.begin_of_data = 0;
    Read_One_BMP_Par(bmp_file, 4, bmp_h.begin_of_data);
    std::cout << "bmp_h.begin_of_data: " << bmp_h.begin_of_data << std::endl;

    // dib header
    dib_h.DIB_number_of_bytes = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.DIB_number_of_bytes);
    std::cout << "dib_h.DIB_number_of_bytes: " << dib_h.DIB_number_of_bytes << std::endl;

    dib_h.image_width = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.image_width);
    std::cout << "dib_h.image_width: " << dib_h.image_width << std::endl;

    dib_h.image_height = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.image_height);
    std::cout << "dib_h.image_height: " << dib_h.image_height << std::endl;

    dib_h.color_planes = 0;
    Read_One_BMP_Par(bmp_file, 2, dib_h.color_planes);
    std::cout << "dib_h.color_planes: " << dib_h.color_planes << std::endl;

    dib_h.number_of_bits_per_pixel = 0;
    Read_One_BMP_Par(bmp_file, 2, dib_h.number_of_bits_per_pixel);
    std::cout << "dib_h.number_of_bits_per_pixel: " << dib_h.number_of_bits_per_pixel << std::endl;

    dib_h.BI_RGB_compression = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.BI_RGB_compression);
    std::cout << "dib_h.BI_RGB_compression: " << dib_h.BI_RGB_compression << std::endl;

    dib_h.size_of_raw_bitmap_data = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.size_of_raw_bitmap_data);
    std::cout << "dib_h.size_of_raw_bitmap_data: " << dib_h.size_of_raw_bitmap_data << std::endl;

    dib_h.pixels_metre_hor = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.pixels_metre_hor);
    std::cout << "dib_h.pixels_metre_hor: " << dib_h.pixels_metre_hor << std::endl;

    dib_h.pixels_metre_ver = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.pixels_metre_ver);
    std::cout << "dib_h.pixels_metre_ver: " << dib_h.pixels_metre_ver << std::endl;

    dib_h.number_of_colors = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.number_of_colors);
    std::cout << "dib_h.number_of_colors: " << dib_h.number_of_colors << std::endl;

    dib_h.important_colors = 0;
    Read_One_BMP_Par(bmp_file, 4, dib_h.important_colors);
    std::cout << "dib_h.important_colors: " << dib_h.important_colors << std::endl;
}
