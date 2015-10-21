#include <allegro.h>
#include "fonts.h"

//Loads all sizes of lucida console from datfile to globaal array of fonts
int loadFonts(){
     DATAFILE *fontFile = NULL;
     fontFile = load_datafile("fonts.dat");
     
     if (fontFile == NULL)
        return 1;
     
     //Iterate through sizes
     for (int i = 0; i <= S20; i++){
         fonts[i] = (FONT*) fontFile[i].dat;
         
         if (fonts[i] == NULL)
            return 1;
     }
     
     return 0;
}
