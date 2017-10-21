// TLE version 
#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector> 
using namespace std; 
bool isPrime(int x){
	if (x == 1) return true; 
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return true; 
}
map<int,int> prime_factorisation(int x){
	map<int,int> ret; 
	for (int i = 2; i*i <= x; i++){
		while (x%i == 0){
			ret[i]++;  
			x /= i; 
		}
	}
	if (x != 1) ret[x]++; 
	return ret; 
}
long long power(int a,int x){ // returns a^x
	if (x == 0) return 1; 
	if (x == 1) return a; 
	return power(a,x/2)*power(a,x/2)*power(a,x%2); 
}
int main(){
	// for anything involving queries, try fast I/O
	int q; 
	scanf("%d",&q);  
	while (q--){
		int i; 
		scanf("%d",&i); 
		if (isPrime(i)){
			printf("-1\n"); 
		}else{
			// prime factorise  
			map<int,int> mp = prime_factorisation(i);  
			bool noPower = true; 
			for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if (it->second > 1){
					noPower = false; 
					break; 
				}
			}
			if (noPower){
				// we simply print i
				printf("%d\n",1);  
				continue; 
			}
			// we make the greedy choice. We can print the smallest 
			// prime factor squared the remaining prime factor number of times 
			// e.g. 2^3 * 3^3, then we can print 2^2 2*3^3 number of times. 
			map<int,int>::iterator it = mp.begin(); 
			it->second -= 2; // to make the number non-composite   
			long long cnt = 1;  
			for (map<int,int>::iterator jt = mp.begin(); jt != mp.end(); jt++){
				cnt *= power(jt->first,jt->second);  
			}
			printf("%lld\n",cnt); 
		}
	}
	return 0; 
}
