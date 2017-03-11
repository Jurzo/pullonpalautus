typedef struct tuote {
	float koko;
	float arvo;
	char *nimike;
	struct tuote *pSeuraava;
} Tuote;

typedef struct palautus {
	char *aikaleima;
	struct tuote *pTuote;
	struct palautus *pSeuraava;
} Palautus;

int lisaaTuote(Tuote **alku, float tArvo, float tKoko, char *puskuri);
int lisaaPalautus(Palautus **alku, Tuote *tuote, char *puskuri);
void vapautaTuotteet(Tuote *p);
void vapautaPalautukset(Palautus *p);
/* eof */
