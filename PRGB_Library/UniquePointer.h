#pragma once

template <typename T>
class UniquePointer
{
private:
	T* _ptr;

// Contructor / Destructor
public:
	UniquePointer(T* t) ;
	~UniquePointer();

// Operators
public:
	operator bool() const;
	T* operator->();
	T& operator*();
	UniquePointer(const UniquePointer& other) = delete;
	UniquePointer& operator= (const UniquePointer& source) = delete;

// Class Methods
public:
	T* release();
	void reset();
	void swap(T* other);
};

