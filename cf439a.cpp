#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
using namespace std;
int a[2001],b[2001];  
set<int> S; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		S.insert(a[i]); 
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];  
		S.insert(b[i]);  
	}
	// count the number of ordered pairs, such that 
	// xi ^ yj equals to one of the numbers in the set S 
	int cnt = 0; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (S.count(a[i]^a[j])){
				cnt++; 
			}
		}
	}
	cout << (cnt%2 == 0 ? "Karen" : "Koyomi") << endl; 
	return 0;  
}
