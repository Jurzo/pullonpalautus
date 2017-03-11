//Nimet: Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <stdio.h>
#include "tiedosto.h"
#include "tietorakenteet.h"
#include "apufunktiot.h"

#define true 1
#define false 0


int valikko(void){

	//Listan lukeminen
	Tuote *tuoteLista;
	lueNimikkeet("tuotetiedosto.txt", &tuoteLista);
	Tuote *tuoteiter = tuoteLista;
	
	while (true){
	
		//tölkien ja pullojen määrä tiedostosta tähän ja niiden pohjalta toinen valikko.
		int i = 1;
		printf("\nSyötä uusi pullo tai tölkki.\n");
		while (true){
			printf("%d) %s %fl", i, tuoteiter->nimike, tuoteiter->koko);//jotain
			i++;
			tuoteiter = tuoteiter->pSeuraava;
			}
		printf("%d) Lopeta syöttö ja tulosta kuitti.",i);
		//kuitin tulostus
		}
	}

int main (void){


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
			valikko();
		
		}else if(valinta == 0){
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
