#include <bits/stdc++.h>

using namespace std;

string s,t;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin>>s>>t;
    t=s+'$'+t;
    int n=t.size(),l=0,r=0;
    vector<int> z(n+10);
    for(int i=1;i<n;i++){
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && t[z[i]]==t[z[i]+i])
            z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    for(int i=s.size()+1;i<n;i++)
        if(z[i]==s.size())
            cout<<i-s.size()<<endl;
    return 0;
}
