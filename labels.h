#ifndef labels
#define labels

extern FONT *fonts[];

struct Color{
       int r, g, b;
};

struct Label{
       int x, y;
       int mx, my;
       int w, h;
       char name[30];
       bool clicked;
       Color c;
};

void drawLabels(Label boxes[]);
void moveLabels(Label boxes[]);

#endif
