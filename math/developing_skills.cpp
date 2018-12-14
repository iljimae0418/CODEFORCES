#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue> 
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
struct custom{
	int curval; 
	int pt; // how far away from the next multiple of 10
	custom(int x,int y):curval(x),pt(y){}
};  
struct cmp{
	bool operator()(custom c1,custom c2){
		return (c1.pt > c2.pt);  
	}
};  
int a[100005]; 
int n,k; 
int main(int argc,char **argv){
	int full = 0;  
	cin >> n >> k; 
	priority_queue<custom,vector<custom>,cmp> pq;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		int d = 0;  
		while (d <= a[i]){
			d += 10; 
		}
		pq.push(custom(a[i],d-a[i]));  
	}
	int ans = 0; 
	while (k > 0 && !pq.empty()){
		custom c = pq.top(); pq.pop();  
		if (c.curval == 100){
			ans += 10; // don't add it back into the queue 
			continue; 
		}
		int add = min(k,c.pt);  
		c.curval += add;  
		k -= add;  
		// calculate pt for c again 
		int d = 0;  
		while (d <= c.curval){
			d += 10;  
		}
		c.pt = d-c.curval;  
		pq.push(c); 
	}
	while (!pq.empty()){
		custom c = pq.top(); pq.pop(); 
		ans += c.curval/10;  
	}
	cout << ans << "\n";  
	return 0; 
}
