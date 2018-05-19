#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
#include <map> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
typedef long long ll;  
ll n,x,ans = 0;  
ll a[100005];
map<ll,ll> cnt;   
int main(){
	IOFAST(); 
	cin >> n >> x; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}	
	cnt[x^a[1]]++;  
	for (int i = 2; i <= n; i++){
		ans += cnt[a[i]];  
		cnt[x^a[i]]++; 
	}
	cout << ans << endl; 
	return 0; 
}
