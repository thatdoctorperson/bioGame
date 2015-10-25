#include <allegro.h>
#include <string.h>
#include <iostream>
#include <ctime>
#include "labels.h"
#include "fonts.h"

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
	BITMAP *background = load_bitmap("meiosis.bmp", NULL);
	BITMAP *bufferMain = create_bitmap(screenw, screenh);
	if (!background)
		return 0;

	
	for (int i = 0; i < 20; i++){
        cellLabels[i].visible = false;

        boxes[i].visible = false;
    }
	
	for (int i = 0; i < 12; i++){
        cellLabels[i].y = i * 45;
        cellLabels[i].x = 735;
        cellLabels[i].h = 40;
        cellLabels[i].w = 100;
        cellLabels[i].clicked = false;
        cellLabels[i].visible = true;
        boxes[i].x = 0;
        boxes[i].y = 225;
        if(i >= 6)
        	boxes[i].y = 500;
        boxes[i].h = 40;
        boxes[i].w = 100;
        boxes[i].visible = true;
    }
    for(int i = 0; i < 12; i++){
    	swap(cellLabels[i].y, cellLabels[rand()%12].y);
	}
    
    for(int i = 0; i < 4; i++)
	    boxes[i].x = i * 105 + 4;
	for(int i = 6; i < 10; i++)
	    boxes[i].x = i%6 * 105 + 4;
	
	boxes[4].x = 435;
	boxes[5].x = 590;
	boxes[10].x = 435;
	boxes[11].x = 590;
	
	strcpy(cellLabels[0].name, "Interphase");
	strcpy(cellLabels[1].name, "Prophase 1");
	strcpy(cellLabels[2].name, "Metaphase 1");
	strcpy(cellLabels[3].name, "Anaphase 1");
	strcpy(cellLabels[4].name, "Telophase 1");
	strcpy(cellLabels[5].name, "Cytokinesis 1");
	strcpy(cellLabels[6].name, "Interkinesis");
	strcpy(cellLabels[7].name, "Prophase 2");
	strcpy(cellLabels[8].name, "Metaphase 2");
	strcpy(cellLabels[9].name, "Anaphase 2");
	strcpy(cellLabels[10].name, "Telophase 2");
	strcpy(cellLabels[11].name, "Cytokenesis 2");

	while (!key[KEY_ESC]) {
		/* put your code here */
        moveLabels(cellLabels, boxes);
        blit(background, bufferMain, 0, 0, 0, 0, screenw, screenh);
        drawLabels(cellLabels, boxes, bufferMain);
        blit(bufferMain, screen, 0, 0, 0, 0, screenw, screenh);
        
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
