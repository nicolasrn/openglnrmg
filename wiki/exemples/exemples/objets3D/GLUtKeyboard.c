
/* Illustration de l'utilisation  */
/* du clavier avec GLUt           */


#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

/* la touche espace modifie la valeur de la variable c */
static int c = 0 ;

/* touche echap pour sortir du programme */
void key(unsigned char key,int x,int y) {
  switch(key) {
    /* echappe pour sortir */
    case 27  : exit(0); 
               break;
    /* espace pour chager la couleur */
    case ' ' : c = (c+1)%7; 
               /* on demande a reafficher l'image */
               glutPostRedisplay();
               break; }
}

/* en fonction de la valeur de c affichage d'une */
/* couleur différente à chaque action sur la touche espace */
void display(void) {
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
  glClear(GL_COLOR_BUFFER_BIT) ;
  glOrtho(-1.0,1.0,-1.0,1.0,
          -1.0,1.0);
  switch(c) {
    case 0 : glColor3f(1.0F,1.0F,1.0F) ;
             break ;
    case 1 : glColor3f(1.0F,1.0F,0.0F) ;
             break ;
    case 2 : glColor3f(1.0F,0.0F,1.0F) ;
             break ;
    case 3 : glColor3f(0.0F,1.0F,1.0F) ;
             break ;
    case 4 : glColor3f(0.0F,1.0F,0.0F) ;
             break ;
    case 5 : glColor3f(0.0F,0.0F,1.0F) ;
             break ;
    case 6 : glColor3f(1.0F,0.0F,0.0F) ;
             break ; }
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
  glutCreateWindow("Gestion du clavier") ;
  glutDisplayFunc(display) ;
  glutKeyboardFunc(key) ;
  glutMainLoop() ;
  return(0);
}

