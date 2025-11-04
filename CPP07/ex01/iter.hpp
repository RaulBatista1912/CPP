#pragma once
#include <string>

template <typename T>
void iter(T *array, const size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void iter(T *array, const size_t len, void (*func)(const T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

