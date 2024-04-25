#include "dfcxx/IRbuilders/builder.h"

#include "mlir/Parser/Parser.h"
#include "circt/Dialect/FIRRTL/FIRRTLDialect.h"
#include "circt/Dialect/SV/SVDialect.h"

namespace dfcxx {
    DFCIRBuilder::DFCIRBuilder(const DFCXXLatencyConfig &config) : _ctx(),
                                                                   _config(config),
                                                                   _builder(&_ctx) {
        // We are allowed to initialize '_builder'-field before loading
        // dialects as OpBuilder only stores the pointer to MLIRContext
        // and doesn't check any of its state.
        _ctx.getOrLoadDialect<mlir::dfcir::DFCIRDialect>();
        _ctx.getOrLoadDialect<mlir::dfcir::DFCIRDialect>();
        _ctx.getOrLoadDialect<circt::firrtl::FIRRTLDialect>();
        _ctx.getOrLoadDialect<circt::sv::SVDialect>();
    }

    mlir::ModuleOp DFCIRBuilder::buildModule(dfcxx::Kernel *kern) {
        assert(_ctx.getLoadedDialect<mlir::dfcir::DFCIRDialect>() != nullptr);
        // !!!!!!!!!!TEMPORARY!!!!!!!!!!
        // TODO: Remove in further updates.
        _module = mlir::parseSourceFile<mlir::ModuleOp>("/home/muxianesty/_test/scalar3.mlir", &_ctx);
        return _module.get();
    }
}