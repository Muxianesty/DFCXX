#ifndef DFCXX_ADDCONST_H
#define DFCXX_ADDCONST_H

#include "dfcxx/DFCXX.h"

class AddConst : public dfcxx::Kernel {
public:
  std::string_view getName() override {
    return "AddConst";
  }

  ~AddConst() override = default;

  AddConst() : dfcxx::Kernel() {
    using dfcxx::DFType;
    using dfcxx::DFVariable;

    const DFType &type = dfUInt(32);
    DFVariable &x = io.input("x", type);
    DFVariable &const5 = constant.var(type, uint64_t(5));
    DFVariable &sum1 = x + const5;
    DFVariable &sum2 = sum1 + x;
    DFVariable &out = io.output("out", type);
    out.connect(sum2);
  }

};

#endif // DFCXX_ADDCONST_H
