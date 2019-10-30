CC = g++

PACKAGES = \
	r_socket \
	jsoncpp

CFLAGS = $(shell pkg-config --cflags $(PACKAGES))
LIBS =  $(shell pkg-config --libs $(PACKAGES))


H = .h
C = .cxx
SRCDIR = src
APIDIR = src/api
HEADERS = $(wildcard $(SRCDIR)/*$(H) $(APIDIR)/*$(H))
SOURCES = $(wildcard $(SRCDIR)/*$(C) $(APIDIR)/*$(C))
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
	./$(BINARY) samples/crackme0x02.exe

# Remove binaries & objects
clean: 
	@echo "Cleaning up..."
	rm $(BINARY)