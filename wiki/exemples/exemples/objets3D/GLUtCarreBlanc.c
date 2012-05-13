
/* Un programme OpenGL tout simple  */


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display(void) {
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
  glClear(GL_COLOR_BUFFER_BIT) ;
  glColor3f(1.0F,1.0F,1.0F) ;
  glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0) ;
  glBegin(GL_POLYGON) ;
  glVertex2f(-0.5F,-0.5F) ;
  glVertex2f(-0.5F,0.5F) ;
  glVertex2f(0.5F,0.5F) ;
  glVertex2f(0.5F,-0.5F) ;
  glEnd() ;
  glFlush() ;
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  glutInitWindowSize(200,200); 
  glutInitWindowPosition(50,10); 
  glutCreateWindow("Carré blanc");
  glutDisplayFunc(display);
  glutMainLoop();
  return(0);
}
