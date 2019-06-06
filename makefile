exe = main.exe
main: main.o lib.a
	g++ main.o lib/lib.a -o $(exe)
main.o: main.c
	g++ -c main.c
lib.a:
	$(MAKE) -C lib
clean:
	rm -f *.o $(exe)
	$(MAKE) -C lib clean
