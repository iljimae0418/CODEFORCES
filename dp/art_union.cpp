#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std; 
int a[50005][10]; // our dp table 
int main(int argc,char **argv){
	int m,n; 
	cin >> m >> n;  
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j]; 
		}
	}
	// compute sum for first row 
	for (int i = 2; i <= m; i++){
		a[i][1] += a[i-1][1];  
	}
	// iteratively compute sum for 2,3,...,nth painter 
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (j == 1){
				a[j][i] += a[j][i-1];  
			}else{
				if (a[j-1][i] >= a[j][i-1]){
					a[j][i] = a[j-1][i]+a[j][i]; 
				}else if (a[j-1][i] < a[j][i-1]){
					a[j][i] = a[j][i-1]+a[j][i]; 
				}
			}
		}
	}
	// print out answer 
	for (int i = 1; i <= m; i++){
		cout << a[i][n]; 
		cout << (i == m ? "\n" : " "); 
	}
	return 0;  
}
