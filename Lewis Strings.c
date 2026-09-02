#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;cin>>s;
    int n=s.length();
    unordered_map<int,int>mp;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')')
        {
            int index=st.top();
            st.pop();
            mp[index]=i;
            mp[i]=index;
        }
    }
        int dir=1;
        string ans;
        for(int i=0;i<n;)
        {
            if(s[i]=='(' or s[i]==')')
            {
                i=mp[i];
                dir*=-1;
            }
            else ans.push_back(s[i]);
            i+=dir;
        }
    cout<<ans;
    return 0;
}