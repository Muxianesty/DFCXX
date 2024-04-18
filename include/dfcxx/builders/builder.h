#ifndef DFCXX_BUILDER_H
#define DFCXX_BUILDER_H

#include "mlir/IR/Builders.h"

namespace dfcxx {
    class DFCIRBuilder {
    private:
        mlir::OpBuilder _builder;
    public:
        DFCIRBuilder();
    };
}

#endif // DFCXX_BUILDER_H
