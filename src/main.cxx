#include "radare.h"
#include "emulator.h"

#include "api_logic/container.h"
#include "api_implementations/processthreadsapi.h"

int main(const int argc, const char *argv[]) {
	Radare *r2 = new Radare(argv[1]);

	Container *apis = new Container();
	apis->load_api(new Processthreadsapi());

	Emulator *emulator = new Emulator(r2, apis);
	emulator->run();

	return 0;
};