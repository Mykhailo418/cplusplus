#pragma once // need to correctly parse headers and give feature to include thisheader only once

// Smart Pointer
template <typename T>
class ScopedPtr
{
public:
	explicit ScopedPtr(T* ptr);
	~ScopedPtr();
	T& operator*();
	T* operator->();

private:
	T* ptr;
};

