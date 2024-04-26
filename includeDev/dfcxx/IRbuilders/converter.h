#ifndef DFCXX_IR_BUILDER_CONVERTER_H
#define DFCXX_IR_BUILDER_CONVERTER_H

#include "dfcxx/typedefs.h"
#include "dfcxx/kernel.h"
#include "dfcir/DFCIROperations.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Builders.h"

namespace dfcxx {
    class DFCIRTypeConverter {
        mlir::MLIRContext *ctx_;

    public:
        DFCIRTypeConverter(mlir::MLIRContext *ctx);
        mlir::Type operator[](DFVariable *var);
    };
}

#endif // DFCXX_IR_BUILDER_CONVERTER_H
