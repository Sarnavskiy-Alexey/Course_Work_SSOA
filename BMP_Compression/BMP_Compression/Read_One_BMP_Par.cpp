#include "Common.h"

template <typename T>
void Read_One_BMP_Par(std::ifstream& bmp_file, const short par_size, T& par)
{
    unsigned char tmp;
    par = 0;
    for (int i = 0; i < par_size; i++)
    {
        tmp = 0;
        bmp_file >> tmp;
        par += ((static_cast<unsigned long long>(tmp)) << (i * 8));
    }
}
