#ifndef DFCXX_KERNEL_H
#define DFCXX_KERNEL_H

#include <string_view>
#include "dfcxx/typedefs.h"
#include "dfcxx/io.h"
#include "dfcxx/offset.h"
#include "dfcxx/constant.h"
#include "dfcxx/types/types.h"
#include "dfcxx/vars/var.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/graph.h"

#include "dfcxx/typebuilders/builder.h"
#include "dfcxx/varbuilders/builder.h"

namespace dfcxx {

    class Kernel {
        friend IO;
        friend Offset;
        friend Constant;
    protected:
        IO io;
        Offset offset;
        Constant constant;

        DFType &dfUInt(uint8_t bytes);
        DFType &dfInt(uint8_t bytes);
        DFType &dfBool();

        Kernel();

    private:
        KernStorage storage_;
        TypeBuilder type_builder_;
        VarBuilder var_builder_;
        Graph graph_;

    public:
        virtual ~Kernel() = default;
        virtual std::string_view getName() = 0;
        void compile(const DFLatencyConfig &config, const Scheduler &sched);
        void compile(const DFLatencyConfig &config, const std::string &filePath, const Scheduler &sched);
    };
}


#endif // DFCXX_KERNEL_H
