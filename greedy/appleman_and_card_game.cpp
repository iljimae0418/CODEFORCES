#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
typedef pair<int,char> P;  
bool cmp(P &p1,P &p2){
	return p1.first > p2.first; 
}
int main(){
	int n,k; 
	cin >> n >> k; 
	string s; 
	cin >> s;  
	map<char,int> mp,toastman; 
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++; 
	}
	vector<P> v; 
	for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
		v.push_back(P(it->second,it->first)); 
	}
	sort(v.begin(),v.end(),cmp); 
	int idx = 0; 
	while (k > 0){
		int sub = min(v[idx].first,k); 
		toastman[v[idx].second] = sub; 
		k -= sub;  
		idx++;  
	}
	typedef long long ll;  
	ll ans = 0;  
	for (map<char,int>::iterator it = toastman.begin(); it != toastman.end(); it++){
		ans += (ll)it->second * (ll)it->second; 
	}
	cout << ans << endl; 
	return 0;  
}	
