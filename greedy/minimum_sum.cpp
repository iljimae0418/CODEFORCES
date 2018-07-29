#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <map> 
#include <sstream> 
#include <set> 
using namespace std; 
typedef pair<int,char> P; 
int used[10]; 
int toInt(string s){
	istringstream iss (s); 
	int n; 
	iss >> n;    
	return n;  
}	
int main(){
	int n; 
	cin >> n; 
	vector<string> v(n); 
	set<char> isFirstDigit;
	for (int i = 0; i < n; i++){
		cin >> v[i]; 
		isFirstDigit.insert(v[i][0]);  
	}
	map<char,int> w; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < v[i].size(); j++){
			w[v[i][j]] += pow(10,v[i].size()-j-1);  
		}
	}
	vector<P> sorted; 
	for (map<char,int>::iterator it = w.begin(); it != w.end(); it++){
		sorted.push_back(P(it->second,it->first));  
	}
	sort(sorted.begin(),sorted.end());  
	map<char,int> f; 
	for (int i = sorted.size()-1; i >= 0; i--){
		if (isFirstDigit.count(sorted[i].second)){
			for (int j = 1; j < 10; j++){
				if (!used[j]){
					f[sorted[i].second] = j; 
					used[j] = 1; 
					break; 
				}
			}
		}else{
			for (int j = 0; j < 10; j++){
				if (!used[j]){
					f[sorted[i].second] = j; 
					used[j] = 1;  
					break; 
				}
			}
		}
	}
	long long ans = 0; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < v[i].size(); j++){
			v[i][j] = char(f[v[i][j]]+'0'); 
		}
		ans += toInt(v[i]); 
	}
	cout << ans << endl; 
	return 0; 
}		
