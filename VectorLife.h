/**
 * It supports following functionalities
 * 1.subscripting operator
 * 2.front() ,back() accessors
 * 2.size() and empty() members
 * 3.assignment operator = used to assign one vector to another
 * 4.reserver(n) makes the capacity at least n
 * 5.constructor and destructor
 *
 */

#include<iostream>
#include<stdexcept>

#ifndef VECTOR_LIFE_H
#define VECTOR_LIFE_H
class VectorLife {

public:
	VectorLife();
	explicit VectorLife(size_t n = 0);
	//Rule of three
	/**
	 * Copyconstructor,assignment operator,Destructor
	 * Use of CC
	 * vector<int> newvec(oldvec);
		vector<int> newvec = oldvec;
		string newstring(oldstring);
		string newstring = oldstring;
	 */
	VectorLife(const VectorLife&); //copy constructor VectorLife(ub_obj)
	VectorLife& operator=(const VectorLife& another_VectorLife); // VectorLife ub = vec[12] -->ub.= (vec[12])
	/**
	 * Assignment operator =>
	 * VectorLife a and b()
	 * a = b;
	 * a.=(b) ===> obj.method_name(obj)
	 */
	~VectorLife();

	//modifiers
	void push_back(const std::string&);
	void pop_back();
	void insert(size_t position,const std::string& value);
	void erase(size_t position);
	void swap(VectorLife& ); // for saving the private VectorLife ...saving private Ryan

	/**
	 * Returning a reference means a new object is not created and returned,
	 * only a reference to it is returned
	 */
	std::string& operator[](size_t index); //lvalue
	const std::string& operator[](size_t index) const; //rvalue


	//operator overloading
	std::string& operator&(const VectorLife& vecotlife_obj);
	//accessors
	size_t get_size() const;
	size_t get_capacity() const;
	bool is_empty() const;
	void reserve(size_t n);

	/**
	 * The reason why we append const ?
	 * logical : const is return type and this cannot be overloading
	 * to acheive overloading we append const
	 */
	std::string& front();
	const std::string& front()const;
	std::string& back();
	const std::string& back()const;

	/**
	 * Exception handling
	 */
	struct DBZ_Exception : public std::runtime_error {
	    DBZ_Exception() : std::runtime_error("Divide by zero") {}

	};

//	struct out_of_range : publict std::runtime_error {
//		out_of_range(std::string str) : std::runtime_error(str) {}
//	};
	/**
	 * const version used when the object itself is const @ RHS
	 */
private:
	//member variable
	size_t num_items;
	size_t capacity;
	const static size_t INITAL_CAPACITY;	//shared among all the VectorLife objects
	std::string* item_ptr; //points to start of memory

	/**
	 * This is the raw pointer.
	 * unique_ptr : delete is called automatically when goes out of scope i.e. after the parenthesis
	 *
	 *
	 */
};


#endif
