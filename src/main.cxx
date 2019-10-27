#include "emulator.h"

int main(const int argc, const char *argv[]) {
	Emulator *emulator = new Emulator(argv[1]);
	emulator->run();
	return 0;
};