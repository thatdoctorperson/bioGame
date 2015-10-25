#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include "fonts.h"
#include "labels.h"
#include "levels.h"

#define levelNum 1

using namespace std;

void init();
void deinit();

FONT *fonts[20];

int main() {
	init();
	
	srand(time(NULL));
	
	show_mouse(screen);
	Label cellLabels[20];
	Destination boxes[20];
	BITMAP *background = NULL;
	BITMAP *bufferMain = create_bitmap(screenw, screenh);
	int lvl = 1;
    
   	loadLvl(cellLabels, boxes, background, lvl);
    
	while (!key[KEY_ESC]) {
        moveLabels(cellLabels, boxes);
        blit(background, bufferMain, 0, 0, 0, 0, screenw, screenh);
        drawLabels(cellLabels, boxes, bufferMain);
        blit(bufferMain, screen, 0, 0, 0, 0, screenw, screenh);
        
        if (mouse_b & 1 && mouse_x < 95 && mouse_x > 15 && mouse_y < 55 && mouse_y > 15){
           if (checkLabels(cellLabels, boxes)){
              loadLvl(cellLabels, boxes, background, lvl);
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
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, screenw, screenh, 0, 0);
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
