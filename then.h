//
// Created by Qpromax on 2026/3/11.
//

#ifndef THEN_THEN_H
#define THEN_THEN_H

#include <functional>

namespace then {

    template<typename T>
    struct Solution {

        constexpr explicit Solution(T v) : val(std::move(v)) {}

        template<typename  F, typename... Args>
        requires std::invocable<F, T, Args...>
        constexpr auto then(F&& func, Args&&... args)
        {
            using InvokeResult = std::invoke_result_t<F, T, Args...>;
            InvokeResult new_val = std::invoke(std::forward<F>(func), std::forward<T>(val), std::forward<Args>(args)...);
            return Solution<InvokeResult>(std::move(new_val));
        }

        constexpr T result() && { return std::move(val); }

    private:
        T val;

    };

}

#endif //THEN_THEN_H