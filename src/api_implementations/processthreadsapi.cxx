#include "processthreadsapi.h"

class ExitProcess: public IApiFunction {
public:
    ExitProcess() {};
    std::vector<FunctionArgument*> get_function_arguments() {
        std::vector<FunctionArgument*> arguments;
        arguments.push_back(new FunctionArgument("uExitCode", FunctionArgument::NUMBER));
        return arguments;
    };
    std::vector<FunctionResult*> emulate_function(const std::vector<FunctionArgument*> arguments) {
        std::vector<FunctionResult*> results;
        results.push_back(new FunctionResult(arguments.at(0)->get_value(), FunctionResult::EXIT_PROCESS));
        return results;
    };
};

Processthreadsapi::Processthreadsapi() {
    this->add_function("ExitProcess", new ExitProcess());
};