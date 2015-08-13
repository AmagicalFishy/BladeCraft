INC_DIR = ..
CFLAGS = -O -I$(INC_DIR)
CPP = g++

BladeCraft: main.o character.o item.o actionmode.o commandmode.o
	$(CPP) $(CFLAGS) -o BladeCraft main.o character.o item.o actionmode.o commandmode.o

main.o: main.cpp
	$(CPP) $(CFLAGS) -c main.cpp

item.o: ../item/item.cpp
	$(CPP) $(CFLAGS) -c ../item/item.cpp

character.o: ../character/character.cpp
	$(CPP) $(CFLAGS) -c ../character/character.cpp

actionmode.o: ../modes/actionmode.cpp
	$(CPP) $(CFLAGS) -c ../modes/actionmode.cpp

commandmode.o: ../modes/commandmode.cpp
	$(CPP) $(CFLAGS) -c ../modes/commandmode.cpp



clean:
	rm -f core ../*/*.o
	rm BladeCraft
