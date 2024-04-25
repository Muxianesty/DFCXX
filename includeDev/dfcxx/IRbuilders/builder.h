#ifndef DFCXX_BUILDER_H
#define DFCXX_BUILDER_H

#include "dfcxx/typedefs.h"
#include "dfcxx/kernel.h"
#include "dfcir/DFCIROperations.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Builders.h"

namespace dfcxx {
    class DFCIRBuilder {
    private:
        mlir::MLIRContext _ctx;
        const DFCXXLatencyConfig &_config;
        mlir::OpBuilder _builder;
        mlir::OwningOpRef<mlir::ModuleOp> _module;
    public:
        explicit DFCIRBuilder(const DFCXXLatencyConfig &config);
        mlir::ModuleOp buildModule(Kernel *kern);
    };
}

#endif // DFCXX_BUILDER_H
