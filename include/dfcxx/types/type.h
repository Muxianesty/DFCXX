#ifndef DFCXX_TYPE_H
#define DFCXX_TYPE_H

#include <cstdint>

namespace dfcxx {

class DFType {
public:
  virtual uint16_t getTotalBits() const = 0;

  virtual ~DFType() = default;

  virtual bool operator==(const DFType &rhs) const = 0;

  bool operator!=(const DFType &rhs) const;

  virtual bool isFixed() const;

  virtual bool isFloat() const;
};

} // namespace dfcxx

#endif // DFCXX_TYPE_H
