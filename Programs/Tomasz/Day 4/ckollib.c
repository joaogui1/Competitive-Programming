#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ckollib.h"

typedef enum {
  niezainicjalizowana,
  zainicjalizowana
} stan_typ;

static stan_typ stan_biblioteki = niezainicjalizowana;
static int N, indeks = 0, licznik_zapytan = 0;
static int* bufor;

static void blad(const char* wiadomosc){
	printf("BLAD! (ERROR!) %s\n", wiadomosc);
	exit(0);
}

static void wczytaj_talie() {
  assert(scanf("%d", &N) == 1);
  if (N <= 0) {
    blad("Liczba kart w talii powinna byc dodatnia. (The number of cards in the deck should be positive.)");
  }
  bufor = (int*)malloc(N * sizeof(int));
  if (bufor == NULL) {
    blad("Blad inicjalizacji. (Initialization error.)");
  }
  int i = 0;
  for (i = 0; i < N; ++i) {
    assert(scanf("%d", &bufor[i]) == 1);
    if (bufor[i] <= 0 || bufor[i] > 2000000000) {
      blad("Numer bajtemona spoza dozwolonego przedzialu. (Number of Bytemon outside the valid range.)");
    }
  }
}

static void inicjalizuj() {
  if (stan_biblioteki == niezainicjalizowana) {
    wczytaj_talie();
    stan_biblioteki = zainicjalizowana;
  }
}

int karta() {
  inicjalizuj();
  ++licznik_zapytan;
  if (licznik_zapytan == 2 * N + 3) {
    blad("Przekroczono limit wywolan funkcji karta. (Number of calls to function karta was exceeded.)");
  }
  if (indeks == N) {
    indeks = 0;
    return 0;
  }
  return bufor[indeks++];
}

void odpowiedz(int wynik){
	inicjalizuj();

  int przebiegow = (licznik_zapytan + N) / (N + 1);
	
  printf("Udzielona odpowiedz: (Given answer:) %d\n"
         "Liczba wywolan funkcji karta: (Number of calls to function karta:) %d\n"
         "Liczba rozpoczetych przebiegow: (Number of started passes:) %d\n",
          wynik, licznik_zapytan, przebiegow);
  free(bufor);
  exit(0);
}
