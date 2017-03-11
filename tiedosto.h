//Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#ifndef TIEDOSTO_H
#define TIEDOSTO_H
int lueNimikkeet(char *, struct tuote **);
int kirjoitaTilapainenLoki(char *, struct palautus *);
int kirjoitaLoki(char *tiedostonimi, struct palautus *alku);
#endif
