// Mika Kopsa 0507014, Juuso Kalliomäki 0457960, Mikko Jutila 0447734

#ifndef TIETORAKENTEET_H
#define TIETORAKENTEET_H
struct tuote {
	float koko;
	float arvo;
	char *nimike;
	struct tuote *pSeuraava;
};

struct palautus {
	char *aikaleima;
	struct tuote *pTuote;
	struct palautus *pSeuraava;
};

int lisaaTuote(struct tuote **alku, float tArvo, float tKoko, char *puskuri);
int lisaaPalautus(struct palautus **alku, struct tuote *tuote, char *puskuri);
void vapautaTuotteet(struct tuote *p);
void vapautaPalautukset(struct palautus *p);
#endif

// eof
