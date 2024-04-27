#include "dfcxx/vars/scalar.h"

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {
    DFScalar::DFScalar(const std::string &name, Direction direction, GraphHelper &helper, const dfcxx::DFType &type) :
            DFVariable(name, direction, helper),
            type_(type) {}

    const DFType &DFScalar::getType() {
        return type_;
    }

    DFVariable &DFScalar::operator+(DFVariable &rhs) {
        if (type_ != rhs.getType()) { throw std::exception(); }
        DFVariable *newVar = helper_.builder_.buildStream("", Direction::NONE, helper_, type_);
        helper_.storage_.addVariable(newVar);
        helper_.addNode(newVar, OpType::ADD, NodeData{});
        helper_.addChannel(this, newVar, 0, false);
        helper_.addChannel(&rhs, newVar, 1, false);
        return *newVar;
    }

    DFVariable &DFScalar::operator*(DFVariable &rhs) {
        if (type_ != rhs.getType()) { throw std::exception(); }
        DFVariable *newVar = helper_.builder_.buildStream("", Direction::NONE, helper_, type_);
        helper_.storage_.addVariable(newVar);
        helper_.addNode(newVar, OpType::MUL, NodeData{});
        helper_.addChannel(this, newVar, 0, false);
        helper_.addChannel(&rhs, newVar, 1, false);
        return *newVar;
    }

    bool DFScalar::isScalar() {
        return true;
    }
}