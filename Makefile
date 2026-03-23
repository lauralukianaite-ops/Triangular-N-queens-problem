main.exe : main.c n_queen.o n_queen.h
	gcc -std=c99  main.c n_queen.o n_queen.h -o main.exe

n_queen.o : n_queen.c n_queen.h
	gcc -c -std=c99 n_queen.c