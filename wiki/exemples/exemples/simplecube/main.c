#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void display(void) 
{
/* definition d'une couleur noire pour le fond */
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
/* application de cette couleur au buffer */  
  glClear(GL_COLOR_BUFFER_BIT) ;
  
/* definition de la couleur de l'objet a afficher */
/* ici un,e couleur blanche */
  glColor3f(1.0F,1.0F,1.0F) ;

/* le systeme de visualisation de l'observateur est orthogonal */
  glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0) ;
/*definition du polygone defini par 4 sommets */  
  glBegin(GL_POLYGON) ;
  glVertex2f(-0.5F,-0.5F) ;
  glVertex2f(-0.5F,0.5F) ;
  glVertex2f(0.5F,0.5F) ;
  glVertex2f(0.5F,-0.5F) ;
  glEnd() ;
  
/* envoi des commandes au système */
  glFlush() ;
}

int main(int argc,char **argv) 
{
    int C = 10 ;
    C+=10;
    if(C>3)
    /* initialisation de la biblio glut */
  glutInit(&argc,argv);
  /* definition du mode d'affichage simple buffer et rgb */
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  /* definition de la taille de la fenetre */
  glutInitWindowSize(200,200); 
  /* definition de la position de la fenetre */
  glutInitWindowPosition(100,100); 
  /* creation et titre de la fenetre */
  glutCreateWindow("Carré blanc");
  
  /* appel à la fonction d'affichage */
  glutDisplayFunc(display);
  
  /* fonction d'execution generale */
  glutMainLoop();
  return(0);
}
