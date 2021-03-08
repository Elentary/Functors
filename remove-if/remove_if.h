#pragma once

#include <stdexcept>

template <class Iterator, class Predicate>
Iterator RemoveIf(Iterator first, Iterator last, Predicate pred) {

    if(first == last) {
        return first;
    }

    Iterator it = first;
    while(it != last){
        if(!pred(*it)){
            std::swap(*first, *it);
            first++;
        }
        it++;
    }
    return first;
}
