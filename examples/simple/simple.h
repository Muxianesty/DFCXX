#ifndef DFCXX_SIMPLE_H
#define DFCXX_SIMPLE_H

#include "dfcxx/DFCXX.h"

class SimpleKernel : public dfcxx::Kernel {
public:
  std::string_view getName() override {
    return "SimpleKernel";
  }

  ~SimpleKernel() override = default;

  SimpleKernel() : dfcxx::Kernel() {
    using dfcxx::DFType;
    using dfcxx::DFVariable;

    const DFType &type = dfUInt(32);
    DFVariable &x = io.input("x", type);
    DFVariable &square = x * x;
    DFVariable &result = square + x;
    DFVariable &test = result + x;
    DFVariable &out = io.output("out", type);
    out.connect(test);
  }

};

#endif // DFCXX_SIMPLE_H
