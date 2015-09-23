#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

int main(){
	vector<string> v;
	ifstream in("text");
	istream_iterator<string> str_it(in);
	ostream_iterator<string> str_ot(cout, " ");
	istream_iterator<string> eof;
	while(str_it!=eof)
		v.push_back(*str_it++);
	for(auto i : v)
		str_ot=i;
	cout<<endl;
	in.close();
	return 0;
}

