#pragma once
#include "Iterator.cpp";
template <typename T>
class Collection {
public:
    virtual Iterator<T>* createIterator() = 0;
};