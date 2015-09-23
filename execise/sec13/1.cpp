#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CopyVector{
	public:
		CopyVector(istream&);
		CopyVector& operator=(const CopyVector&);
		void print(ostream&);
	private:
		vector<string> v;
};
CopyVector::CopyVector(istream& is){
	string temp;
	for(int i=0; i!=4; i++){
		getline(is, temp);
		v.push_back(temp);
	}
}
CopyVector& CopyVector::operator=(const CopyVector& ve){
	copy(ve.v.begin(), ve.v.begin(), v.begin());
}
void CopyVector::print(ostream& os){
	os<<"output"<<endl;
	for(auto i : v)
		os<<i<<endl;
}
int main(){
	CopyVector v1(cin);
	CopyVector v2(cin);
	v2=v1;
	v2.print(cout);
}


