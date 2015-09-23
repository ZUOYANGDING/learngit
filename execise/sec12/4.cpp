#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;
class Strlobptr;
class Strlob{
	public:
		friend class Strlobptr;
		typedef vector<string>::size_type size_type;
		Strlob(): data(make_shared<vector<string>> ()) {}
		Strlob(vector<string> v): data(make_shared<vector<string>> (v)) {}
		size_type size () const {return data->size();}
		bool empty () const {return data->empty();}
		void push_back(const string& s) {data->push_back(s);}
		Strlobptr begin();
		Strlobptr end();
	private:
		shared_ptr<vector<string>> data;
};

class Strlobptr{
	public:
		Strlobptr(): curr(0) {}
		Strlobptr(Strlob& a, size_t sz=0): wptr(a.data), curr(sz) {}
		string& deref() const;
		Strlobptr& incr();
		bool operator !=(const Strlobptr& p){return p.curr!=curr;}
	private:
		shared_ptr<vector<string>> check(size_t, const string&) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};

Strlobptr Strlob::begin(){
	return Strlobptr(*this);
}
Strlobptr Strlob::end(){
	return Strlobptr(*this, data->size());
}
shared_ptr<vector<string>> Strlobptr::check(size_t i, const string& msg) const{
	auto p=wptr.lock();
	if(!p)
		throw runtime_error("unbound weak pointer");
	if(i>=p->size())
		throw out_of_range(msg);
	return p;
}
string& Strlobptr::deref() const{
	auto p=check(curr, "dereference past end");
	return (*p)[curr];
}
Strlobptr& Strlobptr::incr(){
	check(curr, "increment past end of the weak pointer");
	++curr;
	return *this;
}

int main(){
	ifstream f1("test");
	string line;
	Strlob s;
	while(getline(f1, line))
		s.push_back(line);
	Strlobptr s1(s.begin());
	Strlobptr s2(s.end());
	for(s1; s1!=s2; s1.incr())
		cout<<s1.deref()<<endl;
	f1.close();
	return 0;
}

