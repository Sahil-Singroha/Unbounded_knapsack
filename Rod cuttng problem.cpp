#include<bits/stdc++.h>
using namespace std;

int unk(int arr[],int p[],int n,int l)
{
    int t[n+1][l+1];
    memset(t,-1,sizeof(t));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<l+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<l+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=max(p[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
            }
            else 
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][l];
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int p[]={1,5,8,9,10,17,17,20};
    int n=sizeof(p)/sizeof(p[0]);
    int l=1;
    std:: cout<<unk(arr,p,l,n);
}
