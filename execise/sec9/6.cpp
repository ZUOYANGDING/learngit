#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
	stack<char> sta;
	string s;
	auto& expr="This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
	int signal=0;
	int count=1;
	char pro='*';
	for(auto& c : expr){
		sta.push(c);
		if(c=='(')
			signal++;
		if(c==')' && signal!=0){
			while(sta.top()!='('){
				if(sta.top()==pro){
					count++;
					sta.pop();
				}else
					sta.pop();
			}
			sta.pop();
			while(count){
				sta.push(pro);
				count--;
			}
			count=1;
			signal--;
		}
	}
	while(!sta.empty()){
		s.insert(s.begin(), sta.top());
		sta.pop();
	}
	cout<<s<<endl;
	return 0;
}
		
