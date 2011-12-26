#ifndef __mon_module_souris__
#define __mon_module_souris__

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define debug_souris 0

//depend de la souris
extern int sourisanglex;
extern int sourisangley;

void mouse(int button, int state,int x,int y);

void mousemotion(int x,int y);

void doActionSouris();


#endif
