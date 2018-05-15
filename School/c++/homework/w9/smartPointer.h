#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class smartPointer
{
    private:
    T* ptr;

    public:
    explicit smartPointer(T* p = 0) : ptr(p) {} // constructor
    ~smartPointer() {delete ptr;} // destructor
    T& operator*() {return *ptr;} // * overloading - dereference
    T* operator->() {return ptr;} // -> overloading - object pointer
};

#endif