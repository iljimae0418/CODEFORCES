#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
int a[100005]; 
int main(){
	IOFAST();  
	int n; 
	cin >> n; 
	map< int,vector<int> > mp;   
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
		mp[a[i]].push_back(i); 
	}
	map<int,int> ans;  
	for (map< int,vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
		vector<int> v = it->second; 
		bool flag = true; 
		if (v.size() == 1){	
			ans[it->first] = 0; 
		}else if (v.size() > 1){
			int d = v[1]-v[0];  
			bool flag = true; 
			for (int i = 1; i < v.size()-1; i++){
				if (v[i+1]-v[i] != d){
					flag = false; 
					break; 
				}
			}
			if (flag){
				// store the answer in map 
				ans[it->first] = d; 
			}
		}
	}
	cout << ans.size() << endl; 
	for (map<int,int>::iterator it = ans.begin(); it != ans.end(); it++){
		cout << it->first << " " << it->second << endl; 
	}
	return 0; 
}
