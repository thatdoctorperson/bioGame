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
	
	blit(load_bitmap("start.bmp", NULL), screen, 0, 0, 0, 0, screenw, screenh);
	rectfill(screen, 380, 480, 460, 520, makecol(0,255,0));
    textout_ex(screen, fonts[LC18], "Next", 385, 490, makecol(0,0,0), -1);
	while(!((mouse_b & 1 && mouse_x < 460 && mouse_x > 380 && mouse_y < 520 && mouse_y > 480) || key[KEY_ESC])){
	}
	
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
        
        if (mouse_b & 1 && mouse_x < 835 && mouse_x > 755 && mouse_y < 555 && mouse_y > 515){
           if (checkLabels(cellLabels, boxes)){
                if(loadLvl(cellLabels, boxes, background, ++lvl) == 420){
                	blit(load_bitmap("end.bmp", NULL), screen, 0, 0, 0, 0, screenw, screenh);
                	while(!key[KEY_ESC]){
					}
					return 0;
				}	
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
