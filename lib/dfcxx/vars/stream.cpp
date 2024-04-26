#include "dfcxx/vars/stream.h"

namespace dfcxx {
    DFStream::DFStream(const std::string &name, Direction direction, const dfcxx::DFType &type) :
            DFVariable(name, direction),
            type_(type) {}

    const DFType &DFStream::getType() {
        return type_;
    }
}