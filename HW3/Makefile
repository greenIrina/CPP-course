CXX      	 ?= g++
COMP		 ?= -std=c++17 -Wall -fPIC -c -o

DEFINE_NAME  	 := -DNAME=\"Ira\"
LIB_NAME	 := mylib
LIBVER   	 := 5.1.10
OBJS     	 := hello.o here.o bye.o
MAIN_OBJ	 := main.o

vpath %.cpp code

mylib.a: $(OBJS)
	ar rcs $@ $^

dyn_lib: $(OBJS)
	${CXX} -shared -o lib${LIB_NAME}.so.${LIBVER} -Wl,-soname,lib${LIB_NAME}.so $^

main: $(MAIN_OBJ) dyn_lib
	ln -s lib${LIB_NAME}.so.${LIBVER} lib${LIB_NAME}.so
	${CXX} -std=c++17 -o main ${MAIN_OBJ} -L. -l${LIB_NAME} -Wl,-rpath,.

main.o: main.cpp
	${CXX} ${COMP} $@ $^

hello.o: hello.cpp
	${CXX} -std=c++17 -Wall -fPIC ${DEFINE_NAME} -c -o $@ $^

here.o: here.cpp
	${CXX} ${COMP} $@ $^

bye.o: bye.cpp
	${CXX} ${COMP} $@ $^

test:
	make main
	./main

clear:
	rm -rf *.o

clean:
	rm -rf *.o *.a lib${LIB_NAME}.* main qq	