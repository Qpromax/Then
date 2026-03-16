// Created by Qpromax on 2025/3/7.


#include "then.h"
#include <iostream>

//todo 多值情况
//todo 测试左值情况
//todo 写文档
//todo 模块化

int main()
{
    const int pi = 3;
    auto a = then::Solution<int>(3)
        .then([](int x, std::string s) {
            return x + 1;
        }, "hello")
        .then([pi](int x) {
            return (x + 1) * pi;
        }).result();
    // std::print("{}", a);
    std::cout << a << std::endl;

    return 0;
}