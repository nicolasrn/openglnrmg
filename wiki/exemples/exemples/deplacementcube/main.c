
/********************************************************/
/*                     transf.c                         */
/********************************************************/
/* Exemple de composition de transformations            */
/********************************************************/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int a=0,b=0;
int inca=0,incb=0;

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void idle();

int main(int argc,char **argv)
{
  /* initialisation de glut et creation
     de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(500,500);
  glutCreateWindow("transf");

  /* Initialisation d'OpenGL */
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glShadeModel(GL_FLAT);

  /* enregistrement des fonctions de rappel */
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);

  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}

void affichage()
{

  glClear(GL_COLOR_BUFFER_BIT);
  
  glLoadIdentity();
  glRotatef(b/10,0.0,0.0,1.0);
  glTranslatef(0.5,0.0,0.0);
  glRotatef(a/10,0.0,0.0,1.0);

  glBegin(GL_POLYGON);
  glVertex3f(-0.2,-0.2, 0.0);
  glVertex3f( 0.2,-0.2, 0.0);
  glVertex3f( 0.2, 0.2, 0.0);
  glVertex3f(-0.2, 0.2, 0.0);
  glEnd();
  glFlush();
  
  glutSwapBuffers();
}

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'a':
      inca++;
      if (inca>10)
	inca=2;
      glutPostRedisplay();
      break;
    case 'A':
      inca--;
      if (inca<-10)
	inca=-2;
      glutPostRedisplay();
      break;
    case 'b':
      incb++;
      if (incb>10)
	incb=2;
      glutPostRedisplay();
      break;
    case 'B':
      incb--;
      if (incb<-10)
	incb=-2;
      glutPostRedisplay();
      break;
    case 'q' :
      exit(0);
    }
}

void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else 
    glViewport((x-y)/2,0,y,y);
}

void idle()
{
  a+=inca;
  if (a>360)
    a-=360;
  b+=incb;
  if (b>360)
    b-=360;
  glutPostRedisplay();
}
