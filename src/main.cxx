#include "radare.h"
#include "emulator.h"

int main(const int argc, const char *argv[]) {
	Radare *r2 = new Radare(argv[1]);
	Emulator *emulator = new Emulator(r2);
	emulator->run();
	return 0;
};