@ECHO off
REM g- generator name s- source dir b- build dir
cmake -G "Visual Studio 15 2017" -S "." -B ".\VS-cmake-build-debug"
pause