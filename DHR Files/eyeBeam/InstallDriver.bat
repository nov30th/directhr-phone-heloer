@echo off
echo **************************
echo * Install QzjNdis Driver *
echo *     Please wait...     *
echo **************************
echo Installing...
goto:%PROCESSOR_ARCHITECTURE:~-1%
:4
@REM x64
if not exist Drivers\x64\qzjndis.inf goto error
netcfg -v -u "dhr_qzjndis" >nul
netcfg -l Drivers\x64\qzjndis.inf -c s -i "dhr_qzjndis" >nul
goto end
:6
@REM x86
if not exist Drivers\x86\qzjndis.inf goto error
netcfg -v -u "dhr_qzjndis" >nul
netcfg -l Drivers\x64\qzjndis.inf -c s -i "dhr_qzjndis" >nul
goto end

:error
echo Error!
echo Can not found driver package, please contact v.qiu@directhr.cn!
pause >nul

:end
