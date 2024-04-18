#ifndef DFCXX_KERNEL_H
#define DFCXX_KERNEL_H

#include <string>
#include "dfcxx/builders/builder.h"
#include "mlir/IR/BuiltinOps.h"

namespace dfcxx {

    class Kernel {
        friend DFCIRBuilder;
    private:
        mlir::ModuleOp _compile();
    public:
        void compile();
        void compile(const std::string &filePath);
    };

}


#endif // DFCXX_KERNEL_H
