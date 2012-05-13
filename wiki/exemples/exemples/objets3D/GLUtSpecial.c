
/* Illustration de l'utilisation     */
/* des touches de curseur avec GLUt  */


#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

float anglex = 0.0F ;
float angley = 0.0F ;

/*gestion ndes touches clavier */
/* modification de l'orientation en fonction des touches */
/* de direction */
void special(int key,int x,int y) {
  switch(key) {
    case GLUT_KEY_UP    : anglex++;
                          glutPostRedisplay() ;
                          break;
    case GLUT_KEY_DOWN  : anglex--;
                          glutPostRedisplay() ;
                          break;
    case GLUT_KEY_LEFT  : angley++;
                          glutPostRedisplay() ;
                          break;
    case GLUT_KEY_RIGHT : angley--;
                          glutPostRedisplay() ;
                          break; }
}

/* definition d'une source lumineuse */
void myInit() {
/* initialisation des sources lumineuses sous opengl */
  glEnable(GL_LIGHTING);
  /* création de la source 0 */
  glEnable(GL_LIGHT0);
  /* création variable de position */
  GLfloat l_pos[] = { 0.0,-0.5,-4.0,0.0 };
  /* affectation des parametres à la source */
  glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
  /* mode d'utilisation de la source */
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
}

/* définition d'un cube */
void display(void) {
  glClearColor(0.0F,0.0F,0.0F,0.0F) ;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
  
  /* definition du cube fixe*/
  glPushMatrix() ;
  /* deplacement sur les Z + */
  glTranslatef(0.0F,0.0F,1.0F) ;
  /* création de la couleur */
  GLfloat blanc[] = { 1.0,1.0,1.0,0.0 };
  /* définition d'un matériaux */
  glMaterialfv(GL_FRONT,GL_DIFFUSE,blanc);
  /* definition du modèle cube */
  glutSolidCube(0.6) ;
  /* application de la matrice du cube blanc */
  glPopMatrix() ;
  
  /* definition des cubes mobiles */
  glPushMatrix() ;
  /* compsée de deux rotaion suivant les vecteurs */
  glRotatef(anglex,1.0F,0.0F,0.0F) ;
  glRotatef(angley,0.0F,1.0F,0.0F) ;
  /* déplacement suivant l'axe des X */
  glTranslatef(0.5F,0.0F,0.0F) ;
  GLfloat rouge[] = { 1.0,0.0,0.0,0.0 };
  glMaterialfv(GL_FRONT,GL_DIFFUSE,rouge);
  glutSolidCube(0.6) ;
  
  /* déplacement pour le troisième cube */
  glTranslatef(-1.0F,0.0F,0.0F) ;
  GLfloat vert[] = { 0.0,1.0,0.0,0.0 };
  glMaterialfv(GL_FRONT,GL_DIFFUSE,vert);
  glutSolidCube(0.6) ;
  /* prise en compte de la matrice crée */
  glPopMatrix() ;
  
  /* modification de l'affichage */
  /*envoi des données au buffer d'affichage */
  glFlush() ;
  /* inversion des deux buffers */
  glutSwapBuffers() ;
}

/* définition de la creation principale */
int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(200,200);
  glutInitWindowPosition(100,100);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutCreateWindow("Animation au clavier") ;
  /* gestion d'une source lumineuse */
  myInit() ;
  /* gestion des interactions clavier */
  glutSpecialFunc(special) ;
  /* gestion du modèle */
  glutDisplayFunc(display) ;
  glutMainLoop() ;
  return(0);
}

