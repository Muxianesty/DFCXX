#include "dfcxx/vars/scalar.h"

namespace dfcxx {
    DFScalar::DFScalar(const std::string &name, Direction direction, const dfcxx::DFType &type) :
            DFVariable(name, direction),
            type_(type) {}

    const DFType &DFScalar::getType() {
        return type_;
    }
}