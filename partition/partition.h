#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
    Iterator fr = first, an = first;

    while (fr != last) {
        if (pred(*fr)) {
            std::swap(*an++, *fr);
        }
        fr++;
    }

    return an;
}
