#pragma once

template <typename T>
class Atemp
{
	Atemp() = default;
	Atemp(const Atemp&) = default;
	Atemp(const T& _data) : data(_data)
	{
	}

	T data;
};