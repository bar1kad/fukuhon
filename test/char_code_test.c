#include <stdio.h>
#include <curses.h>

enum { ESCAPE_KEY = 27 };
int main() {
    int screen_row_max, screen_col_max;
    int key;

    initscr();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, screen_row_max, screen_col_max);

    while ((key = getch()) != ESCAPE_KEY) {
        move(screen_row_max / 2, screen_col_max / 2);
        printw("%d  ", key);
        refresh();
    }
    endwin();
    return 0;
}

