#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std;  
int a[101]; 
int main(){
	int n,B; 
	cin >> n >> B;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	int cnt = 0,even = 0,odd = 0,coins = 0;
	vector<int> cutPoints;  
	for (int i = 0; i+1 < n; i++){
		if (a[i]%2 == 0) even++;  
		if (a[i]%2 == 1) odd++; 
		if (even == odd && even > 0){
			cutPoints.push_back(abs(a[i+1]-a[i])); 
		}	
	}
	sort(cutPoints.begin(),cutPoints.end()); 
	while (cnt < cutPoints.size() && coins+cutPoints[cnt] <= B){
		coins += cutPoints[cnt++]; 
	}
	cout << cnt << endl; 
	return 0; 
}
