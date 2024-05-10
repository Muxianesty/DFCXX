#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/vars/var.h"

namespace dfcxx {

DFVariable::DFVariable(const std::string &name, Direction direction,
                       GraphHelper &helper) :
        name(name),
        direction(direction),
        helper(helper) {}

std::string_view DFVariable::getName() const {
  return name;
}

bool DFVariable::isStream() {
  return false;
}

bool DFVariable::isScalar() {
  return false;
}

bool DFVariable::isConstant() {
  return false;
}

void DFVariable::connect(dfcxx::DFVariable &connectee) {
  if (getType() != connectee.getType()) { throw std::exception(); }
  helper.addChannel(&connectee, this, 0, true);
}

} // namespace dfcxx