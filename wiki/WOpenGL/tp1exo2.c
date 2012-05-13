#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void maison()
	{
	glColor3f(1,0.93333,0.9254);
	glBegin(GL_QUADS);
		glVertex2i(60,30);
		glVertex2i(60,150);
		glVertex2i(180,150);
		glVertex2i(180,30);
	glEnd();
	
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_TRIANGLES);
		glVertex2i(50,150);
		glVertex2i(120,200);
		glVertex2i(190,150);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
		glVertex2i(100,30);
		glVertex2i(100,70);
		glVertex2i(140,70);
		glVertex2i(140,30);
	glEnd();
	}	

void Ecrire_chaine(char *s,int x,int y)
	{
	int longueur=strlen(s),i;
	glRasterPos2i(x,y);
	for(i=0;i<longueur;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
		
	}
	
void trait()
	{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex2i(30,20);
		glVertex2i(470,20);
	glEnd();
	}
	
void tronc()
	{
	glColor3f(1,0.5,0);
	glBegin(GL_POLYGON);
		glVertex2i(360,30);
		glVertex2i(370,100);
		glVertex2i(380,100);
		glVertex2i(390,30);
	glEnd();
	}	

void arbre()
	{
	glColor3f(0,1,0.4);
	glBegin(GL_POLYGON);
		glVertex2i(370,100);
		glVertex2i(310,120);
		glVertex2i(350,140);
		glVertex2i(400,140);
		glVertex2i(440,120);
		glVertex2i(380,100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(350,140);
		glVertex2i(260,190);
		glVertex2i(375,240);
		glVertex2i(490,190);
		glVertex2i(400,140);
	glEnd();
	}

void affichage(void)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	maison();
	trait();
	tronc();
	arbre();
	glColor3f(1,0,0);Ecrire_chaine("Une maison\0",80,220);
	glColor3f(0,0,1);Ecrire_chaine("Un arbre\0",350,260);
	glFlush();
	}

void redim(int l,int h)
	{
	glViewport(0,0,l,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,l,0,h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	}
	
	
int main(int argc,char **argv)
	{
	/* Initialisation */
	glutInit(&argc,argv);
	
	/* Initialisation des paramètres */
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	
	/* Création de la fenêtre */
	glutCreateWindow("Premier essai graphique");
	
	/* Association d'évènements */
	glutDisplayFunc(affichage);
	glutReshapeFunc(redim);
	
	/* Initialisation de OpenGL */
	glClearColor(1,1,1,1);
			
	
	glutMainLoop();

	return 0;
	}
