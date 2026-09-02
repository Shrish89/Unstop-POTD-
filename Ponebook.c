#include <bits/stdc++.h>
using namespace std;

struct Node{

    map<char,Node*> mp;
    bool eow=false;

    Node(){

    }

};

Node* head=NULL;

void insert(string s){

    Node* curr=head;

    for(auto c:s){

        Node* n=curr->mp[c];

        if(!n){
            n=new Node();
            curr->mp[c]=n;
        }

        curr=n;

    }

    curr->eow=true;

}

void search(string &s,Node* head,int &k,string &t){

    if(k==0 || !head)return;

    if(head->eow){

        cout<<t<<" ";
        k-=1;

    }

    for(auto it:head->mp){

        t.push_back(it.first);
        if(k>0){
            search(s,it.second,k,t);
        }
        t.pop_back();

    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    string s;
    cin>>s;

    int n;

    cin>>n;

    head=new Node();

    vector<string> names;
    string t;
    for(int i=0;i<n;i++)cin>>t,insert(t);

    Node* curr=head;
    string x="";
    for(auto c:s){
        if(curr){
        curr=curr->mp[c];}
        else{
            cout<<-1<<endl;
            continue;
        }
        x+=c;
        int k=3;
        string t=x;
        search(x,curr,k,t);
        if(k==3){
            cout<<-1;
        }
        cout<<endl;

    }

    return 0;
}