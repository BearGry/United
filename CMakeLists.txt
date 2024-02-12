cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)
#add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=UTF-8>")

# PTA 实验
add_executable(pta_exp1 pta/chapter1/a.cpp)

# 编译原理 实验
add_executable(compile_exp1 compile_principle/experiment1/c.cpp)
add_executable(solve pta/chapter2/solve.cpp)
add_executable(a compile_principle/experiment3/a.cpp)

add_executable(gpt compile_principle/experiment3/gpt.cpp)
add_executable(quick pta/chapter3/quick.cpp)
add_executable(LL compile_principle/experiment6_LL/LL.cpp)
add_executable(hate compile_principle/experiment6_LL/hate.cpp)
add_executable(LR0 compile_principle/experiment7_LR0/LR0.cpp)
add_executable(LR1 compile_principle/experiment8_LR1/LR1.cpp)
add_executable(some_test pta/some_test.cpp)
add_executable(harry pta/chapter4/harry.cpp)
add_executable(LR1_bac compile_principle/experiment8_LR1/LR1_bac.cpp)
add_executable(severus pta/chapter5/severus.cpp)
add_executable(weasley pta/chapter6/weasley.cpp)
add_executable(hermione pta/chapter7/hermione.cpp)
add_executable(review pta/review.cpp)