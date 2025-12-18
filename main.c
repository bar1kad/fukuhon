#include <unistd.h>
#include <curses.h>

int main() {
    const char message[] = "Check, check";
    int screen_row, screen_col;

    initscr();
    getmaxyx(stdscr, screen_row, screen_col);
    move(screen_row/2, (screen_col - sizeof(message))/2);
    addstr(message);
    curs_set(0);
    refresh();
    sleep(3);
    endwin();
    return 0;
}

