#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <set> 
using namespace std; 
typedef pair<int,int> P;  
P a[1005];
int alive[1005]; 
bool chk(int x1,int y1,int x2,int y2,int x3,int y3){
	return (y2-y1)*(x3-x1) == (y3-y1)*(x2-x1);  
}
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);  
	int n,x0,y0; 
	cin >> n >> x0 >> y0;  
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;  
		alive[i] = 1;  
	}
	int cnt = 0; 
	for (int i = 0; i < n; i++){
		if (alive[i]){
			for (int j = i+1; j < n; j++){
				if (alive[j] && chk(x0,y0,a[i].first,a[i].second,a[j].first,a[j].second)){
					alive[j] = 0;  
				}
			}
			alive[i] = 0; 
			cnt++;  
		}
	}
	cout << cnt << endl; 
	return 0;  
}
