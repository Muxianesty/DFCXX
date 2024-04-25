#include "dfcxx/var.h"

namespace dfcxx {
    DataflowVariable::DataflowVariable(const std::string &name) : name_(name) {}

    std::string_view DataflowVariable::getName() const {
        return name_;
    }

    Stream::Stream(const std::string &name, const dfcxx::DataflowType &type) :
                                                            DataflowVariable(name),
                                                            type_(type) {}

    const DataflowType &Stream::getType() {
        return type_;
    }
}