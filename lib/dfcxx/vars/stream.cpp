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
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::ADD, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator-(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::SUB, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator*(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MUL, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator/(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::DIV, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator&(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::AND, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator|(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::OR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator^(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::XOR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator!() {
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NOT, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

DFVariable &DFStream::operator-() {
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     type);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NEG, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

DFVariable &DFStream::operator<(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::LESS, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator<=(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::LESS_EQ, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator>(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MORE, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator>=(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MORE_EQ, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator==(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::EQ, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFStream::operator!=(dfcxx::DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFType *newType = helper.typeBuilder.buildBool();
  helper.storage.addType(newType);
  DFVariable *newVar = helper.varBuilder.buildStream("", Direction::NONE, helper,
                                                     *newType);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NEQ, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

bool DFStream::isStream() {
  return true;
}

} // namespace dfcxx