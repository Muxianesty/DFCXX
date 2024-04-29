#ifndef DFCXX_VAR_H
#define DFCXX_VAR_H

#include <string_view>
#include <string>
#include "dfcxx/types/type.h"

namespace dfcxx {

    class GraphHelper;

    class DFVariable {

    public:
        enum Direction {
            NONE = 0,
            INPUT,
            OUTPUT
        };

    private:
        Direction direction_;
        std::string name_;

    protected:
        GraphHelper &helper_;
        DFVariable(const std::string &name, Direction direction, GraphHelper &helper);

    public:
        virtual ~DFVariable() = default;
        std::string_view getName() const;
        virtual const DFType &getType() = 0;

        virtual DFVariable &operator+(DFVariable &rhs) = 0;
        virtual DFVariable &operator*(DFVariable &rhs) = 0;

        virtual bool isStream();
        virtual bool isScalar();
        virtual bool isConstant();

        void connect(DFVariable &connectee);
    };
}

#endif // DFCXX_VAR_H
