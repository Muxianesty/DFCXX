#include "dfcxx/io.h"

namespace dfcxx {

using Direction = dfcxx::DFVariable::Direction;

IO::IO(Graph &graph, VarBuilder &builder, KernStorage &storage)
                                                          : graph(graph),
                                                            helper(graph,
                                                                   builder,
                                                                   storage),
                                                            builder(builder),
                                                            storage(storage) {}

DFVariable &IO::input(const std::string &name, const DFType &type) {
  DFVariable *var = builder.buildStream(name, Direction::INPUT, helper, type);
  storage.addVariable(var);
  graph.addNode(var, OpType::IN, NodeData{});
  return *var;
}

DFVariable &IO::inputScalar(const std::string &name, const DFType &type) {
  DFVariable *var = builder.buildScalar(name, Direction::INPUT, helper, type);
  storage.addVariable(var);
  graph.addNode(var, OpType::IN, NodeData{});
  return *var;
}

DFVariable &IO::output(const std::string &name, const DFType &type) {
  DFVariable *var = builder.buildStream(name, Direction::OUTPUT, helper, type);
  storage.addVariable(var);
  graph.addNode(var, OpType::OUT, NodeData{});
  return *var;
}

DFVariable &IO::outputScalar(const std::string &name, const DFType &type) {
  DFVariable *var = builder.buildScalar(name, Direction::OUTPUT, helper, type);
  storage.addVariable(var);
  graph.addNode(var, OpType::OUT, NodeData{});
  return *var;
}

} // namespace dfcxx