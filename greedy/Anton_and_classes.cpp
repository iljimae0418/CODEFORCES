#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std; 
typedef pair<int,int> P;  
bool cmp_l(P &p1,P &p2){
	return p1.first < p2.first;  
}	
bool cmp_r(P &p1,P &p2){
	return p1.second < p2.second; 
}
int main(){ 
	int n; 
	cin >> n; 
	vector<P> nlist(n); 
	for (int i = 0; i < n; i++){
		cin >> nlist[i].first >> nlist[i].second;  
	}
	int m; 
	cin >> m; 
	vector<P> mlist(m); 
	for (int i = 0; i < m; i++){
		cin >> mlist[i].first >> mlist[i].second;  
	}
	int ans = -2e9;  
	// nlist[j].l > mlist[j].r 
	sort(nlist.begin(),nlist.end(),cmp_l);  
	sort(mlist.begin(),mlist.end(),cmp_r);  
	if (nlist[n-1].first <= mlist[0].second){ // intersects 
		ans = max(ans,0);  
	}else{
		ans = max(ans,nlist[n-1].first-mlist[0].second);  
	}
	// nlist[j].r < mlist[j].l 
	sort(nlist.begin(),nlist.end(),cmp_r); 
	sort(mlist.begin(),mlist.end(),cmp_l); 
	if (mlist[m-1].first <= nlist[0].second){ // intersects 
		ans = max(ans,0); 
	}else{
		ans = max(ans,mlist[m-1].first-nlist[0].second); 
	}
	cout << ans << endl;
	return 0;  
}
