#include "dfcxx/varbuilders/builder.h"

namespace dfcxx {
    DFVariable *VarBuilder::buildStream(const std::string &name, Direction direction, GraphHelper &helper, const DFType &type) {
        return new DFStream(name, direction, helper, type);
    }

    DFVariable *VarBuilder::buildScalar(const std::string &name, Direction direction, GraphHelper &helper, const DFType &type) {
        return new DFScalar(name, direction, helper, type);
    }
}