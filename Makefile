CC = gcc

CFLAGS = -g3 -Wall

PROGRAM = flowar

OBJS = flowarmain.o
include ./make.inc


$(PROGRAM) : clean $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(PROGRAM)
clean :
	rm -rf $(PROGRAM) $(OBJS)
run : $(PROGRAM)
	./$(PROGRAM)
