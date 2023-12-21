SRCS = Box.cpp Pen.cpp main.cpp

CC = g++
CFLAGS = -Wall -Werror

all: draw

Pen.o: Pen.cpp Pen.h
	${CC} ${CFLAGS} -c Pen.cpp

Box.o: Box.cpp Box.h
	${CC} ${CFLAGS} -c Box.cpp

main.o: main.cpp Box.h Box-unicode.h
	${CC} ${CFLAGS} -c main.cpp

draw: main.o Box.o Pen.o
	 ${CC} ${CFLAGS} Box.o main.o Pen.o -o draw

clean:
	rm -rf *.o draw
