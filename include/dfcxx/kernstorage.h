#ifndef DFCXX_KERNSTORAGE_H
#define DFCXX_KERNSTORAGE_H

#include "dfcxx/types/types.h"
#include <unordered_set>

namespace dfcxx {
    class KernStorage {
    private:
        std::unordered_set<DataflowType *> types_;
    public:
        void addType(DataflowType *type);
        ~KernStorage();
    };
}

#endif // DFCXX_KERNSTORAGE_H
