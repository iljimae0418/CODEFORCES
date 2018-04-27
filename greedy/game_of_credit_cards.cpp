#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
#include <vector> 
using namespace std; 
int main(){
	int n; 
	char c; 
	cin >> n; 
	vector<int> s(n),m(n); // sherlock, moriarty 
	for (int i = 0; i < n; i++){
		cin >> c; 
		s[i] = c-'0';  
	}
	for (int i = 0; i < n; i++){
		cin >> c;  
		m[i] = c-'0'; 
	}
	multiset<int> m1(m.begin(),m.end()),m2(m.begin(),m.end()); 
	// min possible flicks moriarty can get 
	int flicks_received = 0; 
	for (int i = 0; i < n; i++){
		if (*m1.rbegin() < s[i]){
			m1.erase(m1.begin()); 
			// getting a flick 
			flicks_received++; 
			continue; 
		}
		for (set<int>::iterator j = m1.begin(); j != m1.end(); j++){
			if (*j >= s[i]){
				m1.erase(j); 
				break; 
			}
		}
	}
	// max possible flicks moriarty can give  
	int flicks_given = 0; 
	for (int i = 0; i < n; i++){
		if (*m2.rbegin() < s[i]){
			m2.erase(m2.begin()); 
			continue; 
		}
		for (set<int>::iterator j = m2.begin(); j != m2.end(); j++){
			if (*j > s[i]){
				m2.erase(j); 
				flicks_given++;  
				break; 
			}
		}
	}
	cout << flicks_received << endl; 
	cout << flicks_given << endl;
	return 0; 
}
