#ifndef DFCXX_SCALAR_H
#define DFCXX_SCALAR_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

class VarBuilder;

class DFScalar : DFVariable {
  friend VarBuilder;
private:
  const DFType &type;

  DFScalar(const std::string &name, Direction direction, GraphHelper &helper,
           const DFType &type);

public:
  ~DFScalar() override = default;

  const DFType &getType() override;

  DFVariable &operator+(DFVariable &rhs) override;

  DFVariable &operator-(DFVariable &rhs) override;

  DFVariable &operator*(DFVariable &rhs) override;

  DFVariable &operator/(DFVariable &rhs) override;

  DFVariable &operator&(DFVariable &rhs) override;

  DFVariable &operator|(DFVariable &rhs) override;

  DFVariable &operator^(DFVariable &rhs) override;

  DFVariable &operator!() override;

  DFVariable &operator-() override;

  DFVariable &operator<(DFVariable &rhs) override;

  DFVariable &operator<=(DFVariable &rhs) override;

  DFVariable &operator>(DFVariable &rhs) override;

  DFVariable &operator>=(DFVariable &rhs) override;

  DFVariable &operator==(DFVariable &rhs) override;

  DFVariable &operator!=(DFVariable &rhs) override;

  bool isScalar() override;
};

} // namespace dfcxx

#endif // DFCXX_SCALAR_H
