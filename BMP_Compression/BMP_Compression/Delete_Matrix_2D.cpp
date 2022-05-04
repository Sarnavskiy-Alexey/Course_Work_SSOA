#include "Common.h"

template <typename T>
T Delete_Matrix_2D(T mas, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete [] mas[i];
    }
    delete [] mas;
    mas = nullptr;

    return mas;
}
