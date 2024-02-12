#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define CTRL_KEY(k) ((k) & 0x1f)

void screen_init() {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    nl();
    keypad(stdscr, TRUE);
    raw();
}

void editor_process_key_event() {
    int c = wgetch(stdscr);

    switch (c) {
        case CTRL_KEY('q'):
            exit(0);
        default:
            addch(c);
    }
}

void screen_destroy() {
    refresh();
    endwin();
}

int main(int argc, char *argv[argc + 1]) {
    atexit(screen_destroy);
    screen_init();
    while (1) {
        editor_process_key_event();
    }
    screen_destroy();
    return 0;
}
