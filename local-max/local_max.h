#pragma once

#include <stdexcept>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
    if (first == last){
        return last;
    }
    if (first == )
    auto solutionIt = first;
    if (first > first + 1){
        return first;
    }
    if (last - 1 > last - 2){
        return last - 1;
    }
    for(auto it = first + 1; it != last - 1; ++it){
        if(it - 1 < it && it + 1 < it){
            return it;
        }
    }
    return last;
}