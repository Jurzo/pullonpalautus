#include <stdio.h>
#include <stdlib.h>

#include "tietorakenteet.h"
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
		fprintf(tiedosto, "%s:%s-%.2fl:%.2f€.\n");
	}
	fclosse(tiedosto);
}
