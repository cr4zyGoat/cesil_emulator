CC = gcc

CFLAGS = $(shell pkg-config --cflags r_socket)
LIBS =  $(shell pkg-config --libs r_socket)

SRC = $(wildcard *.cxx)
BINARY = cesil_emulator

# Make default option 
all: compile

# Compile the binary
compile:
	@echo "Creating $(BINARY) binary..."
	$(CC) $(SRC) -o $(BINARY) $(CFLAGS) $(LIBS)

# Compile & test the application
test: compile
	@echo "Testing application..."
	./$(BINARY)

# Remove binaries & objects
clean: 
	@echo "Cleaning up..."
	rm $(BINARY)