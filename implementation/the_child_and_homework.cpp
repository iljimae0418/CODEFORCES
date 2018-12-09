#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
typedef pair<string,int> P; 
bool cmp(P &p1,P &p2){
	return p1.first.size() < p2.first.size();  
}
int main(){
	map<int,char> mp; 
	mp[0] = 'A'; 
	mp[1] = 'B'; 
	mp[2] = 'C'; 
	mp[3] = 'D';  
	vector<P> v; 
	char p,c;  
	string s; 
	for (int i = 0; i < 4; i++){
		cin >> p >> c; 
		cin >> s;  
		v.push_back(P(s,i)); 
	}
	sort(v.begin(),v.end(),cmp);  
	bool shortest_exist = false, longest_exist = false;  
	if (v[0].first.size()*2 <= v[1].first.size()){
		shortest_exist = true;  
	}
	if (v[2].first.size()*2 <= v[3].first.size()){
		longest_exist = true; 
	}
	if (shortest_exist && !longest_exist){
		cout << mp[v[0].second] << "\n"; 
	}else if (!shortest_exist && longest_exist){
		cout << mp[v[3].second] << "\n"; 
	}else{
		cout << "C" << endl; 
	}
	return 0;  
}
