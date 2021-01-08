#include <cstdio>
#include <iostream>
//#include "Testtuple.h"

#include "test_templatemode.h"
/*
 *using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
	A()
	{
		cout << "construct: " << ++g_constructCount << endl;
	}

	A(const A& a)
	{
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}

	~A()
	{
		cout << "destruct: " << ++g_destructCount << endl;
	}
};

A GetA()
{
	return A();
}

 *
 */

/**
 * 逗号表达式展开参数包
 */

template <class T>
void printarg(T t)
{
	std::cout << t << std::endl;
}

template <class ...Args>
void expand(Args ... args)
{
	int arr[] = {(printarg(args), 0)...};
}

/**
 * 逗号表达式展开参数包
 */

int main(void)
{
#if 0
	A&& a = GetA();
#endif

#if 0
	expand(1, 2, 3, 4);
#endif
	//TestTuple1();
	//TestTuple2();
	//TestTuple3();

#if 0 //测试递归方式展开参数包
	std::cout << sum<int, double, short>::value << std::endl;
#endif

#if 0
	test_tmp();
#endif

#if 0
	my_namespace::instance();
#endif

#if 1
	my_namespace1::test_tmp_instance();
#endif
	getchar();
	return 0;
}
