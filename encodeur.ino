#include "LiquidCrystal.h" 

#define EncodeurA	2
#define EncodeurB	3

#define RS			5
#define E 			4
#define D4			10
#define D5			11
#define D6			12
#define D7			13

LiquidCrystal lcd (RS, E, D4, D5, D6, D7);

volatile boolean mouvement;
volatile boolean up;

int valeur = 0;  

void routineInterruption ()  {     
  if (digitalRead(EncodeurA))
    up = digitalRead(EncodeurB);
  else
    up = !digitalRead(EncodeurB);
  mouvement = true;
}


void setup ()
{
	pinMode(EncodeurA,INPUT);
	pinMode(EncodeurB,INPUT);  

	lcd.begin(20,4);
	analogWrite(9,180);

	attachInterrupt (0,routineInterruption,FALLING);
}

void loop ()
{
	if (mouvement)
	{
		if (up)
			valeur++;
		else
			valeur--;
		mouvement = false;
		lcd.setCursor(0,0);lcd.print(valeur);
	}
} 
