#ifndef DFCXX_KERNEL_H
#define DFCXX_KERNEL_H

#include <string>
#include "dfcxx/typedefs.h"

namespace dfcxx {

    class Kernel {
    public:
        void compile(const DFCXXLatencyConfig &config);
        void compile(const DFCXXLatencyConfig &config, const std::string &filePath);
    };

}


#endif // DFCXX_KERNEL_H
