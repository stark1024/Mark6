#include <iostream>
using namespace std;

int main(){
	int n, i, j;
	char a;
	cout<<"Enter no. of processes:	";
	cin>>n;
	int p[n], bt[n], at[n], t, wt=0, st=0;
	cout<<"Do you want to include arrival time? Y/N:	";
	cin>>a;
	for(i=0; i<n; i++){
		cout<<"Enter burst time for process P"<<i+1<<": 	";
		p[i]=i+1;
		cin>>bt[i];
	}
	if(a == 'Y'){
		for(i=0; i<n; i++){
			cout<<"Enter arrival time for process P"<<i+1<<": 	";
			cin>>at[i];
		}
		for(i=0; i<n; i++){
			for(j=0; j<n-1; j++){
				if(at[j]>at[j+1]){
					t=at[j+1];
					at[j+1]=at[j];
					at[j]=t;

					t=bt[j+1];
					bt[j+1]=bt[j];
					bt[j]=t;

					t=p[j+1];
					p[j+1]=p[j];
					p[j]=t;
				}
			}
		}
	}else{
		for(i=0; i<n; i++){
			at[i]=0;
		}
	}
	cout<<"Series of processes will be:\nProcess:       ";
	for(i=0; i<n; i++){
		cout<<"P"<<p[i]<<"  ";
	}
	cout<<"\nArrival time:  ";
	for(i=0; i<n; i++){
		cout<<at[i]<<"  ";
	}
	t=0;
	cout<<"\nWaiting time:  ";
	for(i=0; i<n; i++){
		cout<<wt<<"  ";
		st = st + bt[i];
		if(st>at[i]){
			wt = st - at[i];
		}else{
			wt = 0;
		}
		if(i != n-1)
			t = t + wt;
	}
	t = t/n;
	cout<<"\nAverage waiting time is "<<t<<endl;

cin>>i;
return 0;
}