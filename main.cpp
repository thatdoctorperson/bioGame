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
	Label boxes[20];
	BITMAP *buffer = create_bitmap(640, 480);
	
	for (int i = 0; i < 20; i++){
        boxes[i].y = i * 50;
        boxes[i].x = 40;
        boxes[i].h = 40;
        boxes[i].w = 100;
        boxes[i].c.r = 255;
        boxes[i].c.g = 0;
        boxes[i].c.b = 255;
        boxes[i].clicked = false;
        strcpy(boxes[i].name, "boner");
    }
    
    

	while (!key[KEY_ESC]) {
		/* put your code here */
        moveLabels(boxes);
        drawLabels(boxes);
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
