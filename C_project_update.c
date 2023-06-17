/*===========================================================================================
 * Title : C Project
 * Name  : Mohamed Abdelhamid
 * Date  : 21/2/2023
 *===========================================================================================*/

#include <stdio.h>
void menu_1 (void);
void menu_2 (void);
char menu_2_operation (void);
void traffic_light_color(void);
void room_temperature(void);
void engine_temperature(void);
void status (void);

struct status{ /*struct of used members*/
	int speed;
	int roomtemperature;
	int ac_state;
	int Engine_state;
	int Engine_temperature_controller;
	int Engine_temperature;
}st;

/////////////////////main///////////////////////
int main (void)
{
	setvbuf (stdout,NULL,_IONBF,0);
	setvbuf (stderr,NULL,_IONBF,0);

	//initial values of the 2 sensors
	st.roomtemperature = 19;
	st.Engine_temperature = 115;

	char input; //user choice

	menu_1();	//display options
	scanf (" %c", &input);

	while (input != 'c'){	//terminate if choice is quit
		if ('a' == input){
			input = menu_2_operation();
		}
		if ('b' == input){
			menu_1();
		}

		scanf ("%c", &input); //get the new choice, if equal to c, the loop will be terminated
	}
	return 0;
}

/////////////////////menu_1/////////////////////////
void menu_1 (void){

	printf ("a. Turn on the vehicle engine\n");
	printf ("b. Turn off the vehicle engine\n");
	printf ("c. Quit the system\n");
	printf ("\n");
}

/////////////////////menu_2/////////////////////////
void menu_2 (void){
	printf ("-Sensors set menu:\n");
	printf ("a. Turn off the engine\n");
	printf ("b. Set the traffic light color\n");
	printf ("c. Set the room temperature\n");
	printf ("d. Set the engine temperature\n");
	printf ("\n");
}

/////////////////////menu_2 Service/////////////////////////
char menu_2_operation (void){
	char c;
	st.Engine_state = 1;	//state of engine is on
	menu_2 ();	//display second menu
	scanf (" %c", &c);

	while (c != 'a'){
		if ('b' == c){
			traffic_light_color ();
		}
		else if ('c' == c){
			room_temperature();
		}
		else if ('d' == c){
			engine_temperature ();
		}
		status(); 	// print the status before you take the new choice of the menu
		menu_2();	//display again the menu
		scanf (" %c", &c); //get the new value of the menu
	}
	return 'b';
}

/////////////////////Traffic light func./////////////////////////
void traffic_light_color(void){
    char color ;
    printf ("Enter the color: ");
    scanf (" %c", &color);

    switch (color){
    case 'G':
    	st.speed = 100;
    	break;
    case 'O':
    	st.speed = 30;
    	st.ac_state = 1;
    	st.roomtemperature = st.roomtemperature * (5/4) + 1;
    	st.Engine_temperature_controller = 1;
    	st.Engine_temperature = st.Engine_temperature * (5/4) + 1;

    	break;
    case 'R':
    	st.speed = 0;
    	break;
    }
}

//////////////////////////AC function/////////////////////////
void room_temperature(void){
	int current_temp;
	printf ("enter the temperature: ");
	scanf ("%d", &current_temp);

	if (current_temp < 10){
		st.roomtemperature = 20;
		st.ac_state = 1;
	}
	else if (current_temp > 30){
		st.roomtemperature = 20;
		st.ac_state = 1;
	}
	else
	{
		st.ac_state = 0;
	}
}

/////////////////////engine controller function/////////////////////////
void engine_temperature(void){
	int engine_temp;
	printf ("Enter Engine temperature: ");
	scanf ("%d", &engine_temp);

	if (engine_temp < 100){
		st.Engine_temperature_controller = 1;
		st.Engine_temperature = 125;
	}
	else if (engine_temp > 150){
		st.Engine_temperature_controller = 1;
		st.Engine_temperature = 125;
	}
	else {
		st.Engine_temperature_controller = 0;
		st.Engine_temperature = 135;
	}
}

//////////////////////////////////////////////////status printing function/////////////////////////////////////////////////////////////
void status (void){
	printf ("\n");
	st.Engine_state ? puts("Engine                        : ON"): puts("Engine                        : OFF");
	st.ac_state ? puts("AC                            : ON"): puts("AC                            : OFF");
	printf ("Speed                         : %d km/hr\n", st.speed);
	printf ("Room Temperature              : %d C\n", st.roomtemperature);
	st.Engine_temperature_controller ? puts("Engine temperature controller : ON"): puts("Engine temperature controller : OFF");
	printf ("Engine temperature            : %d C\n", st.Engine_temperature);
	printf ("\n");
}


