#include "dfcxx/kernel.h"

#include <iostream>
#include <fstream>
#include "dfcxx/IRbuilders/builder.h"
#include "dfcxx/converter.h"

namespace dfcxx {

    Kernel::Kernel() : storage_(), type_builder_(), var_builder_(),
                       graph_(), io(graph_, var_builder_, storage_) { }

    DFType &Kernel::dfUInt(uint8_t bytes) {
        DFType *type = type_builder_.buildFixed(SignMode::UNSIGNED, bytes, 0);
        storage_.addType(type);
        return *type;
    }

    DFType &Kernel::dfInt(uint8_t bytes) {
        DFType *type = type_builder_.buildFixed(SignMode::SIGNED, bytes, 0);
        storage_.addType(type);
        return *type;
    }

    DFType &Kernel::dfBool() {
        DFType *type = type_builder_.buildFixed(SignMode::UNSIGNED, 1, 0);
        storage_.addType(type);
        return *type;
    }

    void Kernel::compile(const DFLatencyConfig &config, const Scheduler &sched) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        llvm::raw_fd_ostream &out = llvm::outs();
        DFCIRConverter(config).convertAndPrint(compiled, out, sched);
    }

    void Kernel::compile(const DFLatencyConfig &config, const std::string &filePath, const Scheduler &sched) {
        DFCIRBuilder builder(config);
        auto compiled = builder.buildModule(this);
        std::error_code ec;
        llvm::raw_fd_ostream out(filePath, ec);
        DFCIRConverter(config).convertAndPrint(compiled, out, sched);
        out.close();
    }
}
