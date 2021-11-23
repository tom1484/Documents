#include <bits/stdc++.h>
using namespace std;
int main() {
  int x=0;
  double y=6.957546152;
  double z=2.657546152;
  int cnt=1;
  double u,t,s=0;
  for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
               if(i==0) u=-4.3;
               else u=4.3;
               if(j==0) t=-4.3;
               else t=4.3;
               if(k==0) s=-4.3;
               else s=4.3;
               cout<<"tuple<double, double, double>e_m"<<cnt<<"("<<u<<","<<t<<","<<s<<");\n";
               cnt++;
            }
        }
    }
for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
               if(i==0) u=-x;
               else u=x;
               if(j==0) t=-y;
               else t=y;
               if(k==0) s=-z;
               else s=z;
               cout<<"tuple<double, double, double>e_m"<<cnt<<"("<<u<<","<<t<<","<<s<<");\n";
               cnt++;
               cout<<"tuple<double, double, double>e_m"<<cnt<<"("<<s<<","<<u<<","<<t<<");\n";
               cnt++;
               cout<<"tuple<double, double, double>e_m"<<cnt<<"("<<t<<","<<s<<","<<u<<");\n";
               cnt++;
            }
        }
    }
}
