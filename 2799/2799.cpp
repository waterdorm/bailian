#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>// 不需要排序我想多了 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	vector<string> f,b;


	int i,j,k;
	int max = 0;
	int nCases;
	scanf("%d",&nCases);
	cin>>ws; // 吃掉回车和空格等，避免影响下面输入。 std::ws 
	f.resize(nCases);
	b.resize(nCases);
	for ( i = 0; i < nCases; i++)
	{
		getline(cin,f[i],'.');
		getline(cin,b[i]);
		if (f[i].size() > max) max = f[i].size();
	}
	for (i =0; i < nCases; i++)
	{
		cout<<setw(max)<<f[i]<<right;
		cout<<'.'<<b[i]<<endl; // <<f[i]
	}
	return 0;
}
