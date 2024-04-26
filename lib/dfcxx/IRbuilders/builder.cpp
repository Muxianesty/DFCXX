#include "dfcxx/IRbuilders/builder.h"

#include "mlir/Parser/Parser.h"
#include "circt/Dialect/FIRRTL/FIRRTLDialect.h"
#include "circt/Dialect/SV/SVDialect.h"

namespace dfcxx {
    DFCIRBuilder::DFCIRBuilder(const DFLatencyConfig &config) : ctx_(),
                                                                config_(config),
                                                                builder_(&ctx_),
                                                                conv_(&ctx_) {
        // We are allowed to initialize '_builder'-field before loading
        // dialects as OpBuilder only stores the pointer to MLIRContext
        // and doesn't check any of its state.
        ctx_.getOrLoadDialect<mlir::dfcir::DFCIRDialect>();
        ctx_.getOrLoadDialect<mlir::dfcir::DFCIRDialect>();
        ctx_.getOrLoadDialect<circt::firrtl::FIRRTLDialect>();
        ctx_.getOrLoadDialect<circt::sv::SVDialect>();
    }

    void DFCIRBuilder::buildKernelBody(Graph *graph, mlir::OpBuilder &builder) {
        std::stack<Node> sorted = topSortNodes(graph);

        while (!sorted.empty()) {
            Node node = sorted.top();
            sorted.pop();
            translate(node, graph, builder);
        }
    }

    mlir::dfcir::KernelOp DFCIRBuilder::buildKernel(dfcxx::Kernel *kern, mlir::OpBuilder &builder) {
        auto kernel = builder.create<mlir::dfcir::KernelOp>(builder.getUnknownLoc(), kern->getName());
        builder.setInsertionPointToStart(&kernel.getBody().emplaceBlock());
        buildKernelBody(&kern->graph_, builder);
        return kernel;
    }

    mlir::ModuleOp DFCIRBuilder::buildModule(dfcxx::Kernel *kern, mlir::OpBuilder &builder) {
        auto module = builder.create<mlir::ModuleOp>(builder.getUnknownLoc());
        builder.setInsertionPointToStart(module.getBody());
        buildKernel(kern, builder);
        return module;
    }

    mlir::ModuleOp DFCIRBuilder::buildModule(dfcxx::Kernel *kern) {

        assert(ctx_.getLoadedDialect<mlir::dfcir::DFCIRDialect>() != nullptr);

        mlir::OpBuilder builder(&ctx_);
        module_ = buildModule(kern, builder);

        // !!!!!!!!!!DEBUG!!!!!!!!!!
        // TODO: Remove in further updates.
        //module_ = mlir::parseSourceFile<mlir::ModuleOp>("/home/muxianesty/_test/simple.mlir", &ctx_);
        return module_.get();
    }
}