CC = g++
CFLAGS = -g -std=c++11
OBJS = main.cpp

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

clean:
	rm -f *~ *.o main
