#include<bits/stdc++.h>

using namespace std;

int main()
{
	int row,col,num;
	
	cout << "Enter the number of rows";
	cin >> row;
	cout << "Enter the number of columns";
	cin >> col;
	
	vector < vector <int> > v3;
	
	for( int i=0; i<row; i++)
	{
		vector<int> v1;
		for(int j=0; j<col;j++)
		{
			cout<<"Enter the number";
			cin>>num;
			v1.push_back(num);
		}
		v3.push_back(v1);
	}
	
	for( int i = 0; i<row; i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<< v3[i][j];
		}
		cout<<endl;
		
	}
	
	cout << *find(v3[1].begin(),v3[1].end(),4);
}
