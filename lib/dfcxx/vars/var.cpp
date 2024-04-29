#include "dfcxx/vars/var.h"

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {
    DFVariable::DFVariable(const std::string &name, Direction direction, GraphHelper &helper) :
                                                                        name_(name),
                                                                        direction_(direction),
                                                                        helper_(helper) {}

    std::string_view DFVariable::getName() const {
        return name_;
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
        helper_.addChannel(&connectee, this, 0, true);
    }
}