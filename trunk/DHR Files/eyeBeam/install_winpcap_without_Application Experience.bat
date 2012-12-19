@echo off
echo Install Winpcap...
net stop "Program Compatibility Assistant Service"
WinPcap_4_1_2.exe
net start "Program Compatibility Assistant Service"
