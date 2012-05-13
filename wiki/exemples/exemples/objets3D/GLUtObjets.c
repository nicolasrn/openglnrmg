
/* Illustration de l'utilisation  */
/* des objets GLUt                */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "../modulesutilitaires/ModuleCylindres.h"

#include <stdlib.h>

static float anglex = 0.0F ;
static float angley = 0.0F ;
static int obj = 0 ;

  

void display(void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(angley,0.0F,1.0F,0.0F) ;
  glRotatef(anglex,1.0F,0.0F,0.0F) ;
  glColor3f(0.0F,0.0F,0.0F);

  
  switch ( obj ) {
    case 0 : glutWireSphere(7.0,20,20) ;
             break ;
    case 1 : glutWireCube(11.0) ;
             break ;
    case 2 : glutWireCone(6.0,9.0,20,20) ;
             break ;
    case 3 : glutWireTorus(2.0,6.0,20,20) ;
             break;
    case 4 : wireCylindre(2.0,8.0,20,10);
             break ;
    case 5 : glScalef(7.0F,7.0F,7.0F) ;
             glutWireTetrahedron() ;
             break ;
    case 6 : glScalef(7.0F,7.0F,7.0F) ;
             glutWireOctahedron() ;
             break ;
    case 7 : glScalef(5.0F,5.0F,5.0F) ;
             glutWireDodecahedron() ;
             break ;
    case 8 : glScalef(7.0F,7.0F,7.0F) ;
             glutWireIcosahedron() ;
             break ;
    case 9 : glutWireTeapot(7.0) ; }
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

void myInit (void) {
}

void myReshape(int w, int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0,10.0,-10.0*h/w,10.0*h/w,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void key(unsigned char key,int x,int y) {
  switch(key) {
    case 27  : exit(0); 
               break;
    case ' ' : obj = (obj+1)%9; 
               glutPostRedisplay();
               break; }
}

void special(int key,int x,int y) {
  switch(key) {
    case GLUT_KEY_UP    : anglex++; 
                          break;
    case GLUT_KEY_DOWN  : anglex--; 
                          break;
    case GLUT_KEY_LEFT  : angley++; 
                          break;
    case GLUT_KEY_RIGHT : angley--; 
                          break; }
  glutPostRedisplay() ;
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
  glutInitWindowSize(200,200);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Objets de GLUT") ;
  myInit() ;
  glutReshapeFunc(myReshape) ;
  glutKeyboardFunc(key) ;
  glutSpecialFunc(special) ;
  glutDisplayFunc(display) ;
  glutMainLoop() ;
  return(0);
}
