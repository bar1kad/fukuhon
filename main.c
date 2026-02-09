#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "util/file_util.h"
#include "util/array_util.h"

enum { ESCAPE_KEY = 27, SPACE_KEY = ' ', BACKSPACE_KEY = 127 };
enum { BUFF_SIZE = 1024 };

void go_to_next_row(int *curr_row, int *curr_col)
{
    (*curr_row)++;
    *curr_col = 1;
}

int is_ascii(char key)
{
    return key >= 32 && key <= 126;
}

void make_output(char *input_buffer, int *curr_col, int *curr_row, int screen_col_max, int file_size)
{
    for (int i = 0; i < BUFF_SIZE && i < file_size; i++) {
        if (*curr_col >= screen_col_max - 1) {
            go_to_next_row(curr_row, curr_col);
        }
        move(*curr_row, *curr_col);
        addch(input_buffer[i]);
        (*curr_col)++;
    }
}

int main(int argc, char **argv)
{
    FILE *file;
    int screen_row_max, screen_col_max;
    int key, curr_col, curr_row;
    int curr_buffer_pos;
    int file_size;

    file = open_for_read(argv[1]);

    initscr();
    getmaxyx(stdscr, screen_row_max, screen_col_max);

    char input_buffer[BUFF_SIZE];
    /* to restore original input using BACKSPACE_KEY */
    char restore_buffer[BUFF_SIZE];

    fgets(input_buffer, sizeof(input_buffer), file);
    arr_copy(input_buffer, restore_buffer, BUFF_SIZE);

    curr_col = 1;
    curr_row = 1;
    curr_buffer_pos = 0;

    file_size = get_file_size(file);
    move(curr_row, curr_col);

/*  make ouput  */
    make_output(input_buffer, &curr_col, &curr_row, screen_col_max, file_size);

    curr_col = 1;
    curr_row = 1;

    move(curr_row, curr_col);
    curs_set(1);
    noecho();

// make input
#if 1
    unsigned char curr_char = input_buffer[curr_buffer_pos];

    while ((key = getch()) != ESCAPE_KEY) {
#if 0
        move(10, 10);
        addch(curr_char);
        move(11, 10);
        addch(key);
        move(12, 10);
        addch(input_buffer[curr_buffer_pos]);
        move(curr_col, curr_row)
#endif 

        if (curr_col >= screen_col_max - 1) {
            go_to_next_row(&curr_row, &curr_col);
        }
//        if (is_ascii(key) && key == input_buffer[curr_buffer_pos]) {
        if (is_ascii(key)) {
            addch(key);
            curr_col++;
            curr_buffer_pos++;
        } else if (key == BACKSPACE_KEY) {
            curr_col--;
            curr_buffer_pos--;
//            move(curr_row, curr_col);
            addch(restore_buffer[curr_buffer_pos]);
            input_buffer[curr_buffer_pos] = restore_buffer[curr_buffer_pos];
        }
        move(curr_row, curr_col);
        refresh();
    }
#endif

    endwin();
    return 0;
}

