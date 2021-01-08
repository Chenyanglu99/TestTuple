#include "Testtuple.h"
#include <utility>
#include <complex>
#include <tuple>
#include <functional>
#include <iostream>
#include <typeinfo>

void TestTuple1(void) {
	//create a four-element tuple
	//-elements are initialized with default value(0 for fundamental types;

	//create and initialize a explicitly

	std::tuple<std::string, int, int, std::complex<double>> t;

	//create and initialize a tuple explicity
	std::tuple<int, float, std::string> t1(41, 6.3, "nico");

	std::cout << std::get<0>(t1) << " ";
	std::cout << std::get<1>(t1) << " ";
	std::cout << std::get<2>(t1) << " ";
	std::cout << std::endl;

	auto t2 = std::make_tuple(22, 44, "nico");

	//assign second value in t2 to t1;
	std::get<1>(t1) = std::get<1>(t2);

	if (t1 < t2) t1 = t2;

	
}

void TestTuple2(void)
{
	std::string s;
	auto x = std::make_tuple(s);
	std::get<0>(x) = "my value"; //modify x but not s

	auto y = std::make_tuple(std::ref(s)); //y is type tuple<string&>, thus y refers to s
	std::get<0>(y) = "my value"; //modifies y

	std::cout << "std::string s = " << s << std::endl;
}



void TestTuple3(void)
{
	using tupletype = typename std::tuple<int, int, float>;
	std::cout << std::tuple_size<tupletype>::value << std::endl;

	std::cout << typeid(std::tuple_element<1, tupletype>::type).name()
		<< std::endl;

	int n;
	auto tt = std::tuple_cat(std::make_tuple(42, 7.7, "hello"), std::tie(n));
	std::get<3>(tt) = 5;
	std::cout << " " << "n = "
		<< n << "std::get<3>(tt) = " << std::get<3>(tt) << std::endl;

}
