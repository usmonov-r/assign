CC = gcc
TARGET = cal

OBJECTS = cal.o plus.o minus.o multiple.o divide.o


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)



cal.o: cal.c cal.h
	$(CC) -c cal.c

plus.o: plus.c cal.h
	$(CC) -c plus.c

minus.o: minus.c cal.h
	$(CC) -c minus.c

multiple.o: multiple.c cal.h
	$(CC) -c multiple.c

divide.o: divide.c cal.h
	$(CC) -c divide.c

clean:
	rm -f *.o $(TARGET)
