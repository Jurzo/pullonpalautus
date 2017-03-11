program: main.o apufunktiot.o tietorakenteet.o tiedosto.o
	gcc main.o apufunktiot.o tietorakenteet.o tiedosto.o -o program -Wall -std=c99
main.o: main.c apufunktiot.h tietorakenteet.h tiedosto.h
	gcc main.c apufunktiot.h tietorakenteet.h tiedosto.h -c -Wall -std=c99
apufunktiot.o: apufunktiot.c apufunktiot.h
	gcc apufunktiot.c apufunktiot.h -c -Wall -std=c99
tietorakenteet.o: tietorakenteet.c tietorakenteet.h
	gcc tietorakenteet.c tietorakenteet.h -c -Wall -std=c99
tiedosto.o: tiedosto.c apufunktiot.h tietorakenteet.h tiedosto.h
	gcc tiedosto.c apufunktiot.h tietorakenteet.h tiedosto.h -c -Wall -std=c99
