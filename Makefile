CC = g++
STD = c++17

PACKAGES = \
	r_socket \
	jsoncpp

CFLAGS = $(shell pkg-config --cflags $(PACKAGES))
LIBS =  $(shell pkg-config --libs $(PACKAGES))

H = .h
C = .cxx
SRCDIR = src
APILOGDIR = $(SRCDIR)/api_logic
APIIMPDIR = $(SRCDIR)/api_implementations
BINARY = cesil_emulator

HEADERS = $(wildcard \
	$(SRCDIR)/*$(H) \
	$(APILOGDIR)/*$(H) \
	$(APIIMPDIR)/*$(H) \
)

SOURCES = $(wildcard \
	$(SRCDIR)/*$(C) \
	$(APILOGDIR)/*$(C) \
	$(APIIMPDIR)/*$(C) \
)

# Make default option
all: compile

# Compile the binary
compile:
	@echo "Creating binary files..."
	$(CC) -std=$(STD) $(HEADERS) $(SOURCES) -o $(BINARY) $(CFLAGS) $(LIBS)
	@echo "Binary executable $(BINARY) created ;)"

# Compile & test the application
test: compile
	@echo "Testing application..."
	./$(BINARY) samples/crackme0x02.exe

# Remove binaries & objects
clean: 
	@echo "Cleaning up..."
	rm $(BINARY)