#include <allegro.h>
#include "labels.h"
#include "fonts.h"

void drawLabels(Label boxes[]){
    BITMAP *buffer = create_bitmap(640, 480);
    clear_to_color(buffer, makecol(0,0,0));
    for (int i = 0; i < 20; i++){
        rectfill(buffer, boxes[i].x, boxes[i].y, boxes[i].x + boxes[i].w, 
            boxes[i].y + boxes[i].h, makecol(boxes[i].c.r, boxes[i].c.g, boxes[i].c.b));
        textout_ex(buffer, fonts[LC18], boxes[i].name, boxes[i].x + 10, boxes[i].y + 10, makecol(0,0,0), -1);
    }
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    destroy_bitmap(buffer);
}

void moveLabels(Label boxes[]){
     for (int i = 0; i < 20; i++){
       if (boxes[i].clicked){
          boxes[i].x = mouse_x - boxes[i].mx;
          boxes[i].y = mouse_y - boxes[i].my;
       }
       if (mouse_b & 1 && mouse_x < boxes[i].x + boxes[i].w && mouse_x > boxes[i].x && mouse_y < boxes[i].y + boxes[i].h && mouse_y > boxes[i].y){
          boxes[i].mx = mouse_x - boxes[i].x;
          boxes[i].my = mouse_y - boxes[i].y;
          boxes[i].clicked = true;
       }else{
          boxes[i].clicked = false;
       }
    }
}
