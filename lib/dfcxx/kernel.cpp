#include "dfcxx/kernel.h"

#include <iostream>
#include <fstream>
#include "dfcxx/builders/builder.h"
#include "dfcxx/converter.h"
namespace dfcxx {

    void Kernel::compile(const DFCXXLatencyConfig &config) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        llvm::raw_fd_ostream &out = llvm::outs();
        DFCIRConverter(config).convertAndPrint(compiled, out);
    }

    void Kernel::compile(const DFCXXLatencyConfig &config, const std::string &filePath) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        std::error_code ec;
        llvm::raw_fd_ostream out(filePath, ec);
        DFCIRConverter(config).convertAndPrint(compiled, out);
        out.close();
    }
}
