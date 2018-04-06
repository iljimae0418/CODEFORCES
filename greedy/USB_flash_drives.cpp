#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;  
int main(){
	int n,m; 
	cin >> n >> m; 
	vector<int> v(n);  
	for (int i = 0; i < n; i++){
		cin >> v[i]; 
	}
	sort(v.begin(),v.end(),greater<int>());  
	int cnt = 0, sum = 0;  
	while (sum < m && cnt < n){
		sum += v[cnt]; 
		cnt++;  
	}
	cout << cnt << endl;
	return 0; 
}
