#include <stdio.h>
#include <curses.h>

int main() {
    int screen_row_max, screen_col_max;
    initscr();
    getmaxyx(stdscr, screen_row_max, screen_col_max);
}

