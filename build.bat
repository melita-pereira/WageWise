@echo off
echo Compiling...
g++ -std=c++17 src/*.cpp -I src -o WageWise.exe -static -D_GLIBCXX_USE_C99_STDIO
if %ERRORLEVEL% EQU 0 (
    echo Success! Running...
    WageWise.exe
) else (
    echo Build failed
    pause
)

