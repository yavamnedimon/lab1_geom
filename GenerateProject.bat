@echo off
setlocal enabledelayedexpansion

pushd %~dp0

set BuildMode="Debug"

if "%~1"=="" (
    echo Use default build mode - %BuildMode%
)


set ProjectGenerator=""
if not "%~2"=="" (
    set ProjectGenerator= -G "%~2"
)

if not exist %BuildMode% (
    mkdir %BuildMode%
)

cmake%ProjectGenerator% -B %BuildMode% -S . -DCMAKE_BUILD_TYPE=%BuildMode% -DCMAKE_TOOLCHAIN_FILE=%cd%\vcpkg\scripts\buildsystems\vcpkg.cmake


if not exist "GeomertyLab1.sln" if exist %BuildMode%\GeomertyLab1.sln (
    mklink GeomertyLab1.sln %BuildMode%\GeomertyLab1.sln
)

if NOT ["%errorlevel%"]==["0"] pause

popd
