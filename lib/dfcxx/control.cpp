#include "dfcxx/control.h"
#include "dfcxx/vars/vars.h"

namespace dfcxx {

using Direction = dfcxx::DFVariable::Direction;
using ConstantValue = dfcxx::DFConstant::ConstantValue;

Control::Control(Graph &graph, VarBuilder &builder, KernStorage &storage) :
        graph(graph),
        helper(graph, builder, storage),
        builder(builder),
        storage(storage) {}

DFVariable &Control::mux(DFVariable &ctrl, DFVariable &var1, DFVariable &var2) {
  if (var1.getType() != var2.getType()) { throw std::exception(); }
  DFVariable *var = nullptr;
  if (var1.isConstant()) {
    var = helper.builder.buildConstant(helper, var1.getType(),
                                       ((DFConstant &) (var1)).getKind(),
                                       ConstantValue{});
  } else if (var1.isScalar()) {
    var = helper.builder.buildScalar("", Direction::NONE, helper,
                                     var1.getType());
  } else if (var1.isStream()) {
    var = helper.builder.buildStream("", Direction::NONE, helper,
                                     var1.getType());
  }

  storage.addVariable(var);
  graph.addNode(var, OpType::MUX, NodeData{.muxId = 0});
  graph.addChannel(&ctrl, var, 0, false);
  graph.addChannel(&var1, var, 1, false);
  graph.addChannel(&var2, var, 2, false);
  return *var;
}

} // namespace dfcxx