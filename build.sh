#!/bin/bash

CXX="${CXX:-g++}"
SRC_APP="./main.cpp ./src/*.cpp ./src/BufferObject/*.cpp ./src/Texture/*.cpp ./src/Handler/*.cpp ./src/Camera/*.cpp ./glad/glad.c"
FLAGS="-Wall -Werror -Wextra -pedantic"
LIBS="-lX11 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm -lstdc++"
OUT="opengl"

set -xe

if [[ -z "$LIBS" ]]
then
    $($CXX $SRC_APP $FLAGS -o $OUT)
else
    $($CXX $SRC_APP $FLAGS $LIBS -o $OUT)
fi

if [[ $? -ne 0 ]]
then
    echo "ERROR: Compile failed!"
    exit 1
else
    echo "Compile succesfully!"
    exit 0
fi
