#include "pch.h"
#include "UniquePointer.h"

template<typename T>
UniquePointer<T>::UniquePointer(T* t) : _ptr(std::move(t))
{
}

template<typename T>
UniquePointer<T>::~UniquePointer()
{
	delete _ptr;
}

template<typename T>
UniquePointer<T>::operator bool() const
{
	return static_cast<bool>(_ptr);
}

template<typename T>
T* UniquePointer<T>::operator->()
{
	return _ptr;
}

template<typename T>
T& UniquePointer<T>::operator*()
{
	return *_ptr;
}

template<typename T>
T* UniquePointer<T>::release()
{
	T* ret = _ptr;
	_ptr = nullptr;
	return ret;
}

template<typename T>
void UniquePointer<T>::reset()
{
	delete _ptr;
	_ptr = nullptr;
}

template<typename T>
void UniquePointer<T>::swap(T* other)
{
	T save = *_ptr;
	*_ptr = *other;
	*other = save;	
}
