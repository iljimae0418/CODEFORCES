// print q integers. The ith of them should be equal to the number of shops
// where Vasilly will be able to buy a bottle of the drink on the ith day  
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
int x[100005];  
int main(){
	int n,q,key;  
	cin >> n; 
	vector<int> x(n);  
	for (int i = 0; i < n; i++){
		cin >> x[i];  
	}
	sort(x.begin(),x.end());  
	cin >> q; 
	while (q--){
		cin >> key; 
		/*vector<int>::iterator it = lower_bound(x.begin(),x.end(),key); 	
		if (it == x.begin() && x[0] > key){
			cout << 0 << endl; 
		}else if (it == x.end() && x[n-1] <= key){
			cout << n << endl; 
		}else{
			if (*it == key){
				cout << it-x.begin()+1 << endl; 
			}else if (*it > key){
				cout << it-x.begin() << endl; 
			}
		}*/  
		// find index containing value less than or equal to key 
		int l = 0, r = n-1; 
		while (l <= r){
			int mid = (l+r)>>1; 
			if (x[mid] <= key){
				l = mid+1; 
			}else{
				r = mid-1; 
			}
		}
		cout << r+1 << endl;  
	}
	return 0; 
}
