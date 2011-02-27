windres -i resource.rc -o res.o
gcc -c -o source.o source.c
gcc -mwindows -o window.exe source.o res.o