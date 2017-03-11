//Nimet: Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <stdlib.h>
#include <string.h>
#include "tietorakenteet.h"



int lisaaTuote(Tuote **alku, float tArvo, float tKoko, char *puskuri){
	Tuote * uusi;
	int merkkeja = 0;

	if(uusi = (Tuote*)malloc(sizeof(Tuote))){
		merkkeja = strlen(puskuri);

		if(uusi->nimike = (char*)malloc((merkkeja+1)*sizeof(char))){
			strcpy(uusi->nimike,puskuri);
			uusi->arvo = tArvo;
			uusi->koko = tKoko;
			uusi->pSeuraava = NULL;

			if(*alku == NULL){
				*alku = uusi;
			}else{
				Tuote * tilapainen = *alku;
				while(tilapainen->pSeuraava){
					tilapainen = tilapainen->pSeuraava;
				}
				tilapainen->pSeuraava = uusi;
			}
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int lisaaPalautus(Palautus **alku, Tuote *tuote, char *puskuri){
	Palautus * uusi;
	int merkkeja = 0;
	if(uusi = (Palautus *)malloc(sizeof(Palautus))){
		merkkeja = strlen(puskuri);
			
		if(uusi->aikaleima = (char*)malloc((merkkeja+1)*sizeof(char))){
			strcpy(uusi->aikaleima,puskuri);
			uusi->pTuote = tuote;
			uusi->pSeuraava = NULL;

			if(*alku == NULL){
				*alku = uusi;
			}else{
				Palautus * tilapainen = *alku;
				while(tilapainen->pSeuraava){
					tilapainen = tilapainen->pSeuraava;
				}
				tilapainen->pSeuraava = uusi;
			}
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

void vapautaTuotteet(Tuote *p){
	Tuote *nykyinen;
	Tuote *tilapainen = p;

	while(tilapainen){
		nykyinen = tilapainen;
		tilapainen = nykyinen->pSeuraava;
		free(nykyinen);
	}
}

void vapautaPalautukset(Palautus *p){
	Palautus *nykyinen;
	Palautus *tilapainen = p;

	while(tilapainen){
		nykyinen = tilapainen;
		tilapainen = nykyinen->pSeuraava;
		free(nykyinen);
	}
}


/* eof */
