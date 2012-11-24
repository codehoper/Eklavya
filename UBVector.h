/**
 *****************************************************************************
 * file name : UBVector.h
 * description : interface of the template UBVector class
 *****************************************************************************
 */
#ifndef _UBVECTOR_H
#define _UBVECTOR_H

template <typename Item>
class UBVector {
public:
    // constructors and assignment operator
    explicit UBVector(size_t n=0); // construct a UBVector with n items
    UBVector(const UBVector&);     // copy constructor
    UBVector& operator=(const UBVector& another_ubvec);

    // destructor
    ~UBVector();

    // accessors
    Item& operator[](size_t index);
    const Item& operator[](size_t index) const;
    Item& front();
    const Item& front() const;
    Item& back();
    const Item& back() const;

    // capacity
    size_t size() const { return num_items; }
    size_t capacity() const { return current_capacity; }
    bool empty() { return num_items == 0; }
    void reserve(size_t n);

    // modifiers
    void push_back(const Item& item);
    void pop_back();
    void insert(size_t position, const Item& value);
    void erase(size_t position);
    void swap(UBVector& another_ubvec); // swap content with one another

private:
    size_t num_items;
    size_t current_capacity;
    static const size_t INITIAL_CAPACITY;
    Item *item_ptr;
};

#include "UBVector.cpp" // only done for template classes

#endif
