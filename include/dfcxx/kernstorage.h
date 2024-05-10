#ifndef DFCXX_KERNSTORAGE_H
#define DFCXX_KERNSTORAGE_H

#include "dfcxx/types/type.h"
#include "dfcxx/vars/var.h"

#include <unordered_set>

namespace dfcxx {

class KernStorage {
private:
  std::unordered_set<DFType *> types;
  std::unordered_set<DFVariable *> variables;
public:
  void addType(DFType *type);

  void addVariable(DFVariable *var);

  ~KernStorage();
};

} // namespace dfcxx

#endif // DFCXX_KERNSTORAGE_H
