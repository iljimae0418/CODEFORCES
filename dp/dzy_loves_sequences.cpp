#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
#include <vector>
using namespace std;  
const int INF = 987654321; 
int a[100005];  
int l[100005],r[100005]; // l[],r[] are initialised to zero  
int main(){
	int n;  
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
	}
	l[1] = 1;  
	for (int i = 2; i <= n; i++){
		if (a[i] > a[i-1]) l[i] = l[i-1]+1; 
		else l[i] = 1;  
	}
	r[n] = 1; 
	for (int i = n-1; i >= 1; i--){
		if (a[i] < a[i+1]) r[i] = r[i+1]+1;   
		else r[i] = 1;  
	}
	int ans = -INF; 
	for (int i = 1; i <= n; i++){
		if (a[i-1]+1 < a[i+1]){
			ans = max(ans,l[i-1]+1+r[i+1]); 
		}else{
			ans = max(ans,max(l[i-1],r[i+1])+1);  
		}
	}
	cout << ans << endl; 
	return 0;  
}
