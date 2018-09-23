#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
const int MAXA = 20000000;  
int a[MAXA],freq[MAXA],used[MAXA];  
int gcd(int a,int b){
	if (b == 0) return a; 
	return gcd(b,a%b); 
}
int main(){
	IOFAST(); 
	int n; 
	cin >> n; 
	cin >> a[0]; 
	int g = a[0]; 
	for (int i = 1; i < n; i++){
		cin >> a[i]; 
		g = gcd(g,a[i]); 
	}
	for (int i = 0; i < n; i++){
		a[i] /= g;
		freq[a[i]]++;   
	}
	int ans = n;  
	for (int i = 2; i < MAXA; i++){
		if (!used[i]){
			int cnt = 0;  
			for (int j = i; j < MAXA; j += i){
				used[j] = 1;  
				cnt += freq[j]; 
			}
			ans = min(ans,n-cnt); 
		}
	}
	cout << (ans == n ? -1 : ans) << endl; 
	return 0;  
}
