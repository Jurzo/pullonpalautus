#include "tietorakenteet.h"

#include <stdio.h>
#include <stdlib.h>

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
