#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/vars/scalar.h"

namespace dfcxx {

DFScalar::DFScalar(const std::string &name, Direction direction,
                   GraphHelper &helper, const dfcxx::DFType &type) :
        DFVariable(name, direction, helper),
        type(type) {}

const DFType &DFScalar::getType() {
  return type;
}

DFVariable &DFScalar::operator+(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::ADD, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator-(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::SUB, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator*(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MUL, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator/(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::DIV, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator&(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::AND, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator|(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::OR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator^(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::XOR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFScalar::operator!() {
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NOT, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

DFVariable &DFScalar::operator-() {
  DFVariable *newVar = helper.builder.buildStream("", Direction::NONE, helper,
                                                  type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NEG, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

bool DFScalar::isScalar() {
  return true;
}

} // namespace dfcxx