#!/bin/bash
set -Ceu

g++  maths.cpp -o maths.exe
./maths.exe

#g++ mcmc.cpp maths.cpp main.cpp -o mcmc.exe
#./mcmc.exe