
CC = gcc
CFLAGS = -Wall -g

.PHONY: all
all: maindrec maindloop mains
 
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o ./libclassrec.so -lm

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so -lm

mains: main.o make recursived
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a -lm

.PHONY: make loopd
make loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared $(CFLAGS) -o libclassloops.so basicClassification.o advancedClassificationLoop.o  

.PHONY: make recursived
make recursived: libclassrec.so
libclassrec.so:	basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared $(CFLAGS) -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

.PHONY: make loops
make loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

.PHONY: make recursives
make recursives:libclassrecs.a
libclassrecs.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o 					advancedClassificationRecursion.o 
					ranlib libclassrec.a
basicClassification.o: basicClassification.c
	$(CC) -c $(CFLAGS) basicClassification.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) -c $(CFLAGS) advancedClassificationRecursion.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) -c $(CFLAGS) advancedClassificationLoop.c
main.o: main.c
	$(CC) -c $(CFLAGS) main.c NumClass.h

.PHONY: clean
clean:
	-rm -rf *.o *.gch *.a *.so mains maindloop maindrec
