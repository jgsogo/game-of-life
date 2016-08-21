
#pragma once

#include <iostream>
#include <iterator>
#include <array>
#include <cmath>
#include <algorithm>

namespace dynamics {

    template <std::size_t NDimensions>
    using vector = std::array<float, NDimensions>;

    template <std::size_t NDimensions>
    float length(const vector<NDimensions>& v) {
        return fabs(std::sqrt(std::accumulate(begin(v), end(v), 0.f, [](float lhs, float rhs){
            return lhs + rhs*rhs;
        })));
    }

    template <std::size_t NDimensions>
    vector<NDimensions>& operator+=(vector<NDimensions>& lhs, const vector<NDimensions>& rhs) {
        std::transform(lhs.begin(), lhs.end(), rhs.begin(), lhs.begin(), std::plus<float>());
        return lhs;
    }

    template <std::size_t NDimensions>
    vector<NDimensions> operator+(const vector<NDimensions>& lhs, const vector<NDimensions>& rhs) {
        vector<NDimensions> ret;
        std::transform(lhs.begin(), lhs.end(), rhs.begin(), ret.begin(), std::plus<float>());
        return ret;
    }

    template <std::size_t NDimensions>
    vector<NDimensions> operator-(const vector<NDimensions>& lhs, const vector<NDimensions>& rhs) {
        vector<NDimensions> ret;
        std::transform(lhs.begin(), lhs.end(), rhs.begin(), ret.begin(), std::minus<float>());
        return ret;
    }

    template <std::size_t NDimensions>
    vector<NDimensions> operator*(const vector<NDimensions>& lhs, const vector<NDimensions>& rhs) {
        vector<NDimensions> ret;
        std::transform(lhs.begin(), lhs.end(), rhs.begin(), ret.begin(), std::multiplies<float>());
        return ret;
    }

    template <std::size_t NDimensions>
    vector<NDimensions> operator*(const vector<NDimensions>& lhs, float rhs) {
        vector<NDimensions> ret;
        std::transform(lhs.begin(), lhs.end(), ret.begin(), [rhs](float item){ return item*rhs;});
        return ret;
    }

    template <std::size_t NDimensions>
    vector<NDimensions> operator-(const vector<NDimensions>& lhs) {
        vector<NDimensions> ret;
        std::transform(lhs.begin(), lhs.end(), ret.begin(), [](float item){ return -item;});
        return ret;
    }

}

template<class Ch, class Tr, class T, std::size_t NDimensions>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const std::array<T, NDimensions>& t)
    -> std::basic_ostream<Ch, Tr>& {
    std::copy(begin(t), end(t), std::ostream_iterator<float>(os, ", "));
    return os;
}
