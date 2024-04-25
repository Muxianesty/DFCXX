#ifndef DFCXX_FLOAT_H
#define DFCXX_FLOAT_H

#include "dfcxx/types/type.h"

namespace dfcxx {

    class FloatType : DataflowType {
    private:
        uint8_t exp_bits_;
        uint8_t frac_bits_;

        FloatType(uint8_t exp_bits, uint8_t frac_bits);
    public:
        uint8_t getExpBits() const;
        uint8_t getFracBits() const;
        uint16_t getTotalBits() const override;
        ~FloatType() override = default;
    };
}

#endif // DFCXX_FLOAT_H
