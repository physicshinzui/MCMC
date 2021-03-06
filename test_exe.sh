#!/bin/bash
set -Ceu

g++ mcmc.cpp main.cpp -o mcmc.exe
./mcmc.exe