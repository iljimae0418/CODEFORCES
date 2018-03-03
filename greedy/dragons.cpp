#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cstdlib>
using namespace std; 
int main(){
	vector< pair<int,int> > v; 
	int s,n; 
	cin >> s >> n; 
	for (int i = 0; i < n; i++){
		int a,b; 
		cin >> a >> b; 
		v.push_back(make_pair(a,b)); 
	}
	sort(v.begin(),v.end()); 
	bool flag = true; 
	for (int i = 0; i < v.size(); i++){
		if (s > v[i].first){
			s += v[i].second; 
		}else{
			flag = false; 
			break; 
		}
	}
	if (flag){
		cout << "YES" << endl; 
	}else{
		cout << "NO" << endl; 
	}
	return 0; 
}
