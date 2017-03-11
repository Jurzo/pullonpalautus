#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct tuote {
	float koko;
	float arvo;
	char *nimike;
	struct tuote *pSeuraava;
};

struct palautus {
	char *aikaleima;
	struct tuote *pTuote;
	int maara;
	struct palautus *pSeuraava;
};

typedef struct tuote Tuote;

typedef struct palautus Palautus;

int lisaaTuote(Tuote **alku, float tArvo, float tKoko, char *puskuri){
	Tuote * uusi;
	int merkkeja = 0;

	if(uusi = (Tuote*)malloc(sizeof(Tuote))){
		merkkeja = strlen(puskuri);

		if(uusi->nimike = (char*)malloc((merkkeja+1)*sizeof(char))){
			memset(uusi->nimike,0,merkkeja+1);
			strncpy(uusi->nimike,puskuri,merkkeja);
			uusi->arvo = tArvo;
			uusi->koko = tKoko;
			uusi->pSeuraava = NULL;

			if(*alku == NULL){
				*alku = uusi;
				printf("%f\n", uusi->koko);
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
	if(*alku){
		Palautus * tilapainen = *alku;
		while(tilapainen){
			if(tilapainen->pTuote == tuote){
				tilapainen->maara += 1;
				return 1;
			}
			tilapainen = tilapainen->pSeuraava;
		}
		return 0;
	}else{
		Palautus * uusi;
		int merkkeja = 0;

		if(uusi = (Palautus *)malloc(sizeof(Palautus))){
			merkkeja = strlen(puskuri);
			
			if(uusi->aikaleima = (char*)malloc((merkkeja+1)*sizeof(char))){
				memset(uusi->aikaleima,0,merkkeja+1);
				strncpy(uusi->aikaleima,puskuri,merkkeja);
				uusi->maara = 1;
				uusi->pTuote = tuote;
				uusi->pSeuraava = NULL;
				*alku = uusi;
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	
}

int main(){
	char testi[10] = "moi";
	Tuote *alku = NULL;
	Palautus *alkuP = NULL;
	printf("%p\n", alku);
	if(lisaaTuote(&alku, 1.0, 2.0,testi)){
		printf("hei\n");
	};
	if(lisaaPalautus(&alkuP, alku, testi)){
		printf("jiihaa\n");
	}
	printf("%s\n", alkuP->aikaleima);
}


/* eof */
