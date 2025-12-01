#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	clock_t start = clock();
	if (Check_arg(ac, av))
		return (1);
	std::vector<int> data;
	for (int i = 1; i < ac; i++) {
		int x = std::atoi(av[i]);
		data.push_back(x);
	}
	std::vector<int> sorted = FordJohnsonSortVec(data);
	clock_t end = clock();
	double elapsed = double(end - start * 1000000 / CLOCKS_PER_SEC);
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << elapsed << " µs" << std::endl;

	clock_t start2 = clock();
	if (Check_arg(ac, av))
		return (1);
	std::deque<int> data2;
	for (int i = 1; i < ac; i++) {
		int x = std::atoi(av[i]);
		data2.push_back(x);
	}
	std::deque<int> sorted2 = FordJohnsonSortDeq(data2);
	clock_t end2 = clock();
	double elapsed2 = double(end2 - start2 * 1000000 / CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque :" << elapsed2 << " µs" << std::endl;

	if (IsSorted(sorted))
		std::cout << "\033[1;32m[Sorted] For "<< ac -1 << " Elements with std::vector\033[0m"<< std::endl;
	else
		std::cout << "\033[1;31m[Not Sorted]\033[0m" << std::endl;
	if (IsSorted(sorted2))
		std::cout << "\033[1;32m[Sorted] For "<< ac -1 << " Elements with std::deque \033[0m"<< std::endl;
	else
		std::cout << "\033[1;31m[Not Sorted]\033[0m" << std::endl;
}

template <typename C>
bool IsSorted(const C &vec) {
	for (size_t i = 1; i < vec.size(); i++) {
		if (vec[i - 1] >= vec[i]) {
			return false;
		}
	}
	return true;
}