//shortest job first serve
#include <iostream>
using namespace std;

void swap(int *at, int *bt, int *p, int j){
	int t;
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

int main(){
	int i, j, n;
	char a;
	cout<<"Enter no. of processes:	";
	cin>>n;
	int p[n], at[n], bt[n], wt=0, st=0, t;
	float avt;
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
					swap(at, bt, p, j);
				}else if((at[j]==at[j+1]) && (bt[j]>bt[j+1])){
				    swap(at, bt, p, j);
				}
			}
		}
		st=bt[0]+at[0];
		for(i=1; i<n-1; i++){
			for(j=i; at[j]<st && j<n-1; j++){
			    if(bt[j]>bt[j+1]){
			        swap(at, bt, p, j);
			    }
	    	}
	    	st = st + bt[i+1];
		}
	}else{
		for(i=0; i<n; i++){
			at[i]=0;
		}
		for(i=0; i<n; i++){
			for(j=0; j<n-1; j++){
				if(bt[j]>bt[j+1]){
					swap(at, bt, p, j);
	            }
			}
		}
	}
	
	cout<<"Series of processes will be:\nProcess:       ";
	for(i=0; i<n; i++){
		cout<<"P"<<p[i]<<"  ";
	}
	if(a == 'Y'){
		cout<<"\nArrival time:  ";
		for(i=0; i<n; i++){
			cout<<at[i]<<"   ";
		}
	}
	cout<<"\nBurst time:    ";
	for(i=0; i<n; i++){
		cout<<bt[i]<<"   ";
	}
	t=0, st=bt[0]+at[0];
	cout<<"\nWaiting time:  ";
	for(i=0; i<n; i++){
		cout<<wt<<"   ";
		if(i!=n-1 && st>at[i+1]){
			wt = st - at[i+1];
		}else{
			wt = 0;
		}
		st = st + bt[i+1];
		t = t + wt;
	}
	avt = (float)t/n;
	cout<<"\nAverage waiting time is "<<avt<<endl;

return 0;
}
