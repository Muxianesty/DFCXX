#ifndef DFCXX_VAR_H
#define DFCXX_VAR_H

#include <string_view>
#include <string>
#include "dfcxx/types/type.h"

namespace dfcxx {

    enum Direction {
        NONE = 0,
        INPUT,
        OUTPUT
    };

    class DFVariable {
    private:
        Direction direction_;
        std::string name_;

    protected:
        DFVariable(const std::string &name, Direction direction);

    public:
        virtual ~DFVariable() = default;
        std::string_view getName() const;
        virtual const DFType &getType() = 0;
    };
}

#endif // DFCXX_VAR_H
