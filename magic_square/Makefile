# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -Werror

# Executable name
EXEC=magic_square

# Source files
SRCS=magic_square.c

# Object files
OBJS=$(SRCS:.c=.o)

# Default target
all: $(EXEC) test
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

# Run tests
test:
	./test.sh $(EXEC) tests

