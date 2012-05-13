
/* Illustration de l'utilisation  */
/* du double-buffer avec GLUt     */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"

static GLfloat view_rotx = 20.0 ;
static GLfloat view_roty = 30.0 ;
static GLfloat view_rotz = 0.0 ;
static int f1;
static int f2;

void display() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  manipulateurSouris();
  manipulateurClavier();
  glRotatef(view_rotx,1.0F,0.0F,0.0F);
  glRotatef(view_roty,0.0F,1.0F,0.0F);
  glRotatef(view_rotz,0.0F,0.0F,1.0F);
  glutSolidTorus(0.7,1.4,1000,1000) ;
  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w,int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.,(float)w/(float)h,1.0,20.0); 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0F,0.0F,-5.0F) ;
  setManipulateurDistance(5.0F);
}

void key2(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'z'    : view_rotz += 2.0;
                  break;
    case 'Z'    : view_rotz -= 2.0;
                  break ; }
}

void special2(int k,int x,int y) {
  switch (k) {
    case GLUT_KEY_UP    : view_rotx += 2.0;
                          break;
    case GLUT_KEY_DOWN  : view_rotx -= 2.0;
                          break;
    case GLUT_KEY_LEFT  : view_roty += 2.0;
                          break;
    case GLUT_KEY_RIGHT : view_roty -= 2.0;
                          break; }
  glutPostRedisplay();
}

void myinit(void) {
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  setManipulateurClavierAngle(20.0F,30.0F,0.0F);
}

void idle(void) {

  glutPostWindowRedisplay(f1);
  glutPostWindowRedisplay(f2);
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(250,200);
  glutInitWindowPosition(50,50);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f1 = glutCreateWindow("Avec double buffer");
  myinit();
  creationMenuBasique();
  glutIdleFunc(idle);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(specialBasique);
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutInitWindowSize(250,200);
  glutInitWindowPosition(350,150);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_SINGLE);
  f2 = glutCreateWindow("Sans double buffer");
  myinit();
  creationMenuBasique();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key2);
  glutSpecialFunc(special2);
  glutMainLoop();
  return(0);
}
