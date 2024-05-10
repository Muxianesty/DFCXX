#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/vars/stream.h"

namespace dfcxx {

DFStream::DFStream(const std::string &name, Direction direction,
                   GraphHelper &helper, const dfcxx::DFType &type) :
        DFVariable(name, direction, helper),
        type(type) {}

const DFType &DFStream::getType() {
  return type;
}

DFVariable &DFStream::operator+(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::ADD, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator*(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MUL, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

bool DFStream::isStream() {
  return true;
}

} // namespace dfcxx