#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
vector<string> v; 
int n; 
string s,t,ans; 
void init(){
	v.push_back("012"); 
	v.push_back("021"); 
	v.push_back("102"); 
	v.push_back("120"); 
	v.push_back("201"); 
	v.push_back("210"); 
}
int edit(int offset,char type){
	int ret = 0; 
	if (type == '0'){
		for (int i = offset; i < s.size(); i += 3){
			if (s[i] != 'R'){
				ret++; 
				t[i] = 'R';  
			}
		}
	}else if (type == '1'){
		for (int i = offset; i < s.size(); i += 3){
			if (s[i] != 'G'){
				ret++;  
				t[i] = 'G';  
			}
		}
	}else if (type == '2'){
		for (int i = offset; i < s.size(); i += 3){
			if (s[i] != 'B'){
				ret++;  
				t[i] = 'B'; 
			}
		}
	}
	return ret; 
}
int main(){
	init(); 
	cin >> n; 
	cin >> s; 
	int mincnt = 1e9;  
	for (int i = 0; i < v.size(); i++){
		string x = v[i]; 
		int cnt = 0; 
		t = s; 
		cnt += edit(0,x[0])+edit(1,x[1])+edit(2,x[2]); 
		if (mincnt > cnt){
			mincnt = cnt; 
			ans = t; 
		}
	}
	cout << mincnt << endl; 
	cout << ans << endl; 
	return 0; 
}
