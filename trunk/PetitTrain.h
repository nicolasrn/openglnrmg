#ifndef __PETIT_TRAIN__
#define __PETIT_TRAIN__

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static void remiseZero()
{
     GLfloat cAmbient[] = {0,0,0,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {1,1,1,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0,0,0,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 51.2;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}

#endif
