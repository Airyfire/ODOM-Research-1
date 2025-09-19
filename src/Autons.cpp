#include "api.h"

// define which auto to run
int selected_auto = 0; // 0 = none, 1 = red auto 1, 2 = red auto 2, 3 = red auto 3, 4 = blue auto 1, 5 = blue auto 2, 6 = blue auto 3

void r_auto1();
void r_auto2();
void r_auto3();
void b_auto1();
void b_auto2();
void b_auto3();

/*
void run_selected_auto() {
    if (selected_auto == 1) {
        r_auto1();
    }
    else if (selected_auto == 2) {
        r_auto2();
    }
    else if (selected_auto == 3) {
        r_auto3();
    }
    else if (selected_auto == 4) {
        b_auto1();
    }
    else if (selected_auto == 5) {
        b_auto2();
    }
    else if (selected_auto == 6) {
        b_auto3();
    }
}
    */