#ifndef DFCXX_CONVERTER_H
#define DFCXX_CONVERTER_H

#include <string>
#include "dfcxx/typedefs.h"
#include "dfcir/conversions/DFCIRPasses.h"
#include "mlir/IR/BuiltinOps.h"

namespace dfcxx {
    class DFCIRConverter {
    private:
        LatencyConfig _config;
    public:
        explicit DFCIRConverter(const DFLatencyConfig &config);
        void convertAndPrint(mlir::ModuleOp module, llvm::raw_fd_ostream &out, const Scheduler &sched);
    };
}

#endif // DFCXX_CONVERTER_H
