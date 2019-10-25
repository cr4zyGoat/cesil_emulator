CC = g++

CFLAGS = $(shell pkg-config --cflags r_socket)
LIBS =  $(shell pkg-config --libs r_socket)

HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cxx)
BINARY = cesil_emulator

# Make default option
all: compile

# Compile the binary
compile:
	@echo "Creating $(BINARY) binary..."
	$(CC) $(HEADERS) $(SOURCES) -o $(BINARY) $(CFLAGS) $(LIBS)

# Compile & test the application
test: compile
	@echo "Testing application..."
	./$(BINARY) /usr/bin/ls

# Remove binaries & objects
clean: 
	@echo "Cleaning up..."
	rm $(BINARY)