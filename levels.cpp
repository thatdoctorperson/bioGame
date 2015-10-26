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
    		lbls = 12;
			background = load_bitmap("meiosis.bmp", NULL);
			if (!background)
				background = create_bitmap(screenw, screenh);
				
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
		    for(int i = 0; i < lbls; i++){
		    	std::swap(cellLabels[i].y, cellLabels[rand()%lbls].y);
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
		case 2:
			lbls = 3;
			background = load_bitmap("metaphase1.bmp", NULL);
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
			
			boxes[0].x = 33;
			boxes[0].y = 362;
			boxes[1].x = 256;
			boxes[1].y = 440;
			boxes[2].x = 476;
			boxes[2].y = 315;
			
		    strcpy(cellLabels[0].name, "Tetrad");
			strcpy(cellLabels[1].name, "Equator");
			strcpy(cellLabels[2].name, "Centomere");
			break;
		case 3:
			lbls = 3;
			background = load_bitmap("telophase1.bmp", NULL);
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
			
			boxes[0].x = 25;
			boxes[0].y = 458;
			boxes[1].x = 230;
			boxes[1].y = 467;
			boxes[2].x = 518;
			boxes[2].y = 279;
			
		    strcpy(cellLabels[0].name, "Chromosome");
			strcpy(cellLabels[1].name, "Cleavage Furrow");
			strcpy(cellLabels[2].name, "Centrioles");
			break;
		case 4:
			lbls = 3;
			background = load_bitmap("prophase2.bmp", NULL);
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
			
			boxes[0].x = 10;
			boxes[0].y = 473;
			boxes[1].x = 276;
			boxes[1].y = 444;
			boxes[2].x = 503;
			boxes[2].y = 437;
			
		    strcpy(cellLabels[0].name, "Cell Membrane");
			strcpy(cellLabels[1].name, "Diploid Cell");
			strcpy(cellLabels[2].name, "Nucleus");
			break;
		case 5:
			lbls = 3;
			background = load_bitmap("anaphase2.bmp", NULL);
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
			background = load_bitmap("cytokinesis2.bmp", NULL);
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
			break;
		default:
			return 420;
	}
	
	return 1;
}
