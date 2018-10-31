#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int main(){
	int n,x,last = 1; 
	long long f_sum = 0,s_sum = 0; 
	cin >> n; 
	vector<int> f,s; // first and second wrestlers respectively
	for (int i = 0; i < n; i++){
		cin >> x;  
		if (x > 0){
			f.push_back(x); 
			f_sum += x; 
			if (i == n-1) last = 1;  
		}else{
			s.push_back(-x);
			s_sum += -x;   
			if (i == n-1) last = 2;   
		}
	}
	if (f_sum > s_sum){
		cout << "first" << endl; 
	}else if (f_sum < s_sum){
		cout << "second" << endl; 
	}else if (f_sum == s_sum){
		if (f == s){
			// if equal length and equal components 
			// look at who performed the last technique 
			cout << (last == 1 ? "first" : "second") << endl; 
		}else{
			bool determined = false; 
			for (int i = 0; i < min(f.size(),s.size()); i++){
				if (f[i] > s[i]){
					determined = true; 
					cout << "first" << endl; 
					break; 
				}else if (f[i] < s[i]){
					determined = true; 
					cout << "second" << endl; 
					break; 
				}
			}
			if (!determined){
				cout << (f.size() > s.size() ? "first" : "second") << endl; 
			}
		}
	}
	return 0; 
}
