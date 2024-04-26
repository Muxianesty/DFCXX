#include "dfcxx/types/type.h"

namespace dfcxx {
    bool DFType::operator!= (const DFType &rhs) const {
        return !(*this == rhs);
    }
}