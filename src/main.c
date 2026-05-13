#include <stdio.h>
#include <stdlib.h>
#include "../include/let.h"

#define IME_DATOTEKE "letovi.bin"

typedef enum {
    IZLAZ,
    DODAJ_LET,
    ISPIS_LETOVA
} OpcijaProgramaEnum;

void ispisIzbornika() {
    printf("\n=== SUSTAV LETOVA ===\n");
    printf("%d. Izlaz\n", IZLAZ);
    printf("%d. Dodaj let\n", DODAJ_LET);
    printf("%d. Ispis letova\n", ISPIS_LETOVA);
    printf("Odabir: ");
}

int main() {
    int odabir;

    do {
        ispisIzbornika();
        scanf("%d", &odabir);

        switch (odabir) {
            case DODAJ_LET:
                dodajLet(IME_DATOTEKE);
                break;
            case ISPIS_LETOVA:
                ispisLetova(IME_DATOTEKE);
                break;
            case IZLAZ:
                printf("Izlaz iz programa.\n");
                break;
            default:
                printf("Nepostojeca opcija!\n");
        }
    } while (odabir != IZLAZ);

    return 0;
}