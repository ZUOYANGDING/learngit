#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>

using namespace std;
typedef vector<string>::size_type line_number;

class R_Text;
class S_Text{
	public:
		friend class R_Text;
		S_Text(ifstream&);
		R_Text search(const string&) const;
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_number>>> wm;
};
S_Text::S_Text(ifstream& f):file(new vector<string>){
	string line;
	while(getline(f, line)){
		file->push_back(line);
		istringstream is(line);
		line_number number=(file->size())-1;
		string w;
		while(is>>w){
			auto& sp=wm[w];
			if(!sp)
				sp.reset(new set<line_number>);
			sp->insert(number);
		}
	}
}
class R_Text{
	friend ostream& print(ostream&, const R_Text&);
	public:
		R_Text(string w, shared_ptr<vector<string>> file, shared_ptr<set<line_number>> s):sought(w),text(file), line(s){}
	private:
		string sought;
		shared_ptr<vector<string>> text;
		shared_ptr<set<line_number>> line;
};
R_Text S_Text::search(const string& word) const{
	static shared_ptr<set<line_number>> nodata(new set<line_number>);
	auto location=wm.find(word);
	if(location!=wm.end())
		return R_Text(word, file, location->second);
	else
		return R_Text(word, file, nodata);
}
ostream& print(ostream& os, const R_Text& result){
	os<<result.sought<<" occurs "<<(result.line)->size()<<" "<<(((result.line)->size())>1 ? "times" : "time")<<endl;
	for(auto number : *(result.line))
		os<<"\t(line"<<" "<<number+1<<")"<<"\t"<<*(result.text->begin()+number)<<endl;
	return os;
}

int main(){
	ifstream input;
	input.open("text1");
	S_Text source(input);
	while(true){
		cout<<"input the word for search:"<<endl;
		string s;
		if(!(cin>>s) || (s=="q"))
			break;
		print(cout, source.search(s));
	}
	input.close();
	return 0;
}

