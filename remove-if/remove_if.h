#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            *last = *first;
            last--;
        }
    }
    return first;
}
