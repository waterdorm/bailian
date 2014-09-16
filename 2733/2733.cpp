#include <iostream>
#include <cstdio>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// 这样要注意特殊情况的相互间的包含关系，注意 if 的次序 
	// 特殊情况优先 
	int year;
	scanf("%d",&year);
	 if ((0 == year % 100) && (year % 400 != 0))
	 	printf("%c\n",'N');
	else if ( 0 == year % 4)
		printf("%c\n",'Y');
	else printf("%c\n",'N');
	return 0;
}
