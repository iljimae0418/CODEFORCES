#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
int chk[10000010];  
bool isp[10000010];  
int db[10000010]; 
ll sum[10000010]; 
int main(){	
	IOFAST(); 
	int n;  
	cin >> n; 
	for (int i = 1; i <= n; i++){
		int x; 
		cin >> x; 
		chk[x]++;  
	}
	for (int i = 2; i <= 10000000; i++){
		if (isp[i]) continue; 
		for (int j = i; j <= 10000000; j += i){
			if (chk[j]) db[i] += chk[j];  
			isp[j] = true; 
		}
	}
	for (int i = 2; i <= 10000000; i++){
		sum[i] = sum[i-1]+db[i]; 
	}
	int m; 
	cin >> m; 
	while (m--){
		int x,y; 
		cin >> x >> y; 
		if (x > 1e7) x = 1e7; 
		if (y > 1e7) y = 1e7;  
		cout << sum[y]-sum[x-1] << endl; 
	}
	return 0; 
}
