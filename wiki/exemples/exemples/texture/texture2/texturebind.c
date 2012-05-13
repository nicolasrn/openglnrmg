
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "loadppm.h"

char texFileName1[] = "tex1.ppm";
char texFileName2[] = "tex2.ppm";
PPMImage *image1,*image2;
GLuint texName[2];
GLfloat alpha=0.0;

void myinit(void)
{    
    image1 = new PPMImage(texFileName1);
    image2 = new PPMImage(texFileName2);

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glGenTextures(2, texName);
    
    
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    /*    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY,
		 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    */
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->sizeX, image1->sizeY,
		  GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glBindTexture(GL_TEXTURE_2D, texName[1]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    /*    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY,
	  0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
    */
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image2->sizeX, image2->sizeY,
		  GL_RGB, GL_UNSIGNED_BYTE, image2->data); 
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

    delete image2;
    delete image1;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glRotatef(alpha,0.0,1.0,0.0);
    
   glBindTexture(GL_TEXTURE_2D, texName[0]);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
   glTexCoord2f(0.0, 3.0); glVertex3f(-2.0, 1.0, 0.0);
   glTexCoord2f(3.0, 3.0); glVertex3f(0.0, 1.0, 0.0);
   glTexCoord2f(3.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
   glEnd();
   glBindTexture(GL_TEXTURE_2D, texName[1]);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
   glTexCoord2f(0.0, 3.0); glVertex3f(1.0, 1.0, 0.0);
   glTexCoord2f(3.0, 3.0); glVertex3f(2.41421, 1.0, -1.41421);
   glTexCoord2f(3.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
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
      alpha+=5.0;
      break;

    case 'A':
      alpha-=5.0;
     break;
     
    case 'r':
      alpha=0.0;
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
