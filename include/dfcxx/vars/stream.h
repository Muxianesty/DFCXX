#ifndef DFCXX_STREAM_H
#define DFCXX_STREAM_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

    class VarBuilder;

    class DFStream : DFVariable {
        friend VarBuilder;
    private:
        const DFType &type_;

        DFStream(const std::string &name, Direction direction, const DFType &type);
    public:
        ~DFStream() override = default;
        const DFType &getType() override;
    };
}

#endif // DFCXX_STREAM_H
