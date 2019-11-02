#include "radare.h"
#include "emulator.h"
#include "api/container.h"

int main(const int argc, const char *argv[]) {
	Radare *r2 = new Radare(argv[1]);
	Container *apis = new Container();
	Emulator *emulator = new Emulator(r2, apis);
	emulator->run();
	return 0;
};