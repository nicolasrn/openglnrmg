
/* Illustration de l'utilisation  */
/* des objets GLUt                */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdlib.h>

static float anglex = 0.0F ;
static float angley = 0.0F ;
static int obj = 0 ;

  

void display(void) {
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  glShadeModel(GL_SMOOTH);
  glPushMatrix();
//  glRotatef(angley,0.0F,1.0F,0.0F) ;
//  glRotatef(anglex,1.0F,0.0F,0.0F) ;
  glColor3f(1.0F,0.0F,0.0F);
  glutSolidTeapot(7.0) ;
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

void myinit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST) ;
  glEnable(GL_LIGHTING) ;
  glEnable(GL_LIGHT0) ;
  glEnable(GL_AUTO_NORMAL) ;
  glEnable(GL_NORMALIZE) ;
  float dir[] = { 0.0F,0.0F,-1.0F,0.0F } ;
  glLightfv(GL_LIGHT0,GL_POSITION,dir) ;
}

void myReshape(int w, int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0,10.0,-10.0*h/w,10.0*h/w,-10.0,20.0);
  gluLookAt(0,0,-5,0,0,0,0,1,0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void key(unsigned char key,int x,int y) {
  switch(key) {
    case 27  : exit(0); 
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
  myinit() ;
  glutReshapeFunc(myReshape) ;
  glutKeyboardFunc(key) ;
  glutSpecialFunc(special) ;
  glutDisplayFunc(display) ;
  glutMainLoop() ;
  return(0);
}
