#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
int main(void)
{
   ifstream myfile("graph.txt");
   int n;
   myfile>>n;
   int a[n][n];
   queue<int> q;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           myfile>>a[i][j];
       }
   }
   int v[n];
   for(int i=0;i<n;i++)
   {
       v[i]=0;
   }
   q.push(0);
   int curr;
   int hat=0;
   while(!q.empty())
   {
       curr = q.front();
       if(v[curr]==1)
       {
           cout<<"The graph is not a tree"<<endl;
           hat=1;
           break;
       }
       v[curr]=1;
       q.pop();
       for(int j=0;j<n;j++)
       {
           if(a[curr][j]==1)
           {
               q.push(j);
           }
       }
   }
   if(hat==0)
   {
       cout<<"The graph is a tree"<<endl;
   }
   return 0;
}
