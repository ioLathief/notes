#include <iostream>
#define print(some) std::cout<<some<<std::endl
using namespace std;

const char * (*doom)(const char *);

const char* some(const char * bla)
{
    string blda=bla;
    blda=blda.append("Iron man is dead");
    return _strdup(blda.c_str());
}
int main()
{
    doom=some;
    print((*doom)("Pirates of the carribbian"));
	std::cin.get();
    return 0;
}