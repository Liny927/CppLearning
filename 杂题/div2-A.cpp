#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    int n;
    string s;
    scanf("%d", &T);
    while(T--)
    {
        int cnt = 0;
        vector<int> ans;
        cin>>n;
        cin>>s;
        for(int i = 0; i < n && cnt < 2; i++)
        {
            if((s[i] - '0')%2)
            {
                cnt++;
                ans.push_back(s[i]-'0');
            }
        }
        if(cnt < 2)
            cout<<"-1";
        else
            for(int i = 0; i < ans.size(); i++)
                cout<<ans[i];
        cout<<endl;
    }
}
