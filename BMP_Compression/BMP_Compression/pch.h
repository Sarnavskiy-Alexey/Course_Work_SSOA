#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <fstream>
#include "Read_One_BMP_Par.cpp"
#include "Write_One_BMP_Par.cpp"
#include "Delete_Matrix_2D.cpp"
#include "Init_Matrix_2D.cpp"

// ALGLIB-CPP
#include "src/alglibinternal.h"
#include "src/alglibmisc.h"
#include "src/ap.h"
#include "src/dataanalysis.h"
#include "src/diffequations.h"
#include "src/fasttransforms.h"
#include "src/integration.h"
#include "src/interpolation.h"
#include "src/kernels_avx2.h"
#include "src/kernels_fma.h"
#include "src/kernels_sse2.h"
#include "src/linalg.h"
#include "src/optimization.h"
#include "src/solvers.h"
#include "src/specialfunctions.h"
#include "src/statistics.h"
#include "src/stdafx.h"

#endif // PCH_H
