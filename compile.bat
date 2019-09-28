@echo off
cls

REM set vars
set C_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe"
set CPP_COMPILER="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
set MAKE_BIN="C:/Program Files (x86)/CodeBlocks/MinGW/bin/mingw32-make.exe"

echo ---------------- Cmake for Code::Blocks ----------------
cd bin\build\CodeBlocksProject
cmake ../../.. -G"CodeBlocks - MinGW Makefiles" -DCMAKE_C_COMPILER=%C_COMPILER% -DCMAKE_CXX_COMPILER=%CPP_COMPILER% -DCMAKE_MAKE_PROGRAM=%MAKE_BIN% -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1
echo use code::blocs to open project

REM echo ---------------- cmake without IDE ----------------
REM cd bin\build\standaloan
REM cmake ../../.. -G"MinGW Makefiles" -DCMAKE_C_COMPILER=%C_COMPILER% -DCMAKE_CXX_COMPILER=%CPP_COMPILER% -DCMAKE_MAKE_PROGRAM=%MAKE_BIN% -DCMAKE_C_COMPILER_WORKS=1 -DCMAKE_CXX_COMPILER_WORKS=1
REM mingw32-make.exe
REM cd ../../..
REM start bin/build/standaloan/SAHEB_Engine.exe

pause
