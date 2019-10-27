CC = g++

PACKAGES = \
	r_socket \
	jsoncpp

CFLAGS = $(shell pkg-config --cflags $(PACKAGES))
LIBS =  $(shell pkg-config --libs $(PACKAGES))

SRCDIR = src
HEADERS = $(wildcard $(SRCDIR)/*.h)
SOURCES = $(wildcard $(SRCDIR)/*.cxx)
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