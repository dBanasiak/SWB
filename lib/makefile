all: mathsLibs.o
	ar rvs lib.a $^
mathLibs.o: mathLibs.c
	g++ -c mathLibs.c
%.o: %.c %.h
	g++ -c $<
clean:
	rm -f *.o *.a
