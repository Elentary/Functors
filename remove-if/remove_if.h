#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
    Iterator sol = first;
    for (; first != last; ++first) {
        if (pred(*first)) {
            sol++;
        } else {
            *first = *sol;
        }
    }
    return first;
}
