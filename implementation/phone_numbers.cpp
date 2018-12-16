#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
typedef pair<string,int> P; 
bool taxi(string s){
	return (s[0] == s[1] && s[1] == s[3] && s[3] == s[4] &&
		s[4] == s[6] && s[6] == s[7]); 
}
bool pizza(string s){
	return (s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && 
		s[4] > s[6] && s[6] > s[7]); 
}
bool cmp(P &p1,P &p2){
	return p1.second < p2.second; 
}
int main(){
	int n; 
	cin >> n;
	int taxiCnt = 0, pizzaCnt = 0, girlCnt = 0;
	vector<P> tl,pl,gl;  
	for (int i = 0; i < n; i++){
		int m, t = 0, p = 0, g = 0; 
		string name,number; 
		cin >> m >> name; 
		for (int j = 0; j < m; j++){
			cin >> number;  
			if (taxi(number)) t++; 
			else if (pizza(number)) p++; 
			else g++; 
		}	
		if (t > taxiCnt){
			taxiCnt = t;  
			tl.clear(); 
			tl.push_back(P(name,i)); 
		}else if (t == taxiCnt){
			tl.push_back(P(name,i)); 
		}
		if (p > pizzaCnt){
			pizzaCnt = p; 
			pl.clear(); 
			pl.push_back(P(name,i)); 
		}else if (p == pizzaCnt){
			pl.push_back(P(name,i)); 
		}
		if (g > girlCnt){
			girlCnt = g; 
			gl.clear(); 
			gl.push_back(P(name,i)); 
		}else if (g == girlCnt){
			gl.push_back(P(name,i)); 
		}
	}
	cout << "If you want to call a taxi, you should call: "; 
	sort(tl.begin(),tl.end(),cmp);  
	for (int i = 0; i < tl.size(); i++){
		if (i == tl.size()-1) cout << tl[i].first << ".\n"; 
		else cout << tl[i].first << ", "; 
	}
	cout << "If you want to order a pizza, you should call: "; 
	sort(pl.begin(),pl.end(),cmp);  
	for (int i = 0; i < pl.size(); i++){
		if (i == pl.size()-1) cout << pl[i].first << ".\n"; 
		else cout << pl[i].first << ", ";  
 	}
 	cout << "If you want to go to a cafe with a wonderful girl, you should call: "; 
 	sort(gl.begin(),gl.end(),cmp); 
 	for (int i = 0; i < gl.size(); i++){
 		if (i == gl.size()-1) cout << gl[i].first << ".\n"; 
 		else cout << gl[i].first << ", "; 
 	}
	return 0; 
}
