#include "dfcxx/vars/constant.h"

#include "dfcxx/types/types.h"
#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {
    DFConstant::DFConstant(GraphHelper &helper, const dfcxx::DFType &type, TypeKind kind, ConstantValue value) :
                                                               DFVariable("", Direction::NONE, helper),
                                                               type_(type),
                                                               kind_(kind),
                                                               value_(value) {}

    const DFType &DFConstant::getType() {
        return type_;
    }

    DFVariable &DFConstant::operator+(DFVariable &rhs) {
        if (type_ != rhs.getType()) { throw std::exception(); }
        DFVariable *newVar;
        if (rhs.isConstant()) {
            ConstantValue val{};
            DFConstant &casted = (DFConstant&)(rhs);
            switch (kind_) {
                case INT: val.int_ = value_.int_ + casted.value_.int_; break;
                case UINT: val.uint_ = value_.uint_ + casted.value_.uint_; break;
                case FLOAT: val.double_ = value_.double_ + casted.value_.double_; break;
            }
            newVar = helper_.builder_.buildConstant(helper_, type_, kind_, val);
        } else {
            newVar = helper_.builder_.buildStream("", Direction::NONE, helper_, type_);
        }
        helper_.storage_.addVariable(newVar);
        helper_.addNode(newVar, OpType::ADD, NodeData{});
        helper_.addChannel(this, newVar, 0, false);
        helper_.addChannel(&rhs, newVar, 1, false);
        return *newVar;
    }

    DFVariable &DFConstant::operator*(DFVariable &rhs) {
        if (type_ != rhs.getType()) { throw std::exception(); }
        DFVariable *newVar;
        if (rhs.isConstant()) {
            ConstantValue val{};
            DFConstant &casted = (DFConstant&)(rhs);
            switch (kind_) {
                case INT: val.int_ = value_.int_ + casted.value_.int_; break;
                case UINT: val.uint_ = value_.uint_ + casted.value_.uint_; break;
                case FLOAT: val.double_ = value_.double_ + casted.value_.double_; break;
            }
            newVar = helper_.builder_.buildConstant(helper_, type_, kind_, val);
        } else {
            newVar = helper_.builder_.buildStream("", Direction::NONE, helper_, type_);
        }
        helper_.storage_.addVariable(newVar);
        helper_.addNode(newVar, OpType::MUL, NodeData{});
        helper_.addChannel(this, newVar, 0, false);
        helper_.addChannel(&rhs, newVar, 1, false);
        return *newVar;
    }

    DFConstant::TypeKind DFConstant::getKind() const {
        return kind_;
    }

    int64_t DFConstant::getInt() const {
        return value_.int_;
    }

    uint64_t DFConstant::getUInt() const {
        return value_.uint_;
    }

    double DFConstant::getDouble() const {
        return value_.double_;
    }

    bool DFConstant::isConstant() {
        return true;
    }

}