
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Identifiant de texture
//
int IdTex; 

// Decalage pour l'animation de la 
// texture
//
int decalage=0; 

// Position de l'oeil
float ex=0;
float ey=0;
float ez=3;



void init()
{
  glClearColor(0,0,1,0);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
}



void construit_texture()
{
  unsigned char pixel[256][256][3];
  int i,j;
  int a;
  
  /* Initialisation des pixels */
  for (i=0;i<256;i++)
    for (j=0;j<256;j++) {
      
      if (j==decalage) 
		{
		pixel[i][j][0]=255;
		pixel[i][j][1]=255;
		pixel[i][j][2]=0;
		}
      else 	{
		pixel[i][j][0]=255;
      		pixel[i][j][1]=100;
      		pixel[i][j][2]=100;
		}
    }
  
  /* Paramètrage de la texture */
  glBindTexture(GL_TEXTURE_2D,IdTex);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,256,256,0,
	       GL_RGB,GL_UNSIGNED_BYTE,pixel);
}


void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(ex,ey,ez, 0.0,0.0,0.0, 0.0,1.0,0.0);

  glBindTexture(GL_TEXTURE_2D,IdTex);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0,1.0);   glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0,0.0);   glVertex3f(-0.5,-0.5, 0.5);
    glTexCoord2f(1.0,0.0);   glVertex3f( 0.5,-0.5, 0.5);
    glTexCoord2f(1.0,1.0);   glVertex3f( 0.5, 0.5, 0.5);
  glEnd();

  
  glutSwapBuffers();
}





void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'x':
         ex=ex+0.05;
         break;
      case 'X':
         ex=ex-0.05;
         break;
      case 'y':
         ey=ey+0.05;
         break;
      case 'Y':
         ey=ey-0.05;
         break;
      case 'z':
         ez=ez+0.05;
         break;
      case 'Z':
         ez=ez-0.05;
         break;
      case 27:
         exit(0);
         break;
   }
   glutPostRedisplay();
}




void my_timer(int v)
{
  decalage+=1;
  if (decalage>255)
    decalage=0;

  construit_texture();

  glutTimerFunc(0.1, my_timer, 0.1);

  glutPostRedisplay();
  
}


int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(400,400);
  glutCreateWindow(argv[0]);

  glGenTextures(1,&IdTex);

  init();

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutTimerFunc(1, my_timer, 1);

  glutMainLoop();
  return 0;
}



