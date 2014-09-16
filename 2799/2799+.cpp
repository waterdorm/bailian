#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
int i,n,maxlen=0;
cin>>n;
cin>>ws;
vector<string> vint(n),vdec(n);
for(i=0;i<n;i++)
{
getline(cin,vint[i],'.');
getline(cin,vdec[i]);
if(vint[i].size()>maxlen) maxlen = vint[i].size();
}
for(i=0;i<n;i++)
cout<<setw(maxlen)<<right<<vint[i]<<'.'<<vdec[i]<<endl;
return 0;
}
