#!/bin/bash

NAME=icc

g++ -std=c++11 -O2 -static -o the grader.cpp $NAME.cpp -lm 2>&1
