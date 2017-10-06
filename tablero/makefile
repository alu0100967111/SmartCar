CXX = g++
CFLAGS = -std=c++11 -I$(IDIR) 

SRCDIR = ./src/
IDIR = ./include/

SOURCES = $(SRCDIR)*.cpp

all: clean busqueda run 

debug: gdb clean

gdb:
	gdb busqueda 

busqueda:
	$(CXX) $(CFLAGS) $(SOURCES) -o $@
	
run:
	./busqueda
	
clean:
	$(RM) busqueda

