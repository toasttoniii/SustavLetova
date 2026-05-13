#include "../include/let.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dodajLet(const char *imeDatoteke) {
    if (imeDatoteke == NULL) return;
    
    Let let;

    printf("Unesite oznaku leta (npr. OU401): ");
    scanf("%9s", let.oznaka);
    getchar(); // ocisti buffer

    printf("Unesite destinaciju: ");
    fgets(let.destinacija, MAX_DESTINACIJA, stdin);
    let.destinacija[strcspn(let.destinacija, "\n")] = 0;

    printf("Unesite datum (DD.MM.GGGG): ");
    fgets(let.datum, 11, stdin);
    let.datum[strcspn(let.datum, "\n")] = 0;
    getchar();

    printf("Unesite cijenu karte: ");
    scanf("%f", &let.cijena);
    getchar();

    printf("Unesite broj slobodnih mjesta: ");
    scanf("%d", &let.slobodnaMjesta);
    getchar();

    let.status = SCHEDULED;

    FILE *fp = fopen(imeDatoteke, "ab");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    fwrite(&let, sizeof(Let), 1, fp);
    fclose(fp);

    printf("Let uspjesno dodan!\n");
}

void ispisLetova(const char *imeDatoteke) {
    if (imeDatoteke == NULL) return;
    
    Let let;

    FILE *fp = fopen(imeDatoteke, "rb");
    if (fp == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    printf("\n%-5s %-10s %-20s %-12s %-8s %-8s %-10s\n",
           "ID", "Oznaka", "Destinacija", "Datum", "Cijena", "Mjesta", "Status");
    printf("-----------------------------------------------------------------------\n");

    int id = 1;
    while (fread(&let, sizeof(Let), 1, fp) == 1) {
        let.id = id++;
        printf("%-5d %-10s %-20s %-12s %-8.2f %-8d %-10s\n",
               let.id, let.oznaka, let.destinacija, let.datum,
               let.cijena, let.slobodnaMjesta,
               let.status == SCHEDULED ? "SCHEDULED" :
               let.status == DELAYED   ? "DELAYED"   :
               let.status == CANCELLED ? "CANCELLED" : "COMPLETED");
    }

    fclose(fp);
}