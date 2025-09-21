CC = gcc


CFLAGS = -Wall -Wextra -g -std=c11


TARGET = game


SRCS = main.c


$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)


rebuild: clean $(TARGET)


.PHONY: clean rebuild