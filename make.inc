#default case that takes place in case the user wouldn't enter a flowar implementation
#OBJS = flowardp.o

ifeq ($(flowar),rec)
	OBJS += flowarrec.o
endif

ifeq ($(flowar),mem)
	OBJS += flowarmem.o
endif
ifeq ($(flowar),dp)
	OBJS += flowardp.o
endif
