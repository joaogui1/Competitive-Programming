#!/bin/bash

NAME=supper

/usr/bin/g++ -DEVAL -Wall -static -O2 -o $NAME grader.cpp assistant.cpp advisor.cpp
