#include <stdio.h>

int main()	//escape sequence
{
	int x =10, y= 20;
	
	printf("\033[2J"); //0으로 시작은 8진수를 의미함(10진수:27)
						//[2J : 화면 클리어를 위한 escape sequence			
	while(1)
	{
		printf("\033[%d;%dH@", y, x);   //커서 이동 [x;yH
	}
	return 0;
	
}
