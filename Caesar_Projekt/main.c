/* 
 * Enkel ncurses-baseret CLI til at demonstrere Cæsar-kryptering/dekryptering.
 * Kommentarer og beskeder er på dansk.
 */

#include <curses.h>
#include <stdlib.h>
#include <ctype.h>
#include "caesar.h"

#define BUF_SZ 1024

/* Spørger brugeren om et shift-tal (0-25). Returnerer normaliseret shift. */
int ask_shift(WINDOW *w, int y, int x) {
    char s[16];
    mvwprintw(w, y, x, "Shift (0-25): ");
    wrefresh(w);
    echo();                 /* Vis input mens der tastes */
    wgetnstr(w, s, 15);     /* Læs max 15 chars */
    noecho();
    int shift = atoi(s);
    shift = (shift % 26 + 26) % 26;
    return shift;
}

/* Spørger brugeren om en tekst og skriver den ind i buf */
void ask_text(WINDOW *w, int y, int x, char *buf, int bufsz) {
    mvwprintw(w, y, x, "Indtast tekst: ");
    wrefresh(w);
    echo();
    wgetnstr(w, buf, bufsz - 1);
    noecho();
}

int main(void) {
    /* Initialiser ncurses */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int ch;
    char input[BUF_SZ];

    /* Simpel hovedløkke med menu */
    while (1) {
        clear();
        mvprintw(1,2,"Cæsar Kryptering (ncurses) - vælg:");
        mvprintw(3,4,"1) Krypter");
        mvprintw(4,4,"2) Dekrypter");
        mvprintw(5,4,"3) Afslut");
        mvprintw(7,2,"Tryk 1-3:");
        refresh();

        ch = getch();
        if (ch == '3' || ch == 'q' || ch == 'Q') break;

        if (ch == '1' || ch == '2') {
            clear();
            /* Læs tekst og shift fra brugeren */
            ask_text(stdscr, 2, 2, input, BUF_SZ);
            int shift = ask_shift(stdscr, 4, 2);

            /* Kald på krypterings-/dekrypteringsfunktion */
            char *out = NULL;
            if (ch == '1') out = encrypt(input, shift);
            else out = decrypt(input, shift);

            /* Vis resultat */
            mvprintw(6,2,"Resultat:");
            mvprintw(7,2,"%s", out ? out : "(fejl)");
            mvprintw(9,2,"Tryk en tast for at fortsætte...");
            refresh();
            getch();

            /* Frigør hukommelse */
            free(out);
        }
    }

    /* Luk ncurses ned og afslut */
    endwin();
    return 0;
}

