cmake_minimum_required(VERSION 3.21)
project(Zawody)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executable)

add_executable(Zawody main.cpp
            zawody.h
            Common.h
            Element.h
            Trasa.h
            Uczestnik.h

        )
