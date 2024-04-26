#ifndef DFCXX_VAR_BUILDER_H
#define DFCXX_VAR_BUILDER_H

#include "dfcxx/vars/vars.h"

namespace dfcxx {
    class VarBuilder {
    public:
        DFVariable *buildStream(const std::string &name, Direction direction, const DFType &type);
        DFVariable *buildScalar(const std::string &name, Direction direction, const DFType &type);
    };
}

#endif // DFCXX_VAR_BUILDER_H
