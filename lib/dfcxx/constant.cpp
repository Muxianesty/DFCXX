#include "dfcxx/constant.h"

namespace dfcxx {

using TypeKind = dfcxx::DFConstant::TypeKind;
using ConstantValue = dfcxx::DFConstant::ConstantValue;

Constant::Constant(Graph &graph, TypeBuilder &typeBuilder,
                   VarBuilder &varBuilder, KernStorage &storage) : graph(graph),
                   helper(graph, typeBuilder, varBuilder, storage),
                   varBuilder(varBuilder), storage(storage) {}

DFVariable &Constant::var(const DFType &type, int64_t value) {
  DFVariable *var = varBuilder.buildConstant(helper, type, TypeKind::INT,
                                             ConstantValue{.int_ = value});
  storage.addVariable(var);
  graph.addNode(var, OpType::CONST, NodeData{});
  return *var;
}

DFVariable &Constant::var(const DFType &type, uint64_t value) {
  DFVariable *var = varBuilder.buildConstant(helper, type, TypeKind::UINT,
                                             ConstantValue{.uint_ = value});
  storage.addVariable(var);
  graph.addNode(var, OpType::CONST, NodeData{});
  return *var;
}

DFVariable &Constant::var(const DFType &type, double value) {
  DFVariable *var = varBuilder.buildConstant(helper, type, TypeKind::FLOAT,
                                             ConstantValue{.double_ = value});
  storage.addVariable(var);
  graph.addNode(var, OpType::CONST, NodeData{});
  return *var;
}

} // namespace dfcxx