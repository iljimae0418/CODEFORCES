#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
struct info{
	int sum,idx,eliminate;  
	info(){} 
}; 
vector< vector<int> > v; 
vector<info> collection; 
bool cmp(info &i1,info &i2){
	return i1.sum < i2.sum; 
}
int main(){
	int k; 
	cin >> k; 
	for (int i = 0; i < k; i++){
		int n,sum = 0; 
		cin >> n; 
		vector<int> t(n); 
		for (int j = 0; j < n; j++){
			cin >> t[j]; 
			sum += t[j]; 
		}
		info I; 
		I.idx = i;  
		for (int j = 0; j < n; j++){
			sum -= t[j];  
			I.sum = sum; 
			sum += t[j]; 
			I.eliminate = j; 
			collection.push_back(I); 
		}
	}
	sort(collection.begin(),collection.end(),cmp);
	bool exist = false; 
	for (int i = 0; i < collection.size()-1; i++){
		if (collection[i].sum == collection[i+1].sum 
			&& collection[i].idx != collection[i+1].idx){
			exist = true; 
			cout << "YES" << endl;  
			cout << collection[i].idx+1 << " " << collection[i].eliminate+1 << endl; 
			cout << collection[i+1].idx+1 << " " << collection[i+1].eliminate+1 << endl; 
			break; 
		}
	}
	if (!exist){
		cout << "NO" << endl; 
	}
	return 0;  
}
