

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
  glLoadIdentity();                
  glTranslatef(0.0,0.0,-5.0);      
  manipulateurSouris();            
  manipulateurClavier();         
  glScalef(1.0,2.0,3.0);           
  glutWireCube(1.0);              
  glFlush();
  glutSwapBuffers();
}

void myinit(void) {
  glShadeModel(GL_FLAT);
  setManipulateurDistance(1.0F);
}

void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);     
  glLoadIdentity();                
  glFrustum(-1.,1.,-1.,1.,1.5,20.);
  glMatrixMode(GL_MODELVIEW);      
  glViewport(0,0,w,h);             
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


