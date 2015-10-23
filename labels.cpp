#include <allegro.h>
#include "labels.h"
#include "fonts.h"

void drawLabels(Label cellLabels[], Destination boxes[]){
    BITMAP *buffer = create_bitmap(640, 480);
    clear_to_color(buffer, makecol(0,0,0));
    for (int i = 0; i < 20; i++){
        if (boxes[i].visible){
            rectfill(buffer, boxes[i].x, boxes[i].y, boxes[i].x + boxes[i].w, 
                boxes[i].y + boxes[i].h, BOXCOL);
        }
    }
    for (int i = 0; i < 20; i++){
        if (cellLabels[i].visible){
            rectfill(buffer, cellLabels[i].x, cellLabels[i].y, cellLabels[i].x + cellLabels[i].w, 
                cellLabels[i].y + cellLabels[i].h, LABELCOL);
            textout_ex(buffer, fonts[LC18], cellLabels[i].name, cellLabels[i].x + 10, cellLabels[i].y + 10, makecol(0,0,0), -1);
        }
    }
    
    rectfill(buffer, 540, 420/*BLAZE IT*/, 620, 460, makecol(0,255,0));
    textout_ex(buffer, fonts[LC18], "Check", 550, 430, makecol(0,0,0), -1);
    
    blit(buffer, screen, 0, 0, 0, 0, 640, 480);
    destroy_bitmap(buffer);
}

void moveLabels(Label cellLabels[], Destination boxes[]){
     for (int i = 0; i < 20; i++){
       if (cellLabels[i].clicked){
          cellLabels[i].x = mouse_x - cellLabels[i].mx;
          cellLabels[i].y = mouse_y - cellLabels[i].my;
       }else{
          for (int j = 0; j < 20; j++){
              if (cellLabels[i].x > boxes[j].x - 30 && cellLabels[i].x < boxes[j].x + 30 && cellLabels[i].y > boxes[j].y - 30 && cellLabels[i].y < boxes[j].y + 30){
                 cellLabels[i].x = boxes[j].x;
                 cellLabels[i].y = boxes[j].y;
              }
          }
       }
       if (mouse_b & 1 && mouse_x < cellLabels[i].x + cellLabels[i].w && mouse_x > cellLabels[i].x && mouse_y < cellLabels[i].y + cellLabels[i].h && mouse_y > cellLabels[i].y){
          cellLabels[i].mx = mouse_x - cellLabels[i].x;
          cellLabels[i].my = mouse_y - cellLabels[i].y;
          cellLabels[i].clicked = true;
          break;
       }else{
          cellLabels[i].clicked = false;
       }
    }
}

bool checkLabels(Label cellLabels[], Destination boxes[]){
     bool check = true;
     for (int i = 0; i < 20; i++){
         if (cellLabels[i].visible && (cellLabels[i].x!=boxes[i].x || cellLabels[i].x!=boxes[i].x)){
            check = false;
         }
     }
     return check;
}
