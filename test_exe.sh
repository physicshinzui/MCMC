#!/bin/bash
set -Ceu

g++ mcmc.cpp maths.cpp main.cpp -o mcmc.exe
./mcmc.exe