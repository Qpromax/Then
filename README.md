# Then

## 简介
`Then` 链式调用方式，允许你对一个值连续应用多个函数。

## 使用方法
1. **包含头文件**：
   ```cpp
   #include "then.h"
   ```

2. **创建 `Solution` 对象**：
   ```cpp
   then::Solution<int> s(42);
   ```

3. **链式应用函数**：
   ```cpp
   auto result = s.then([](int x) { return x * 2; })
                 .then([](int x, int add) { return x + add; }, 10)
                 .result();
   ```
   - 第一个 `then` 将 `42` 乘以 2，得到 `84`，包装成 `Solution<int>`。
   - 第二个 `then` 应用 lambda，接受当前值 `84` 和额外参数 `10`，得到 `94`。
   - 最后调用 `.result()` 移动出最终值。

4. **获取最终结果**：
   ```cpp
   int final = std::move(some_solution).result();
   ```

## 完整示例
```cpp
#include <iostream>
#include <string>
#include "then.h"

int main() {
    using namespace then;

    // 初始值
    Solution<std::string> s("Hello");

    // 链式转换
    auto final = s.then([](std::string str) { return str + ", World"; })
                   .then([](std::string str, char suffix) { return str + suffix; }, '!')
                   .then([](std::string str) { return str.length(); })
                   .result();

    std::cout << "Length: " << final << std::endl; // 输出 13
    return 0;
}
```

## 编译要求
- 需要支持 C++20 的编译器。
