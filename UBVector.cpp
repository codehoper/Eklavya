/**
 *****************************************************************************
 * file name : UBVector.cpp
 * description : implement the UBVector template interface
 *****************************************************************************
 */
#include <iostream>
#include <stdexcept>
#include "UBVector.h"
using namespace std;

// actually allocate the const member
template <typename Item>
const size_t UBVector<Item>::INITIAL_CAPACITY = 5;

/**
 * -----------------------------------------------------------------------------
 *  constructor which contains a default constructor
 * -----------------------------------------------------------------------------
 */
template <typename Item>
UBVector<Item>::UBVector(size_t n) :
    num_items(n),
    current_capacity(max(n, UBVector<Item>::INITIAL_CAPACITY)),
    item_ptr(new Item[max(n, UBVector<Item>::INITIAL_CAPACITY)])
{ /* constructor has empty body */ }

/**
 * -----------------------------------------------------------------------------
 *  deep copy constructor
 *  - copy the members other than the pointer
 *  - allocate space for the pointer
 *  - copy items one by one
 * -----------------------------------------------------------------------------
 */
template <typename Item>
UBVector<Item>::UBVector(const UBVector<Item>& the_other) :
    num_items(the_other.num_items),
    current_capacity(the_other.num_items),
    item_ptr(new Item[the_other.num_items])
{
    for (size_t i=0; i<num_items; ++i)
        item_ptr[i] = the_other.item_ptr[i];
}

/**
 * -----------------------------------------------------------------------------
 *  release the requested memory space
 * -----------------------------------------------------------------------------
 */
template <typename Item>
UBVector<Item>::~UBVector() {
    delete [] item_ptr;
}

/**
 * -----------------------------------------------------------------------------
 *  the [] operator, throw an exception if out of range
 *  returned value can be used as an lvalue, e.g., ubvec[10] = a;
 * -----------------------------------------------------------------------------
 */
template <typename Item>
Item& UBVector<Item>::operator[](size_t index) {
    if (index < num_items)
        return item_ptr[index];
    else
        throw out_of_range("index is out of range");
}

/**
 * -----------------------------------------------------------------------------
 *  the [] operator, throw an exception if out of range
 *  returned value can only be used on the right of an assignment
 *  such as a = ubvec[10];
 * -----------------------------------------------------------------------------
 */
template <typename Item>
const Item& UBVector<Item>::operator[](size_t index) const {
    if (index < num_items)
        return item_ptr[index];
    else
        throw out_of_range("index is out of range");
}

/**
 * -----------------------------------------------------------------------------
 *  front and back member functions
 * -----------------------------------------------------------------------------
 */
template <typename Item>
Item& UBVector<Item>::front() { return (*this)[0]; }

template <typename Item>
const Item& UBVector<Item>::front() const { return (*this)[0]; }

template <typename Item>
Item& UBVector<Item>::back() { return (*this)[num_items-1]; }

template <typename Item>
const Item& UBVector<Item>::back() const { return (*this)[num_items-1]; }

/**
 * -----------------------------------------------------------------------------
 *  append the item at the end, reserve new space if necessary
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::push_back(const Item& item) {
    if (num_items == current_capacity)
        reserve(2*current_capacity);
    item_ptr[num_items++] = item;
}

/**
 * -----------------------------------------------------------------------------
 *  insert an item, reserve new capacity if the new size exceeds the current
 *  capacity, and shift all items back one position
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::insert(size_t position, const Item& new_item) {
    if (num_items == current_capacity)
        reserve(2*current_capacity);
    for (size_t i=num_items; i>position; --i)
        item_ptr[i] = item_ptr[i-1];
    item_ptr[position] = new_item;
    ++num_items;
}

/**
 * -----------------------------------------------------------------------------
 *  reserve space so that the new vector can store at least n items
 *  if n is less than twice the current capacity, double the current capacity
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::reserve(size_t n) {
    if (n > current_capacity) {
        current_capacity = max(n, 2*current_capacity);
        Item *new_data_ptr = new Item[current_capacity];
        for (size_t i=0; i<num_items; ++i) {
            new_data_ptr[i] = item_ptr[i];
        }
        delete [] item_ptr;
        item_ptr = new_data_ptr;
    }
}

/**
 * -----------------------------------------------------------------------------
 *  erase an element at position, shift suffix back one spot
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::erase(size_t position) {
    if (position < num_items) {
        for (size_t i=position; i<num_items-1; ++i) {
            item_ptr[i] = item_ptr[i+1];
        }
        item_ptr[num_items-1] = Item(); // prevent memory leak
        num_items--;
    }
}

/**
 * -----------------------------------------------------------------------------
 *  erase the last element
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::pop_back() {
    erase(num_items-1);
}

/**
 * -----------------------------------------------------------------------------
 *  swapping two UBVectors: swap the num_items, current_capacity, and the two
 *  item pointers.
 *  have to use std::swap instead of just swap because there's a naming conflict
 * -----------------------------------------------------------------------------
 */
template <typename Item>
void UBVector<Item>::swap(UBVector<Item>& the_other) {
    std::swap(num_items, the_other.num_items);
    std::swap(current_capacity, the_other.current_capacity);
    std::swap(item_ptr, the_other.item_ptr);
}

/**
 * -----------------------------------------------------------------------------
 *  assignment operator for UBVector:
 *  - create a new copy of the other object using the copy constructor
 *  - swap the content of this object with the temporary object
 *  - return a reference to this object.
 *  - when we return, the temporary object will be destroyed
 *  have to use std::swap instead of just swap because there's a naming conflict
 * -----------------------------------------------------------------------------
 */
template <typename Item>
UBVector<Item>& UBVector<Item>::operator=(const UBVector<Item>& the_other) {
    UBVector<Item> temp(the_other); // uses (deep) copy constructor here
    swap(temp);
    return *this;
}
