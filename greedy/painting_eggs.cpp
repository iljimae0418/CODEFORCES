#include <iostream> 
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[1000005],g[1000005];  
int main(){
	int n, sa = 0, sg = 0; 
	string solution;  
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i] >> g[i];  
	}
	for (int i = 0; i < n; i++){
		if (abs(sa+a[i]-sg) <= 500){
			sa += a[i]; 
			solution += "A";  
		}else{
			sg += g[i]; 
			solution += "G";  
		}
	}
	if (abs(sa-sg) > 500) cout << -1 << endl; 
	else cout << solution << endl; 
	return 0;  
} 
