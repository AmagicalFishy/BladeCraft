IDIR = -Iinclude -Ilib
LDIR = lib
CFLAGS = -Wall -pg -g -O $(IDIR) -std=c++11 -fdiagnostics-color
CPP = g++
ODIR = build
SDIR = src

_DEPS = linkedlist.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o soul.o world.o attacks.o handlers.o notifiers.o #item.o actionmode.o commandmode.o room.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

BladeCraft: $(OBJ) 
	$(CPP) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(LDIR) $(ODIR)
	$(CPP) -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o core 
	rm -f debug/core
	rm -rf build
	rm -f BladeCraft
