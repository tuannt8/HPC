
# Executable name
TARGET = ex1

LIBSRCS = ex1.cpp
LIBOBJS = $(LIBSRCS:.cpp=.o)

CXX = gcc
CXXFLAGS = -Wall

all: $(LIBSRCS)
	gcc -L /usr/lib64/atlas  -lcblas $(LIBSRCS) -o $(TARGET) $(CXXFLAGS)
# $(LIBSRCS) $(TARGET)

depend: $(LIBSRCS)
	makedepend -Y $(LIBSRCS) 2> /dev/null
# DO NOT DELETE
