#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
long long power(long long a,long long x){
	if (x == 0LL) return 1LL;  
	if (x == 1LL) return a; 
	return power(a,x/2LL)*power(a,x/2LL)*power(a,x%2);  
}
int main(){
	int n,temp,cnt = 0; 
	cin >> n; 
	temp = n; 	
	while (temp){
		temp /= 10; 
		cnt++; 
	}
	long long ans = 0; 
	for (int i = 0; i <= cnt-2; i++){
		ans += power(10,i)*9LL*(i+1); 
	}
	ans += cnt * (n-power(10,cnt-1)+1);  
	cout << ans << endl; 
	return 0;   
}
