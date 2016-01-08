TARGET	=	test
CC		=	g++
CXFLAGS	=

SRCFILES	=	main.cpp lib.cpp lib.h
OBJS		=	$(SRCFILES:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CXFLAGS) $(OBJS) 
	
depend: $(SRCFILES)
	makedepend -Y $(SRCFILES) 2> /dev/null
	
# DO NOT DELETE
