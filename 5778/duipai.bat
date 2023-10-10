@echo off
set cnt = 1
:loop
	echo ==第%cnt%次测试
	set /a cnt = %cnt% + 1
	gen.exe %random% > data.in
	5778.enum.exe < data.in >std.out
	5778.exe < data.in > my.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop