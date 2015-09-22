#include <iostream>
#include "seven.h"
/*need to be improved*/
std::allocator<std::string> Str_vec::alloc;

Str_vec::Str_vec() :
	element(nullptr), first_free(nullptr), cap(nullptr)
{}

void Str_vec::free()
{
	if (element)
	{
		std::string *temp=first_free;
		while(temp!=element)
		{
			alloc.destroy(--temp);
		}
		alloc.deallocate(element, cap-first_free);
	}
}

void Str_vec::chk_n_alloc()
{
	if (size() == capacity())
	{
		reallocate();
	}
}

void Str_vec::move_n_alloc(size_t n)
{
	auto new_data=alloc.allocate(n);
	auto dest=new_data;
	auto original=element;
	for (size_t i=0; i!=size(); ++i)
	{
		alloc.construct(dest++, std::move(*original++));
	}
	free();
	element=new_data;
	first_free=dest;
	cap=element+n;
}

void Str_vec::reallocate()
{
	size_t new_capacity=size() ? 2*size() : 1;
	move_n_alloc(new_capacity);
}

std::pair<std::string*, std::string*> Str_vec::alloc_n_copy
			(const std::string *b, const std::string *e)
{
	auto data=alloc.allocate(e-b);
	auto new_end=std::uninitialized_copy(b, e, data);
	return {data, new_end};
}

Str_vec::Str_vec(const Str_vec &v)
{
	auto new_data=alloc_n_copy(v.begin(), v.end());
	element=new_data.first;
	first_free=new_data.second;
	cap=first_free;
}

Str_vec& Str_vec::operator=(const Str_vec &vec)
{
	free();
	auto data=alloc_n_copy(vec.begin(), vec.end());
	element=data.first;
	first_free=data.second;
	cap=first_free;
	return *this;
}

Str_vec::~Str_vec()
{
	free();
}

size_t Str_vec::size() const
{
	return first_free-element;
}

size_t Str_vec::capacity() const
{
	return cap-element;
}

void Str_vec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::string* Str_vec::begin() const
{
	return element;
}

std::string* Str_vec::end() const
{
	return first_free;
}

void Str_vec::resize(size_t n)
{
	resize(n, std::string());
}

void Str_vec::resize(size_t n, const std::string &s)
{
	if (n<size())
	{
		auto temp=size()-n;
		for (size_t i=0; i!=temp; ++i)
		{
			alloc.destroy(--first_free);
		}
	}
	else if (n>size() && n<=capacity())
	{
		auto temp=n-size();
		for (size_t i=0; i!=temp; ++i)
		{
			alloc.construct(first_free++, s);
		}
	}
	else if (n>capacity())
	{
		while (n>capacity())
		{
			reallocate();
		}
		auto temp=n-size();
		for (size_t i=0; i!=temp; ++i)
		{
			alloc.construct(first_free++, s);
		}
	}
}

void Str_vec::reserve(size_t n)
{
	if (n<capacity())
	{
		return;
	}
	else
	{
		move_n_alloc(n);
	}
}


int main()
{
	std::string s;
	Str_vec v;
	v.reserve(5);
	for (int i=0; i!=5; ++i)
	{
		getline(std::cin, s);
		v.push_back(s);
	}
	for (auto i=v.begin(); i!=v.end(); ++i)
	{
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	v.reserve(10);
	v.resize(10, "s");
	for (auto i=v.begin(); i!=v.end(); ++i)
	{
		std::cout<<*i<<" ";
	}
	std::cout<<std::endl;
	return 0;
}

	


