#include "Common.h"

double* Delete_Matrix_1D(double* mas)
{
    delete[] mas;
    mas = nullptr;

    return mas;
}
