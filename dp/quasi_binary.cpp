#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <vector>
#include <algorithm>
using namespace std; 
string convert(int x){
	string t = ""; 
	while (x){
		t += char((x&1)+'0');  
		x >>= 1;  
	}
	reverse(t.begin(),t.end()); 
	return t;  
}
int toNumber(string s){
	int ret = 0; 
	for (int i = s.size()-1, ten = 0; i >= 0; i--,ten++){
		ret += pow(10,ten)*(s[i]-'0');  
	}
	return ret;  
}
int dp[1000005],reconstruct[1000005]; 
void printAns(vector<int> &v,int n){
	if (n > 0){
		printAns(v,n-reconstruct[n]); 
		cout << reconstruct[n] << " "; 
	}
	return; 
}
const int INF = 2e9+88; 
int main(){	
	int n; 
	cin >> n; 
	vector<int> v; 
	for (int i = 0; i < (1<<7); i++){
		v.push_back(toNumber(convert(i))); 
	}
	dp[0] = 0; 
	for (int i = 1; i <= n; i++){
		dp[i] = INF;  
		for (int j = 0; j < v.size(); j++){
			if (v[j] <= i && 1+dp[i-v[j]] < dp[i]){
				dp[i] = 1+dp[i-v[j]]; 
				reconstruct[i] = v[j];  
			}
		}
	}
	cout << dp[n] << endl; 
	printAns(v,n); 
	cout << endl; 
	return 0; 
}	
