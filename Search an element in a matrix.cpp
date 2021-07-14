/*
Naive approach:
>> traverse the array and to search elements one by one using 2 nested for loops.
>> Check every element with x and if the element is found then print “element found”

TC => O(n*n) = O(n^2)
SC => O(1)

Better approach: ((Divide & Conquer))
>> Start searching from the top-right corner of the matrix. There are three possible cases. 

>> The given number is greater than the current number: This will ensure that all the elements 
	in the current row are smaller than the given number as the pointer is already at the right-most 
	elements and the row is sorted. Thus, the entire row gets eliminated and continues the search for the next row. 
	Here, elimination means that a row needs not be searched.
	
>> The given number is smaller than the current number: This will ensure that all the elements in the current column 
	are greater than the given number. Thus, the entire column gets eliminated and continues the search for the previous column, 
	i.e. the column on the immediate left.
	
>> The given number is equal to the current number: This will end the search.

TC => O(n ^1.58). 
SC => O(1)

MOST Optimal approach:
>> Use binary search instead of linear search

Binary seach wala likh lo baad me                                              

TC => O(log(n)+log(n)) = O(log(n))
SC => O(1)
*/

#include<iostream>
#include<vector>                        

using namespace std;

void search2D(int a[4][4],int key,int size)
{		
	//matrix is already rowise and columnwise sorted 
	int max=a[size-1][size-1];
	int min=a[0][0];
	
	//corner case
	if(key<=min || key>=max)
	{
		cout<<"\nOUT OF MATRIX RANGE";
	}
	else
	{
		int i=0,j=size-1,flag=0;
		
		//iterate till last row
		while(i<size && j>=0)    
		{
			if(key==a[i][j])
			{
				cout<<"\nKey found at => row number: "<<i<<" column number: "<<size-1;
				flag=1;break;
			}
			//search in next row keeping column same
			else if(key>a[i][j])
			{
				i++;
			}
			//search in previous columns keeping row same
			else if(key<a[i][j])
			{
				j--;
			}
		}
		if(flag==0)
		{
			cout<<"\nNOT FOUND!!";
		}
	}
}

int main()
{
	int size=0,element=0,key=0;
	/*
	//input matrix as a vector bcoz vectors are cache friendly
	vector<vector<int> > a;
	
	cout<<"\nDimensions of matrix ([n cross n] enter n) => ";cin>>size;
	
	//taking input
	cout<<"\nEnter matrix (SORTED ROTATED)\n";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<"\na"<<i<<""<<j<<" => ";
			cin>>a[i][j];
		}
	}
	
	cout<<"\nEnter key to be found => ";cin>>key;
	*/
	
	int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    
    
	//calling our function
	search2D(mat,29,4);
	
	return 0;
}
