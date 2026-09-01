#include <iostream>
#include <vector>
using namespace std;

void find(int i,vector<int>&v,vector<int>&nums,vector<vector<int>>&ans){
  //  if(v.size())
    ans.push_back(v);
    int j=nums.size()-1;
    while(i<j){
        v.push_back(nums[j]);
        find(j,v,nums,ans);
        v.pop_back();
        j--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
vector<int>v;
vector<vector<int>>ans;
  for(int i=nums.size()-1;i>=0;i--){
   v.push_back(nums[i]);
   find(i,v,nums,ans);
   v.pop_back();
}
cout<<" "<<endl;
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
    cout<<endl;
}
//cout<<ans.size();
    return 0;
}