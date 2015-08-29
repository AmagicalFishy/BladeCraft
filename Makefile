IDIR = -Iinclude -Ilib
LDIR = lib
CFLAGS = -Wall -pg -g -O $(IDIR) -std=c++11 -fdiagnostics-color
CPP = g++
ODIR = build
SDIR = src

_DEPS = linkedlist.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o soul.o world.o attacks.o handlers.o notifiers.o item.o\
	   room.o info.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(ODIR) BladeCraft

$(ODIR): 
	mkdir -p $@

BladeCraft: $(OBJ)
	$(CPP) $^ $(CFLAGS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CPP) -c $< $(CFLAGS) -o $@


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o core 
	rm -f debug/core
	rm -rf build
	rm -f BladeCraft
