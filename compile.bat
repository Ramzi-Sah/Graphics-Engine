@echo off
cls
cd build

REM echo ---------------- Cmake for Code::Blocks ----------------
REM cmake .. -G"CodeBlocks - MinGW Makefiles" -DCMAKE_C_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe" -DCMAKE_MAKE_PROGRAM="C:/Program Files (x86)/CodeBlocks/MinGW/bin/mingw32-make.exe" -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1
REM echo use code::blocs to open project

echo ---------------- cmake without IDE ----------------
cmake .. -G"MinGW Makefiles" -DCMAKE_C_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe" -DCMAKE_MAKE_PROGRAM="C:/Program Files (x86)/CodeBlocks/MinGW/bin/mingw32-make.exe" -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1
mingw32-make.exe

pause
