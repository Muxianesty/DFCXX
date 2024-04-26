#include "dfcxx/vars/var.h"

namespace dfcxx {
    DFVariable::DFVariable(const std::string &name, Direction direction) : name_(name), direction_(direction) {}

    std::string_view DFVariable::getName() const {
        return name_;
    }
}