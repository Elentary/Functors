#pragma once

#include <stdexcept>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
    if (first == last){
        return last;
    }
    if (last == first + 1){
        return first;
    }
    if (*(first + 1) < *first){
        return first;
    }
    for(auto it = first + 1; it != last - 1; ++it){
        if(*(it - 1) < *it && *(it + 1) < *it){
            return it;
        }
    }
    if (*(last - 2) < *(last - 1)){
        return last - 1;
    }
    return last;
}