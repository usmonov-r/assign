CC = gcc
TARGET = cal
OBJECTS = cal.o plus.o minus.o multiple.o divide.o

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

cal.o: cal.c
	$(CC) -c cal.c

plus.o: plus.c
	$(CC) -c plus.c

minus.o: minus.c
	$(CC) -c minus.c

multiple.o: multiple.c
	$(CC) -c multiple.c

divide.o: divide.c
	$(CC) -c divide.c

clean:
	rm -f *.o $(TARGET)
