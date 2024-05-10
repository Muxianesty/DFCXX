#ifndef DFCXX_CONST_H
#define DFCXX_CONST_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

class VarBuilder;

class DFConstant : DFVariable {
  friend VarBuilder;

public:
  enum TypeKind : uint8_t {
    INT = 0,
    UINT,
    FLOAT
  };

  union ConstantValue {
    int64_t int_;
    uint64_t uint_;
    double double_;
  };

private:
  const DFType &type;
  TypeKind kind;
  ConstantValue value;

  DFConstant(GraphHelper &helper, const DFType &type, TypeKind kind,
             ConstantValue value);

public:
  ~DFConstant() override = default;

  const DFType &getType() override;

  DFVariable &operator+(DFVariable &rhs) override;

  DFVariable &operator*(DFVariable &rhs) override;

  TypeKind getKind() const;

  int64_t getInt() const;

  uint64_t getUInt() const;

  double getDouble() const;

  bool isConstant() override;
};

} // namespace dfcxx

#endif // DFCXX_CONST_H
