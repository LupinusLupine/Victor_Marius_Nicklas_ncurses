#include <curses.h>
/* gcc -o hello.exe hello_ncurses.c -lncurses */
int main()
{
    initscr(); /* Start curses mode */
    printw("Hello Ncurses !!!"); /* Print Hello Ncurses */
    refresh(); /* Print it on to the real screen */
    getch(); /* Wait for user input */
    endwin(); /* End curses mode */
}