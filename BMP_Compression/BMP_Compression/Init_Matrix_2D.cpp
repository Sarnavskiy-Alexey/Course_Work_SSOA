#include "Common.h"

template <typename T1, typename T2>
T1 Init_Matrix_2D(T1 mas, int rows, int columns)
{
    mas = new T2*[rows];
    for (int i = 0; i < rows; i++)
    {
        mas[i] = new T2[columns];
    }

    return mas;
}
