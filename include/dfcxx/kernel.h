#ifndef DFCXX_KERNEL_H
#define DFCXX_KERNEL_H

#include <string_view>
#include "dfcxx/typedefs.h"
#include "dfcxx/io.h"
#include "dfcxx/offset.h"
#include "dfcxx/constant.h"

namespace dfcxx {

    class Kernel {

    protected:
        IO io;
        Offset offset;
        Constant constant;

    public:
        virtual ~Kernel() = default;
        virtual std::string_view getName() = 0;
        void compile(const DFCXXLatencyConfig &config, const Scheduler &sched);
        void compile(const DFCXXLatencyConfig &config, const std::string &filePath, const Scheduler &sched);
    };
}


#endif // DFCXX_KERNEL_H
