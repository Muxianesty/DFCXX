#include "dfcxx/typebuilders/builder.h"

namespace dfcxx {
    DFType *TypeBuilder::buildFixed(dfcxx::SignMode mode, uint8_t int_bits, uint8_t frac_bits) {
        return new FixedType(mode, int_bits, frac_bits);
    }

    DFType *TypeBuilder::buildFloat(uint8_t exp_bits, uint8_t frac_bits) {
        return new FloatType(exp_bits, frac_bits);
    }
}