#include "dfcxx/varbuilders/builder.h"

using Direction = dfcxx::DFVariable::Direction;
using TypeKind = dfcxx::DFConstant::TypeKind;
using ConstantValue = dfcxx::DFConstant::ConstantValue;

namespace dfcxx {

DFVariable *
VarBuilder::buildStream(const std::string &name, Direction direction,
                        GraphHelper &helper, const DFType &type) {
  return new DFStream(name, direction, helper, type);
}

DFVariable *
VarBuilder::buildScalar(const std::string &name, Direction direction,
                        GraphHelper &helper, const DFType &type) {
  return new DFScalar(name, direction, helper, type);
}

DFVariable *VarBuilder::buildConstant(GraphHelper &helper, const DFType &type,
                                      TypeKind kind, ConstantValue value) {
  return new DFConstant(helper, type, kind, value);
}

} // namespace dfcxx