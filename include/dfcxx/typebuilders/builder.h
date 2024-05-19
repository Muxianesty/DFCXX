#ifndef DFCXX_TYPE_BUILDER_H
#define DFCXX_TYPE_BUILDER_H

#include "dfcxx/types/types.h"

namespace dfcxx {

class TypeBuilder {
public:
  DFType *buildFixed(SignMode mode, uint8_t intBits, uint8_t fracBits);

  DFType *buildBool();

  DFType *buildFloat(uint8_t expBits, uint8_t fracBits);
};

} // namespace dfcxx

#endif // DFCXX_TYPE_BUILDER_H
