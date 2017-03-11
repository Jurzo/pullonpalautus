//Nimet: Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int aika(void){
	time_t current_time;
	char* c_time_string;
	
	current_time = time(NULL);
	
	if (current_time == ((time_t)-1)){
		(void) fprintf(stderr, "Ajan haku epäonnistui.\n");
		}
	c_time_string = ctime(&current_time);
	
	if (c_time_string == NULL){
		(void) fprintf(stderr, "Ajan muutos epäonnistui.\n");
		}
	return current_time;
		
	
}
