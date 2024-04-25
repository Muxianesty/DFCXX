#ifndef DFCXX_VAR_H
#define DFCXX_VAR_H

#include <string_view>
#include <string>
#include "dfcxx/types/type.h"

namespace dfcxx {
    class DataflowVariable {
    private:
        std::string name_;

    protected:
        DataflowVariable(const std::string &name);

    public:
        virtual ~DataflowVariable() = default;
        std::string_view getName() const;
        virtual const DataflowType &getType() = 0;
    };

    class Stream : DataflowVariable {
    private:
        const DataflowType &type_;

        Stream(const std::string &name, const DataflowType &type);
    public:
        ~Stream() override = default;
        const DataflowType &getType() override;
    };

}

#endif // DFCXX_VAR_H
