// requires extremely meticulous caseworks 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <set> 
using namespace std;  
typedef long long ll;  
ll a[100005];  
int main(){
	map<ll,ll> mp; 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n);  
	for (int i = 0; i < n-1; i++){
		mp[a[i+1]-a[i]]++;  
	}
	if (n == 1){
		// infinitely many solutions 
		cout << -1 << endl; 
	}else if (mp.size() > 2){
		// cannot become an arithmetic sequence with only 
		// a single addition of a new number 
		cout << 0 << endl; 
	}else if (mp.size() == 1){
		set<ll> st; 
		if (n == 2){
			map<ll,ll>::iterator it = mp.begin();  
			ll d = it->first;  
			if (d%2 == 0){
				st.insert(a[0]-d); 
				st.insert(a[0]+d/2);  
				st.insert(a[1]+d);  
				cout << st.size() << endl; 
				for (set<ll>::iterator it = st.begin(); it != st.end(); it++){
					cout << *it << " ";  
				}
				cout << endl; 
			}else{
				st.insert(a[0]-d); 
				st.insert(a[1]+d);  
				cout << st.size() << endl; 
				for (set<ll>::iterator it = st.begin(); it != st.end(); it++){
					cout << *it << " "; 
				}
				cout << endl; 
			}
		}else{
			map<ll,ll>::iterator it = mp.begin(); 
			ll d = it->first;    
			st.insert(a[0]-d); 
			st.insert(a[n-1]+d);  
			cout << st.size() << endl; 
			for (set<ll>::iterator it = st.begin(); it != st.end(); it++){
				cout << *it << " "; 
			}
			cout << endl; 
		}
	}else if (mp.size() == 2){
		map<ll,ll>::iterator it = mp.begin(); 
		map<ll,ll>::reverse_iterator it2 = mp.rbegin();  
		if (it->first != it2->first/2 || it->second < it2->second){
			cout << 0 << endl; // no solution 
		}else if (it->second > 1 && it2->second > 1){
			cout << 0 << endl; 
		}else if (it->first == 0 || it2->first == 0){
			cout << 0 << endl; 
		}else{
			cout << 1 << endl; 
			for (int i = 0; i < n-1; i++){
				if (a[i+1]-a[i] == it2->first){
					cout << a[i]+it->first << endl; 
					break; 
				}
			}
		}
	}
	return 0;  
}
