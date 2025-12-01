#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
#include <deque>

bool	Check_arg(int ac, char **av);
bool	Check_if_digit(char *av);
bool	Check_if_duplicate_numbers(int ac, char **av);
template <typename C>
bool IsSorted(const C &vec);

std::vector<int>	FordJohnsonSortVec(const std::vector<int>& v);
void	InsertVec(std::vector<int>& vec, int value);
std::vector<int>	JacobsthalSequenceVec(int n);
std::vector<int>	SortWithPairedVec(std::vector<int> vec, std::vector<std::pair<int,int> > pair);

std::deque<int>	FordJohnsonSortDeq(const std::deque<int>& V);
void	InsertDeq(std::deque<int>& vec, int value);
std::deque<int>	JacobsthalSequenceDeq(int n);
std::deque<int>	SortWithPairedDeq(std::deque<int> vec, std::deque<std::pair<int,int> > pair);