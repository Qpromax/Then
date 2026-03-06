// Created by Qpromax on 2024/6/11.

#include <any>
#include <functional>
#include <utility>
#include <print>

template<typename T>
struct Wrapper {

    constexpr explicit Wrapper(T v) : val(std::move(v)) {}

    template<typename  F, typename... Args>
    requires std::invocable<F, T, Args...>
    constexpr auto then(F&& func, Args&&... args)
    {
        using InvokeResult = std::invoke_result_t<F, T, Args...>;
        InvokeResult new_val = std::invoke(std::forward<F>(func), std::forward<T>(val), std::forward<Args>(args)...);
        return Wrapper<InvokeResult>(std::move(new_val));
    }

    constexpr T result() && { return std::move(val); }

private:
    T val;

};

int main()
{
    const int pi = 3;
    auto a = Wrapper<int>(3)
        .then([](int x) {
            return x + 1;
        })
        .then([pi](int x) {
            return (x + 1) * pi;
        }).result();
    std::print("{}", a);

    return 0;
}