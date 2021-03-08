#pragma once

#include <stdexcept>
#include <iostream>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {
    Iterator start = first;
    Iterator forw = first++;
    Iterator end = last--;

    if(first == last){
        return start;
    }

    if(first == end){
        return (*start > *(end)) ? start : end;
    }

    while(forw != end){
        Iterator next = forw++;
        if(*forw > *start && *forw > *next){
            return forw;
        }
    }
}
