#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Input number of element to be store in array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"element:";
        cin>>arr[i];

    }
    sort(arr,arr+n);
    /*this is for sort the array so we can find maximum element form user input and 
   using this element we make one array of that size
   */
    int m=arr[n-1];
    m++;
    int a[m];


    for(int i=0;i<m;i++)
    {
        a[i]=0;
    }

    for(int i=0;i<n;i++)
    {

     a[arr[i]]++;
    }
   cout<<endl;
        for(int i=0;i<m;i++)
        {
            if(a[i]>0)
                cout<<i<<"->"<<a[i]<<endl;


        }


}