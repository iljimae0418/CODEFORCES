#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
int a[2222]; 
int main(){
	int n, ans = 1; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}	
	for (int i = 0; i < n; i++){
		int cnt = 1; 
		bool down = false;  
		for (int j = i+1; j < n; j++){
			if (down && a[j] > a[j-1]){
				break; // water cannot flow anymore 
			}
			if (a[j] < a[j-1]){
				down = true; 
				cnt++;  
			}else if (a[j] >= a[j-1]){
				cnt++; 
			}
		}
		ans = max(ans,cnt);  
	}
	cout << ans << "\n";  
	return 0;  
}
