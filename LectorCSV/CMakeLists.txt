cmake_minimum_required(VERSION 4.1)
project(LectorCSV)

set(CMAKE_CXX_STANDARD 20)

add_executable(LectorCSV main.cpp
        AnalizadorEstadistico.h
        AnalizadorEstadistico.cpp
        Datos.h
        Datos.cpp
        DatoString.cpp
        DatoString.h
        DatoString.cpp
        DatoFloat.cpp
        DatoFloat.h
        AnalizadorEstadisticoString.h
        AnalizadorEstadisticoString.cpp
        Columna.cpp
        Columna.h)
