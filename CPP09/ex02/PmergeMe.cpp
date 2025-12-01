#include "PmergeMe.hpp"

bool	Check_arg(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: Arguments needed" << std::endl;
		return (true);
	}
	for(int i = 1; i < ac; i++) {
		if (Check_if_digit(av[i])) {
			std::cerr << "Error: Multiple arguments of positive integers required" << std::endl;
			return (true);
		}
	}
	if (Check_if_duplicate_numbers(ac, av)) {
		std::cerr << "Error: Duplicate numbers are not allowed" << std::endl;
		return (true);
	}
	return (false);
}

bool	Check_if_digit(char *av) {
	for(size_t i = 0; i < strlen(av); i++) {
		if (!std::isdigit(av[i]))
			return (true);
	}
	return (false);
}

bool	Check_if_duplicate_numbers(int ac, char **av) {
	for(int i = 1; i < ac; i++) {
		for (int j = 1; j < i; j++) {
			if (std::strcmp(av[i], av[j]) == 0)
				return (true);
		}
	}
	return (false);
}

std::vector<int> JacobsthalSequenceVec(int n) {
	std::vector<int> J;
	if (n <= 0)
		return J;

	int j0 = 1;
	int j1 = 3;

	J.push_back(j0);
	if (n == 1)
		return J;
	J.push_back(j1);
	while (true)
	{
		int j2 = j1 + 2 * j0;
		if (j2 > n)
			break;
		J.push_back(j2);
		j0 = j1;
		j1 = j2;
	}
	return J;
}


void	InsertVec(std::vector<int>& vec, int value) {
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}

std::vector<int>	SortWithPairedVec(std::vector<int> vec, std::vector<std::pair<int,int> > pair) {
	std::vector<int> result;

	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < pair.size(); j++) {
			if (vec[i] == pair[j].second) {
				result.push_back(pair[j].first);
				break;
			}
			else if (vec[i] == pair[j].first) {
				result.push_back(pair[j].second);
				break;
			}
		}
	}
	return (result);
}

std::vector<int>	FordJohnsonSortVec(const std::vector<int>& V) {
	int n = V.size();
	if (n <= 1)
		return V;

	std::vector<int> larger;
	std::vector<int> smaller;
	std::vector< std::pair<int,int> > pairs;

	for (int i = 0; i + 1 < n; i += 2)
			pairs.push_back(std::make_pair(V[i], V[i + 1]));

	int	lastOdd = (n % 2) ? V[n - 1] : -1;

	for (int i = 0; i < (int)pairs.size(); i++) {
		if (pairs[i].first > pairs[i].second) {
			larger.push_back(pairs[i].first);
			smaller.push_back(pairs[i].second);
		} else {
			larger.push_back(pairs[i].second);
			smaller.push_back(pairs[i].first);
		}
	}

	std::vector<int> S = FordJohnsonSortVec(larger);
	std::vector<int> K = SortWithPairedVec(S, pairs);
	std::vector<int> J = JacobsthalSequenceVec(K.size());
	//std::cout << "Jacob :";
	//for (size_t i = 0; i < J.size(); i++) {
	//	std::cout << J[i] << " ";
	//}
	//std::cout << "\n";
	//std::cout << "S :";
	//for (size_t i = 0; i < S.size(); i++) {
	//	std::cout << S[i] << "[" << i + 1 << "]"<<" ";
	//}
	//std::cout << "\n" << "K :";
	//for (size_t i = 0; i < K.size(); i++) {
	//	std::cout << K[i] << "[" << i + 1 << "]" << " ";
	//}
	//std::cout << "\n";
	for (size_t i = 0; i < J.size(); i++) {
		if (J[i] == 1) {
			//std::cout << "Insert1 : " << K[0] << std::endl;
			S.insert(S.begin(), K[0]);
			continue;
		}
		int	k = J[i];
		while ((int)K.size() < k)
			k--;
		while(k != J[i - 1]) {
			//std::cout << "Insert2 : " << K[k - 1] << std::endl;
			InsertVec(S, K[k - 1]);
			k--;
		}
	}
	if (J.back() < (int)K.size()) {
		for (int i = K.size(); i != J.back(); i--) {
			//std::cout << "Insert3 : " << K[i - 1] << std::endl;
			InsertVec(S, K[i - 1]);
		}
	}
	if (lastOdd != -1) {
		//std::cout << "Insert4 : " << lastOdd << std::endl;
		InsertVec(S, lastOdd);
	}
	return S;
}

std::deque<int>	FordJohnsonSortDeq(const std::deque<int>& V) {
	int n = V.size();
	if (n <= 1)
		return V;

	std::deque<int> larger;
	std::deque<int> smaller;
	std::deque< std::pair<int,int> > pairs;

	for (int i = 0; i + 1 < n; i += 2)
			pairs.push_back(std::make_pair(V[i], V[i + 1]));

	int	lastOdd = (n % 2) ? V[n - 1] : -1;

	for (int i = 0; i < (int)pairs.size(); i++) {
		if (pairs[i].first > pairs[i].second) {
			larger.push_back(pairs[i].first);
			smaller.push_back(pairs[i].second);
		} else {
			larger.push_back(pairs[i].second);
			smaller.push_back(pairs[i].first);
		}
	}

	std::deque<int> S = FordJohnsonSortDeq(larger);
	std::deque<int> K = SortWithPairedDeq(S, pairs);
	std::deque<int> J = JacobsthalSequenceDeq(K.size());

	for (size_t i = 0; i < J.size(); i++) {
		if (J[i] == 1) {
			S.insert(S.begin(), K[0]);
			continue;
		}
		int	k = J[i];
		while ((int)K.size() < k)
			k--;
		while(k != J[i - 1]) {
			InsertDeq(S, K[k - 1]);
			k--;
		}
	}
	if (J.back() < (int)K.size()) {
		for (int i = K.size(); i != J.back(); i--) {
			InsertDeq(S, K[i - 1]);
		}
	}
	if (lastOdd != -1) {
		InsertDeq(S, lastOdd);
	}
	return S;
}

std::deque<int> JacobsthalSequenceDeq(int n) {
	std::deque<int> J;
	if (n <= 0)
		return J;

	int j0 = 1;
	int j1 = 3;

	J.push_back(j0);
	if (n == 1)
		return J;
	J.push_back(j1);
	while (true) {
		int j2 = j1 + 2 * j0;
		if (j2 > n)
			break;
		J.push_back(j2);
		j0 = j1;
		j1 = j2;
	}

	return J;
}

void	InsertDeq(std::deque<int>& vec, int value) {
	std::deque<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
	vec.insert(it, value);
}

std::deque<int>	SortWithPairedDeq(std::deque<int> vec, std::deque<std::pair<int,int> > pair) {
	std::deque<int> result;

	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < pair.size(); j++) {
			if (vec[i] == pair[j].second) {
				result.push_back(pair[j].first);
				break;
			}
			else if (vec[i] == pair[j].first) {
				result.push_back(pair[j].second);
				break;
			}
		}
	}
	return (result);
}
