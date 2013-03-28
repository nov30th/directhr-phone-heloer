@echo off
echo **************************
echo * Install QzjNdis Driver *
echo *     Please wait...     *
echo **************************
if "%PROCESSOR_ARCHITEW6432%"=="AMD64" goto x64
if "%processor_architecture%"=="AMD64" goto x64
if "%processor_architecture%"=="x86" goto x86
goto error_processor_architecture

:error_processor_architecture
echo Error!
echo Can not found processor_architecture, please contact v.qiu@directhr.cn!
pause >nul
goto end

:x64
@REM x64
echo Installing x64 driver...
if not exist Drivers\x64\qzjndis.inf goto error
netcfg.exe -v -u "dhr_qzjndis" >nul
netcfg.exe -l Drivers\x64\qzjndis.inf -c s -i "dhr_qzjndis" >nul
goto end

:x86
@REM x86
echo Installing x86 driver...
if not exist Drivers\x86\qzjndis.inf goto error
netcfg.exe -v -u "dhr_qzjndis" >nul
netcfg.exe -l Drivers\x86\qzjndis.inf -c s -i "dhr_qzjndis" >nul
goto end

:error
echo Error!
echo Can not found driver package, please contact v.qiu@directhr.cn!
pause >nul

:end