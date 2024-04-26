#include "dfcxx/kernstorage.h"

namespace dfcxx {
    void KernStorage::addType(dfcxx::DFType *type) {
        types_.insert(type);
    }

    void KernStorage::addVariable(DFVariable *var) {
        variables_.insert(var);
    }

    KernStorage::~KernStorage() {
        for (DFType *type : types_) {
            delete type;
        }
        for (DFVariable *var : variables_) {
            delete var;
        }
    }
}