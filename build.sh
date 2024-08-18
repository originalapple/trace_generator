#!/bin/bash

# 변수 정의
CXX=g++
CXXFLAGS="-Iinclude -std=c++14"  # include 디렉토리 포함

# 소스 파일
SRC="src/main.cpp"

# 출력 파일 이름
OUT="main"

# 컴파일
$CXX $CXXFLAGS $SRC -o outputs/$OUT

# 실행
./$OUT

