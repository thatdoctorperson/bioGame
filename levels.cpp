#include <iostream>
#include <allegro.h>
#include "labels.h"
#include "levels.h"

int loadLvl(Label cellLabels[], Destination boxes[], BITMAP *&background, int levelNum){
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
			background = load_bitmap("meiosis.bmp", NULL);
			if (!background)
				background = create_bitmap(screenw, screenh);
				
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
		    	std::swap(cellLabels[i].y, cellLabels[rand()%12].y);
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
			break;
		default:
			return 404;
	}
	
	return 1;
}
