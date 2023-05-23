# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -pedantic

# Executable name
EXEC=translate

# Source files
SRCS=translate.c

# Object files
OBJS=$(SRCS:.c=.o)

# Default target
all: $(EXEC)
	./test.sh $(EXEC) tests
	rm -f $(OBJS)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)