#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int x,y;

int main()
{	
	printf("\033[2J");		//clear screen
	int fd = wiringPiI2CSetup(0x48); //디바이스 아이디 = 48(그냥 쓰기x)
									//dh: 디바이스 핸들(dev handle
		
	while(1)
	{
		wiringPiI2CWrite(fd, 00);	//c00 (Right ) Select(조도센서)
		wiringPiI2CRead(fd) ;
		int x = (wiringPiI2CRead(fd) * 80)/255;	//fd로 부터 값을 읽어서 int로 돌려주는
								//0~255인 x값을 최대 80까지로 바꾸는  식
		delay(100);		
		
		
		wiringPiI2CWrite(fd, 01);	//ch01(TEMP) Select(온도센서)
		wiringPiI2CRead(fd);
		int y = (wiringPiI2CRead(fd)*24)/255;		//fd로 부터 값을 읽어서 int로 돌려주는
		delay(100);			//0~255인 y값을 최대 24로 바꾸는 식
		
		/*
		wiringPiI2CWrite(fd, 03);	//ch03(VR) input3번 (가변저항센서)
		wiringPiI2CRead(fd);
		int v3 = wiringPiI2CRead(fd);	//fd로 부터 값을 읽어서 int로 돌려주는
		*/
		
		printf("\033[%d;%dH(%d,%d)\n", y,x,x,y);
		delay(200);		
		
	}
	
	return 0;
} 


