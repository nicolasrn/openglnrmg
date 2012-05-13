/* Illustration de l'utilisation  */
/* du multi-fenetrage avec GLUt   */



#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>

#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"

static GLfloat view_rotx1 = 20.0F ;
static GLfloat view_roty1 = 30.0F ;
static GLfloat view_rotz1 = 0.0F ;
static GLfloat view_rotx2 = 20.0F ;
static GLfloat view_roty2 = 30.0F ;
static GLfloat view_rotz2 = 0.0F ;
static int f1;
static int f2;
void redraw1() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(view_rotx1,1.0,0.0,0.0);
  glRotatef(view_roty1,0.0,1.0,0.0);
  glRotatef(view_rotz1,0.0,0.0,1.0);
  glutSolidTorus(0.7,1.4,20,20) ;
  glPopMatrix();
  glutSwapBuffers();
}

void redraw2() {
  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(view_rotx2,1.0,0.0,0.0);
  glRotatef(view_roty2,0.0,1.0,0.0);
  glRotatef(view_rotz2,0.0,0.0,1.0);
  glutWireTorus(0.7,1.4,20,20) ;
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
}

void key1(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'z'    : view_rotz1 += 2.0;
                  break;
    case 'Z'    : view_rotz1 -= 2.0;
                  break;
    case '\033' : exit(0);
                  break ; }
}

void key2(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'z'    : view_rotz2 += 2.0;
                  break;
    case 'Z'    : view_rotz2 -= 2.0;
                  break ; }
}

static void special1(int k,int x,int y) {
  switch (k) {
    case GLUT_KEY_UP    : view_rotx1 += 2.0;
                          break;
    case GLUT_KEY_DOWN  : view_rotx1 -= 2.0;
                          break;
    case GLUT_KEY_LEFT  : view_roty1 += 2.0;
                          break;
    case GLUT_KEY_RIGHT : view_roty1 -= 2.0;
                          break; }
  glutPostWindowRedisplay(f1);
  glutPostWindowRedisplay(f2);
}

static void special2(int k,int x,int y) {
  switch (k) {
    case GLUT_KEY_UP    : view_rotx2 += 2.0;
                          break;
    case GLUT_KEY_DOWN  : view_rotx2 -= 2.0;
                          break;
    case GLUT_KEY_LEFT  : view_roty2 += 2.0;
                          break;
    case GLUT_KEY_RIGHT : view_roty2 -= 2.0;
                          break; }
  glutPostWindowRedisplay(f2);
  glutPostWindowRedisplay(f1);
}

void idle(void) {

  glutPostWindowRedisplay(f1);
  glutPostWindowRedisplay(f2);
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  
  
  
  glutInitWindowPosition(50,50);
  glutInitWindowSize(250,200);
  
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  f1 = glutCreateWindow("Fenêtres avec GLUt");
  glutIdleFunc(idle);
  glutDisplayFunc(redraw1);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key1);
  glutSpecialFunc(special1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  
  glutInitWindowPosition(250,100);
  f2 = glutCreateWindow("Fenêtre fille");
  glutDisplayFunc(redraw2);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key2);
  glutSpecialFunc(special2);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  
  glutMainLoop();
  return(0);
}
