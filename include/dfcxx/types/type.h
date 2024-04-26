#ifndef DFCXX_TYPE_H
#define DFCXX_TYPE_H

#include <cstdint>


namespace dfcxx {
    class DFType {
    public:
        virtual uint16_t getTotalBits() const = 0;
        virtual ~DFType() = default;
    };
}

#endif // DFCXX_TYPE_H
