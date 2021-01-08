#include "test_templatemode.h"

void instance()
{
    auto* pa = my_namespace::Instance<my_namespace::A>(1);

    auto* pb = my_namespace::Instance<my_namespace::B>(1, 2);

}

void my_namespace1::test_tmp_instance()
{
    auto* pa = my_namespace1::instance<my_namespace1::A>(1);
    auto* pb = my_namespace1::instance<B>(1,2);
}
