#pragma once
class String
{
private:
	size_t _length;
	char* _str;

// Constructors / Destructor
public:
	String();
	String(const char* val);
	~String();

// Class Methods
public:
	char* c_str();
	size_t getLength() const;
	void Concatenate(String s2);

// Operators
public:
	String& operator+=(const String& other);
	String operator+(const String& other) const;

// Conversions
public:
	operator char* () const;

// Rule of 5
public:
	// Copy
	String(const String& other);
	// Move
	String(String&& other) noexcept;
	// Copy Assignment
	String& operator= (const String& source);
	// Move Assignment
	String& operator= (String&& source) noexcept;

// Static Methods
public:
	static String Concatenate(String s1, String s2);

// Iterator
	class Iterator {
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = char;
		using pointer = value_type*;
		using reference = value_type&;

	private:
		pointer m_Ptr;

	// Constructor
	public:
		Iterator(pointer ptr);

	// Operators
	public:
		Iterator& operator++();
		Iterator& operator++(int);
		Iterator& operator--();
		Iterator& operator--(int);
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
		reference operator[](int index);
		pointer operator->();
		reference operator*();
	};

	Iterator begin() const;
	Iterator end() const;
};