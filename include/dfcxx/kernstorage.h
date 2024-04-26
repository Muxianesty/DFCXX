#ifndef DFCXX_KERNSTORAGE_H
#define DFCXX_KERNSTORAGE_H

#include "dfcxx/types/type.h"
#include "dfcxx/vars/var.h"
#include <unordered_set>

namespace dfcxx {
    class KernStorage {
    private:
        std::unordered_set<DFType *> types_;
        std::unordered_set<DFVariable *> variables_;
    public:
        void addType(DFType *type);
        void addVariable(DFVariable *var);
        ~KernStorage();
    };
}

#endif // DFCXX_KERNSTORAGE_H
