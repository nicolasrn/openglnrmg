/* Illustration de l'utilisation  */
/* du reshape en OpenGL + GLUt    */

/* Espace pour activer/désactiver l'affichage homothétique */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"

static int proj = 0 ;
static int ww ;
static int hh ;

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if ( proj )
    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
    else
    glOrtho(-10.0,10.0,-10.0*(double) hh/ww,10.0*(double) hh/ww,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glutWireSphere(7.0,12,12) ;
  glPopMatrix();
  glFlush();
}

void myinit (void) {
  glClearColor(0.0,0.0,0.0,1.0);
}

void myReshape(int w,int h) {
  glViewport(0,0,w,h);
  ww = w ;
  hh = h ;
}

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
    // c'est la touche espace
      case 32     : proj = (proj+1)%2;
                    glutPostRedisplay();
                    break; }
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
  glutInitWindowSize(200,200); 
  glutInitWindowPosition(50,50); 
  glutCreateWindow("Reshape homothétique"); 
  myinit();
  creationMenuBasique();
  setManipulateurDistance(1.0F);
  glutReshapeFunc(myReshape);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}


