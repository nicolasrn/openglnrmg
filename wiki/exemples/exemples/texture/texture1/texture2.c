
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "loadppm.h"

char texFileName[] = "snoopy2.ppm";
PPMImage *image;

GLfloat minX=0.0,maxX=2.0;

void myinit(void)
{    
     /* construction du tableau de texture */
    image = new PPMImage(texFileName);

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    /* fonction de création de la texture */
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image->sizeX, image->sizeY,
		  GL_RGB, GL_UNSIGNED_BYTE, image->data);
	/* suppression de l'image de référence */	  
    delete image;
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    /* autorosation de l'utilisation des textures */
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}

void display(void)
{
     /* asoociation image sommet objet */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);

    glTexCoord2f(minX, 0.0); glVertex3f(-2.0, -1.0, 0.0);
    glTexCoord2f(minX, 1.0); glVertex3f(-2.0, 1.0, 0.0);
    glTexCoord2f(maxX, 1.0); glVertex3f(2.0, 1.0, 0.0);
    glTexCoord2f(maxX, 0.0); glVertex3f(2.0, -1.0, 0.0);

    glEnd();
    glutSwapBuffers();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

static void Key(unsigned char key, int x, int y)
{

    switch (key) {
      case 27:
	exit(1);

    case 'a':
      minX += 0.1;
      if (minX>maxX)minX=maxX;
      break;

    case 'A':
      minX -= 0.1;
      if (minX<0)minX=0;
      break;

    case 'z':
      maxX += 0.1;
      if (maxX>1.0)maxX=1.0;
      break;

    case 'Z':
      maxX -= 0.1;
      if (maxX<minX)maxX=minX;
      break;
    case 'r':
      minX=0.0;
      maxX=1.0;
      break;

    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("texture1");
    myinit();
    glutReshapeFunc (myReshape);
    glutKeyboardFunc(Key);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
