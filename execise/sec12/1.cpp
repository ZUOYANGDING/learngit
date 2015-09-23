#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <memory>

using namespace std;

class Strlob{
	public:
		typedef vector<string>::size_type size_type;
		Strlob(): data(make_shared<vector<string>>()){}
		Strlob(initializer_list<string> l) : data(make_shared<vector<string>> (l)) {}
		size_type const size() {return data->size();}
		bool empty () const {return data->empty();}
		string& front();
		string& back();
		void push_back(const string& t) {data->push_back(t);}
		void pop_back();
	private:
		shared_ptr<vector<string>> data;
		void check(size_type, const string&) const;
};

void Strlob::check(size_type size, const string& msg) const{
	if (size>=data->size())
		throw out_of_range(msg);
}

void Strlob::pop_back(){
	check(0, "pop_back on the empty Strlob");
	data->pop_back();
}

string& Strlob::front(){
	check(0, "The front of the empty Strlob");
	return data->front();
}

string& Strlob::back(){
	check(0, "The back of the empty Strlob");
	return data->back();
}

int main(){
	Strlob s1;
	if(s1.empty()){
		Strlob s2={"I", "have", "a", "football"};
		s1=s2;
	}
	s1.push_back("haha!");
	cout<<s1.front()<<endl;
	cout<<s1.back()<<endl;
	while(!s1.empty()){
		cout<<s1.back()<<endl;
		s1.pop_back();
	}
	return 0;
}


