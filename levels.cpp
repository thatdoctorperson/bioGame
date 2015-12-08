#include <iostream>
#include <allegro.h>
#include "labels.h"
#include "levels.h"

int loadLvl(Label cellLabels[], Destination boxes[], BITMAP *&background, int levelNum){
	int lbls;
	
	for (int i = 0; i < 20; i++){
		cellLabels[i].x = screenw;
		cellLabels[i].y = screenh;
        cellLabels[i].h = 0;
        cellLabels[i].w = 0;
        cellLabels[i].clicked = false;
        cellLabels[i].visible = false;
        boxes[i].x = screenw + 1;
        boxes[i].y = screenh + 1;
        boxes[i].h = 0;
        boxes[i].w = 0;
        boxes[i].visible = false;
    }
    
    switch(levelNum){
    	case 1:
    		lbls = 4;
    		background = create_bitmap(screenw, screenh);
			clear_to_color(background, makecol(125, 38, 205));
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 43;
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
		    /*for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}*/
		    
		    for(int i = 0; i < 4; i++)
			    boxes[i].x = i * 105 + 4;
			for(int i = 6; i < 10; i++)
			    boxes[i].x = i%6 * 105 + 4;
			
			boxes[4].x = 435;
			boxes[5].x = 590;
			boxes[10].x = 435;
			boxes[11].x = 590;
			
			strcpy(cellLabels[0].name, "A");
			strcpy(cellLabels[1].name, "very");
			strcpy(cellLabels[2].name, "clean");
			strcpy(cellLabels[3].name, "animal");

			break;
		case 2:
			lbls = 5;
			background = create_bitmap(screenw, screenh);
			clear_to_color(background, makecol(125, 38, 205));
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 45 + 214;
		        cellLabels[i].x = 735;
		        cellLabels[i].h = 40;
		        cellLabels[i].w = 100;
		        cellLabels[i].clicked = false;
		        cellLabels[i].visible = true;
		        boxes[i].x = 0;
		        boxes[i].y = 0;
		        boxes[i].h = 40;
		        boxes[i].w = 100;
		        boxes[i].visible = true;
		    }
		    /*for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}*/
			
			boxes[0].x = 33;
			boxes[0].y = 362;
			boxes[1].x = 256;
			boxes[1].y = 440;
			boxes[2].x = 476;
			boxes[2].y = 315;
			
		    strcpy(cellLabels[0].name, "But");
			strcpy(cellLabels[1].name, "thought");
			strcpy(cellLabels[2].name, "to");
			strcpy(cellLabels[3].name, "be");
			strcpy(cellLabels[4].name, "dirtiest");
			break;
		case 3:
			lbls = 4;
			background = create_bitmap(screenw, screenh);
			clear_to_color(background, makecol(125, 38, 205));
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 45 + 214;
		        cellLabels[i].x = 735;
		        cellLabels[i].h = 40;
		        cellLabels[i].w = 100;
		        cellLabels[i].clicked = false;
		        cellLabels[i].visible = true;
		        boxes[i].x = 0;
		        boxes[i].y = 0;
		        boxes[i].h = 40;
		        boxes[i].w = 100;
		        boxes[i].visible = true;
		    }
		    /*for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}*/
			
			boxes[0].x = 25;
			boxes[0].y = 458;
			boxes[1].x = 230;
			boxes[1].y = 467;
			boxes[2].x = 518;
			boxes[2].y = 279;
			
		    strcpy(cellLabels[0].name, "Where");
			strcpy(cellLabels[1].name, "does");
			strcpy(cellLabels[2].name, "it");
			strcpy(cellLabels[3].name, "sleep?");
			break;
		case 4:
			lbls = 4;
			background = create_bitmap(screenw, screenh);
			clear_to_color(background, makecol(125, 38, 205));
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 45 + 214;
		        cellLabels[i].x = 735;
		        cellLabels[i].h = 40;
		        cellLabels[i].w = 100;
		        cellLabels[i].clicked = false;
		        cellLabels[i].visible = true;
		        boxes[i].x = 0;
		        boxes[i].y = 0;
		        boxes[i].h = 40;
		        boxes[i].w = 100;
		        boxes[i].visible = true;
		    }
		    /*for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}*/
			
			boxes[0].x = 10;
			boxes[0].y = 473;
			boxes[1].x = 276;
			boxes[1].y = 444;
			boxes[2].x = 503;
			boxes[2].y = 437;
			
		    strcpy(cellLabels[0].name, "Where");
			strcpy(cellLabels[1].name, "utensils");
			strcpy(cellLabels[2].name, "are");
			strcpy(cellLabels[3].name, "inkiest");
			break;
		/*case 5:
			lbls = 3;
			background = load_bitmap("bitmaps/anaphase2.bmp", NULL);
			if (!background)
				background = create_bitmap(screenw, screenh);
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 45 + 214;
		        cellLabels[i].x = 735;
		        cellLabels[i].h = 40;
		        cellLabels[i].w = 100;
		        cellLabels[i].clicked = false;
		        cellLabels[i].visible = true;
		        boxes[i].x = 0;
		        boxes[i].y = 0;
		        boxes[i].h = 40;
		        boxes[i].w = 100;
		        boxes[i].visible = true;
		    }
		    for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}
			
			boxes[0].x = 163;
			boxes[0].y = 430;
			boxes[1].x = 353;
			boxes[1].y = 443;
			boxes[2].x = 578;
			boxes[2].y = 136;
			
		    strcpy(cellLabels[0].name, "Daughter CellS");
			strcpy(cellLabels[1].name, "Poles");
			strcpy(cellLabels[2].name, "Spindle Fibre");
			break;
		case 6:
			lbls = 2;
			background = load_bitmap("bitmaps/cytokinesis2.bmp", NULL);
			if (!background)
				background = create_bitmap(screenw, screenh);
				
			for (int i = 0; i < lbls; i++){
		        cellLabels[i].y = i * 45 + 214;
		        cellLabels[i].x = 735;
		        cellLabels[i].h = 40;
		        cellLabels[i].w = 100;
		        cellLabels[i].clicked = false;
		        cellLabels[i].visible = true;
		        boxes[i].x = 0;
		        boxes[i].y = 0;
		        boxes[i].h = 40;
		        boxes[i].w = 100;
		        boxes[i].visible = true;
		    }
		    for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
			}
			
			boxes[0].x = 24;
			boxes[0].y = 282;
			boxes[1].x = 573;
			boxes[1].y = 313;
			
		    strcpy(cellLabels[0].name, "Chromatin");
			strcpy(cellLabels[1].name, "Haploid Cells");
			break;*/
		default:
			return 420;
	}
	
	return 1;
}
