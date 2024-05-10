#include "dfcxx/typebuilders/builder.h"

namespace dfcxx {

DFType *TypeBuilder::buildFixed(dfcxx::SignMode mode, uint8_t intBits,
                                uint8_t fracBits) {
  return new FixedType(mode, intBits, fracBits);
}

DFType *TypeBuilder::buildFloat(uint8_t expBits, uint8_t fracBits) {
  return new FloatType(expBits, fracBits);
}

} // namespace dfcxx