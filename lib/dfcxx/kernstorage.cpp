#include "dfcxx/kernstorage.h"

namespace dfcxx {

void KernStorage::addType(dfcxx::DFType *type) {
  types.insert(type);
}

void KernStorage::addVariable(DFVariable *var) {
  variables.insert(var);
}

KernStorage::~KernStorage() {
  for (DFType *type: types) {
    delete type;
  }
  for (DFVariable *var: variables) {
    delete var;
  }
}

} // namespace dfcxx