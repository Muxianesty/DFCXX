#include "dfcxx/vars/var.h"

namespace dfcxx {
    DFVariable::DFVariable(const std::string &name, Direction direction, GraphHelper &helper) :
                                                                        name_(name),
                                                                        direction_(direction),
                                                                        helper_(helper) {}

    std::string_view DFVariable::getName() const {
        return name_;
    }

    void DFVariable::connect(dfcxx::DFVariable &connectee) {
        if (getType() != connectee.getType()) { throw std::exception(); }
        // TODO: Add channel creation.
    }
}