#ifndef DFCXX_TYPE_H
#define DFCXX_TYPE_H

#include <cstdint>


namespace dfcxx {
    class DataflowType {
    public:
        virtual uint16_t getTotalBits() const = 0;
        virtual ~DataflowType() = 0;
    };
}

#endif // DFCXX_TYPE_H
