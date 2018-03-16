#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <queue> 
using namespace std; 
int a[100005]; 
typedef long long ll; 
int main(){
	int n; 
	cin >> n;
	priority_queue< int,vector<int>,greater<int> > pq; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	sort(a,a+n);  
	int wait = 0, cnt = 0; 
	for (int i = 0; i < n; i++){
		if (wait > a[i]) continue; 
		else{
			cnt++; 
			wait += a[i]; 
		}
	}
	cout << cnt << endl; 
 	return 0; 
 }
