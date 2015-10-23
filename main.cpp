#include <allegro.h>
#include <string.h>
#include <iostream>
#include "labels.h"
#include "fonts.h"

using namespace std;

void init();
void deinit();

FONT *fonts[20];

int main() {
	init();
	
	show_mouse(screen);
	Label cellLabels[20];
	Destination boxes[20];
	BITMAP *buffer = create_bitmap(640, 480);
	
	for (int i = 0; i < 20; i++){
        cellLabels[i].visible = false;

        boxes[i].visible = false;
    }
	
	for (int i = 0; i < 10; i++){
        cellLabels[i].y = i * 50;
        cellLabels[i].x = 40;
        cellLabels[i].h = 40;
        cellLabels[i].w = 100;
        cellLabels[i].clicked = false;
        strcpy(cellLabels[i].name, "boner");
        cellLabels[i].visible = true;
        
        boxes[i].x = 200;
        boxes[i].y = i * 50;
        boxes[i].h = 40;
        boxes[i].w = 100;
        boxes[i].visible = true;
    }
    
    

	while (!key[KEY_ESC]) {
		/* put your code here */
        moveLabels(cellLabels, boxes);
        drawLabels(cellLabels, boxes);
        
        if (mouse_b & 1 && mouse_x < 620 && mouse_x > 540 && mouse_y < 460 && mouse_y > 420){
           if (checkLabels(cellLabels, boxes)){
              return 0;
           }
        }
	}

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
	if (loadFonts()){
	   cout << "********Error loading fonts********";
    }
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
