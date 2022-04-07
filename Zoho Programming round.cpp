#include <bits/stdc++.h>
using namespace std;
int n=5,de[5],am[5],k=0,dprev,dpres,i,j=0,m,loop;
char res,dest,rep[2];

void booking(int loop,int k)                                 // function to handle booking.
{     
	    cout<<"Enter the Restuarant name: "<<endl;
		cin>>res;
		cout<<"Enter the Destination point: "<<endl;
		cin>>dest;
		j++;
		loop=loop+1;
		if(j==1)
		rep[0]=dest;
		else
		{
			rep[1]=dest;
			j=0;
		}
}
void assign()                                                //function to assign delivery executive
   {  
        if(loop==5)
		{
			loop=5%n;
		}	
		if(k==0)                                             //for the very first order
		{
			cout<<"Delivery Executive of id No."<<de[k]<<" is allocated"<<endl;
			cout<<endl;
			am[k]=am[k]+50;
			dprev=k;
		}
		else if(rep[1]==rep[0])                             //for consecutive orders from same person
		{
			cout<<"Delivery Executive of id No."<<dprev+1<<" is allocated"<<endl;
			cout<<endl;
			am[dprev]=am[dprev]+5;
		}
		else                                                //for all the other orders
		{
			m=am[0];
			for(i=0;i<5;i++)
			{
				if(am[i]<=m)
				{
					m=am[i];
					dpres=i;
				}
			}
			cout<<"Delivery executive of id No."<<dpres+1<<" is allocated"<<endl;
			cout<<endl;
			am[dpres]+=50;
			dprev=dpres;
		}
}
		void status()                                     //for displaying the status of the delivery person
		{ 
			cout<<"Amount collected by Delivery Executive of id No."<<de[dprev]<<" is Rs."<<am[dprev]<<endl;
			cout<<endl;
			cout<<"Amount collected by Delivery Executive of id No."<<de[dprev]<<" along with allowance "<<"is Rs."<<am[dprev]+10<<endl;
			cout<<endl;
		}
int main()
{  int r,s;
    for(r=0;r<n;r++)
	de[r]=r+1;
	for(s=0;s<n;s++)
	am[s]=0;
    loop=-1,k=0;
   int x=0;
   for(x=0;x>=0;x++)
   {
   booking(loop,k);
   assign();
   status();
   loop++;
   k++;
}
   return 0;	
}

