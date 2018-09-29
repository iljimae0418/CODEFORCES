#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
typedef long long ll;  
ll s[200005]; 
ll p[200005];  
int N,D; 
int main(){
	cin >> N >> D; 
	for (int i = 1; i <= N; i++){
		cin >> s[i]; 
	}
	for (int i = 1; i <= N; i++){
		cin >> p[i]; 
	}
	s[D] += p[1]; 
	int give = 2, test = N, pivot = s[D]; 
	map<ll,ll> mp; 
	mp[s[D]]++; 
	for (int i = 1; i <= N; i++){
		if (i == D) continue;  
		if (s[i]+p[test] > s[D]){
			// we can never beat the ith player 
			s[i] += p[give++]; 
		}else{
			s[i] += p[test--];  
		}
		mp[s[i]]++; 
	}
	int rank = 1;  
	for (map<ll,ll>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++){
		if (it->first == pivot){
			cout << rank << endl;  
			break; 
		}else{
			rank += it->second;  
		}
	}
	return 0; 
}
