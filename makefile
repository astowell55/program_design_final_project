tree: tree.o myDS.o myIO.o
	gcc -o tree tree.o myDS.o  myIO.o

tree.o: tree.c myIO.h myDS.h 
	gcc -c tree.c

myIO.o: myIO.c myIO.h myDS.h	
	gcc -c myIO.c

myDS.o: myDS.c myDS.h
	gcc -c myDS.c

myAlgo.o: myAlgo.c myAlgo.h
	gcc -c myAlgo.c
	
clean:
	rm *.o