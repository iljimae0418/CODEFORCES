#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector> 
using namespace std; 
const int INF = (int)1e9; 
typedef pair<int,int> P; 
int a[100005]; 
map<int,int> cnt;  
map<int,P> range; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		cnt[a[i]]++;  
		if (!range.count(a[i])){
			range[a[i]].first = i; // first appearance 
			range[a[i]].second = i; 
		}else{
			range[a[i]].second = i;  // update the last seen index only 
		}
	}
	vector<P> v; 
	for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++){
		v.push_back(P(it->second,it->first)); 
	}
	sort(v.begin(),v.end()); 
	int maxbeauty = v[v.size()-1].first; 
	vector<int> beauties;  
	beauties.push_back(v[v.size()-1].second); 
	for (int i = v.size()-2; i >= 0; i--){
		if (v[i].first == maxbeauty){
			beauties.push_back(v[i].second); 
		}else{
			break; 
		}
	}
	int minLength = INF;  
	int from = -1, to = -1;  
	for (int i = 0; i < beauties.size(); i++){
		if (range[beauties[i]].second-range[beauties[i]].first + 1 < minLength){
			minLength = range[beauties[i]].second-range[beauties[i]].first + 1;  
			from = range[beauties[i]].first; 
			to = range[beauties[i]].second; 
		}
	}
	cout << from << " " << to << "\n"; 
	return 0; 
}
