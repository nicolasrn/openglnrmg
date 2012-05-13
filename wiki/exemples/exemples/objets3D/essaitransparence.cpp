/* Gestion des transparences en OpenGL  */

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdio.h>
#include <math.h>

#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

void myinit(void) {
  GLfloat light_position0[] = { 1.0F,1.0F,1.0F,0.0F };
  glLightfv(GL_LIGHT0,GL_AMBIENT,couleurNoir());
  glLightfv(GL_LIGHT0,GL_DIFFUSE,couleurBlanc());
  glLightfv(GL_LIGHT0,GL_SPECULAR,couleurNoir());
  glLightfv(GL_LIGHT0,GL_POSITION,light_position0);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
}

void display1(void) {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
      glPushMatrix();
          glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,couleurRouge(0.5F)) ;
          glScalef(17.0F,5.0F,10.0F) ;
          glutSolidCube(1.0) ;
      glPopMatrix();
  glPopMatrix();
}

void display2(void) {
  glPushMatrix();
      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,couleurBlanc(0.5F)) ;
      glPushMatrix();
          glScalef(9.0F,9.0F,18.0F) ;
          glutSolidCube(1.0) ;
      glPopMatrix();
  glPopMatrix();
}

void display(void) {
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix() ;
      display1() ;
      display2() ;
  glPopMatrix() ;
  glFlush();
  glutSwapBuffers() ;
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(300,300); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Transparences"); 
  myinit(); 
  creationMenuBasique();
  setParametresOrthoBasique(-11.0,11.0,-11.0,11.0,-500.0,500.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}
