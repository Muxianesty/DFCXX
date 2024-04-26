#ifndef DFCXX_TYPE_BUILDER_H
#define DFCXX_TYPE_BUILDER_H

#include "dfcxx/types/types.h"

namespace dfcxx {
    class TypeBuilder {
    public:
        DFType *buildFixed(SignMode mode, uint8_t int_bits, uint8_t frac_bits);
        DFType *buildFloat(uint8_t exp_bits, uint8_t frac_bits);
    };
}

#endif // DFCXX_TYPE_BUILDER_H
