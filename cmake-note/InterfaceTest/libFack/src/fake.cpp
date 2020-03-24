

#include "fake.h"

fake::fake(const std::string &monster) : monster(monster)
{

}

std::string fake::name()
{
    return monster;
}
