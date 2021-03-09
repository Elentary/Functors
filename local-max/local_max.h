#pragma once

#include <stdexcept>
#include <iostream>

template <class Iterator>
Iterator LocalMax(Iterator first, Iterator last) {

    if (first == last) {
        return first;
    }

    Iterator prev = first++;
    if (first == last || *first < *(prev)) {
        return prev;
    }

    Iterator current = first++;
    Iterator next = first;

    while (current != last) {
        if(next != last){
            if (*prev < *current && *next < *current) {
                return current;
            }
        } else {
            if (*prev < *current) {
                return current;
            }
        }

        prev++;
        current++;
        next++;
    }

    return last;
}
