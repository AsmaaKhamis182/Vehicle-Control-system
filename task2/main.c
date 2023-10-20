#include <stdio.h>
#include <stdlib.h>


int  speed;
int  flag = 0;              // Engine state : ON
int  temp_room = 20;
int  temp_engin = 125;
int  flag_temp_room = 0;    // AC : ON
int  flag_temp_engin = 0;   // Engine Temperature Controller State : ON


// Prototype of function

void start(void);
void Turn_on(void);
void Turn_off(void);
void engine_temperature(void);
void traffic_light_color(void);
void room_temperature(void);
void display(void);
void Quit(void);


int main(void)
{
  start();
}

// Body of functions

void start(void)
{
    fflush(stdin);
    char number;
    printf("\n ************************** Vehicle Control system ******************************* \n");
    printf("(a)Turn on the vehicle engine\n(b)Turn off the vehicle engine\n(c)Quit the system\n");
    printf("Enter the  Number : ");
    scanf("%c",&number);
    if (number == 'a')
    {
		printf("You are in turn on the vehicle engine mode.");
        Turn_on();
    }
    else if (number == 'b')
    {
		printf("You are in turn off the vehicle engine mode.");
        Turn_off();
    }
    else if (number == 'c')
    {
	    printf("You are in quit the system mode.");
        Quit();
    }
}



void Quit(void)
{


}

void Turn_off(void)
{
    flag = 1;
    start();
}



void Turn_on(void)
{
	flag = 0;
    char number;
    fflush(stdin);
    printf("Sensors set menu\n");
    printf("(a)Turn off the engine\n(b)Set the traffic light color\n(c)Set the room temperature (Temperature Sensor)\n");
    printf("(d)Set the engine temperature (Engine Temperature Sensor)\n");
    printf("Enter number of choice : ");
    scanf("%c",&number);

    if  (number == 'a')
    {
		Turn_on();
    }
    else if(number == 'b')
    {
        traffic_light_color();
    }
    else if (number == 'c')
    {
        room_temperature();
    }
    else if (number == 'd')
    {
        engine_temperature();
    }
}



void engine_temperature(void)
{
   int  temperature;
   printf("Enter the temperature of engine : ");
   scanf("%d",&temperature);
   if ((temperature < 100) && (temperature > 150))
   {
       flag_temp_engin = 0;
       temp_engin = 125;
   }
   else
   {
      flag_temp_engin = 1;
   }
   display();
}


void traffic_light_color(void)
{
    fflush(stdin);
    char light;
    printf("Enter the traffic light : ");
    scanf("%c",&light);
    if (light=='G')
    {
        speed = 100;
    }
    else if (light == 'O')
    {
        speed = 30;
        flag_temp_room = 0;
        temp_room = (temp_room*(5/4))+1;
        flag_temp_engin = 0;
        temp_engin = (temp_engin*(5/4))+1;
    }
    else if (light == 'R')
    {
       speed = 0;
    }
    display();
}




void room_temperature(void)
{
    int temputature;
    printf("enter the temperature of room : ");
    scanf("%d",&temputature);
    if((temputature < 10) && (temputature > 30))
    {
        temp_room=20;
        flag_temp_room=0;
    }
    else
    {
        flag_temp_room=1;
    }
    display();
}



void display(void)
{
   if (flag == 0)
    {
       printf("Engine State is : ON\n");
    }
   else
    {
       printf("Engine State is : OFF\n");
    }
   if (flag_temp_room == 0)
    {
       printf("AC : ON\n");
    }
   else
    {
       printf("AC : OFF\n");
    }
    printf("Speed = %d Km/hr\n",speed);
    printf("Room Temperature = %d\n",temp_room);
    if (flag_temp_engin == 0)
    {
      printf("Engine Temperature Controller State : ON\n");
    }
    else
	{
      printf("Engine Temperature Controller State : OFF\n");
    }
    printf("Engine Temperature : %d\n",temp_engin);
    printf("************************** End **********************************\n");
    start();
}

