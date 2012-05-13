
/* Illustration de l'utilisation     */
/* de la fonction reshape avec GLUt  */

#include <GL/gl.h>
#include <GL/glu.h>

#include <GL/glut.h>

/* permet de redimensionner 
l'affichage en fonction de la taille de la fenetre */
void reshape(int w,int l) {
  glViewport(0,0,w,l);
  /* On veut changer la matrice de projection */
  glMatrixMode(GL_PROJECTION);
  /* chargement de la matrice identité */
  glLoadIdentity();
  /* On modifie les valeurs de projection */
  if ( w > l )
    glOrtho((float) -w/l,(float) w/l,-1.0,1.0,-1.0,1.0);
    else
    glOrtho(-1.0,1.0,(float) -l/w,(float) l/w,-1.0,1.0);
    /* On applique la modification de matrice */
  glMatrixMode(GL_MODELVIEW);
  /*On revient sur la matrice initiale */
  glLoadIdentity();
}

/* affichage du carre blanc */
void display(void) {
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
  glClear(GL_COLOR_BUFFER_BIT) ;
  glColor3f(1.0F,1.0F,1.0F) ;
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
  glutInitWindowSize(200,200);
  glutInitWindowPosition(100,100);
  glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
  glutCreateWindow("Carre blanc homothetique") ;
  glutReshapeFunc(reshape) ;
  glutDisplayFunc(display) ;
  glutMainLoop() ;
  return(0);
}

