#include<bits/stdc++.h>
using namespace std;
int main()
{
  cout<<"Enter number of bits in data:";
   int n;
  cin>>n;
  cout<<"Enter the data:";
  int arr[100];
 //memset(arr,0,sizeof arr);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  int g;
  cout<<"Enter the size of generator:";
  cin>>g;
  int gen[g];
  cout<<"Enter the crc generator:";
  for(int i=0;i<g;i++)
   cin>>gen[i];
    int s=n+g-1;
   cout<<"Extended data size=:";
   cout<<s<<endl;
    
   for(int i=n;i<s;i++)
        arr[i]=0;
 int temp[s+1];
     cout<<"Extended data size=:";
           for(int i=0;i<s;i++)
             {
                  temp[i]=arr[i];
                   cout<<temp[i]<<" ";
              }
     cout<<endl;

  for(int i=0;i<n;i++)
   {
     int j=0;
     int k=i;
    //  cout<<temp[i]<<"* ";
     if(temp[k] >= gen[j])
        {
            for(j=0,k=i;j<g;j++,k++)
            {
                if(temp[k]==gen[j])
                    temp[k]=0;
                else
                    temp[k]=1;
            }
              // cout<<temp[k]<<"- ";
        }
       
   }
 cout<<"CRC :";
  for(int i=n;i<s;i++)
       cout<<temp[i]<<" ";
     cout<<endl;


// part -2 - reciver side

    int rec[s+1];
       for(int i=0;i<n;i++)
           rec[i]=arr[i];
         for(int j=n;j<s;j++)
            rec[j]=temp[j];

           for(int i=0;i<n;i++)
		   {
		     int j=0;
		     int k=i;
		    //  cout<<temp[i]<<"* ";
		     if(rec[k] >= gen[j])
			{
			    for(j=0,k=i;j<g;j++,k++)
			    {
				if(rec[k]==gen[j])
				    rec[k]=0;
				else
				    rec[k]=1;
			    }
			      // cout<<temp[k]<<"- ";
			}
		   }
           for(int i=n;i<s;i++)
             if(rec[i]!=0)
                 {
                    cout<<"error occured"<<endl;
                     break;
                  }
              else
                 {
                     cout<<"data successfully received"<<endl; 
                     break;
                 }      
     
return 0;
}

