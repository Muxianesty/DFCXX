#include "dfcxx/io.h"

namespace dfcxx {
    IO::IO(Graph &graph, VarBuilder &builder, KernStorage &storage) : graph_(graph),
                                                                      builder_(builder),
                                                                      storage_(storage) {}

    DFVariable &IO::input(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildStream(name, Direction::INPUT, type);
        storage_.addVariable(var);
        return *var;
    }

    DFVariable &IO::inputScalar(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildScalar(name, Direction::INPUT, type);
        storage_.addVariable(var);
        return *var;
    }

    DFVariable &IO::output(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildStream(name, Direction::OUTPUT, type);
        storage_.addVariable(var);
        return *var;
    }

    DFVariable &IO::outputScalar(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildScalar(name, Direction::OUTPUT, type);
        storage_.addVariable(var);
        return *var;
    }
}