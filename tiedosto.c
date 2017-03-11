#include <stdio.h>
#include <stdlib.h>

#include "tietorakenteet.h"
#include "apufunktiot.h"
#include "tiedosto.h"

int lueNimikkeet(char *tiedostonimi, Tuote **alku) {
	char nimikePuskuri[32];
	float kokoPuskuri, arvoPuskuri;
	FILE *tiedosto = fopen(tiedostonimi, "r");
	while (!feof(tiedosto)) {
		if (fscanf("%s %f %f\n", nimikePuskuri, &kokoPuskuri, &arvoPuskuri) < 3) {
			printf("Rivi hylättiin.\n");
		} else {
			if (lisaaTuote(alku, arvoPuskuri, kokoPuskuri, nimikePuskuri) == 0) {
				printf("Tuotteen lisäys epäonnistui.\n");
			}
		}
	}
	fclose(tiedosto);
	return 0;
}

int kirjoitaTilapainenLoki(char *tiedostonimi, Palautus *alku) {
	FILE *tiedosto = fopen(tiedostonimi, "w");
	while (alku != NULL) {
		Tuote *pTuote = alku->pTuote;
		fprintf(tiedosto, "%s:%s-%.2fl:%.2f€.\n", alku->aikaleima, pTuote->nimike, pTuote->koko, pTuote->arvo);
		alku = alku->pSeuraava;
	}
	fclose(tiedosto);
}

int kirjoitaLoki(char *tiedostonimi, Palautus *alku) {
	int palautustenLkm;
	float panttienSumma;
	Tuote *pTuote = alku->pTuote;
	
	while (alku != NULL) {
		palautustenLkm++;
		panttienSumma += pTuote->arvo;
	}
	
	FILE *tiedosto = fopen(tiedostonimi, "a");
	fprintf(tiedosto, "%s:%s - Palautukset %d kpl. Pantit %.2f€.\n", alku->aikaleima, pTuote->nimike, pTuote->koko, pTuote->arvo);
	fclose(tiedosto);
}
