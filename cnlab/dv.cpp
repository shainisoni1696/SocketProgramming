#include<bits/stdc++.h>
using namespace std;
struct node{
 int dist[30];
 int from[30];
}route[20];
 
int main()
{
   int d[20][20];
   int n;
   cout<<"enter the number of nodes:";
   cin>>n;
  
   for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
            {
                 cin>>d[i][j];
                 d[i][i]=0;
                 route[i].dist[j]=d[i][j];
                 route[i].from[j]=j;
              }
        }
   bool flag=1;
 do{
     flag=0;
    for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
             {
                 for(int k=0;k<n;k++)
                   {
                        if(route[i].dist[j] > (route[i].dist[k]+route[k].dist[j]))
                            {
                               route[i].dist[j] = route[i].dist[k]+route[k].dist[j];
                               route[i].from[j]=k;
                               flag=1;
                             }
                    }
              }
         }
    }while(flag);
   
     for(int i=0;i<n;i++)
       {
          cout<<"DV for router"<<i+1<<" is :";
          cout<<"Dest\tCost\tNextHop\n";
          for(int j=0;j<n;j++)
            cout<<j+1<<"\t"<<route[i].dist[j]<<"\t"<<route[i].from[j]<<endl;
       }
return 0;
}
            
