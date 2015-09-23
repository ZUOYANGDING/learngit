#include <iostream>
#include <vector>
#include <list>
//using std::vector;
//using std::string;
using namespace std;

int main(){
	string s;
	vector<string> v{"a", "an", "and"};
	list<const char*> l{"a", "an", "and", "others"};
	cout<<(equal(v.cbegin(), v.cend(), l.cbegin()) ? "equal" : "not equal")<<endl;
	return 0;
}
