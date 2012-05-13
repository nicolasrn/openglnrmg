/* Un cube en projection orthographique  */
/* en en projection en perspective       */

/* Manipulation avec les fleches */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>


#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

static int f1;
static int f2;

/* contenu de la premi�re fen�tre */
void display1() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glutWireCube(5.0) ;
  glPopMatrix();
  glutSwapBuffers();
  glutPostWindowRedisplay(f1);
}

/* contenu de la seconde fen�tre */
void display2() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glutWireCube(5.0) ;
  glPopMatrix();
  glutSwapBuffers();
  glutPostWindowRedisplay(f2);
  
}

void myinit(void) {
  glEnable(GL_DEPTH_TEST);
  setManipulateurClavierAngle(20.0F,30.0F,0.0F);
}

int main(int argc,char **argv) {
    
  glutInit(&argc,argv);
  /* param�tres de la premi�re fen�tre */
  glutInitWindowSize(170,170);
  glutInitWindowPosition(50,50);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f1 = glutCreateWindow("Orthographique");
  myinit();
  creationMenuBasique();
  glutDisplayFunc(display1);
  /* projection orthogonale */
  setParametresOrthoBasique(-5.0,5.0,-5.0,5.0,-50.0,50.0);
  setManipulateurDistance(1.0F);
  glutReshapeFunc(reshapeOrthoBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  
  /* parametres de la seconde fen�tre */
  glutInitWindowSize(170,170);
  glutInitWindowPosition(500,50);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f2 = glutCreateWindow("Perspective");
  myinit();
  creationMenuBasique();
  glutDisplayFunc(display2);
  /* parametre de la projection perspective */
  setParametresPerspectiveBasique(65.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-8.5F);
  setManipulateurDistance(5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  
  /* fin de la creation des fenetres */
  glutMainLoop();
  return(0);
}