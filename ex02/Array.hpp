#pragma once

#include <iostream>

template <typename T>

class Array {
	private:
		T	*_array;
		int	_size;

	public:
		Array( void ) : _size(0) {
			this->_array = new T[0];
			std::cout << "Default constructor called with size of 0" << std::endl;
		}

		Array( int size ) : _size(size) {
			this->_array = new T[size];
			std::cout << "Default constructor called with size of " << size << std::endl;
		}
		
		Array( Array const &copy ) : _size(copy.getSize()) {
			this->_array = NULL;
			*this = copy;
			std::cout << "Copy Constructor called" << std::endl;
		}

		Array &operator=( Array const &assign ) {
			if (this->_array)
				delete [] this->_array;
			if (assign.getSize())
			{
				this->_size = assign.getSize();
				this->_array = new T[this->_size];
				for (int i = 0; i < this->_size; i++)
					this->_array[i] = assign._array[i];
			}
			return *this;
		}

		~Array( void ) {
			if (this->_array)
				delete [] this->_array;
		}

		int getSize( void ) const {
			return this->_size;
		}

		// Create an overloaded "[]" sign so arrays can work properly
		T &operator[]( int index ) {
			if (index < 0 || index >= this->_size)
				throw OutOfRangeException();
			return this->_array[index];
		}

		class OutOfRangeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
	return "Index out of range";
}