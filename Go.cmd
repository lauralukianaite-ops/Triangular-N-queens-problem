if .%USERDOMAIN% == .SavasPC goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
rem 1 testas: N=3, M=3 (nera sprendinio)
echo 3 3 > test1.txt
main.exe test1.txt > result1.txt

rem 2 testas: N=4, M=3
echo 4 3 > test2.txt
main.exe test2.txt > result2.txt

rem 3 testas: N=4, M=4 (nera sprendinio)
echo 4 4 > test3.txt
main.exe test3.txt > result3.txt

rem 4 testas: N=6, M=4
echo 6 4 > test4.txt
main.exe test4.txt > result4.txt

rem 5 testas: N=8, M=5
echo 8 5 > test5.txt
main.exe test5.txt > result5.txt

rem 6 testas: N=10, M=7
echo 10 7 > test6.txt
main.exe test6.txt > result6.txt

rem 7 testas: N=10, M=8 (nera sprendinio)
echo 10 8 > test7.txt
main.exe test7.txt > result7.txt

rem 8 testas: timeout
main.exe -n 999 -m 666 -timeout 1000 > result8.txt