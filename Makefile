CC= gcc
AR=ar

#flag setup
FLAGS= -Wall -g



OBJECT_STATIC_LOOP= basicClassification.o advancedClassificationLoop.o
OBJECT_STATIC_REC= basicClassification.o advancedClassificationRecursion.o
OBJECT_DYNAMIC_LOOP= basicClassification.o advancedClassificationLoop.o
OBJECT_DYNAMIC_REC= basicClassification.o advancedClassificationRecursion.o

all:loops recursives looped recursived mains maindloop maindrec


loops: libclassloops.a
recursives: libclassrec.a
looped: libclassloops.so
recursived: libclassrec.so




#creating libraries
libclassloops.a:$(OBJECT_STATIC_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_STATIC_LOOP)
libclassrec.a:$(OBJECT_STATIC_REC)
	$(AR) -rcs libclassrec.a $(OBJECT_STATIC_REC)	
libclassloops.so:$(OBJECT_DYNAMIC_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECT_DYNAMIC_LOOP)
libclassrec.so:$(OBJECT_DYNAMIC_REC)
	$(CC) -shared -o libclassrec.so $(OBJECT_DYNAMIC_REC)	




basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -fpic
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -fpic
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -fpic

#creating main
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so 
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c



.PHONY: clean all
# PHONY tells make that “clean”,”all” are Not really file names, in case they exist in directory

clean:
		rm -f mains maindloop maindrec *.o *.a *.so *.gch






