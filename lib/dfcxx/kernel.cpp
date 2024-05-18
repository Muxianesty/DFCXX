#include "dfcxx/converter.h"
#include "dfcxx/IRbuilders/builder.h"
#include "dfcxx/kernel.h"

#include <iostream>

namespace dfcxx {

Kernel::Kernel() : storage(), typeBuilder(), varBuilder(),
                   graph(), io(graph, varBuilder, storage),
                   offset(graph, varBuilder, storage),
                   constant(graph, varBuilder, storage),
                   control(graph, varBuilder, storage) {}

DFType &Kernel::dfUInt(uint8_t bits) {
  DFType *type = typeBuilder.buildFixed(SignMode::UNSIGNED, bits, 0);
  storage.addType(type);
  return *type;
}

DFType &Kernel::dfInt(uint8_t bits) {
  DFType *type = typeBuilder.buildFixed(SignMode::SIGNED, bits, 0);
  storage.addType(type);
  return *type;
}

DFType &Kernel::dfFloat(uint8_t expBits, uint8_t fracBits) {
  DFType *type = typeBuilder.buildFloat(expBits, fracBits);
  storage.addType(type);
  return *type;
}

DFType &Kernel::dfBool() {
  DFType *type = typeBuilder.buildFixed(SignMode::UNSIGNED, 1, 0);
  storage.addType(type);
  return *type;
}

void Kernel::compile(const DFLatencyConfig &config, const Scheduler &sched) {
  DFCIRBuilder builder(config);
  auto compiled = builder.buildModule(this);
  llvm::raw_fd_ostream &out = llvm::outs();
  DFCIRConverter(config).convertAndPrint(compiled, out, sched);
}

void Kernel::compile(const DFLatencyConfig &config, const std::string &filePath,
                     const Scheduler &sched) {
  DFCIRBuilder builder(config);
  auto compiled = builder.buildModule(this);
  std::error_code ec;
  llvm::raw_fd_ostream out(filePath, ec);
  DFCIRConverter(config).convertAndPrint(compiled, out, sched);
  out.close();
}

} // namespace dfcxx
