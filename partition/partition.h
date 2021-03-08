#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator Partition(Iterator first, Iterator last, Predicate pred) {
    if(first == last){
        return last;
    }
    if(std::next(first) == last && pred(*first)){
        return last;
    }
    if(std::next(first) == last && !pred(*first)){
        return first;
    }
    for (auto it = first; it != last; ++it){
        if(!pred(*it)){
            first = it;
            break;
        }
    }
    for (auto it = std::next(first); it != last; ++it) {
        if (pred(*it)) {
            std::swap(*first, *it);
            ++first;
        }
    }
    return first;
}
