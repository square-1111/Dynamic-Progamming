#include <bits/stdc++.h>
using namespace std;

int q=INT_MAX;

int s[1000][1000];

int rec(int p[],int i, int j){
	if(i==j){return 0;}
	int val=INT_MAX;
	for(int k=i;k<j;k++){
		int x=rec(p,i,k)+rec(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(val>x){
			val=x;
			s[i][j]=k;
		}
		//val=min(val,rec(p,i,k)+rec(p,k+1,j)+p[i-1]*p[k]*p[j]);
	}

	return val;
}

void pa(int i, int j){
	if(i==j){cout<<"A"<<i;}
	else{
		cout<<"(";
		pa(i,s[i][j]);
		pa(s[i][j]+1,j);
		cout<<")";
	}
}

int mini[1000][1000],para[1000][1000];

void dp(int p[], int n){
	int size=n;
	for(int i=0;i<n;i++){
		mini[i][i]=0;
	}
	for(int len=2;len<n;len++){
		for(int i=0;i<n-len;i++){
			int j=i+len-1;
			mini[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int q=mini[i][k]+mini[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(mini[i][j]>q){
					mini[i][j]=q;
					para[i][j]=k;
				}
			}
		}
	}
}

void parant(int i,int j){
	if(i==j){
		cout<<"A"<<i+1;
	}
	else{
		cout<<"(";
		parant(i,para[i][j]);
		parant(para[i][j]+1,j);
		cout<<")";
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	int row,col;
	cin>>row>>col;
	arr[0]=row,arr[1]=col;
	for(int i=2;i<=n;i++){
		cin>>row>>col;
		arr[i]=col;
	}
	for(int i=0;i<n+1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nminimum number of scalar multiplication are by rec "<<rec(arr,1,n)<<endl;
	//cout<<"\nminimum number of scalar multiplication are by dp "<<dp(arr,n);
	dp(arr,n+1);
	parant(0,n-1);
	cout<<"\nrec order\n";
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+2;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	pa(1,n);
}