#include <stdlib.h>
#include <string.h>
#include "caesar.h"

/* 
 * Hjælpefunktion: forskyd et enkelt tegn med 'shift' pladser.
 * Bevarer små og store bogstaver; alle andre tegn returneres uændrede.
 */
static char shift_char(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        return (char)('A' + ( (c - 'A' + shift + 26) % 26 ));
    } else if (c >= 'a' && c <= 'z') {
        return (char)('a' + ( (c - 'a' + shift + 26) % 26 ));
    }
    /* Tegn som ikke er bogstaver returneres uændret */
    return c;
}

/*
 * Krypter en streng med Cæsar-chifferet.
 * Returnerer en malloc'et streng som skal free'es af kaldende kode.
 */
char *encrypt(const char *text, int shift) {
    if (!text) return NULL;
    size_t n = strlen(text);
    char *out = malloc(n + 1);
    if (!out) return NULL;
    for (size_t i = 0; i < n; ++i) out[i] = shift_char(text[i], shift);
    out[n] = '\0';
    return out;
}

/*
 * Dekrypter ved at anvende den inverse forskydning.
 * Her genbruger vi encrypt med (26 - shift) så vi undgår duplikeret logik.
 */
char *decrypt(const char *text, int shift) {
    /* Normaliser shift til 0-25 */
    shift = (shift % 26 + 26) % 26;
    return encrypt(text, (26 - shift) % 26);
}

