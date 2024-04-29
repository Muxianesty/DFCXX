#include "dfcxx/io.h"

namespace dfcxx {
    using Direction = dfcxx::DFVariable::Direction;

    IO::IO(Graph &graph, VarBuilder &builder, KernStorage &storage) : graph_(graph),
                                                                      helper_(graph, builder, storage),
                                                                      builder_(builder),
                                                                      storage_(storage) {}

    DFVariable &IO::input(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildStream(name, Direction::INPUT, helper_, type);
        storage_.addVariable(var);
        graph_.addNode(var, OpType::IN, NodeData{});
        return *var;
    }

    DFVariable &IO::inputScalar(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildScalar(name, Direction::INPUT, helper_, type);
        storage_.addVariable(var);
        graph_.addNode(var, OpType::IN, NodeData{});
        return *var;
    }

    DFVariable &IO::output(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildStream(name, Direction::OUTPUT, helper_, type);
        storage_.addVariable(var);
        graph_.addNode(var, OpType::OUT, NodeData{});
        return *var;
    }

    DFVariable &IO::outputScalar(const std::string &name, const DFType &type) {
        DFVariable *var = builder_.buildScalar(name, Direction::OUTPUT, helper_, type);
        storage_.addVariable(var);
        graph_.addNode(var, OpType::OUT, NodeData{});
        return *var;
    }
}