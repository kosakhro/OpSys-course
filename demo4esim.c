/**
 * Demo 4 kirjallinen palautustehtävä.
 *
 * Tämä koettaa johdatella käymään läpi samoja kysymyksiä, joita
 * ryhmäharjoitteessa käytiin läpi kasvotusten. Tee kaikki kohdat 1-5.
 *
 * 1. Tutustu seuraavaan C#-ohjelmaan:
 *
 *       https://repl.it/repls/StaleDodgerblueBotany
 *
 * 2. Kirjoita vastaukset seuraaviin kysymyksiin C#-esimerkkiin
 *    liittyen. Vastausten pohtiminen ennakkoon toivottavasti
 *    helpottaa myöhempien tehtävien tekemistä:
 *
 *    Kysymys: Millainen lukujono on Fibonacci? Miten se
 *    muodostetaan?
 *    Vastaus: (kirjoita tähän)
 *
 *    Kysymys: Mikä tietorakenne C#-esimerkkiohjelmassa on käytössä?
 *    Vastaus: (kirjoita tähän)
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia pinosta.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia keosta.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan pinomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan kekomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus:
 *
 *    Kysymys: Milloin pinosta varattu muisti vapautuu?
 *    Vastaus:
 *
 *    Kysymys: Milloin keosta varattu muisti vapautuu?
 *    Vastaus:
 *
 *
 *
 * 3. Tutustu tähän C-kieliseen esimerkkiohjelmaan ja vastaa
 *    seuraaviin kysymyksiin:
 *
 *    Kysymys: Mikä tietorakenne C-esimerkkiohjelmassa on käytössä?
 *    Vastaus: (kirjoita tähän)
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia pinosta.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia keosta.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan pinomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus:
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan kekomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus:
 *
 *    Kysymys: Milloin pinosta varattu muisti vapautuu?
 *    Vastaus:
 *
 *    Kysymys: Milloin keosta varattu muisti vapautuu?
 *    Vastaus:
 *
 *    Kysymys: Selitä, miksi aliohjelmaan lisaa() viedään osoitin
 *    luku-tietueeseen.
 *    Vastaus:
 *
 *    Kysymys: Miksi esimerkiksi rivillä
 *
 *                 lukujono = lisaa(lukujono, 3);
 *
 *    täytyy tehdä sijoitus muuttujaan lukujono? Ts. Miksi ei olisi
 *    vain
 *
 *                 lisaa(lukujono, 3);
 *
 *    Vastaus:
 *
 *    Kysymys: Aliohjelman lisaa() kutsumuoto (engl. signature) on
 *
 *                luku *lisaa(luku *lukujono, int arvo);
 *
 *    Miksi se ei voisi olla
 *
 *                luku lisaa(luku *lukujono, int arvo);
 *
 *    Vastaus:
 *
 * 4. Tallenna tämä koodi nimelle "demo4vastaus.c" ja muokkaa tätä
 *    niin, että se toimii samoin kuin kohdan 1 C#-ohjelma. Voit
 *    katsoa mallia siitä sekä alkuperäisestä esimerkkikoodista.
 *
 * 5. Palauta syntynyt tiedosto "demo4vastaus.c" kommentteineen.
 *
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct _luku luku;

struct _luku  {
  int arvo;
  struct _luku *seuraava;
};

luku *lisaa(luku *lukujono, int arvo) {
  luku *uusi = NULL;
  uusi = malloc(sizeof(luku));
  uusi->arvo = arvo;
  uusi->seuraava = lukujono;
  return uusi;
}

void tyhjenna(luku *lukujono) {
  if (lukujono == NULL) return;
  luku *seuraava = lukujono->seuraava;
  free(lukujono);
  tyhjenna(seuraava);
}


int laske_summa(luku *lukujono, int summa) {
  luku *nykyinen = lukujono;
  if (nykyinen == NULL) return summa;
  return laske_summa(nykyinen->seuraava, summa+nykyinen->arvo);
}

int main(int argc, char **argv) {
  luku *lukujono = lisaa(NULL, 1);
  lukujono = lisaa(lukujono, 2);
  lukujono = lisaa(lukujono, 3);
  lukujono = lisaa(lukujono, 4);

  int summa = laske_summa(lukujono, 0);
  printf("summa on %d\n", summa);
  tyhjenna(lukujono);

  return 0;
}
