#!/bin/bash

NAME=artclass

/usr/bin/g++ -DEVAL -O2 -o $NAME grader.c graderlib.c $NAME.cpp -ljpeg
