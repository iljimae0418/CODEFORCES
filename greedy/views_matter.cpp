// find maximum number of blocks you can remove 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <set> 
using namespace std;  
long long a[100005];  
int main(int argc,char ** argv){
	int n,m; 
	long long sum = 0;  
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		sum += a[i]; 
	}
	if (n == 1){
		cout << 0 << endl; 
	}else if (n > 1){
		long long req = 0, prev = 0;  
		sort(a,a+n); 
		for (int i = 0; i < n; i++){
			req++; 
			if (a[i] > prev) prev++;  
		}
		req += a[n-1]-prev;  
		cout << sum-req << endl; 
	}
	return 0; 
}
