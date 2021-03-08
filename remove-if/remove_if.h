#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            break;
        }
    }
    if (first != last) {
        for (auto it = first; ++it != last;) {
            if (!pred(*it)) {
                *first++ = std::move(*it);
            }
        }
    }
    return first;
}
