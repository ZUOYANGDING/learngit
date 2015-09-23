#include <iostream>
#include <string>

using namespace std;

class the_Date{
	public:
		the_Date(const string &s);
		string year;
		string date;
		string month;
};
the_Date::the_Date(const string &s){
	if (s.find_first_of("/")!=string::npos){
		month=s.substr(s.find_first_of("/")-1, 1);
		date=s.substr(s.find_first_of("/")+1, 1);
		year=s.substr(s.find_last_of("/")+1);
	}else{
		month=s.substr(0, s.find_first_of(" "));
		date=s.substr(s.find_first_of(" ")+1, 1);
		year=s.substr(s.find_last_of(",")+1);
	}
}




int main(){
	string s;
	getline(cin, s);
	the_Date data(s);
	cout<<"Year: "<<data.year<<endl;
	cout<<"Month: "<<data.month<<endl;
	cout<<"Date: "<<data.date<<endl;
	return 0;
}
	
