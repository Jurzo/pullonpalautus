//Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#include <stdio.h>
#include <stdlib.h>

#include "tietorakenteet.h"
#include "apufunktiot.h"
#include "tiedosto.h"

int lueNimikkeet(char *tiedostonimi, struct tuote **alku) {
	char nimikePuskuri[32];
	float kokoPuskuri, arvoPuskuri;
	printf("%s\n", tiedostonimi);
	FILE *tiedosto;
	if ((tiedosto = fopen(tiedostonimi, "r")) == NULL) {
		printf("Tiedoston lukeminen epäonnistui.\n");
		return 0;
	}
	printf("Tiedosto avattu.\n");
	while (!feof(tiedosto)) {
		if (fscanf(tiedosto, "%s %f %f\n", nimikePuskuri, &kokoPuskuri, &arvoPuskuri) < 3) {
			printf("Rivi hylätty!\n");
		} else {
			printf("Rivi luettu.\n");
			printf("%s %f %f\n", nimikePuskuri, kokoPuskuri, arvoPuskuri);
			if (lisaaTuote(alku, arvoPuskuri, kokoPuskuri, nimikePuskuri) == 0) {
				printf("Tuotteen lisäys epäonnistui.\n");
				return 0;
			}
		}
	}
	fclose(tiedosto);
	return 1;
}

int kirjoitaTilapainenLoki(char *tiedostonimi, struct palautus *alku) {
	FILE *tiedosto = fopen(tiedostonimi, "w");
	while (alku != NULL) {
		struct tuote *pTuote = alku->pTuote;
		fprintf(tiedosto, "%s:%s-%.2fl:%.2f€.\n", alku->aikaleima, pTuote->nimike, pTuote->koko, pTuote->arvo);
		alku = alku->pSeuraava;
	}
	fclose(tiedosto);
	return 1;
}

int kirjoitaLoki(char *tiedostonimi, struct palautus *alku) {
	int palautustenLkm;
	float panttienSumma;
	struct tuote *pTuote = alku->pTuote;
	
	while (alku != NULL) {
		palautustenLkm++;
		panttienSumma += pTuote->arvo;
	}
	
	FILE *tiedosto = fopen(tiedostonimi, "a");
	fprintf(tiedosto, "%s:%s - Palautukset %d kpl. Pantit %.2f€.\n", alku->aikaleima, pTuote->nimike, palautustenLkm, panttienSumma);
	fclose(tiedosto);
	return 1;
}
