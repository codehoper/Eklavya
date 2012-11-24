#include<string.h>
#include"VectorLife.h"

using namespace std;

//static member initialization
const size_t VectorLife :: INITAL_CAPACITY = 12;

/**
 * Use of Initialization list : Improve the performance @ Compiler level
 * http://www.parashift.com/c++-faq-lite/init-lists.html
 */
VectorLife :: VectorLife(size_t n):
				num_items(n),
				capacity(max(n,INITAL_CAPACITY)),
				item_ptr (new string[capacity])
{

}

VectorLife::VectorLife(const VectorLife &other_vec):
		num_items(other_vec.num_items),
		capacity(other_vec.capacity),
		item_ptr(new string[other_vec.num_items])
{
	for(size_t i=0;i<num_items;i++) {
		item_ptr[i] = other_vec.item_ptr[i];
	}
}
//VectorLife :: VectorLife(size_t n) {
//	num_items        = n;
//	capacity = max(n, INITAL_CAPACITY);
//	item_ptr = new string[capacity];
//}

VectorLife:: ~VectorLife() {
	delete [] item_ptr;
}

VectorLife& VectorLife::operator=(const VectorLife& other_vec) {
		VectorLife(other_vec); //Use deep copy constructor
		return (*this);
		//http://stackoverflow.com/questions/2750316/this-vs-this-in-c
		/**
		 * If you had a function that returned this,
		 * it would be a pointer to the current object,
		 * while a function that returned *this would be a "clone" of the
		 * current object, allocated on the stack --
		 * unless you have specified the return type of the method to return
		 * a reference.
		 */
}

std::string& VectorLife::operator[](size_t index) {
	if(index < num_items) {
		//	return this->item_ptr[index];
		return item_ptr[index];
	} else {
		throw std::runtime_error("index out of range");
	}
}

const std::string& VectorLife::operator[](size_t index) const{
	if(index < num_items) {
		//	return this->item_ptr[index];
		return item_ptr[index];
	} else {
		throw std::runtime_error("index out of range");
	}
}

string& VectorLife::front() {
	return (*this)[0];
}

const string& VectorLife::front() const{
	return (*this) [0];
}

string& VectorLife::back() {
	return (*this)[num_items -1];
}

const string& VectorLife::back() const{
	return (*this) [num_items -1];
}

size_t VectorLife::get_size() const {
	return capacity;
}

int main() {

	    VectorLife ubv(3); ubv[0] = "this"; ubv[1] = "is"; ubv[2] = "good!";
	    cout << ubv[0] << " " << ubv[1] << " " << ubv[2] << endl;
	    ubv.front() = "THIS";
	    ubv.back() = "GOOD!";
	    cout << ubv.front() << " " << ubv[1] << " " << ubv[2] << endl;
	    try {
	        cout << ubv[4] << endl;
	    } catch (exception &e) {
	        cout << e.what() << endl;
	    }

}
