template <typename T>
Array<T>::Array() : array(NULL), len(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]),len(n) {

}

template <typename T>
Array<T>::Array(Array const &copy) : len(copy.len) {
	array = new T[len];
	for (size_t i = 0; i < len; i++)
		array[i] = copy.array[i];
}

template <typename T>
Array<T>::~Array() {
	delete [] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy) {
	if (this != &copy) {
		delete []array;
		len = copy.len;
		array = new T[len];
		for (size_t i = 0; i < len; i++)
			array[i] = copy.array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= len)
		throw OutOfBoundsException();
	return (array[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= len)
		throw OutOfBoundsException();
	return (array[i]);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw () {
	return ("Error: Index out of bounds");
}

template <typename T>
size_t Array<T>::size() const {
	return (len);
}