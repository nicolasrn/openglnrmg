
/* Illustration de l'utilisation  */
/* d'une tache de fond avec GLUt  */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float anglex = 0.0F ;
float angley = 0.0F ;
float anglez = 0.0F ;

void idle(void) 
{
  anglex += 1.0F ;
  angley += 1.0F ;
  anglez += 1.0F ;
  glutPostRedisplay() ; 
  /* ordre de rafraichissement de la fenetre active */
}

void myInit() {
     
     /* gestion de la lumière */
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  GLfloat l_pos[] = { 0.0,-0.5,-1.0,0.0 };
  glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
}

void display(void) {
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
  /* cretion de la matrice de transformation */
  glPushMatrix() ;
  glRotatef(anglex,1.0F,0.0F,0.0F) ;
  glRotatef(angley,0.0F,1.0F,0.0F) ;
  glRotatef(anglez,0.0F,0.0F,1.0F) ;
  
  /* definition du cube rouge */
  glTranslatef(0.5F,0.0F,0.0F) ;
  GLfloat rouge[] = { 1.0,0.0,0.0,0.8 };
  glMaterialfv(GL_FRONT,GL_DIFFUSE,rouge);
  glutSolidCube(0.6) ;
  /* definition de la sphere verte */
  glTranslatef(-1.0F,0.0F,0.0F) ;
  GLfloat vert[] = { 0.0,1.0,0.0,0.8 };
  glMaterialfv(GL_FRONT,GL_DIFFUSE,vert);
  glutSolidSphere(0.4,50,50) ;
  
  /*fermeture de la matrice de transformation */
  glPopMatrix() ;
  /* envoi de la scene dans le buffer */
  glFlush() ;
  
  /* echange des buffers */
  glutSwapBuffers() ;
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(200,200);
  glutInitWindowPosition(100,100);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutCreateWindow("Animation automatique") ;
  myInit() ;
  glutIdleFunc(idle) ;
  glutDisplayFunc(display) ;
  glutMainLoop() ;
  return(0);
}

