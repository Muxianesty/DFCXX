#include "dfcxx/types/float.h"

namespace dfcxx {
    FloatType::FloatType(uint8_t exp_bits, uint8_t frac_bits) : exp_bits_(exp_bits),
                                                                frac_bits_(frac_bits) {}

    uint8_t FloatType::getExpBits() const {
        return exp_bits_;
    }

    uint8_t FloatType::getFracBits() const {
        return frac_bits_;
    }

    uint16_t FloatType::getTotalBits() const {
        return uint16_t(exp_bits_) + frac_bits_;
    }

    bool FloatType::operator== (const DFType &rhs) const {
        const FloatType &casted = (const FloatType &)(rhs);
        return exp_bits_ == casted.exp_bits_ && frac_bits_ == casted.frac_bits_;
    }

}