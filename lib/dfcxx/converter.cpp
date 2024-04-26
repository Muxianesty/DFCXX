#include "dfcxx/converter.h"
#include "mlir/Pass/PassManager.h"
#include "circt/Conversion/Passes.h"

namespace dfcxx {
    DFCIRConverter::DFCIRConverter(const DFLatencyConfig &config) {
        _config = LatencyConfig();
        for (auto [op, latency] : config) {
            _config[static_cast<mlir::dfcir::Ops>(op)] = latency;
        }
        _config[mlir::dfcir::UNDEFINED] = 0;
    }

    void DFCIRConverter::convertAndPrint(mlir::ModuleOp module, llvm::raw_fd_ostream &out, const Scheduler &sched) {
        mlir::MLIRContext *context = module.getContext();
        mlir::PassManager pm(context);
        pm.addPass(mlir::dfcir::createDFCIRToFIRRTLPass(&_config));
        switch (sched) {
            case Linear: pm.addPass(mlir::dfcir::createDFCIRLinearSchedulerPass()); break;
            case Dijkstra: pm.addPass(mlir::dfcir::createDFCIRDijkstraSchedulerPass()); break;
        }
        pm.addPass(circt::createLowerFIRRTLToHWPass());
        pm.addPass(circt::createLowerSeqToSVPass());
        pm.addPass(circt::createExportVerilogPass(out));
        auto result = pm.run(module);
        assert(result.succeeded());
    }
}