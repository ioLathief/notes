#include <iostream>
#include <vector>

template<typename T>
void print_vec(std::vector<T> &myvector)
{
    std::cout << "all in here : ";
    for (auto &x: myvector)
        std::cout << ' ' << x;
    std::cout << '\n';
}


int main()
{
    std::cout << "somethng" << std::endl;
    std::cin.get();
    return 0;
}

/*
 int main()
{
	std::vector<int>           layer{1};
	std::vector<int>::iterator iter;
	iter = layer.begin();

#define iter_em(x) iter=layer.emplace(iter, x); print_vec(layer);

	print_vec(layer);
	iter_em(10)
	iter_em(2)
	iter_em(3)
	iter_em(4)
std::cout<<"\n\n\n-------------------------------\n\n\n"<<std::endl;
	std::vector<int> vec = {10,20,30};
	print_vec(vec);

	std::vector<int>::iterator it = vec.begin();

	it = vec.emplace ( vec.begin(), 100 );
	print_vec(vec);

	it=vec.emplace ( it, 200 );
	print_vec(vec);

	vec.emplace ( it, 300 );
	print_vec(vec);
}

 * */