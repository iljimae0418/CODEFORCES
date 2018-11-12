#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std; 
typedef long long ll;  
ll n, k;
ll h[200001];
int cnt[200001];
int main(){
    cin >> n >> k;  
    ll maxH = -2e9, minH = 2e9;  
    for (int i = 1; i <= n; i++){
        cin >> h[i];  
        cnt[h[i]]++;  
        maxH = max(maxH,h[i]); 
        minH = min(minH,h[i]);  
    }
    for (int i = maxH; i >= 1; i--){
        cnt[i] += cnt[i+1];  
    }
    ll ans = 0, cur = 0;  
    for (int i = maxH; i > minH; i--){
        if (cur+cnt[i] > k){
            ans++; 
            cur = 0; 
        }
        cur += cnt[i];  
    }
    if (cur) ans++; 
    cout << ans << endl; 
    return 0; 
}
