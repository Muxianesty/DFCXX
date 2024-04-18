#include "dfcxx/kernel.h"

#include <fstream>
#include <iostream>

namespace dfcxx {

    mlir::ModuleOp Kernel::_compile() {
        DFCIRBuilder builder;
        return nullptr;
    }

    void Kernel::compile() {
        auto compiled = _compile();
        compiled->dump();
    }

    void Kernel::compile(const std::string &filePath) {
        auto compiled = _compile();
        std::error_code ec;
        llvm::raw_fd_ostream out(filePath, ec);
        compiled.print(out);
        out.close();
    }
}
