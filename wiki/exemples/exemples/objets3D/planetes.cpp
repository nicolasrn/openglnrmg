/*                     Exemple de rotation + revolution de soleil/planetes/lunes  

Attention : vis-a-vis de l'enonce, les dimmensions ne sont pas ici respectees 
	    les angles de rotation sont par contre approximes

*/


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ex=0;
float ey=0;
float ez=23;
float pas_camera=1;
float vitesse=1;

float angle_revolution_terre=0;
float angle_rotation_terre=0;
float angle_revolution_lune=0;
float angle_rotation_mars=0;
float angle_revolution_mars=0;


#ifndef PI
#define PI    3.14159265358979323846
#endif



#define X .525731112119133606
#define Z .850650808352039932

GLfloat sommets[12][3] =
{
  {-X, 0, Z},
  {X, 0, Z},
  {-X, 0, -Z},
  {X, 0, -Z},
  {0, Z, X},
  {0, Z, -X},
  {0, -Z, X},
  {0, -Z, -X},
  {Z, X, 0},
  {-Z, X, 0},
  {Z, -X, 0},
  {-Z, -X, 0}
};

int index[20][3] =
{
  {0, 4, 1},
  {0, 9, 4},
  {9, 5, 4},
  {4, 5, 8},
  {4, 8, 1},
  {8, 10, 1},
  {8, 3, 10},
  {5, 3, 8},
  {5, 2, 3},
  {2, 7, 3},
  {7, 10, 3},
  {7, 6, 10},
  {7, 11, 6},
  {11, 0, 6},
  {0, 1, 6},
  {6, 1, 10},
  {9, 0, 11},
  {9, 11, 2},
  {9, 2, 5},
  {7, 2, 11},
};




void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable (GL_DEPTH_TEST);
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();
   gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void pousser_profondeur(float v[3])
{
	float d=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	v[0]=v[0]/d;
	v[1]=v[1]/d;
	v[2]=v[2]/d;
} 

void draw_triangle(float* v1, float *v2, float *v3, int n, float r, float g, float b)
{
  int xyz;
  float v[3][3];

  if(n==0)
	{
	glBegin(GL_TRIANGLES);
   		glColor3f(r,g,b);
		glVertex3f(v1[0], v1[1], v1[2]);
   		glColor3f(1,1,1);
		glVertex3f(v2[0], v2[1], v2[2]);
   		glColor3f(r,g,b);
		glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();
	}
   else	{
	for(xyz=0; xyz<3; xyz++)
		{
		v[0][xyz]=(v1[xyz]+v2[xyz])/2;	
		v[1][xyz]=(v1[xyz]+v3[xyz])/2;	
		v[2][xyz]=(v3[xyz]+v2[xyz])/2;	
		}	 

        pousser_profondeur(v[0]);
        pousser_profondeur(v[1]);
        pousser_profondeur(v[2]);


	draw_triangle(v1, v[0], v[1], n-1, r,g,b);
	draw_triangle(v[0], v2, v[2], n-1, r,g,b);
	draw_triangle(v[0], v[1], v[2], n-1, r,g,b);
	draw_triangle(v[1], v[2], v3, n-1, r,g,b);
	}
}


void draw_sphere(float size, float r, float g, float b) 
{
   int i;

   glPushMatrix();

   glScalef(size,size,size);

   for (i = 0; i <20; i++) {
    draw_triangle(sommets[index[i][2]], sommets[index[i][1]], sommets[index[i][0]], 2,r,g,b);
   }

   glPopMatrix();

}


void display(void)
{
  glLoadIdentity ();
  gluLookAt (ex, ey, ez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glClear (GL_COLOR_BUFFER_BIT);
  glClear (GL_DEPTH_BUFFER_BIT);


  
  // Soleil
  draw_sphere(6.9 ,1,1,0);



  // Terre
  glPushMatrix();
  glRotatef(angle_revolution_terre,0,1,0);
  glTranslatef(-12,0,0);
  glPushMatrix();
  glRotatef(angle_rotation_terre, sin(PI/8), cos(PI/8), 0);
  draw_sphere(0.63,0,0,1);

  // lune
  glPopMatrix();
  glRotatef(angle_revolution_lune,0, 1, 0);
  glTranslatef(-1,0,0);
  draw_sphere(0.1,0.5,0.5,0.5);
  glPopMatrix();
  

  

  // Mars
  glPushMatrix();
  glRotatef(angle_revolution_mars,0,1,0);
  glTranslatef(-8,0,0);
  glRotatef(angle_rotation_mars, sin(PI/8), cos(PI/8), 0);
  draw_sphere(0.63,1,0,0);
  glPopMatrix();



  glutSwapBuffers();
}


void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90, 1, 1, 2000);
   glMatrixMode (GL_MODELVIEW);
}



void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'x':
         ex=ex+pas_camera;
         break;
      case 'X':
         ex=ex-pas_camera;
         break;
      case 'y':
         ey=ey+pas_camera;
         break;
      case 'Y':
         ey=ey-pas_camera;
         break;
      case 'z':
         ez=ez+pas_camera;
         break;
      case 'Z':
         ez=ez-pas_camera;
         break;
      case 'V':
         vitesse++;
         break;
      case 'v':
         vitesse--;
         break;
      case 27:
         exit(0);
         break;
   }
   glutPostRedisplay();
}



void mon_timer(int val)
{
   angle_revolution_terre=angle_revolution_terre+(vitesse*0.1);
   if (angle_revolution_terre==360)
        angle_revolution_terre=0;

   angle_rotation_terre=angle_rotation_terre+(vitesse*1);
   if (angle_rotation_terre==360)
        angle_rotation_terre=0;

   angle_revolution_lune=angle_revolution_lune+(vitesse*10);
   if (angle_revolution_lune==360)
        angle_revolution_lune=0;

   angle_revolution_mars=angle_revolution_mars+(vitesse*0.4);
   if (angle_revolution_mars==360)
        angle_revolution_mars=0;


   glutTimerFunc(1,mon_timer,1);
   glutPostRedisplay();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutTimerFunc(1, mon_timer, 1);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   return 0;
}



