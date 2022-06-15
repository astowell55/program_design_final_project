tree: tree.o myDS.o myIO.o myAlgo.o myUI.o
	gcc -o tree tree.o myDS.o  myIO.o myAlgo.o myUI.o

tree.o: tree.c myIO.h myDS.h myAlgo.h myUI.h tree.h
	gcc -c tree.c

myIO.o: myIO.c myIO.h myDS.h	
	gcc -c myIO.c

myDS.o: myDS.c myDS.h tree.h
	gcc -c myDS.c

myAlgo.o: myAlgo.c myAlgo.h
	gcc -c myAlgo.c

myUI.o: myUI.c myUI.h
	gcc -c myUI.c
	
clean:
	rm *.o