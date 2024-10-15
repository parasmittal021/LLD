#pragma once
template <typename T>
class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual T next() = 0;
        virtual ~Iterator() {}

};