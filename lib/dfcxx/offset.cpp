#include "dfcxx/offset.h"
#include "dfcxx/vars/vars.h"

namespace dfcxx {

using Direction = dfcxx::DFVariable::Direction;
using ConstantValue = dfcxx::DFConstant::ConstantValue;

Offset::Offset(Graph &graph, VarBuilder &builder, KernStorage &storage) :
        graph(graph),
        helper(graph, builder, storage),
        builder(builder),
        storage(storage) {}

DFVariable &Offset::operator()(DFVariable &stream, int64_t offset) {
  if (!stream.isStream()) { throw std::exception(); }
  DFVariable *var = builder.buildStream("", Direction::NONE, helper,
                                        stream.getType());
  storage.addVariable(var);
  graph.addNode(var, OpType::OFFSET, NodeData{.offset = offset});
  graph.addChannel(&stream, var, 0, false);
  return *var;
}

} // namespace dfcxx