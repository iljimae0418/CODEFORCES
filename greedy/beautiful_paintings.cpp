#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[1001]; 
int used[1001]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n);  
	int cnt = 0;  
	for (int i = 0; i < n; i++){
		int x = i;  
		if (used[x]) continue;  
		used[x] = 1; 
		for (int j = i+1; j < n; j++){
			if (!used[j] && a[j] > a[x]){
				cnt++; 
				used[j] = 1; 
				x = j;  
			}
		}
	}
	cout << cnt << endl; 
	return 0; 
}
