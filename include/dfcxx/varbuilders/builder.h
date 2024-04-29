#ifndef DFCXX_VAR_BUILDER_H
#define DFCXX_VAR_BUILDER_H

#include "dfcxx/vars/vars.h"

namespace dfcxx {
    class VarBuilder {
        using Direction = dfcxx::DFVariable::Direction;
        using TypeKind = dfcxx::DFConstant::TypeKind;
        using ConstantValue = dfcxx::DFConstant::ConstantValue;

    public:
        DFVariable *buildStream(const std::string &name, Direction direction, GraphHelper &helper, const DFType &type);
        DFVariable *buildScalar(const std::string &name, Direction direction, GraphHelper &helper, const DFType &type);
        DFVariable *buildConstant(GraphHelper &helper, const DFType &type, TypeKind kind, ConstantValue value);
    };
}

#endif // DFCXX_VAR_BUILDER_H
