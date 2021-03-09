#pragma once

#include <stdexcept>

template <class Iterator, class T>
Iterator FindLast(Iterator first, Iterator last, const T& val) {
    auto al = last;
    for (; first != last; ++first) {
        if (*first == val) {
            al = first;
        }
    }
    return al;
}
