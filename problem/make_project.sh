#!/bin/bash

projectName=$1

echo "================================"
echo Make project $projectName
echo "================================"
mkdir $projectName
echo "[*] make directory : $projectName"
cd ./$projectName
mkdir include
echo "[*] make directory : $projectName/include"
mkdir "source"
echo "[*] make directory : $projectName/source"
touch Makefile
echo "[*] make file : $projectName/Makefile"
touch include/problem.h
echo "[*] make directory : $projectName/include/problem.h"
touch source/main.c
echo "[*] make directory : $projectName/source/main.c"
touch source/problem.c
echo "[*] make directory : $projectName/source/problem.c"
echo "================================"
echo "Let's study c language :)"

