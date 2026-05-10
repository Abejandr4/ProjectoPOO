cmake_minimum_required(VERSION 4.1)
project(LectorCSV)

set(CMAKE_CXX_STANDARD 20)

add_executable(LectorCSV main.cpp
        AnalizadorEstadistico.cpp
        Datos.cpp
        DatoMedicion.h
        DatoString.cpp
        DatoString.h
        DatoString.cpp
        DatoFloat.cpp
        DatoFloat.h)
