#include <stdio.h>
#include <stdlib.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glaux.h> 



static float anglex = 0.0F ;
static float angley = 0.0F ;
static int obj = 0 ;

void CALLBACK display(void) {
  glClearColor (1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0F,0.0F,0.0F);
  glPushMatrix();
  glRotatef(angley,0.0F,1.0F,0.0F) ;
  glRotatef(anglex,1.0F,0.0F,0.0F) ;
  switch ( obj ) {
    case 0  : auxWireSphere(7.0) ;
              break ;
    case 1  : auxWireCube(11.0) ;
              break ;
    case 2  : auxWireCone(6.0,9.0) ;
              break ;
    case 3  : auxWireCylinder(3.0,9.0) ;
              break ;
    case 4  : auxWireBox(4.0,7.0,12.0) ;
              break ;
    case 5  : auxWireTorus(2.0,6.0) ;
              break ;
    case 6  : auxWireTetrahedron(9.0) ;
              break ;
    case 7  : auxWireOctahedron(9.0) ;
              break ;
    case 8  : auxWireDodecahedron(9.0) ;
              break ;
    case 9  : auxWireIcosahedron(9.0) ;
              break ;
    case 10 : auxWireTeapot(7.0) ; }
  glPopMatrix();
  glFlush();
  auxSwapBuffers();
}

void myinit (void) {
}

void CALLBACK myReshape(int w,int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0,10.0,-10.0*h/w,10.0*h/w,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void CALLBACK up(void) {
  anglex++ ;
}

void CALLBACK down(void) {
  anglex-- ;
}

void CALLBACK left(void) {
  angley++ ;
}

void CALLBACK right(void) {
  angley-- ;
}

void CALLBACK space(void) {
  obj++ ;
  if ( obj == 11 )
    obj = 0 ;
}

main() {
  auxInitDisplayMode (AUX_DOUBLE | AUX_RGBA);
  auxInitPosition (0, 0, 500, 500);
  auxInitWindow ("Objets");
  myinit ();
  auxKeyFunc(AUX_UP,up) ;
  auxKeyFunc(AUX_DOWN,down) ;
  auxKeyFunc(AUX_LEFT,left) ;
  auxKeyFunc(AUX_RIGHT,right) ;
  auxKeyFunc(AUX_SPACE,space) ;
  auxReshapeFunc (myReshape);
  auxMainLoop(display);
}
