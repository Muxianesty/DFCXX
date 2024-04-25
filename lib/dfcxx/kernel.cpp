#include "dfcxx/kernel.h"

#include <iostream>
#include <fstream>
#include "dfcxx/IRbuilders/builder.h"
#include "dfcxx/converter.h"

namespace dfcxx {
    void Kernel::compile(const DFCXXLatencyConfig &config, const Scheduler &sched) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        llvm::raw_fd_ostream &out = llvm::outs();
        DFCIRConverter(config).convertAndPrint(compiled, out, sched);
    }

    void Kernel::compile(const DFCXXLatencyConfig &config, const std::string &filePath, const Scheduler &sched) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        std::error_code ec;
        llvm::raw_fd_ostream out(filePath, ec);
        DFCIRConverter(config).convertAndPrint(compiled, out, sched);
        out.close();
    }
}
