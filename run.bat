@echo off
echo Copying required DLL...
copy "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll" . 2>nul
copy "C:\msys64\ucrt64\bin\libstdc++-6.dll" . 2>nul
copy "C:\msys64\ucrt64\bin\libwinpthread-1.dll" . 2>nul
echo.
echo Compiling...
g++ -std=c++17 src/*.cpp -I src -o WageWise.exe
if %ERRORLEVEL% EQU 0 (
    echo Success! Running...
    WageWise.exe
) else (
    echo Build failed
)
pause
