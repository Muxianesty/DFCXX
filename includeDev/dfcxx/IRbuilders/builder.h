#ifndef DFCXX_IR_BUILDER_H
#define DFCXX_IR_BUILDER_H

#include "dfcxx/typedefs.h"
#include "dfcxx/kernel.h"
#include "dfcxx/IRbuilders/converter.h"
#include "dfcir/DFCIROperations.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Builders.h"

#include <stack>

namespace dfcxx {
    class DFCIRBuilder {
    private:
        mlir::MLIRContext ctx_;
        const DFLatencyConfig &config_;
        mlir::OpBuilder builder_;
        std::unordered_map<Node, mlir::Value> map_;
        mlir::OwningOpRef<mlir::ModuleOp> module_;
        DFCIRTypeConverter conv_;

        void buildKernelBody(Graph *graph, mlir::OpBuilder &builder);
        mlir::dfcir::KernelOp buildKernel(Kernel *kern, mlir::OpBuilder &builder);
        mlir::ModuleOp buildModule(Kernel *kern, mlir::OpBuilder &builder);

        std::stack<Node> topSortNodes(Graph *graph);
        void translate(Node node, Graph *graph, mlir::OpBuilder &builder);

    public:
        explicit DFCIRBuilder(const DFLatencyConfig &config);
        mlir::ModuleOp buildModule(Kernel *kern);
    };
}

#endif // DFCXX_IR_BUILDER_H
