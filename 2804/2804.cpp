#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_NUM 11
int main(int argc, char** argv) {
	map <string,string> dict;
	map<string,string>::iterator it;
	string tkey,tvalue;
	char temp[MAX_NUM*3];
	char key[MAX_NUM];
	char value[MAX_NUM];
	char query[MAX_NUM];
	
	while (fgets(temp,30,stdin), temp[0] != '\n')
	{
		sscanf(temp,"%s%s",value,key);
		dict.insert(make_pair(key,value));
	}
	while (scanf("%s",query)!= EOF)
	{
		
		if ((it = dict.find(query))!= dict.end())
			printf("%s\n",(it->second).c_str());
		else printf("eh\n");
			
	}
	return 0;
}
