#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector < pair<int,int> > vect;
	
	int arr[] = {1,2,3,4,5};
	int arr2[] = {1,23,4,5,6};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0; i<n;i++)
	{
		vect.push_back(make_pair(arr[i],arr2[i]));
	}
	
	for(int i=0;i<n;i++)
	{
		cout<< vect[i].first;
	}
}
