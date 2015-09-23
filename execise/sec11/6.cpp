#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

map<string, string>* t_map(ifstream& source){
	static map<string, string> m;
	string s;
	while(getline(source, s)){
		istringstream one_line(s);
		string key, words;
		while(one_line>>key && getline(one_line, words)){
			if (words.size()<1)
				throw runtime_error("There is no rule for key: "+key);
			else
				m[key]=words.substr(1);
		}
	}
	return &m;
}

void trans_form(ifstream& input, ifstream& source){
	map<string, string>* trans_map=t_map(source);
	string line;
	while(getline(input, line)){
		istringstream one_line(line);
		string word;
		while(one_line>>word){
			auto index=(*trans_map).find(word);
			if (index==(*trans_map).end())
				cout<<word<<" ";
			else
				cout<<index->second<<" ";
		}
		cout<<"\n";
	}
}



int main(){
	ifstream input, source;
	input.open("map", ifstream::in);
	source.open("source_text", ifstream::in);
	if (!input.is_open() || !source.is_open()){
		throw runtime_error("cannot open the file\n");
		exit(1);
	}
	trans_form(input, source);
	input.close();
	source.close();
	return 0;
}

