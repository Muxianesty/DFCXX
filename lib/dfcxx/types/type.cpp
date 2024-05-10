#include "dfcxx/types/type.h"

namespace dfcxx {

bool DFType::operator!=(const DFType &rhs) const {
  return !(*this == rhs);
}

bool DFType::isFixed() const {
  return false;
}

bool DFType::isFloat() const {
  return false;
}

} // namespace dfcxx