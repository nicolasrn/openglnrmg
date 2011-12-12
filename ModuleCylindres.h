
/* Module de dessin des cylindres         */

#ifndef MODULECYLINDRE
#define MODULECYLINDRE

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define X 1
#define Y 2
#define Z 3

void wireCylindre(float r,float h,int n,int m);
void solidCylindre(float r,float h,int n,int m, bool texture = false);
void wireCylindre(float r,float h,int n,int m,int axe);
void solidCylindre(float r,float h,int n,int m,int axe);

#endif
