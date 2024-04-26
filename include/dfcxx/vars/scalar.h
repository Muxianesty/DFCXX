#ifndef DFCXX_SCALAR_H
#define DFCXX_SCALAR_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

    class VarBuilder;

    class DFScalar : DFVariable {
        friend VarBuilder;
    private:
        const DFType &type_;

        DFScalar(const std::string &name, Direction direction, GraphHelper &helper, const DFType &type);
    public:
        ~DFScalar() override = default;
        const DFType &getType() override;
        DFVariable &operator+ (DFVariable &rhs) override;
        DFVariable &operator* (DFVariable &rhs) override;
    };
}

#endif // DFCXX_SCALAR_H
