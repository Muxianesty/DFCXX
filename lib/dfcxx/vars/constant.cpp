#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/types/types.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/vars/constant.h"

namespace dfcxx {

DFConstant::DFConstant(GraphHelper &helper, const dfcxx::DFType &type,
                       TypeKind kind, ConstantValue value) :
        DFVariable("", Direction::NONE, helper),
        type(type),
        kind(kind),
        value(value) {}

const DFType &DFConstant::getType() {
  return type;
}

DFVariable &DFConstant::operator+(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ + casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ + casted.value.uint_;
        break;
      case FLOAT:
        val.double_ = value.double_ + casted.value.double_;
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::ADD, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator-(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ - casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ - casted.value.uint_;
        break;
      case FLOAT:
        val.double_ = value.double_ - casted.value.double_;
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::SUB, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator*(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ * casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ * casted.value.uint_;
        break;
      case FLOAT:
        val.double_ = value.double_ * casted.value.double_;
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::MUL, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator/(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ / casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ / casted.value.uint_;
        break;
      case FLOAT:
        val.double_ = value.double_ / casted.value.double_;
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::DIV, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator&(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ & casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ & casted.value.uint_;
        break;
      case FLOAT:
        // TODO: FIX.
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::AND, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator|(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ | casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ | casted.value.uint_;
        break;
      case FLOAT:
        // TODO: FIX.
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::OR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator^(DFVariable &rhs) {
  if (type != rhs.getType()) { throw std::exception(); }
  DFVariable *newVar;
  if (rhs.isConstant()) {
    ConstantValue val{};
    DFConstant &casted = (DFConstant &) (rhs);
    switch (kind) {
      case INT:
        val.int_ = value.int_ | casted.value.int_;
        break;
      case UINT:
        val.uint_ = value.uint_ | casted.value.uint_;
        break;
      case FLOAT:
        // TODO: FIX.
        break;
    }
    newVar = helper.builder.buildConstant(helper, type, kind, val);
  } else {
    newVar = helper.builder.buildStream("", Direction::NONE, helper, type);
  }
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::XOR, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  helper.addChannel(&rhs, newVar, 1, false);
  return *newVar;
}

DFVariable &DFConstant::operator!() {
  DFVariable *newVar;
  ConstantValue val{};
  switch (kind) {
    case INT:
      val.int_ = ~value.int_;
      break;
    case UINT:
      val.uint_ = ~value.uint_;
      break;
    case FLOAT:
      // TODO: FIX.
      break;
  }
  newVar = helper.builder.buildConstant(helper, type, kind, val);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NOT, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

DFVariable &DFConstant::operator-() {
  DFVariable *newVar;
  ConstantValue val{};
  switch (kind) {
    case INT:
      val.int_ = -value.int_;
      break;
    case UINT:
      val.uint_ = -value.uint_;
      break;
    case FLOAT:
      val.double_ = -value.double_;
      break;
  }
  newVar = helper.builder.buildConstant(helper, type, kind, val);
  helper.storage.addVariable(newVar);
  helper.addNode(newVar, OpType::NEG, NodeData{});
  helper.addChannel(this, newVar, 0, false);
  return *newVar;
}

DFConstant::TypeKind DFConstant::getKind() const {
  return kind;
}

int64_t DFConstant::getInt() const {
  return value.int_;
}

uint64_t DFConstant::getUInt() const {
  return value.uint_;
}

double DFConstant::getDouble() const {
  return value.double_;
}

bool DFConstant::isConstant() {
  return true;
}

} // namespace dfcxx