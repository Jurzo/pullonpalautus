//Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <stdlib.h>
#include <string.h>
#include "tietorakenteet.h"

int lisaaTuote(struct tuote **alku, float tArvo, float tKoko, char *puskuri){
	struct tuote * uusi;
	int merkkeja = 0;

	if(uusi = (struct tuote*)malloc(sizeof(struct tuote))){
		merkkeja = strlen(puskuri);

		if(uusi->nimike = (char*)malloc((merkkeja+1)*sizeof(char))){
			strcpy(uusi->nimike,puskuri);
			uusi->arvo = tArvo;
			uusi->koko = tKoko;
			uusi->pSeuraava = NULL;

			if(*alku == NULL){
				printf("fdhsui\n");
				*alku = uusi;
			}else{
				struct tuote * tilapainen = *alku;
				while(tilapainen->pSeuraava != NULL){
					printf("a");
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

int lisaaPalautus(struct palautus **alku, struct tuote *tuote, char *puskuri){
	struct palautus * uusi;
	int merkkeja = 0;
	if(uusi = (struct palautus *)malloc(sizeof(struct palautus))){
		merkkeja = strlen(puskuri);
			
		if(uusi->aikaleima = (char*)malloc((merkkeja+1)*sizeof(char))){
			strcpy(uusi->aikaleima,puskuri);
			uusi->pTuote = tuote;
			uusi->pSeuraava = NULL;

			if(*alku == NULL){
				*alku = uusi;
			}else{
				struct palautus * tilapainen = *alku;
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

void vapautaTuotteet(struct tuote *p){
	struct tuote *nykyinen;
	struct tuote *tilapainen = p;

	while(tilapainen){
		nykyinen = tilapainen;
		tilapainen = nykyinen->pSeuraava;
		free(nykyinen);
	}
}

void vapautaPalautukset(struct palautus *p){
	struct palautus *nykyinen;
	struct palautus *tilapainen = p;

	while(tilapainen){
		nykyinen = tilapainen;
		tilapainen = nykyinen->pSeuraava;
		free(nykyinen);
	}
}


/* eof */
