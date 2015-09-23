#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	ifstream in("text");
	ofstream out1, out2;
	out1.open("even", ofstream::out);
	out2.open("odd", ofstream::out);
	istream_iterator<int> is_int(in), eof;
	ostream_iterator<int> os_int1(out1, "\n");
	ostream_iterator<int> os_int2(out2, "\n");
	vector<int> v1;
	vector<int> v2;
	while(is_int!=eof){
		if ((*is_int)%2==0)
			v1.push_back(*is_int++);
		else
			v2.push_back(*is_int++);
	}
	copy(v1.begin(), v1.end(), os_int1);
	copy(v2.begin(), v2.end(), os_int2);
	in.close();
	out1.close();
	out2.close();
	return 0;
}

