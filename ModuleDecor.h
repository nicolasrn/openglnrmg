#ifndef __DECOR__
#define __DECOR__

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "ModuleCouleurs.h"
#include "ModuleMonGlutSolidCube.h"
#include "MonModuleCamera.h"
#include "PetitTrain.h"

extern GLUquadric* param; 

void creerTerrain(GLuint *tabTexture);

void creerMur(int mx, int my, int taille, int tailleTexture);

void creerRail();

void creerSapin();

void creerMouton();

void creerMaison();
 
void creerTunnel();

void creerLampadaire();

void decoSapin();

void decoMouton();

#endif
