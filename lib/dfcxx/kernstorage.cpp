#include "dfcxx/kernstorage.h"

namespace dfcxx {
    void KernStorage::addType(dfcxx::DataflowType *type) {
        types_.insert(type);
    }

    KernStorage::~KernStorage() {
        for (DataflowType *type : types_) {
            delete type;
        }
    }
}