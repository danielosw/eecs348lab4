default: code1.o code2.o
	gcc -o code1 code1.o
	gcc -o code2 code2.o
code1.o: code1.c
	gcc -c code1.c
code2.o: code2.c
	gcc -c code2.c
clean:
	rm *.o
