#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/hal/lv_hal_indev.h"
#include "liblvgl/llemu.h"
#include "liblvgl/llemu.hpp"
#include "liblvgl/lv_conf_internal.h"
#include "liblvgl/misc/lv_txt.h"
#include "pros//screen.h"
#include "pros/screen.hpp"
#include "pros/colors.hpp"
#include "api.h"
#include "liblvgl/font/lv_font.h" // Include the font header
#include "Autons.hpp"

//create separate screens for red and blue
lv_obj_t* red_screen = lv_obj_create(NULL); // Create a new screen
lv_obj_t* blue_screen = lv_obj_create(NULL); // Create a new screen
lv_obj_t* original_screen = lv_scr_act(); // Get the current active screen

//callback functions for red and blue buttons
void red_select(lv_event_t* e){
    lv_scr_load(red_screen); // Load the new screen
}

void blue_select(lv_event_t* e){
    lv_scr_load(blue_screen); // Load the new screen
}

void back_to_main(lv_event_t* e){
    lv_scr_load(original_screen); // Load the main screen
}

// callbacks for confirming auton selection on red screen
void run_r_auto1(lv_event_t* e){
    // put something in here
    selected_auto = 1;
}

void run_r_auto2(lv_event_t* e){
    // put something in here
    selected_auto = 2;
}

void run_r_auto3(lv_event_t* e){
    // put something in here
    selected_auto = 3;
}

// callbacks for confirming auton selection on blue screen
void run_b_auto1(lv_event_t* e){
    // put something in here
    selected_auto = 4;
}

void run_b_auto2(lv_event_t* e){
    // put something in here
    selected_auto = 5;
}

void run_b_auto3(lv_event_t* e){
    // put something in here
    selected_auto = 6;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//callback functions for auton buttons on red screen

// red auto 1 description
void red_auto1_select(lv_event_t* e){
    lv_obj_t* r_a1_desc = lv_obj_create(red_screen);
    lv_obj_set_size(r_a1_desc, 200, 200);
    lv_obj_align(r_a1_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(r_a1_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(r_a1_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* r_a1_label = lv_label_create(r_a1_desc);
    lv_label_set_long_mode(r_a1_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(r_a1_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(r_a1_label, "Left-side scoring routine");
    lv_obj_set_style_text_font(r_a1_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(r_a1_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(r_a1_label); //place label on center of button
}

// red auto 2 description
void red_auto2_select(lv_event_t* e){
    lv_obj_t* r_a2_desc = lv_obj_create(red_screen);
    lv_obj_set_size(r_a2_desc, 200, 200);
    lv_obj_align(r_a2_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(r_a2_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(r_a2_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* r_a2_label = lv_label_create(r_a2_desc);
    lv_label_set_long_mode(r_a2_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(r_a2_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(r_a2_label, "Right-side scoring routine");
    lv_obj_set_style_text_font(r_a2_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(r_a2_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(r_a2_label); //place label on center of button
}

// red auto 3 description
void red_auto3_select(lv_event_t* e){
    lv_obj_t* r_a3_desc = lv_obj_create(red_screen);
    lv_obj_set_size(r_a3_desc, 200, 200);
    lv_obj_align(r_a3_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(r_a3_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(r_a3_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* r_a3_label = lv_label_create(r_a3_desc);
    lv_label_set_long_mode(r_a3_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(r_a3_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(r_a3_label, "Solo win routine");
    lv_obj_set_style_text_font(r_a3_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(r_a3_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(r_a3_label); //place label on center of button
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//callback functions for auton buttons on blue screen

// red auto 1 description
void blue_auto1_select(lv_event_t* e){
    lv_obj_t* b_a1_desc = lv_obj_create(blue_screen);
    lv_obj_set_size(b_a1_desc, 200, 200);
    lv_obj_align(b_a1_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(b_a1_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(b_a1_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* b_a1_label = lv_label_create(b_a1_desc);
    lv_label_set_long_mode(b_a1_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(b_a1_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(b_a1_label, "Left-side scoring routine");
    lv_obj_set_style_text_font(b_a1_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(b_a1_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(b_a1_label); //place label on center of button
}

// red auto 2 description
void blue_auto2_select(lv_event_t* e){
    lv_obj_t* b_a2_desc = lv_obj_create(blue_screen);
    lv_obj_set_size(b_a2_desc, 200, 200);
    lv_obj_align(b_a2_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(b_a2_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(b_a2_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* b_a2_label = lv_label_create(b_a2_desc);
    lv_label_set_long_mode(b_a2_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(b_a2_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(b_a2_label, "Right-side scoring routine");
    lv_obj_set_style_text_font(b_a2_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(b_a2_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(b_a2_label); //place label on center of button
}

// red auto 3 description
void blue_auto3_select(lv_event_t* e){
    lv_obj_t* b_a3_desc = lv_obj_create(blue_screen);
    lv_obj_set_size(b_a3_desc, 200, 200);
    lv_obj_align(b_a3_desc, LV_ALIGN_RIGHT_MID, -5, 0); // Position on the right of auto buttons
    lv_obj_set_style_bg_color(b_a3_desc, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //button color white
    lv_obj_set_style_bg_opa(b_a3_desc, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* b_a3_label = lv_label_create(b_a3_desc);
    lv_label_set_long_mode(b_a3_label, LV_LABEL_LONG_WRAP); // Enable text wrapping
    lv_obj_set_width(b_a3_label, 180); // Set the width of the label to fit within the container
    lv_label_set_text(b_a3_label, "Solo win routine");
    lv_obj_set_style_text_font(b_a3_label, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(b_a3_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(b_a3_label); //place label on center of button
}
int auton_selector() {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // create a red button on the screen
    lv_obj_t* Red = lv_btn_create(original_screen); //button creation
    lv_obj_set_size(Red, 225, 200); //inital size
    lv_obj_align(Red, LV_TEXT_ALIGN_LEFT, 0, 20); //alignment
    lv_obj_set_style_bg_color(Red, lv_color_hex(0xFF0000), LV_PART_MAIN); //button color

    //label this Red button
    lv_obj_t* red_label = lv_label_create(Red);
    lv_label_set_text(red_label,"RED");
    lv_obj_set_style_text_color(red_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(Red, &lv_font_montserrat_30, LV_PART_MAIN); // set font
    lv_obj_center(red_label); //place label on center of button

    lv_obj_add_event_cb(Red, red_select, LV_EVENT_CLICKED, NULL); //button functionality
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // create a blue button on the screen
    lv_obj_t* Blue = lv_btn_create(original_screen); //button creation
    lv_obj_set_size(Blue, 225, 200); //inital size
    lv_obj_align(Blue, LV_TEXT_ALIGN_RIGHT, 0, 20); //alignment
    lv_obj_set_style_bg_color(Blue, lv_color_hex(0x23C1FF), LV_PART_MAIN); //button color
 
    //label this Blue button
    lv_obj_t* blue_label = lv_label_create(Blue);
    lv_label_set_text(blue_label,"BLUE");
    lv_obj_set_style_text_color(blue_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(Blue, &lv_font_montserrat_30, LV_PART_MAIN); // set font
    lv_obj_center(blue_label); //place label on center of button

    lv_obj_add_event_cb(Blue, blue_select, LV_EVENT_CLICKED, NULL); //button functionality
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Red Screen Design
    lv_obj_t* red_auto1 = lv_btn_create(red_screen);
    
    //Auto 1 button
    lv_obj_set_size(red_auto1, 200, 75); //inital size
    lv_obj_align(red_auto1, LV_ALIGN_TOP_LEFT, 0, 0); //alignment

    lv_obj_set_style_bg_color(red_auto1, lv_color_hex(0xE75480), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(red_auto1, LV_OPA_COVER, LV_PART_MAIN); //background type

    lv_obj_t* red_auto1_label = lv_label_create(red_auto1);
    lv_label_set_text(red_auto1_label,"Auto 1");
    lv_obj_set_style_text_font(red_auto1, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_auto1_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_auto1_label); //place label on center of button

    // add callback to button auto1 below:
    lv_obj_add_event_cb(red_auto1, red_auto1_select, LV_EVENT_CLICKED, NULL); //button functionality

    // Auto 2 button
    lv_obj_t* red_auto2 = lv_btn_create(red_screen);
    lv_obj_set_size(red_auto2, 200, 75); //inital size
    lv_obj_align(red_auto2, LV_ALIGN_LEFT_MID, 0, 0); //alignment
    lv_obj_set_style_bg_color(red_auto2, lv_color_hex(0xE75480), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(red_auto2, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* red_auto2_label = lv_label_create(red_auto2);
    lv_label_set_text(red_auto2_label,"Auto 2");
    lv_obj_set_style_text_font(red_auto2, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_auto2_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_auto2_label); //place label on center of button

    //add callback to button auto2 below:
    lv_obj_add_event_cb(red_auto2, red_auto2_select, LV_EVENT_CLICKED, NULL); //button functionality

    // Auto 3 button
    lv_obj_t* red_auto3 = lv_btn_create(red_screen);
    lv_obj_set_size(red_auto3, 200, 75); //inital size
    lv_obj_align(red_auto3, LV_ALIGN_BOTTOM_LEFT, 0, 0); //alignment
    lv_obj_set_style_bg_color(red_auto3, lv_color_hex(0xE75480), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(red_auto3, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* red_auto3_label = lv_label_create(red_auto3);
    lv_label_set_text(red_auto3_label,"Auto 3");
    lv_obj_set_style_text_font(red_auto3, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_auto3_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_auto3_label); //place label on center of button

    //add callback to button auto3 below:
    lv_obj_add_event_cb(red_auto3, red_auto3_select, LV_EVENT_CLICKED, NULL); //button functionality

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Blue Screen Design

    lv_obj_t* blue_auto1 = lv_btn_create(blue_screen);
    
    //Auto 1 button
    lv_obj_set_size(blue_auto1, 200, 75); //inital size
    lv_obj_align(blue_auto1, LV_ALIGN_TOP_LEFT, 0, 0); //alignment

    lv_obj_set_style_bg_color(blue_auto1, lv_color_hex(0x005F6B), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(blue_auto1, LV_OPA_COVER, LV_PART_MAIN); //background type

    lv_obj_t* blue_auto1_label = lv_label_create(blue_auto1);
    lv_label_set_text(blue_auto1_label,"Auto 1");
    lv_obj_set_style_text_font(blue_auto1, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_auto1_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_auto1_label); //place label on center of button

    // add callback to button auto1 below:
    lv_obj_add_event_cb(blue_auto1, blue_auto1_select, LV_EVENT_CLICKED, NULL); //button functionality

    // Auto 2 button
    lv_obj_t* blue_auto2 = lv_btn_create(blue_screen);
    lv_obj_set_size(blue_auto2, 200, 75); //inital size
    lv_obj_align(blue_auto2, LV_ALIGN_LEFT_MID, 0, 0); //alignment
    lv_obj_set_style_bg_color(blue_auto2, lv_color_hex(0x005F6B), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(blue_auto2, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* blue_auto2_label = lv_label_create(blue_auto2);
    lv_label_set_text(blue_auto2_label,"Auto 2");
    lv_obj_set_style_text_font(blue_auto2, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_auto2_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_auto2_label); //place label on center of button

    //add callback to button auto2 below:
    lv_obj_add_event_cb(blue_auto2, blue_auto2_select, LV_EVENT_CLICKED, NULL); //button functionality

    // Auto 3 button
    lv_obj_t* blue_auto3 = lv_btn_create(blue_screen);
    lv_obj_set_size(blue_auto3, 200, 75); //inital size
    lv_obj_align(blue_auto3, LV_ALIGN_BOTTOM_LEFT, 0, 0); //alignment
    lv_obj_set_style_bg_color(blue_auto3, lv_color_hex(0x005F6B), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(blue_auto3, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* blue_auto3_label = lv_label_create(blue_auto3);
    lv_label_set_text(blue_auto3_label,"Auto 3");
    lv_obj_set_style_text_font(blue_auto3, &lv_font_montserrat_24, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_auto3_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_auto3_label); //place label on center of button

    //add callback to button auto3 below:
    lv_obj_add_event_cb(blue_auto3, blue_auto3_select, LV_EVENT_CLICKED, NULL); //button functionality
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // YES button for confirmation of auton selection --- RED SCREEN
    lv_obj_t* red_yes_button = lv_btn_create(red_screen);
    lv_obj_set_size(red_yes_button, 70, 50); //inital size
    lv_obj_align(red_yes_button, LV_ALIGN_CENTER, -2, -25); //alignment
    lv_obj_set_style_bg_color(red_yes_button, lv_color_hex(0x00FF00), LV_PART_MAIN); //button color green
    lv_obj_set_style_bg_opa(red_yes_button, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* red_yes_label = lv_label_create(red_yes_button);
    lv_label_set_text(red_yes_label,"Yes");
    lv_obj_set_style_text_font(red_yes_button, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_yes_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_yes_label); //place label on center of button

    if (red_auto1_select && lv_obj_has_state(red_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(red_yes_button, run_r_auto1, LV_EVENT_CLICKED, NULL); //button functionality
    }
    else if (red_auto2_select && lv_obj_has_state(red_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(red_yes_button, run_r_auto2, LV_EVENT_CLICKED, NULL); //button functionality
    }
    else if (red_auto3_select &&lv_obj_has_state(red_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(red_yes_button, run_r_auto3, LV_EVENT_CLICKED, NULL); //button functionality
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // NO button for confirmation of auton selection --- RED SCREEN
    lv_obj_t* red_no_button = lv_btn_create(red_screen);
    lv_obj_set_size(red_no_button, 70, 50); //inital size
    lv_obj_align(red_no_button, LV_ALIGN_CENTER, -2, 25); //alignment
    lv_obj_set_style_bg_color(red_no_button, lv_color_hex(0xFF0000), LV_PART_MAIN); //button color red
    lv_obj_set_style_bg_opa(red_no_button, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* red_no_label = lv_label_create(red_no_button);
    lv_label_set_text(red_no_label,"No");
    lv_obj_set_style_text_font(red_no_button, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_no_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_no_label); //place label on center of button
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // YES button for confirmation of auton selection --- BLUE SCREEN
    lv_obj_t* blue_yes_button = lv_btn_create(blue_screen);
    lv_obj_set_size(blue_yes_button, 70, 50); //inital size
    lv_obj_align(blue_yes_button, LV_ALIGN_CENTER, -2, -25); //alignment
    lv_obj_set_style_bg_color(blue_yes_button, lv_color_hex(0x00FF00), LV_PART_MAIN); //button color green
    lv_obj_set_style_bg_opa(blue_yes_button, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* blue_yes_label = lv_label_create(blue_yes_button);
    lv_label_set_text(blue_yes_label,"Yes");
    lv_obj_set_style_text_font(blue_yes_button, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_yes_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_yes_label); //place label on center of button
    if (blue_auto1_select && lv_obj_has_state(blue_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(blue_yes_button, run_b_auto1, LV_EVENT_CLICKED, NULL); //button functionality
    }
    else if (blue_auto2_select && lv_obj_has_state(blue_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(blue_yes_button, run_b_auto2, LV_EVENT_CLICKED, NULL); //button functionality
    }
    else if (blue_auto3_select &&lv_obj_has_state(blue_yes_button, LV_INDEV_STATE_RELEASED)) {
        lv_obj_add_event_cb(blue_yes_button, run_b_auto3, LV_EVENT_CLICKED, NULL); //button functionality
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // NO button for confirmation of auton selection --- BLUE SCREEN
    lv_obj_t* blue_no_button = lv_btn_create(blue_screen);
    lv_obj_set_size(blue_no_button, 70, 50); //inital size
    lv_obj_align(blue_no_button, LV_ALIGN_CENTER, -2, 25); //alignment
    lv_obj_set_style_bg_color(blue_no_button, lv_color_hex(0xFF0000), LV_PART_MAIN); //button color red
    lv_obj_set_style_bg_opa(blue_no_button, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* blue_no_label = lv_label_create(blue_no_button);
    lv_label_set_text(blue_no_label,"No");
    lv_obj_set_style_text_font(blue_no_button, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_no_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_no_label); //place label on center of button
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // back button to return to main screen from red screen
    lv_obj_t* red_back = lv_btn_create(red_screen);
    lv_obj_set_size(red_back, 60, 60); //inital size
    lv_obj_align(red_back, LV_ALIGN_BOTTOM_MID, 0, -2); //alignment
    lv_obj_set_style_bg_color(red_back, lv_color_hex(0x808080), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(red_back, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* red_back_label = lv_label_create(red_back);
    lv_label_set_text(red_back_label,"Main");
    lv_obj_set_style_text_font(red_back, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(red_back_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(red_back_label); //place label on center of button
    lv_obj_add_event_cb(red_back, back_to_main, LV_EVENT_CLICKED, NULL); //button functionality
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // back button to return to main screen from blue screen
    lv_obj_t* blue_back = lv_btn_create(blue_screen);
    lv_obj_set_size(blue_back, 60, 60); //inital size
    lv_obj_align(blue_back, LV_ALIGN_BOTTOM_MID, 0, -2); //alignment
    lv_obj_set_style_bg_color(blue_back, lv_color_hex(0x808080), LV_PART_MAIN); //button color grey
    lv_obj_set_style_bg_opa(blue_back, LV_OPA_COVER, LV_PART_MAIN); //background type
    lv_obj_t* blue_back_label = lv_label_create(blue_back);
    lv_label_set_text(blue_back_label,"Main");
    lv_obj_set_style_text_font(blue_back, &lv_font_montserrat_18, LV_PART_MAIN); // set font
    lv_obj_set_style_text_color(blue_back_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_center(blue_back_label); //place label on center of button
    lv_obj_add_event_cb(blue_back, back_to_main, LV_EVENT_CLICKED, NULL); //button functionality
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;

}

