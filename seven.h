#ifndef _SEVEN_H_
#define _SEVEN_H_

#include <memory>
#include <string>

class Str_vec
{
	public:
		Str_vec();
		Str_vec(const Str_vec&);
		Str_vec& operator=(const Str_vec&);
		~Str_vec();
		size_t size () const;
		size_t capacity() const;
		void push_back(const std::string&);
		std::string *begin() const;
		std::string *end() const;
		void resize(size_t);
		void resize(size_t, const std::string&);
		void reserve(size_t);
	private:
		static std::allocator<std::string> alloc;
		void free();
		void move_n_alloc(size_t);
		void reallocate();
		void chk_n_alloc();
		std::pair<std::string*, std::string*> alloc_n_copy
			(const std::string*, const std::string*);
		std::string *element;
		std::string *first_free;
		std::string *cap;
};
#endif

