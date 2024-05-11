# DFCXX
DFCxx is a domain-specific language, which allows specifying the computational logic of a streaming computer to generate SystemVerilog hardware descriptions.

DFCxx provides a library of C++ classes (like `Stream`, `Scalar`, `Kernel`), allowing relations between objects to represent the computational logic of a streaming computer.

By inheriting `dfcxx::Kernel` abstract class and implementing a parameterless constructor this new class represents the main unit of computation, <i>kernel</i>.

The computational logic of a streaming dataflow computer has to be statically scheduled: DFCIR currently has two implementations of scheduling algorithms (Linear Programming-approach and a simple as-soon-as-possible algorithm).

By using one of `dfcxx::Kernel::compile`-method overloads, it is possible to choose a scheduling strategy and latency configuration for computational elements, as well as the output file for SystemVerilog code to be generated in.

```cpp
#include "dfcxx/DFCXX.h"

class NewKernel : public dfcxx::Kernel {
public:
  std::string_view getName() override {
    return "NewKernel";
  }

  ~NewKernel() override = default;

  NewKernel() : dfcxx::Kernel() {
    using dfcxx::DFType;
    using dfcxx::DFVariable;

    const DFType &type = dfUInt(32);
    DFVariable &x = io.input("x", type);
    DFVariable &sum = x + x;
    ...
    ...
  }
};

int main(int argc, char **argv) {
    NewKernel kernel;
    DFLatencyConfig config = {
            {dfcxx::ADD_INT, 2},
            {dfcxx::MUL_INT, 3}
    };
    kernel.compile(config, dfcxx::Linear);
}
```

## Prerequisites

**[!!!]** Current version was tested _**only on Ubuntu 20.04**_ **[!!!]**

DFCxx uses [DFCIR](https://github.com/Muxianesty/DFCIR) and FIRRTL ([CIRCT](https://github.com/llvm/circt/)) intermediate representations, making them project's dependencies. DFCIR is present in DFCxx in the form of a `git`-submodule, so it has to be initialized with the following commands:
```
git submodule init
git submodule update
```
CIRCT is also needed to build DFCIR, so please refer to [DFCIR building guide](https://github.com/Muxianesty/DFCIR/tree/main?tab=readme-ov-file#prerequisites) before building DFCxx. DFCxx shares dependencies with DFCIR.

**[!!!]Currently supported CIRCT release: 1.72.0, Apr 5 2024 ([link](https://github.com/llvm/circt/releases/tag/firtool-1.72.0))[!!!]**

## Building DFCxx
DFCxx is a CMake package, so in order to build it a simple CMake environment has to be set up.

DFCxx needs to know the locations where DFCIR and CIRCT have been installed, and corresponding **full paths** to these location have to be passed to CMake environment in the form of `DFCIR_BUILD_DIR` and `CIRCT_BIN_HOME` CMake variables:<br>

assuming CIRCT-archive was downloaded in home directory (`~`) and was extracted using `tar -xvf`, thus `firtool-1.72.0` (the directory with the top-level `CMakeLists.txt`-file) is also in the home directory, with DFCIR being built as a `git`-submodule of DFCxx, the CMake environment can be set up using the following commands:
```
cd <DFCXX_DIR>
mkdir build
cd build
cmake .. -G Ninja -DCIRCT_BIN_HOME="~/firtool-1.72.0" -DDFCIR_BUILD_DIR="<DFCXX_DIR>/DFCIR/build"
```
After this, use `cmake --build .` to build DFCxx.

## Usage of DFCxx
Currently DFCxx project is concentrated in a single static library - a CMake target, addressed by its alias `DFCXX::DFCXX`.
Using CMake `find_package(REQUIRED CONFIG HINTS)`-functionality, this library can be incorporated in other projects (the **full path** after `HINTS` needs to specify the build-directory for DFCxx).

The following code describes a simple `CMakeLists.txt`-file of a project, using DFCxx:
```cmake
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(TESTPROJECT C CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(DFCXX REQUIRED CONFIG HINTS "~/DFCXX/build")

add_executable(TEST test.cpp)
target_link_libraries(TEST DFCXX::DFCXX)
```

Along with the project, a number of usage examples is provided: they can be found in the `examples`-directory, and within each
example's directory its corresponding kernel definition can be found (`*.h`-file) with subdirectories code for different scheduling configurations
(`main.cpp`-files).
