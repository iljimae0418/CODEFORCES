#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <set> 
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef pair<int,int> P;  
const int N = 300*1000 + 13;  
const int INF = (int)1e9;  
int n; 
int prl[N],prr[N],sul[N],sur[N]; 
int l[N],r[N]; 
int main(){
	IOFAST(); 
	int n;  
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> l[i] >> r[i];  
	}
	prl[0] = sul[n] = 0;  
	prr[0] = sur[n] = INF;  
	for (int i = 0; i < n; i++){
		prl[i+1] = max(prl[i],l[i]); 
		prr[i+1] = min(prr[i],r[i]);  
	}
	for (int i = n-1; i >= 0; i--){
		sul[i] = max(sul[i+1],l[i]);  
		sur[i] = min(sur[i+1],r[i]);  
	}
	int ans = 0; 
	for (int i = 0; i < n; i++){
		ans = max(ans,min(prr[i],sur[i+1])-max(prl[i],sul[i+1]));  
	}
	cout << ans << endl; 
	return 0;  
}	
