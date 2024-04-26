#ifndef DFCXX_IR_BUILDER_H
#define DFCXX_IR_BUILDER_H

#include "dfcxx/typedefs.h"
#include "dfcxx/kernel.h"
#include "dfcir/DFCIROperations.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Builders.h"

namespace dfcxx {
    class DFCIRBuilder {
    private:
        mlir::MLIRContext _ctx;
        const DFLatencyConfig &_config;
        mlir::OpBuilder _builder;
        mlir::OwningOpRef<mlir::ModuleOp> _module;
    public:
        explicit DFCIRBuilder(const DFLatencyConfig &config);
        mlir::ModuleOp buildModule(Kernel *kern);
    };
}

#endif // DFCXX_IR_BUILDER_H
