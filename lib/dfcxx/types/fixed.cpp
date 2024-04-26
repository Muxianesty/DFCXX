#include "dfcxx/types/fixed.h"

namespace dfcxx {
    FixedType::FixedType(SignMode mode, uint8_t int_bits, uint8_t frac_bits) :
                                                                        mode_(mode),
                                                                        int_bits_(int_bits),
                                                                        frac_bits_(frac_bits) {}
    SignMode FixedType::getSign() const {
        return mode_;
    }

    uint8_t FixedType::getIntBits() const {
        return int_bits_;
    }

    uint8_t FixedType::getFracBits() const {
        return frac_bits_;
    }

    uint16_t FixedType::getTotalBits() const {
        return uint16_t(int_bits_) + frac_bits_;
    }

    bool FixedType::operator== (const DFType &rhs) const {
        const FixedType &casted = (const FixedType &)(rhs);
        return mode_ == casted.mode_ && int_bits_ == casted.int_bits_ && frac_bits_ == casted.frac_bits_;
    }

    bool FixedType::isFixed() const {
        return true;
    }

    bool FixedType::isInt() const {
        return frac_bits_ == 0;
    }

    bool FixedType::isSigned() const {
        return mode_ == SignMode::SIGNED;
    }

    bool FixedType::isUnsigned() const {
        return mode_ == SignMode::UNSIGNED;
    }

    bool FixedType::isBool() const {
        return mode_ == SignMode::UNSIGNED && int_bits_ == 1 && frac_bits_ == 0;
    }
}