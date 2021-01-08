#pragma once
#include <iostream>
#include <typeinfo>

//可变模板类

//模板偏特化和递归方式来展开参数包
//前向声明

/**
 * \brief 展开可变参数包测试
 * \tparam Args 可变参数包
 */
template <typename... Args>
struct sum;

//基本定义
template <typename First, typename... Rest>
struct sum<First, Rest...>
{
    enum { value = sum<First>::value + sum<Rest...>::value };
};

//递归终止
template <typename Last>
struct sum<Last>
{
    enum { value = sizeof(Last) };
};


//继承方式展开参数包
/**
 * \brief 整数序列的定于
 */
template <int...>
struct index_seq
{
};

/**
 * \brief 继承方式，开始展开参数包
 * \tparam N 
 * \tparam Indexes 参数包
 */

template <int N, int... Indexes>
struct make_indexes : make_indexes<N - 1, N - 1, Indexes...>
{
};

/**
 * \brief 模板特化，终止展开参数包的条件
 * \tparam Indexes 
 */
template <int... Indexes>
struct make_indexes<0, Indexes...>
{
    typedef index_seq<Indexes...> type;
};


/**
 * \brief 测试继承方式解开参数包
 */
inline void test_tmp()
{
    using T = make_indexes<3>::type;
    std::cout << typeid(T).name() << std::endl;
}

namespace my_namespace
{
    template <typename T>
    T* Instance()
    {
        return new T();
    }

    template <typename T, typename T0>
    T* Instance(T0 arg0)
    {
        return new T(arg0);
    }

    template <typename T, typename T0, typename T1>
    T* Instance(T0 arg0, T1 arg1)
    {
        return new T(arg0, arg1);
    }

    template <typename T, typename T0, typename T1, typename T2>
    T* Instance(T0 arg0, T1 arg1, T2 arg2)
    {
        return new T(arg0, arg1, arg2);
    }

    template <typename T, typename T0, typename T1, typename T2, typename T3>
    T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3)
    {
        return new T(arg0, arg1, arg2, arg3);
    }

    template <typename T, typename T0, typename T1, typename T2, typename T3, typename T4>
    T* Instance(T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
    {
        return new T(arg0, arg1, arg2, arg3, arg4);
    }

    struct A
    {
        A(int)
        {
        }
    };

    struct B
    {
        B(int, double)
        {
        }
    };

    void instance();
}

namespace my_namespace1
{
    struct A
    {
        A(int)
        {
        }
    };

    struct B
    {
        B(int, double)
        {
        }
    };

    //可变参数模板优化后的工厂函数
    template<typename T, typename... Args>
    T* instance(Args&&... args)
    {
        return new T(std::forward<Args>(args)...);
    }

    void test_tmp_instance();
}
