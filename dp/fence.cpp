#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int n,k; 
int h[200000];  
int psum[200000]; 
const int INF = 987654321;  
int main(){
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> h[i]; 
	}
	psum[1] = h[1]; 
	for (int i = 2; i <= n; i++){
		psum[i] = psum[i-1]+h[i]; 
	}
	// to get the sum of values of indexes 
	// i,i+1,...,i+k-1 we simply compute 
	// psum[i+k-1]-psum[i-1] 
	int ans = INF,ansIdx = -1;  
	for (int i = 1; i+k-1 <= n; i++){
		if (psum[i+k-1]-psum[i-1] < ans){
			ans = psum[i+k-1]-psum[i-1];
			ansIdx = i;   
		}
	}
	cout << ansIdx << endl; 
	return 0; 
}
