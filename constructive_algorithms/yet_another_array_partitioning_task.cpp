#include <iostream>
#include <algorithm>
#include <queue> 
#include <vector> 
#include <set> 
#include <map> 
using namespace std; 
const int MAXN = 200005; 
typedef long long ll;  
ll a[MAXN]; 
int main(int argc,char **argv){
	ll n,m,k,beauty = 0; 
	cin >> n >> m >> k;  
	priority_queue< ll,vector<ll>,less<ll> > pq; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		pq.push(a[i]); 
	}
	map<ll,ll> mp; 
	int cnt = 0;  
	while (cnt < m*k){
		beauty += pq.top(); 
		mp[pq.top()]++; 
		pq.pop(); 
		cnt++; 
	}	
	cout << beauty << endl; 
	// let's start partitioning 
	int i = 1, track = 0,printAns = 0; 
	int idx = 0;  
	while (i <= n){
		if (track == m){
			// we partition here 
			if (printAns < k-1){
				printAns++; 
				cout << i-1 << " "; 
			}
			track = 0;  
			idx++; 
		}
		if (mp.count(a[i]) && mp[a[i]] > 0){
			track++; 
			mp[a[i]]--; 
		}
		i++; 
	}
	cout << "\n"; 
	return 0;
}
