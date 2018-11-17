#include <iostream>
#include <map>
#include <cstdio> 
using namespace std; 

int main(){
	int ans = 0; 
	string paper,garland; 
	cin >> paper >> garland; 
	map<char,int> p,g; 
	for (int i = 0; i < paper.size(); i++){
		p[paper[i]]++;  
	}
	for (int i = 0; i < garland.size(); i++){
		g[garland[i]]++;  
	}
	for (map<char,int>::iterator it = g.begin(); it != g.end(); it++){
		if (!p.count(it->first)) return !printf("-1\n");  
		ans += min(it->second,p[it->first]);  
	}
	if (ans == 0){
		cout << -1 << endl; 
	}else{
		cout << ans << endl; 
	}
	return 0;  
}	
