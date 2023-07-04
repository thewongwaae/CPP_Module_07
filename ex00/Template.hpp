#pragma once

/*
	Cannot seperate a template function into a .hpp and .cpp file
*/

template< typename A >

const A &max( const A &a, const A &b ) {
	return (a > b ? a : b);
}

template< typename B >

const B &min( const B &a, const B &b ) {
	return (a < b ? a : b);
}

template< typename C >

void swap( C &a, C &b ) {
	C tmp = a;
	a = b;
	b = tmp;
}
