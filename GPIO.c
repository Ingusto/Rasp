#include <wiringPi.h>
#include <stdio.h>

#define RED		8
#define	GREEN	9
#define	YELLOW	7
#define	SW		2
#define	SW2		3

int mode = 0;
int intv = 0;
int tim;
int ps[40];


void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin, ps[pin]);
}

void gpioisr()
{
	
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured..\n");
}


int main()
{
	wiringPiSetup();
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	pinMode(SW2, INPUT);
	
	while(intv <10)
	{	
		
		tim = (9-intv)*100;

		if(mode)
		{
			Toggle(8); delay(tim);
			Toggle(9); delay(tim);
			Toggle(7); delay(tim);
		}
		else 
		{
			Toggle(7); delay(tim);
			Toggle(9); delay(tim);
			Toggle(8); delay(tim);
		}
		
		if(digitalRead(SW2) == 0)
		{
			intv = 10;
			digitalWrite(RED, 0);
			digitalWrite(YELLOW, 0);
			digitalWrite(GREEN, 0);
		}
	}
	return 0;			// whille문 안에 있따면 gg
}
