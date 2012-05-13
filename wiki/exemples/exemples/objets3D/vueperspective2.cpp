#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"



void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurBlanc());
  glLoadIdentity();                /*(1)*/
  glTranslatef(0.0,0.0,-3.0);      /*(1)*/
  manipulateurSouris();            /*(1)*/
  manipulateurClavier();           /*(1)*/
  glScalef(1.0,5.0,3.0);           /*(2)*/
  glutWireCube(0.2);               /*(2)*/
  glFlush();
  glutSwapBuffers();
}

void myinit(void) {
  glShadeModel(GL_FLAT);
  setManipulateurDistance(1.0F);
}

void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);     /*(3)*/
  glLoadIdentity();                /*(3)*/
  glFrustum(-1.,1.,-1.,1.,1.5,20.);/*(3)*/
  glMatrixMode(GL_MODELVIEW);      /*(2)*/
  glViewport(0,0,w,h);             /*(4)*/
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(200,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Visualisation"); 
  myinit(); 
  creationMenuBasique();
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}


