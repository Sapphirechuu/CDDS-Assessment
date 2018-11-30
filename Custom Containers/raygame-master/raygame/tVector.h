#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array
	tVector(const tVector &other);

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store

	/*bool empty() const;
	void resize(size_t newSize);
	void shrink_to_fit();
	void clear();

	tVector& operator = (const tVector &rhs);

	T& operator[] (size_t index);*/
	
};

template<typename T>
tVector<T>::tVector()
{
	arr = nullptr;
	arrSize = arrCapacity = 0;
}

template<typename T>
tVector<T>::~tVector()
{
	delete[] arr;
}

template<typename T>
tVector<T>::tVector(const tVector &other)
{
	arr = new T[other.arrCapacity];

	for (size_t i = 0; i < other.arrSize; ++i)
	{
		arr[i] = other.arr[i];
	}
	arrSize = other.arrSize;

}

template<typename T>
T * tVector<T>::data()
{
	return arr;
}

template<typename T>
void tVector<T>::reserve(size_t newCapacity)
{
	if (newCapacity <= arrCapacity)
	{
		return;
	}

	T* temp = new T[newCapacity];

	for (size_t i = 0; i < arrSize; ++i)
	{
		temp[i] = arr[i];
	}

	delete[] arr;
	arr = temp;
	arrCapacity = newCapacity;
}

template<typename T>
void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity)
	{
		if (arrCapacity == 0)
		{
			reserve(1);
		}
		else
		{
			reserve(arrCapacity * GROWTH_FACTOR);
		}
	}

	arr[arrSize++] = value;
}

template<typename T>
void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
T & tVector<T>::at(size_t index)
{
	return arr[index];
}

template<typename T>
size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

//template<typename T>
//bool tVector<T>::empty() const
//{
//	return arrSize == 0;
//}
//
//template<typename T>
//void tVector<T>::resize(size_t newSize)
//{
//	reserve(newSize);
//
//	if (newSize < arrSize)
//	{
//		arrSize = newSize;
//	}
//	else
//	{
//		for (size_t i = arrSize; i < newSize; ++i)
//		{
//			push_back(T());
//		}
//	}
//}
//
//template<typename T>
//void tVector<T>::shrink_to_fit()
//{
//	if (arrSize == arrCapacity)
//	{
//		return;
//	}
//
//	T* temp = new T[arrSize];
//	for (size_t i = 0; i < arrSize; ++i)
//	{
//		temp[i] = arr[i];
//	}
//	delete[] arr;
//	arr = temp;
//	arrSize = arrCapacity = arrSize;
//}
//
//
//
//template<typename T>
//tVector & tVector<T>::operator=(const tVector & rhs)
//{
//	delete[] arr;
//
//	arr = new T[rhs.arrCapacity];
//}
//
//template<typename T>
//T & tVector<T>::operator[](size_t index)
//{
//	// TODO: insert return statement here
//}
