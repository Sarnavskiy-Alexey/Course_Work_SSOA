#include "Common.h"

T_BMP_DATA_real Matrix_Product(T_BMP_DATA_real m1, T_BMP_DATA_real m2, size_t left_size, size_t center_size, size_t right_size)
{
    T_BMP_DATA_real m_producted = new T_DATA_real*[left_size];
    for (size_t i = 0; i < left_size; i++)
    {
        m_producted[i] = new T_DATA_real[right_size];
    }

    for (size_t l = 0; l < left_size; l++)
    {
        for (size_t r = 0; r < right_size; r++)
        {
            T_DATA_real sum = 0;

            for(size_t c = 0; c < center_size; c++)
            {
                sum += m1[l][c] * m2[c][r];
            }

            m_producted[l][r] = sum;
        }
    }

    return m_producted;
}
