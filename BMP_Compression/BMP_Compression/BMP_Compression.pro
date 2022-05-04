TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Delete_Matrix_1D.cpp \
        Delete_Matrix_2D.cpp \
        Init_Matrix_1D.cpp \
        Init_Matrix_2D.cpp \
        Matrix_Product.cpp \
        Read_BMP.cpp \
        Read_BMP_headers.cpp \
        Read_One_BMP_Par.cpp \
        Write_BMP.cpp \
        Write_One_BMP_Par.cpp \
        main.cpp \
        src/alglibinternal.cpp \
        src/alglibmisc.cpp \
        src/ap.cpp \
        src/dataanalysis.cpp \
        src/diffequations.cpp \
        src/fasttransforms.cpp \
        src/integration.cpp \
        src/interpolation.cpp \
        src/kernels_avx2.cpp \
        src/kernels_fma.cpp \
        src/kernels_sse2.cpp \
        src/linalg.cpp \
        src/optimization.cpp \
        src/solvers.cpp \
        src/specialfunctions.cpp \
        src/statistics.cpp

HEADERS += \
    Common.h \
    pch.h \
    src/alglibinternal.h \
    src/alglibmisc.h \
    src/ap.h \
    src/dataanalysis.h \
    src/diffequations.h \
    src/fasttransforms.h \
    src/integration.h \
    src/interpolation.h \
    src/kernels_avx2.h \
    src/kernels_fma.h \
    src/kernels_sse2.h \
    src/linalg.h \
    src/optimization.h \
    src/solvers.h \
    src/specialfunctions.h \
    src/statistics.h \
    src/stdafx.h
