#default case that takes place in case the user wouldn't enter a flowar implementation

ifeq ($(flowar),rec)
	OBJS += flowarrec.o
else

	ifeq ($(flowar),mem)
		OBJS += flowarmem.o
	
	else
		OBJS += flowardp.o
		
		ifeq ($(path),yes)
		CFLAGS = -DPATH
		endif
	endif		
endif
