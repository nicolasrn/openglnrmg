#ifndef __DECOR__
#define __DECOR__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "ModuleCouleurs.h"
#include "ModuleMonGlutSolidCube.h"

#define testTerrain 1

extern GLUquadric* param; 

void creerTerrain(GLuint *tabTexture);

void creerRail();

void creerSapin();

void creerMouton();

void creerMaison();
 
void creerTunnel();

void decoSapin();

void decoMouton();

#endif
