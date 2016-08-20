
#pragma once

#include <tuple>
#include <iostream>

namespace utils {

    // Create a tuple of given size and type
    template<std::size_t N, typename T>
    struct create_tuple {
        typedef decltype(std::tuple_cat(std::declval<std::tuple<T>>(), std::declval<typename create_tuple<N-1, T>::type>())) type;
    };

    template<typename T>
    struct create_tuple<1, T> {
        typedef typename std::tuple<T> type;
    };
    //  ... end create_tuple.

    // Print tuple
    //  - credit: http://stackoverflow.com/questions/6245735/pretty-print-stdtuple
    template<std::size_t...> struct seq{};

    template<std::size_t N, std::size_t... Is>
    struct gen_seq : gen_seq<N-1, N-1, Is...>{};

    template<std::size_t... Is>
    struct gen_seq<0, Is...> : seq<Is...>{};

    template<class Ch, class Tr, class Tuple, std::size_t... Is>
    void print_tuple(std::basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){
        using swallow = int[];
        (void)swallow{0, (void(os << (Is == 0? "" : ", ") << std::get<Is>(t)), 0)...};
    }
    //  ... end print tuple

}


template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t)
    -> std::basic_ostream<Ch, Tr>& {
    os << "(";
    utils::print_tuple(os, t, utils::gen_seq<sizeof...(Args)>());
    return os << ")";
}
