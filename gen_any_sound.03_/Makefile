TARGET = make_any_sound

CC = gcc

CFLAGS = -Wall -O3

all: $(TARGET)

$(TARGET): snd.c 
	$(CC) $(CFLAGS) -o $(TARGET) snd.c 

clean:
	rm -f $(TARGET)
