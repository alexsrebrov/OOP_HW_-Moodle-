#pragma once
#include <iostream>
#define TT template<typename T>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

static constexpr size_t defCap = 10;


TT
class MyVector
{
public:
	MyVector();
	explicit MyVector(size_t capacity);
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other);
	MyVector& operator=(MyVector&& other);
	~MyVector();

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

	void add(const T& other);
	void remove(size_t index);

	bool has(const T& el) const;
	size_t getIndex(const T& el) const;
	size_t getSize() const;
	size_t getCapacity() const;
	void clear();
	bool empty() const;
	void setCapacity(size_t newCap);

	void printAll() const;
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCap);
	void free();
	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);
};

TT
inline MyVector<T>::MyVector() : MyVector(defCap) {}

TT
inline MyVector<T>::MyVector(size_t capacity)
{
	this->capacity = capacity;
	this->size = 0;
	data = new T[capacity];
}

TT
inline MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}

TT
inline MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

TT
inline MyVector<T>::MyVector(MyVector&& other)
{
	moveFrom(std::move(other));
}

TT
inline MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

TT
inline MyVector<T>::~MyVector()
{
	free();
}

TT
inline const T& MyVector<T>::operator[](size_t index) const
{
	if (index >= capacity){ throw std::invalid_argument("Invalid index");}
	return data[index];
}

TT
inline T& MyVector<T>::operator[](size_t index)
{
	if (index >= capacity) { throw std::invalid_argument("Invalid index"); }
	return data[index];
}

TT
inline void MyVector<T>::add(const T& other)
{
	if (size >= capacity) resize(capacity * 2);
	data[size++] = other;
}

TT
inline void MyVector<T>::remove(size_t index)
{
	if (index >= size) return;
	std::swap(data[index], data[--size]);
}

TT
inline bool MyVector<T>::has(const T& el) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == el) return true;
	};
	return false;
}

TT
inline size_t MyVector<T>::getIndex(const T& el) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == el) return i;
	};
	throw std::invalid_argument("Invalid index");	
}

TT
inline size_t MyVector<T>::getSize() const
{
	return this->size;
}

TT
inline size_t MyVector<T>::getCapacity() const
{
	return capacity;
}

TT
inline void MyVector<T>::clear()
{
	size = 0;
}

TT
inline bool MyVector<T>::empty() const
{
	return !size;
}

TT
inline void MyVector<T>::setCapacity(size_t newCap)
{
	resize(newCap);
}

TT
inline void MyVector<T>::printAll() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << data[i];
	}
}

TT
inline void MyVector<T>::resize(size_t newCap)
{
	if (size >= newCap) newCap = size * 2;
	T* newData = new T[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newCap;
}

TT
inline void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

TT
inline void MyVector<T>::copyFrom(const MyVector& other)
{
	size = other.size;
	capacity = other.capacity;
	if (capacity <= size) capacity = size;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

TT
inline void MyVector<T>::moveFrom(MyVector&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
}

