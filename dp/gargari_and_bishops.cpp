#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll; 
typedef pair<int,int> P;  
P a[2];  
ll val[2];  
ll grid[2222][2222]; 
ll d1[4444],d2[4444];  
int main(){
	IOFAST(); 
	int n; 
	cin >> n;  
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> grid[i][j];  
			d1[i+j] += grid[i][j]; 
			d2[i-j+n] += grid[i][j];  
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if ((i+j)%2 == 0){
				if (d1[i+j]+d2[i-j+n]-grid[i][j] >= val[0]){
					val[0] = d1[i+j]+d2[i-j+n]-grid[i][j]; 
					a[0].first = i; 
					a[0].second = j;  
				}
			}else if ((i+j)%2 == 1){
				if (d1[i+j]+d2[i-j+n]-grid[i][j] >= val[1]){
					val[1] = d1[i+j]+d2[i-j+n]-grid[i][j]; 
					a[1].first = i; 
					a[1].second = j; 
				}
			}
		}
	}
	cout << val[0]+val[1] << endl; 
	cout << a[0].first << " " << a[0].second << " " << a[1].first << " " << a[1].second << endl; 
	return 0; 
}
