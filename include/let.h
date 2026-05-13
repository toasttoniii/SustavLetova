#ifndef LET_H
#define LET_H

#include <stdio.h>

#define MAX_OZNAKA    10
#define MAX_DESTINACIJA 50

typedef enum {
    SCHEDULED,
    DELAYED,
    CANCELLED,
    COMPLETED
} StatusLeta;

typedef struct {
    int id;
    char oznaka[MAX_OZNAKA];
    char destinacija[MAX_DESTINACIJA];
    char datum[11];
    float cijena;
    int slobodnaMjesta;
    StatusLeta status;
} Let;

// CREATE
void dodajLet(const char *imeDatoteke);

// READ
void ispisLetova(const char *imeDatoteke);

#endif