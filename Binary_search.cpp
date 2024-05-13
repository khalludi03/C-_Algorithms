#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int s;
    cin>>s;
    int k = binary_search(vec.begin(),vec.end(),s);
    // only return true/false
    cout<<k<<endl;
    int l = 0;
    int r = n;
    int mid;
    //BINARY SEARCH TIME COMPLEXITY O(logN):)
    while(l<=r)
    {
        mid = (l+r)/2;
        if(vec[mid]==s)
        {
            cout<<s<<endl;
            break;
        }
        else if(vec[mid]<s)
            l = mid+1;
        else 
            r = mid-1;    
    }

    return 0;
}
