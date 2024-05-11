#ifndef DFCXX_MOVINGSUM_H
#define DFCXX_MOVINGSUM_H

#include "dfcxx/DFCXX.h"

class MovingSum : public dfcxx::Kernel {
public:
  std::string_view getName() override {
    return "MovingSum";
  }

  ~MovingSum() override = default;

  MovingSum() : dfcxx::Kernel() {
    using dfcxx::DFType;
    using dfcxx::DFVariable;

    const DFType &type = dfUInt(32);
    DFVariable &x = io.input("x", type);
    DFVariable &x_minus = offset(x, -1);
    DFVariable &x_plus = offset(x, 1);
    DFVariable &sum1 = x_minus + x;
    DFVariable &sum2 = sum1 + x_plus;
    DFVariable &out = io.output("out", type);
    out.connect(sum2);
  }

};

#endif // DFCXX_MOVINGSUM_H
