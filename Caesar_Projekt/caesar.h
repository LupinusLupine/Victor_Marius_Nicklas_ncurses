#ifndef CAESAR_H
#define CAESAR_H

/* funktioner til Cæsar-kryptering/dekryptering */
char *encrypt(const char *text, int shift);
char *decrypt(const char *text, int shift);

#endif

