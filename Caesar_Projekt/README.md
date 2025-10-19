# Caesar Kryptering (Ncurses-projekt)

Dette program er udviklet som en del af gruppeopgaven i Ncurses
.

Formålet er at lave et program, der kan **kryptere og dekryptere tekst** ved hjælp af
**Cæsar-chifferet**, samt vise en simpel **tekstbrugergrænseflade** ved brug af **ncurses**.

---

## 📁 Filstruktur

| Filnavn     | Funktion |
|--------------|-----------|
| `main.c`     | Indeholder hovedprogrammet og ncurses-menuen. Brugeren kan vælge at kryptere eller dekryptere tekst. |
| `caesar.c`   | Indeholder implementering af kryptering og dekryptering med Cæsar-chifferet. |
| `caesar.h`   | Headerfil med funktionsdeklarationer for `encrypt()` og `decrypt()`. |
| `Makefile`   | Bruges til at kompilere hele projektet nemt med `make`. |

Kilder og anvendte ressourcer:

I arbejdet med denne opgave er følgende filer blevet brugt som reference og hjælp til forståelse af ncurses og C-programmering:

NCurses setup - fejlretning.docx
Bruges til at forstå opsætning og fejlfinding af ncurses og MinGW

NCurses setup - fejlretning


NCURSES-Programming-HOWTO.pdf
Givet som teknisk reference til ncurses-funktioner og opbygning af brugerflader i terminaler

NCURSES-Programming-HOWTO


osdc_Jim-Hall_C-Programming-Tips.pdf
Anvendt som inspirationskilde til korrekt C-programmeringspraksis og brug af ncurses i små spil og terminalprogrammer

osdc_Jim-Hall_C-Programming-Tips


Derudover er ChatGPT (OpenAI) anvendt som støtteværktøj
