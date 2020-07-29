#include<bits/stdc++.h>
using namespace std;
void init(int *bitTree,int size){
	for(int i=0;i<size;++i){
		bitTree[i]=0;
	}
}
void updateBitTree(int *bitTree, int n, int index, int val){
	index +=1;
	while(index <= n){
		bitTree[index]+=val;
		index += (index & (-index));
	}
}

int getSum(int *bitTree, int index){
	int sum=0;
	index+=1;
	while(index > 0){
		sum += bitTree[index];
		index -= (index & (-index));
	}
	return sum;
}

int main()
{
	int n;
	cout<<"enter the n: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	int bitTree[n+1];// where 0th is dummy node
	init(bitTree,n+1);
	
	for(int i=0;i<n;++i){
		updateBitTree(bitTree,n,i,arr[i]);
	}
	int k;
	cout<<"enter the k: ";
	cin>>k;
	while(k--){
		int p;
		cout<<"enter 1 for update and 2 for range sum: ";
		cin>>p;
		if(p==1){
			int x,y;
			cout<<"enter i and val: ";
			cin>>x>>y;
			updateBitTree(bitTree,n,x,y-arr[x]);
			arr[x]  = y;
			cout<<"done"<<endl;
		}else if(p==2){
			int x,y;
			cout<<"enter the range: ";
			cin>>x>>y;
			cout<< getSum(bitTree,y)- getSum(bitTree,x-1)<<" is the sum"<<endl;
		}else{
			break;
		}
	}
return 0;
}

