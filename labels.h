#ifndef labels
#define labels

#define LABELCOL makecol(255,0,255)
#define BOXCOL makecol(0,255,255)

extern FONT *fonts[];

struct Destination{
       int x, y;
       int w, h;
       bool visible;
};

struct Label{
       int x, y;
       int mx, my;
       int w, h;
       char name[30];
       bool clicked;
       bool visible;
};

void drawLabels(Label cellLabels[], Destination boxes[]);
void moveLabels(Label cellLabels[], Destination boxes[]);
bool checkLabels(Label cellLabels[], Destination boxes[]);

#endif
