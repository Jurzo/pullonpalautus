//Nimet: Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <stdio.h>
//#include "tiedosto.h"
//#include "tietorakenteet.h"
//#include "apufunktiot.h"

#define true 1
#define false 0

int main (void){

	//Listan lukeminen
	//Tuote *tuoteLista;
	//lueNimikkeet("tuotetiedosto.txt", &tuoteLista);

	int valinta;
	while (true){
	
		//valikon tulostus
		
		printf("Pullonpalautusautomaatti\nAutomaatti on valmis ottamaan vastaan pullot ja tölkit.\n");
		printf("1) Aloita palautus\n0) Lopeta\n");
		
		//valinnan tarkkailu
		
		printf("Valitse: ");
		if (scanf("%d", &valinta) != 1){
			printf("Virheellinen valinta\n");
			while (getchar() != '\n') {}
			continue;
			}
		if (valinta == 1){
			//tölkien ja pullojen määrä tiedostosta tähän ja niiden pohjalta toinen valikko.
			int i;
			printf("\nSyötä uusi pullo tai tölkki.\n");
			for (){
				printf("%d) %s %fl", i, ?, ?);//jotain
				}
			printf("Lopeta syöttö ja tulosta kuitti.");
			}
		
		else if(valinta == 0){
			printf("Suljetaan pullonpalautusautomaatti.\n");
			break;
			}
		
		else{
			//virhe ilmoitus, jos on kokonaisluku
			printf("Valitse 1 aloittaaksesi tai 0 lopettaaksesi\n");
			}
	}
}
//eof
