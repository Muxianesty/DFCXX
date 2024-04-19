#include "dfcxx/converter.h"
#include "mlir/Pass/PassManager.h"
#include "circt/Conversion/Passes.h"

namespace dfcxx {

    DFCIRConverter::DFCIRConverter(const DFCXXLatencyConfig &config) {
        _config = LatencyConfig();
        for (auto [op, latency] : config) {
            _config[static_cast<mlir::dfcir::Ops>(op)] = latency;
        }
        _config[mlir::dfcir::UNDEFINED] = 0;
    }

    void DFCIRConverter::convertAndPrint(mlir::ModuleOp module, llvm::raw_fd_ostream &out) {
        mlir::MLIRContext *context = module.getContext();
        mlir::PassManager pm(context);
        pm.addPass(mlir::dfcir::createDFCIRToFIRRTLPass(&_config));
        pm.addPass(mlir::dfcir::createDFCIRLinearSchedulerPass());
        pm.addPass(circt::createLowerFIRRTLToHWPass());
        pm.addPass(circt::createLowerSeqToSVPass());
        pm.addPass(circt::createExportVerilogPass(out));
        auto result = pm.run(module);
        assert(result.succeeded());
    }
}