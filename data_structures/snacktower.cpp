#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int fallen[100005];  
int main(){	
	int n,x; 
	cin >> n;
	int t = n; // t: top 
	for (int i = 1; i <= n; i++){
		cin >> x;  
		fallen[x] = 1; 
		if (x == t){
			while (fallen[t] == 1){
				cout << t << " "; 
				t--; 
			}
			cout << endl; 
		}else{
			cout << endl; 
		}
	}
	return 0; 
}
