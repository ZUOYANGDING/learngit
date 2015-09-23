#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Sales_data{
	public:
		Sales_data(const string& s): bookNO(s){}
		string isbn() const {return bookNO;}
	private:
		string bookNO;
};

int main(){
	vector<string> v;
	string s;
	while(cin>>s){
		Sales_data books_no(s);
		v.push_back(books_no.isbn());
	}
	for(auto i : v)
		cout<<i<<endl;
	sort(v.begin(), v.end());
	for(auto i : v)
		cout<<i<<endl;
	return 0;
}

