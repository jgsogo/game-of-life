
#pragma once

#include <iostream>
#include <iterator>
#include <array>

namespace dynamics {

    template <std::size_t NDimensions>
    using vector = std::array<float, NDimensions>;

}

template<class Ch, class Tr, class T, std::size_t NDimensions>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const std::array<T, NDimensions>& t)
    -> std::basic_ostream<Ch, Tr>& {
    std::copy(begin(t), end(t), std::ostream_iterator<float>(os, ", "));
    return os;
}
