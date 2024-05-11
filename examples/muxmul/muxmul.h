#ifndef DFCXX_MUXMUL_H
#define DFCXX_MUXMUL_H

#include "dfcxx/DFCXX.h"

class MuxMul : public dfcxx::Kernel {
public:
  std::string_view getName() override {
    return "MuxMul";
  }

  ~MuxMul() override = default;

  MuxMul() : dfcxx::Kernel() {
    using dfcxx::DFType;
    using dfcxx::DFVariable;

    const DFType &type = dfUInt(32);
    const DFType &ctrl_type = dfUInt(1);
    DFVariable &x = io.input("x", type);
    DFVariable &ctrl = io.input("ctrl", ctrl_type);
    DFVariable &c1 = constant.var(type, uint64_t(0));
    DFVariable &c2 = constant.var(type, uint64_t(1));
    DFVariable &muxed = control.mux(ctrl, c1, c2);
    DFVariable &sum = x + x;
    DFVariable &product = sum * muxed;
    DFVariable &out = io.output("out", type);
    out.connect(product);
  }

};

#endif // DFCXX_MUXMUL_H
