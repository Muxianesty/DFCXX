#ifndef DFCXX_FIXED_H
#define DFCXX_FIXED_H

#include "dfcxx/types/type.h"

namespace dfcxx {

    enum SignMode {
        UNSIGNED = 0,
        SIGNED
    };

    class TypeBuilder;

    class FixedType : DFType {
        friend TypeBuilder;
    private:
        SignMode mode_;
        uint8_t int_bits_;
        uint8_t frac_bits_;

        FixedType(SignMode mode, uint8_t int_bits, uint8_t frac_bits);
    public:
        SignMode getSign() const;
        uint8_t getIntBits() const;
        uint8_t getFracBits() const;
        uint16_t getTotalBits() const override;
        ~FixedType() override = default;

        bool operator== (const DFType &rhs) const override;

        bool isInt() const;
        bool isSigned() const;
        bool isUnsigned() const;
        bool isBool() const;
    };
}

#endif // DFCXX_FIXED_H
