CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra

SRC := writer.c
OBJ := $(SRC:.c=.o)
TARGET := writer

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
