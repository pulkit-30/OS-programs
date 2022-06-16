#include <bits/stdc++.h>
using namespace std;

signed main ()
{


int p,b,t=-1,currminfrag=INT_MAX,totalfragmentation=0;
cin>>p>>b;
int processes[p],blocksize[b],fragmentation[b];
int status[b] ={-1,-1,-1,-1,-1};

for(int i=0;i<p;++i){cin>>processes[i];}
for(int i=0;i<b;++i){cin>>blocksize[i];}

for(int i=0;i<p;++i){
  currminfrag = INT_MAX;

  for(int j=0;j<b;++j){
if(status[j]==-1 && processes[i]<=blocksize[j] ){ 
  if ((blocksize[j]-processes[i])<currminfrag) {
    currminfrag = (blocksize[j]-processes[i]);
    t = j;
  }
 }
}
    status[t] = i;

 }


  for(int i=0;i<b;++i){
    cout<<status[i]<<endl;
    if(status[i]!=-1) totalfragmentation += (blocksize[i] - processes[status[i]]);
  }
  cout<<"Total fragmentation is "<<totalfragmentation<<endl;


    
}