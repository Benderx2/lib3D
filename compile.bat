gcc -c wrapper.c -o wrapper.o
gcc -c wraptest.c -o wraptest.o -std=c99
gcc -c raster.c -o raster.o -std=c99
gcc -c vector.c -o vector.o -std=c99
gcc -c matrix.c -o matrix.o -std=c99
gcc -c mesh.c -o mesh.o -std=c99
gcc -c vec4.c -o vec4.o -std=c99
gcc -c render.c -o render.o -std=c99
ar -rcs -o lib3Dc.a wraptest.o vector.o wrapper.o raster.o matrix.o render.o
gcc wraptest.c lib3Dc.a -o wptest.exe -lmingw32 -lSDLmain -lSDL
del *.o
copy .\wptest.exe .\bin\
copy .\lib3Dc.a .\bin\
del wptest.exe
del lib3Dc.a
pause