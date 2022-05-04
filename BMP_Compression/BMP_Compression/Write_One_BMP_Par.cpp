#include "Common.h"

template <typename T>
void Write_One_BMP_Par(std::ofstream& fo, const short par_size, const T& par)
{
    unsigned char tmp;
    for (int i = 0; i < par_size; i++)
    {
        tmp = 0;
        tmp = static_cast<unsigned char>((par >> (i * 8)));
        fo << tmp;
    }
}
