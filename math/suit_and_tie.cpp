#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[202]; 
typedef pair<int,int> P; 
int main(){
	int n,cnt = 0; 
	cin >> n; 
	for (int i = 1; i <= 2*n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= 2*n; i++){
		for (int j = i+1; j <= 2*n; j++){
			if (a[i] == a[j]){
				for (int k = j; k > i+1; k--){
					swap(a[k],a[k-1]); 
					cnt++;  
				}
			}
		}
	}
	cout << cnt << endl; 
	return 0; 
}
