#ifndef DFCXX_STREAM_H
#define DFCXX_STREAM_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

class VarBuilder;

class DFStream : DFVariable {
  friend VarBuilder;
private:
  const DFType &type;

  DFStream(const std::string &name, Direction direction, GraphHelper &helper,
           const DFType &type);

public:
  ~DFStream() override = default;

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

  bool isStream() override;
};

} // namespace dfcxx

#endif // DFCXX_STREAM_H
