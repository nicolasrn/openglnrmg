
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define    ImageWidth 524
#define    ImageHeight 524
GLubyte MatrixImage[ImageHeight][ImageWidth][3];
float RGB [2];
static GLint height;

 int fonctionTexture(int x,int y)
 {
    float dx,dy;
    dx=(128.0-(float)x)/255.0*40.0;
    dy=(128.0-(float)y)/255.0*40.0;
    float a=cos(sqrt(dx*dx+dy*dy));
    return (int)((a+1.0)/2.0*255);
}
                  
void makeImage(void)
{
 
 int x,y;
 float color;
 int seed;
 int width;
 int i,j,a;
 float  scale;

for(y=0;y< ImageWidth; y++)
{
    for(x=0;x<ImageHeight; x++)
    {

      scale=1;
      width=12413;
      seed=63;

        a=fonctionTexture(x,y);  
        MatrixImage[x][y][0] = a;
        MatrixImage[x][y][1] = 128;
        MatrixImage[x][y][2] = 128;  

   }
}
}       

void init(void)
{   
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   makeImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glRasterPos2i(0, 0);
   glDrawPixels(ImageWidth, ImageHeight, GL_RGB,
                GL_UNSIGNED_BYTE, MatrixImage);
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   height = (GLint) h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
    
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(100, 100);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
