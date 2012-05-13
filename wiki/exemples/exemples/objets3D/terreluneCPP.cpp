/* Progammation d'un systeme Terre-Lune  */

/* les touches 2 4 6 et 8 pour les mouvements */
/* de la lune */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

static int year = 0;
static int day = 0; 

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case '2' : day = (day + 10) % 360;
                 glutPostRedisplay();
                 break;
      case '8' : day = (day - 10) % 360;
                 glutPostRedisplay();
                 break;
      case '4' : year = (year + 5) % 360;
                 glutPostRedisplay();
                 break;
      case '6' : year = (year - 5) % 360;
                 glutPostRedisplay();
                 break; }
}

void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurNoir());
  glPushMatrix(); 
  manipulateurSouris();
  manipulateurClavier();
  glutWireSphere(1.0,20,20); 
  glRotatef((GLfloat) year,0.0,1.0,0.0); 
  glTranslatef(2.0,0.0,0.0); 
  glRotatef((GLfloat) day,0.0,1.0,0.0); 
  glutWireSphere(0.2,15,15); 
  glPopMatrix(); 
  glFlush(); 
  glutSwapBuffers();
} 
  
void myinit(void) { 
  glClearColor(1.0,1.0,1.0,1.0);
} 
  
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
  glutInitWindowSize(300,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Système Terre-Lune"); 
  myinit(); 
  creationMenuBasique();
  setParametresPerspectiveBasique(36.0F,1.5F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  setManipulateurDistance(5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}


