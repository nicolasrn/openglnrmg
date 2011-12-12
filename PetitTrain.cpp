#include <iostream>
#include <cstdlib>
#include <cmath> 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <windows.h> 
#include <Mmsystem.h>
#include <conio.h>

#include "ModuleCouleurs.h"
#include "ModuleManipulateur.h"
#include "ModuleReshape.h"
#include "ModuleCylindres.h"
#include "ModuleRoue.h"
#include "ModuleMenus.h"
#include "ModuleMonGlutSolidCube.h"

using namespace std;

static int angle = 90;
static int angleTrain = 0;
static float anglex = 0.0F ;
static float angley = 0.0F ;
static float anglez = 0.0F ;
static float up = 0.0F ;
static int az = 6 ;
static int a = 0 ;
static float PI = 3.14;//159265;
static float monCosinus[360];
static float monSinus[360];
static int angleCloche = 4;
static int tempcompt = 1;
GLUquadric* param = gluNewQuadric(); 

static int x=0, y=0, z=0;
static float dist = 4.5, hauteurCam = 4.5;
static float depCamX = 0.0, depCamY = 0.0, depCamZ = 0.0;

void monte()
{
	up = 0.03;
	glutPostRedisplay() ;
}

void descend()
{
	up = 0;
	glutPostRedisplay() ;
}

void trigo()
{
	for (int i = 0; i<=360; i++)
	{
		monCosinus[i] = cos(i*PI/180);
		monSinus[i] = sin(i* PI/180);
	}
}

void tournerRoue()
{
	if(az==0)
	{
		glTranslatef(0.53, -0.53, 0);
	}
	else
	{
		glTranslatef((0.53 * monCosinus[az]), 0.53*monSinus[az] -0.53, 0);
	}    
}

void remiseZero()
{
     GLfloat cAmbient[] = {0,0,0,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {1,1,1,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0,0,0,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 51.2;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}

void creerAvantLoco()
{
	//création de l'avant de la loco
	glPushMatrix();
	effetComplexChrome();
		glColor4fv(couleurCylindre);
		glTranslatef(-1, 0.2, 0);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.7,1.7,20,10);
		
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurAvant);
		glTranslatef(-1.85, 0.2, 0);
		glRotatef(-90, 0, 1, 0);
		gluCylinder(param,0.7,0,0.3,20,1);
	glPopMatrix();
	
	
	glPushMatrix();
		glColor4fv(couleurOptique);
		glTranslatef(-2, 0.2, 0);
		gluSphere(param,0.2,20,20);
	glPopMatrix();
	remiseZero();
	
	glPushMatrix();
		glColor4fv(couleurPhare);
		glTranslatef(-2.02, 0.2, 0);
		gluSphere(param,0.19,20,20);
	glPopMatrix();

}

void creerChemine()
{
	//création de la cheminée
	effetComplexArgent();
	glPushMatrix();
		glColor4fv(couleurChemine);
		glTranslatef(-1.6, 1.1, 0);
		solidCylindre(0.2,0.4,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurChemine);
		glTranslatef(-1.6, 1.1, 0);
		glRotatef(-90, 1, 0, 0);  
		gluCylinder(param,0.18,0.4,0.4,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurChemine);
		glTranslatef(-1.6, 1.5, 0);
		glRotatef(-90, 1, 0, 0);      
		gluCylinder(param,0.4,0.18,0.4,20,1);
	glPopMatrix();
	remiseZero();
}

void creerCloche()
{
	//création de la cloche
	effetComplexArgent();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		
		glTranslatef(2.1, 1.4, -1.05);//decalage du centre de rotation
		glRotatef(angleCloche, 1, 0, 0); //mouvement de va et vient de la cloche
		glTranslatef(-1.05, -1.4, 0);//remise en place du centre
		
		glPushMatrix();
			glColor4fv(couleurCloche1);
			glTranslatef(-1.05, 1, 0);
			glRotatef(-90, 1, 0, 0);     
			gluCylinder(param,0.2,0.1,0.3,20,1);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurCloche2);
			glTranslatef(-1.05, 1, 0);
			glRotatef(-90, 1, 0, 0);             
			gluCylinder(param,0.25,0.2,0.05,20,1);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurCloche2);
			glTranslatef(-1.05, 1.3, 0);
			gluSphere(param,0.1,20,20);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurCloche1);
			glTranslatef(-1.05, 1.4, 0);
			gluSphere(param,0.07,20,20);
		glPopMatrix();
	glPopMatrix();
	remiseZero();
}

void creerAccrocheCloche()
{
     effetComplexOr();
	//création de l'accroche cloche
	glPushMatrix();
		glColor4fv(couleurClocheAccroche);
		glTranslatef(-1.05, 1.12, 0.3);
		solidCylindre(0.025,0.6,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurClocheAccroche);
		glTranslatef(-1.05, 1.12, -0.3);
		solidCylindre(0.025,0.6,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurClocheAccroche);
		glTranslatef(-1.05, 1.4, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.025,0.58,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurClocheAccroche);
		glTranslatef(-1.05, 1.4, 0.3);
		gluSphere(param,0.04,20,20);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurClocheAccroche);
		glTranslatef(-1.05, 1.4, -0.3);
		gluSphere(param,0.04,20,20);
	glPopMatrix();
	remiseZero();
}

void creerInterieurCloche()
{
	//intérieur cloche
	effetComplexOr();
	glPushMatrix();
		glColor4fv(couleurClocheBaton);
		glTranslatef(-1.05, 1.12, 0);
		solidCylindre(0.025,0.3,20,10); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurClocheBaton);
		glTranslatef(-1.05, 1, 0);
		gluSphere(param,0.07,20,20);
	glPopMatrix();
	remiseZero();
}

void creerSoupape()
{
	//soupape
	glPushMatrix();
		glColor4fv(couleurSoupape1);
		glTranslatef(-0.52, 0.8, 0);
		glRotatef(-90, 1, 0, 0);         
		gluCylinder(param,0.3,0.2,0.15,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurSoupape2);
		glTranslatef(-0.52, 1, 0);
		solidCylindre(0.2,0.2,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0, up, 0);
		
		glPushMatrix();
			glColor4fv(couleurSoupape1);
			glTranslatef(-0.52, 1, 0);
			glRotatef(-90, 1, 0, 0);         
			gluCylinder(param,0.25,0.2,0.12,20,1);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurSoupape1);
			glTranslatef(-0.52, 1.12, 0);
			glRotatef(-90, 1, 0, 0);         
			gluCylinder(param,0.2,0.05,0.05,20,1);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurSoupape2);
			glTranslatef(-0.52, 1.15, 0);
			gluSphere(param,0.05,20,20);
		glPopMatrix();
	glPopMatrix();
}

void creerPhares()
{
	//phares
	//droit
	effetComplexArgent();
	glPushMatrix();
		glColor4fv(couleurGdPhare);
		glTranslatef(-1.6, -0.4, 0.65);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.21,0.51,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare2);
		glTranslatef(-1.833, -0.4, 0.675);
		glRotatef(-90, 0, 1, 0);  
		gluCylinder(param,0.2,0.3,0.2,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare2);
		glTranslatef(-1.245, -0.4, 0.668);
		glRotatef(-90, 0, 1, 0);  
		gluCylinder(param,0.0,0.22,0.1,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare);
		glTranslatef(-1.3, -0.4, 0.668);
		gluSphere(param,0.1,20,20);
	glPopMatrix();
	remiseZero();
	
	glPushMatrix();
		glColor4fv(couleurPhare);
		glTranslatef(-1.92, -0.4, 0.672);
		gluSphere(param,0.21,20,20);
	glPopMatrix();
	
	//gauche
	effetComplexArgent();
	glPushMatrix();
		glColor4fv(couleurGdPhare);
		glTranslatef(-1.6, -0.4, -0.65);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.21,0.51,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare2);
		glTranslatef(-1.833, -0.4, -0.675);
		glRotatef(-90, 0, 1, 0);  
		gluCylinder(param,0.2,0.3,0.2,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare2);
		glTranslatef(-1.245, -0.4, -0.668);
		glRotatef(-90, 0, 1, 0);  
		gluCylinder(param,0.0,0.22,0.1,20,1);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGdPhare);
		glTranslatef(-1.3, -0.4, -0.668);
		gluSphere(param,0.1,20,20);
	glPopMatrix();
	remiseZero();
	
	glPushMatrix();
		glColor4fv(couleurPhare);
		glTranslatef(-1.92, -0.4, -0.672);
		gluSphere(param,0.21,20,20);
	glPopMatrix();
}

void creerCabine()
{
     effetComplexChrome();
	//création de la cabine
	//création du côté
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.1, 0.7, 0.75);
		glScalef(0.2,2.4,0.1);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(1.3, 0.7, 0.75);
		glScalef(0.2,2.4,0.1);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(0.6, 0.2, 0.75);
		glScalef(1.2,1.4,0.1);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(0.6, 1.8, 0.75);
		glScalef(1.2,0.2,0.1);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.025, 1.3, 0.775);
		glScalef(0.05,0.8,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(1.175, 1.3, 0.775);
		glScalef(0.05,0.8,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.6, 0.925, 0.775);
		glScalef(1.1,0.05,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.6, 1.675, 0.775);
		glScalef(1.1,0.05,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	//création du côté en face
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.1, 0.7, -0.75);
		glScalef(0.2,2.4,0.1);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(1.3, 0.7, -0.75);
		glScalef(0.2,2.4,0.1);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(0.6, 0.2, -0.75);
		glScalef(1.2,1.4,0.1);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(0.6, 1.8, -0.75);
		glScalef(1.2,0.2,0.1);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.025, 1.3, -0.775);
		glScalef(0.05,0.8,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(1.175, 1.3, -0.775);
		glScalef(0.05,0.8,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.6, 0.925, -0.775);
		glScalef(1.1,0.05,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(0.6, 1.675, -0.775);
		glScalef(1.1,0.05,0.15);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	//création de la face avant
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.15, 1.8, 0);
		glScalef(0.1,0.2,1.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.15, 0.2, 0);
		glScalef(0.1,1.4,1.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.15, 1.3, -0.6);
		glScalef(0.1,0.8,0.2);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(-0.15, 1.3, 0.6);
		glScalef(0.1,0.8,0.2);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(-0.175, 1.3, 0.475);
		glScalef(0.15,0.8,0.05);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(-0.175, 1.3, -0.475);
		glScalef(0.15,0.8,0.05);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(-0.175, 0.925, 0);
		glScalef(0.15,0.05,0.9);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCadre);
		glTranslatef(-0.175, 1.675, 0);
		glScalef(0.15,0.05,0.9);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	//création de la face arrière (côté porte)
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(1.35, 1.8, 0);
		glScalef(0.1,0.2,1.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(1.35, 0.6, -0.6);
		glScalef(0.1,2.2,0.2);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurMur);
		glTranslatef(1.35, 0.6, 0.6);
		glScalef(0.1,2.2,0.2);
		glutSolidCube(1.0); 
	glPopMatrix();
	
	//création du sol
	glPushMatrix();
		glColor4fv(couleurSol);
		glTranslatef(0.6, -0.475, 0);
		glScalef(1.4,0.05,1.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	//création du toit
	glPushMatrix();
		glColor4fv(couleurToit);
		glTranslatef(0.6, 2.11, 0.42);
		glRotatef(-60, 1, 0, 0);
		glScalef(2,1,0.05);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurToit);
		glTranslatef(0.6, 2.11, -0.42);
		glRotatef(60, 1, 0, 0);
		glScalef(2,1,0.05);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	//les pinions
	glBegin(GL_POLYGON);
		glColor4fv(couleurMur);
		glVertex3f(1.4,1.9, 0.8);//sommet
		
		glColor4fv(couleurMur);
		glVertex3f(1.4,2.35, 0);
		
		glColor4fv(couleurMur);
		glVertex3f(1.4,1.9, -0.8);//sommet           
		glEnd();
		
		glBegin(GL_POLYGON);
		glColor4fv(couleurMur);
		glVertex3f(1.3,1.9, 0.8);//sommet
		
		glColor4fv(couleurMur);
		glVertex3f(1.3,2.35, 0);
		
		glColor4fv(couleurMur);
		glVertex3f(1.3,1.9, -0.8);//sommet  
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor4fv(couleurMur);
		glVertex3f(-0.1,1.9, 0.8);//sommet
		
		glColor4fv(couleurMur);
		glVertex3f(-0.1,2.35, 0);
		
		glColor4fv(couleurMur);
		glVertex3f(-0.1,1.9, -0.8);//sommet  
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor4fv(couleurMur);
		glVertex3f(-0.2,1.9, 0.8);//sommet
		
		glColor4fv(couleurMur);
		glVertex3f(-0.2,2.35, 0);
		
		glColor4fv(couleurMur);
		glVertex3f(-0.2,1.9, -0.8);//sommet  
	glEnd();
	
	//ajout des poignees
	
	//poignee 1
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 0.6, 0.6);
		solidCylindre(0.03,1.2,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGrisClair());
		glTranslatef(1.45, 0, 0.6);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.03,0.15,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGrisClair());
		glTranslatef(1.45, 1.2, 0.6);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.03,0.15,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 0, 0.6);
		gluSphere(param,0.035,20,20);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 1.2, 0.6);
		gluSphere(param,0.035,20,20);
	glPopMatrix();
	
	//poignee2
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 0.6, -0.6);
		solidCylindre(0.03,1.2,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGrisClair());
		glTranslatef(1.45, 0, -0.6);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.03,0.15,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurGrisClair());
		glTranslatef(1.45, 1.2, -0.6);
		glRotatef(90, 0, 0, 1);
		solidCylindre(0.03,0.15,20,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 0, -0.6);
		gluSphere(param,0.035,20,20);
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurCylindre);
		glTranslatef(1.5, 1.2, -0.6);
		gluSphere(param,0.035,20,20);
	glPopMatrix();
	remiseZero();
	
}

void creerRoues()
{
	//création des roues
	//roue 1                
	glPushMatrix();
		glTranslatef(0.78, -0.65, 0.83);
		glRotatef(a,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
		
		
		//attache roue1
		glPushMatrix();
			glColor4fv(couleurBrun());
			glTranslatef(0.53, 0.1, 0.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.06,0.28,20,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurRouge());
			glTranslatef(0.53, 0.1, 0);
			gluDisk(param,0,0.06,20,1);
		glPopMatrix();
	glPopMatrix();
		
	//roue2
	glPushMatrix();
		glTranslatef(-0.55, -0.65, 0.83);
		glRotatef(a,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
		
		
		//attache roue2
		glPushMatrix();
			glColor4fv(couleurBrun());
			glTranslatef(0.53, 0.1, 0.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.06,0.28,20,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurRouge());
			glTranslatef(0.53, 0.1, 0);
			gluDisk(param,0,0.06,20,1);
			glPopMatrix();
	glPopMatrix();
		
	//roue 3
	glPushMatrix();
		glTranslatef(0.78, -0.65, -0.99);
		glRotatef(az,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
		
		glPushMatrix();
			glColor4fv(couleurBrun());
			glTranslatef(0.537, 0.045, 0.02);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.06,0.28,20,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurRouge());
			glTranslatef(0.537, 0.045, 0.15);
			gluDisk(param,0,0.06,20,1);
		glPopMatrix();
	glPopMatrix();
		
		
	//roue4
	glPushMatrix();
		glTranslatef(-0.55, -0.65, -0.99);
		glRotatef(az,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
		
		glPushMatrix();
			glColor4fv(couleurBrun());
			glTranslatef(0.537, 0.045, 0.02);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.06,0.28,20,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurRouge());
			glTranslatef(0.537, 0.045, 0.15);
			gluDisk(param,0,0.06,20,1);
		glPopMatrix();
	glPopMatrix();
}

void creerRouesWagon()
{
	//création des roues
	//roue 1                
	glPushMatrix();
		glTranslatef(0.78, -0.65, 0.83);
		glRotatef(a,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
	glPopMatrix();
		
	//roue2
	glPushMatrix();
		glTranslatef(-0.55, -0.65, 0.83);
		glRotatef(a,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
	glPopMatrix();
		
	//roue 3
	glPushMatrix();
		glTranslatef(0.78, -0.65, -0.99);
		glRotatef(az,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
	glPopMatrix();
		
		
	//roue4
	glPushMatrix();
		glTranslatef(-0.55, -0.65, -0.99);
		glRotatef(az,0.0,0.0,1.0);
		Roue(couleurRoueInterieur, couleurRoueExterieur, couleurFlanRoue);
	glPopMatrix();
}

void creerBarres()
{
     //axe roues droite////////////////////////////////////////////////////////////////////////////////
	
	glPushMatrix();
		tournerRoue();
		glTranslatef(0.06, -0.1, 0);     
		
		//axe entre roue 1 et roue2
		effetComplexOr();
        glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(0, 0, 1.06);
			glScalef(1.35,0.14,0.1);
			glutSolidCube(1.0);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(0.7, 0, 1.07);
			glScalef(1,1,0.5);
			gluSphere(param,0.14,20,20);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(-0.6, 0, 1.07);
			glScalef(1,1,0.5);
			gluSphere(param,0.14,20,20);
		glPopMatrix();
		remiseZero();
		
		glPushMatrix();
			glColor4fv(couleurGrisFonce());
			glTranslatef(0.7, 0, 1.15);
			glRotatef(90, 0, 0, 1);
			glScalef(0.13,0.13,1);
			glutSolidTorus(0.2,0.45,2,6);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurNoir());
			glTranslatef(0.7, 0, 1.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.08,0.045,6,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurGrisFonce());
			glTranslatef(-0.6, 0, 1.15);
			glRotatef(90, 0, 0, 1);
			glScalef(0.13,0.13,1);
			glutSolidTorus(0.2,0.45,2,6);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurNoir());
			glTranslatef(-0.6, 0, 1.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.08,0.045,6,10);       
		glPopMatrix();
	
	glPopMatrix();
	
	//axe roues gauche
	glPushMatrix();
		tournerRoue();
		glTranslatef(0.06, -0.1, 0);     
		
		//axe entre roue 2 et roue 3
		effetComplexOr();
        glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(0, 0, -1.06);
			glScalef(1.35,0.14,0.1);
			glutSolidCube(1.0);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(0.7, 0, -1.07);
			glScalef(1,1,0.5);
			gluSphere(param,0.14,20,20);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurAxe);
			glTranslatef(-0.6, 0, -1.07);
			glScalef(1,1,0.5);
			gluSphere(param,0.14,20,20);
		glPopMatrix();
		remiseZero();
		
		glPushMatrix();
			glColor4fv(couleurGrisFonce());
			glTranslatef(0.7, 0, -1.15);
			glRotatef(90, 0, 0, 1);
			glScalef(0.13,0.13,1);
			glutSolidTorus(0.2,0.45,2,6);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurNoir());
			glTranslatef(0.7, 0, -1.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.08,0.045,6,10);       
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurGrisFonce());
			glTranslatef(-0.6, 0, -1.15);
			glRotatef(90, 0, 0, 1);
			glScalef(0.13,0.13,1);
			glutSolidTorus(0.2,0.45,2,6);
		glPopMatrix();
		
		glPushMatrix();
			glColor4fv(couleurNoir());
			glTranslatef(-0.6, 0, -1.13);
			glRotatef(90, 1, 0, 0);
			solidCylindre(0.08,0.045,6,10);       
		glPopMatrix();
	
	glPopMatrix();
     
}
void creerAxesRoues()
{
	//axe roues avant
	glPushMatrix();
		glColor4fv(couleurRose());
		glTranslatef(-0.55, -0.65, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.2,2,20,10);
	glPopMatrix();
	
	//axe roues arrière
	glPushMatrix();
		glColor4fv(couleurRose());
		glTranslatef(0.78, -0.65, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.2,2,20,10);
	glPopMatrix();
	
	//axe central
	glPushMatrix();
		glColor4fv(couleurSol);
		glTranslatef(-0.3, -0.70, 0);
		glScalef(3.2,0.4,0.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	
	/////////////////////////////////////////////////////////////////////////// 
	
}

void creerAxesRouesWagon()
{
	//axe roues avant
	glPushMatrix();
		glColor4fv(couleurRose());
		glTranslatef(-0.55, -0.65, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.2,2,20,10);
	glPopMatrix();
	
	//axe roues arrière
	glPushMatrix();
		glColor4fv(couleurRose());
		glTranslatef(0.78, -0.65, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.2,2,20,10);
	glPopMatrix();
	
	//axe central
	glPushMatrix();
		glColor4fv(couleurSol);
		glTranslatef(0, -0.62, 0);
		glScalef(2.9,0.4,0.4);
		glutSolidCube(1.0);  
	glPopMatrix();
	
	
	/////////////////////////////////////////////////////////////////////////// 
	
}

void creerPointe()
{
	//pointe
	//fixation
	effetComplexArgent();
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-1.9, -0.5, 0);
		glRotatef(90, 1, 0, 0);
		solidCylindre(0.04,0.4,20,10);
	glPopMatrix();
	
	//partie gauche axe principal 1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.15, -0.8, -0.4);
		glRotatef(90, 0, 0, 1);
		glRotatef(45, 0, 0, 1);
		glRotatef(30, -1, 0, 0);
		solidCylindre(0.03,1,20,10);
	glPopMatrix();
	
	//partie droite axe principal 1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.15, -0.8, 0.4);
		glRotatef(90, 0, 0, 1);
		glRotatef(45, 0, 0, 1);
		glRotatef(30, 1, 0, 0);
		solidCylindre(0.03,1,20,10);
	glPopMatrix();
	
	//axe milieu
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.4, -0.8, 0);
		glRotatef(90, 0, 0, 1);
		glRotatef(30, 0, 0, 1);
		solidCylindre(0.03,1.2,20,10);
	glPopMatrix();
	
	//partie droite bas 1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.68, -1.1, -0.345);
		glRotatef(90, 1, 0, 0);
		glRotatef(35, 0, 0, 1);
		solidCylindre(0.03,0.78,20,10);
	glPopMatrix();
	
	//partie gauche bas1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.68, -1.1, 0.345);
		glRotatef(90, 1, 0, 0);
		glRotatef(35, 0, 0, -1);
		solidCylindre(0.03,0.78,20,10);
	glPopMatrix();
	
	//partie gauche axe prinipal 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-1.9, -0.8, -0.5);
		glRotatef(50, 1, 0, 0);
		solidCylindre(0.03,0.9,20,10);
	glPopMatrix();
	
	//partie droite bas 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.18, -1.1, -0.75);
		glRotatef(90, 0, 0, 1);
		glRotatef(16, 1, 0, 0);
		solidCylindre(0.03,0.6,20,10);
	glPopMatrix();
	
	//partie gauche axe principal 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-1.9, -0.8, 0.5);
		glRotatef(50, -1, 0, 0);
		solidCylindre(0.03,0.9,20,10);
	glPopMatrix();
	
	//partie gauche bas 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.18, -1.1, 0.75);
		glRotatef(90, 0, 0, 1);
		glRotatef(16, -1, 0, 0);
		solidCylindre(0.03,0.6,20,10);
	glPopMatrix();
	
	//partie gauche tige 1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.05, -0.8, -0.47);
		glRotatef(45, 1, 0, 0);
		glRotatef(-20, 0, 0, 1);
		solidCylindre(0.02,0.9,20,10);
	glPopMatrix();
	
	//partie droite tige 1
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.05, -0.8, 0.47);
		glRotatef(45, -1, 0, 0);
		glRotatef(-20, 0, 0, 1);
		solidCylindre(0.02,0.9,20,10);
	glPopMatrix();
	
	//partie gauche tige 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.25, -0.82, -0.265);
		glRotatef(31, 1, 0, 0);
		glRotatef(-47, 0, 0, 1);                 
		solidCylindre(0.02,0.95,20,10);
	glPopMatrix();
	
	//partie gauche tige 3
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.32, -0.8, -0.12);
		glRotatef(14, 1, 0, 0);
		glRotatef(-57, 0, 0, 1);                 
		solidCylindre(0.02,1.08,20,10);
	glPopMatrix();
	
	//partie droite tige 2
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.25, -0.82, 0.265);
		glRotatef(31, -1, 0, 0);
		glRotatef(-47, 0, 0, 1);                 
		solidCylindre(0.02,0.95,20,10);
	glPopMatrix();
	
	//partie droite tige 3
	glPushMatrix();
		glColor4fv(couleurGrisFonce());
		glTranslatef(-2.32, -0.8, 0.12);
		glRotatef(14, -1, 0, 0);
		glRotatef(-57, 0, 0, 1);                 
		solidCylindre(0.02,1.08,20,10);
	glPopMatrix();
	remiseZero();
	
}

void creerPasserelle()
{
     effetComplexChrome();
     glPushMatrix();
         glPushMatrix();
                     glColor4fv(couleurSol);
                     glTranslatef(1.7, -0.8, 0);
                     glScalef(0.8,0.05,1.4);
                     glutSolidCube(1.0);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurSol);
                     glTranslatef(1.3, -0.65, 0);
                     glScalef(0.05,0.3,1.4);
                     glutSolidCube(1.0);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, -0.2, -0.6);
                     solidCylindre(0.03,1.2,20,10);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, -0.2, 0.6);
                     solidCylindre(0.03,1.2,20,10);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, -0.2, 0.2);
                     solidCylindre(0.03,1.2,20,10);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, -0.2, -0.2);
                     solidCylindre(0.03,1.2,20,10);
         glPopMatrix();
         
         glPushMatrix();
                     glRotatef(90,1,0,0);
                     glColor4fv(couleurGrille);
                     glTranslatef(2, 0, -0.4);
                     solidCylindre(0.03,1.2,20,10);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, 0.4, -0.6);
                     gluSphere(param,0.035,20,20);
         glPopMatrix();
         
         glPushMatrix();
                     glColor4fv(couleurGrille);
                     glTranslatef(2, 0.4, 0.6);
                     gluSphere(param,0.035,20,20);
         glPopMatrix();
     
     glPopMatrix();
     remiseZero();
}
void creerContenaire()
{
     effetComplexChrome();
    //création de la cabine
	//création du sud
	glPushMatrix();
		glColor4fv(couleurWagon1);
		glTranslatef(0, 0.3, 0.75);
		glScalef(3,1.5,0.1); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurWagon2);
		glTranslatef(0, 1.06, 0.775);
		glScalef(3,0.05,0.15); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	//création du nord
	glPushMatrix();
		glColor4fv(couleurWagon1);
		glTranslatef(0, 0.3, -0.75);
		glScalef(3,1.5,0.1); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurWagon2);
		glTranslatef(0, 1.06, -0.775);
		glScalef(3,0.05,0.15); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
    
    //création de l'est
	glPushMatrix();
		glColor4fv(couleurWagon1);
        glTranslatef(1.46, 0.3, 0);
		glScalef(0.1, 1.5, 1.5); //x = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	glPushMatrix();
		glColor4fv(couleurWagon2);
		glTranslatef(1.485, 1.06, 0);
		glScalef(0.15,0.05,1.7); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	//création de l'ouest
	glPushMatrix();
		glColor4fv(couleurWagon1);
        glTranslatef(-1.46, 0.3, 0);
		glScalef(0.1, 1.5, 1.5); //x = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	glPushMatrix();
		glColor4fv(couleurWagon2);
		glTranslatef(-1.485, 1.06, 0);
		glScalef(0.15,0.05,1.7); //z = epaisseur
		glutSolidCube(1.0);  
	glPopMatrix();
	
	//création du sol
	glPushMatrix();
		glColor4fv(couleurWagon2);
        glTranslatef(0, -0.41, 0);
		glScalef(2.9, 0.1, 1.5);
		glutSolidCube(1.0);  
	glPopMatrix();
	remiseZero();
}

void creerAccrocheLoco()
{
     glPushMatrix();
         glColor4fv(couleurGrille);
         glTranslatef(1.8, -0.85, 0);
         glRotatef(90, 0,0,1);
         solidCylindre(0.03,1.2,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurGrille);
         glTranslatef(2.4, -0.85, 0);
         glRotatef(90, 1,0,0);
         glutSolidTorus	(	0.04 , 0.07 , 10 ,20 );
     glPopMatrix(); 
}

void creerAccrocheWagon()
{
     glPushMatrix();
         glColor4fv(couleurGrille);
         glTranslatef(-1.6, -0.62, 0);
         glRotatef(90, 0,0,1);
         solidCylindre(0.03,0.8,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurGrille);
         glTranslatef(-2, -0.87, 0);
         solidCylindre(0.03,0.5,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurGrille);
         glTranslatef(-2, -0.62, 0);
         gluSphere(param,0.03,20,20);
     glPopMatrix();
}

void creerTrain()
{
	//matrix de la loco
	glPushMatrix(); 
		creerAvantLoco();
		
		creerChemine();
		
		creerCloche();
		
		creerAccrocheCloche();
		
		creerInterieurCloche();
		
		creerSoupape();
		
		creerPhares();
		
		creerCabine();       
		
		creerRoues();
		
		creerAxesRoues();
        
        creerBarres();   
		
		creerPointe();
		
		creerPasserelle();
		
		creerAccrocheLoco();
		
	glPopMatrix();
}

void creerWagon()
{
	glPushMatrix();
        creerContenaire();
        
		creerRouesWagon();
		
		creerAxesRouesWagon();
		
		creerAccrocheWagon();
	glPopMatrix();
}

void creerRail()
{
    double max = 20;
    double min = max - 0.16;
    glPushMatrix();
        glColor3fv(couleurBlanc());
        glTranslatef(0, -1.27, 19);
        glRotatef(90, 1, 0, 0);
        gluDisk(param, min, max, 100, 8);
    glPopMatrix();
    
    max = 18 + .16;
    min = max - 0.16;
    glPushMatrix();
        glColor3fv(couleurBlanc());
        glTranslatef(0, -1.27, 19);
        glRotatef(90, 1, 0, 0);
        gluDisk(param, min, max, 100, 8);
    glPopMatrix();
}

void creerTerrain()
{
    glPushMatrix();
        glColor3fv(couleurBlanc(0));
        //glTranslatef(0, -1.78, 0);
        glTranslatef(0, -1.78, 0);
        glScalef(100, 1, 100);
        monGlutSolidCube(1);
    glPopMatrix();
}

void display(void)
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4fv(couleurNoir());
	
	//pour le recpouvremment: dessine ce qu'il faut
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	
	//Matrice de la scene
	glPushMatrix();
		
        manipulateurSouris();
		manipulateurClavier();
		
		//rotation de toute la scene
		glRotatef(anglex,1.0F,0.0F,0.0F);
		glRotatef(angley,0.0F,1.0F,0.0F);
		glRotatef(anglez,0.0F,0.0F,1.0F);
		
        //cout << couleurCylindre[0] << " " << couleurCylindre[1] << " " << couleurCylindre[2] << " " << endl;
        gluLookAt(dist * monCosinus[angle], hauteurCam, dist * monSinus[angle], depCamX, depCamY, depCamZ, 0.0, 1.0, 0.0);
        
		glPushMatrix();
    		glColor4fv(couleurRouge());
            glutSolidCube(1);
        glPopMatrix();
        
        glPushMatrix();
            creerTerrain();
        glPopMatrix();
        
        //creation du train dans la scene au point 0, 0, 0
        glPushMatrix();
            
            glRotatef(angleTrain, 0, 1, 0);
            glTranslatef(0, 0, -19);
            creerRail();
            
            //glTranslatef(0, 0, -18);
            //glTranslatef(-18*monCosinus[1], 0, 18*monSinus[1]);
            //deplacement du train il faut aussi une rotation progressive pour mettre le train dans le bon sens ...
            //ca aurait était trop facile sinon X|
            //glTranslatef(18*monCosinus[angleTrain], 0, -18*monSinus[angleTrain]);
            //pas terrible la rotation
            //ici déplacement du train sur les rails
            
            glPushMatrix();
                glTranslatef(-2.2, 0, 0.125);
                glRotatef(5, 0, 1, 0);
                creerTrain();
            glPopMatrix();
            
            //creation du wagon au point x, y, z
            glPushMatrix();
                glRotatef(-4, 0, 1, 0);
                glTranslatef(2.2, 0, 0);
                creerWagon();
            glPopMatrix();
        glPopMatrix();

            
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
} 

void myinit(void) { 
	glClearColor(1.0,1.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	glEnable(GL_TEXTURE_2D);
    
    GLfloat L0pos[]={ x, y, z};
    GLfloat L0dif[]={ 0.5, 0.8, 0.7};
    
    GLfloat L1pos[]={ -x, -y, -z};
    GLfloat L1dif[]={ 0.3, 0.4, 0.1};
    
    //GLfloat Mspec[]={0,0,0};
    //GLfloat Mshiny=0;
    
    //glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Mspec);
    //glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Mshiny);
    
    glLightfv(GL_LIGHT0,GL_POSITION,L0pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,L0dif);
    glLightfv(GL_LIGHT0,GL_SPECULAR,L0dif);
    
    glLightfv(GL_LIGHT1,GL_POSITION,L1pos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,L1dif);
    glLightfv(GL_LIGHT1,GL_SPECULAR,L1dif);
} 

void special(int key,int x,int y) {
	switch(key) 
	{
	case GLUT_KEY_UP    : 
		anglex--; 
		break;
	case GLUT_KEY_DOWN  : 
		anglex++; 
		break;
	case GLUT_KEY_LEFT  : 
		angley--; 
		break;
	case GLUT_KEY_RIGHT : 
		angley++; 
		break; 
	}
	glutPostRedisplay() ;
}

void clavier(unsigned char touche,int x,int y)
{

	switch (touche)
	{   
	case 'l':
		if (glIsEnabled(GL_LIGHT0))
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		glutPostRedisplay();
		break;
    case 'm':
		if (glIsEnabled(GL_LIGHT1))
			glDisable(GL_LIGHT1);
		else
			glEnable(GL_LIGHT1);
		glutPostRedisplay();
		break;
    case 'z':
        anglez++;
        glutPostRedisplay() ;
        break;
    case 'Z':
        anglez--;
        glutPostRedisplay() ;
        break;
    case 'o':
		angle+=1;
		if (angle>=360)
			angle-=360;
		glutPostRedisplay();
		break;
	case 'p' :
		angle-=1;
		if (angle<0)
			angle+=360;
		glutPostRedisplay();
		break;
	case 'i' :
        hauteurCam += 2;
        glutPostRedisplay();
        break;
    case 'u' :
        hauteurCam -= 2;
        glutPostRedisplay();
        break;
    case '6':
        depCamX += 2;
        glutPostRedisplay();
        break;
    case '4':
        depCamX -= 2;
        glutPostRedisplay();
        break;
    case '8':
        depCamY += 2;
        glutPostRedisplay();
        break;
    case '2':
        depCamY -= 2;
        glutPostRedisplay();
        break;
    case '9':
        depCamZ += 2;
        glutPostRedisplay();
        break;
    case '1':
        depCamZ -= 2;
        glutPostRedisplay();
        break;
	case '+':
		dist -= .5;
		glutPostRedisplay();
		break;
	case '-':
		dist += .5;
		glutPostRedisplay();
		break;
	case 'a':
		az = (az+ 5)%360;
		a = a+5;
		
		angleTrain = (angleTrain + 1) % 360;
		
		glutPostRedisplay() ;
		break;
	case 'b':
		
		if(tempcompt<16)
		{
			angleCloche ++ ;
			tempcompt= tempcompt +1;
			
		}
		if(tempcompt>=16 && tempcompt<49)
		{
			angleCloche -- ;
			tempcompt= tempcompt +1;
		}
		if(tempcompt>=49)
		{
			angleCloche ++ ;
			tempcompt= tempcompt +1;
		}
		if(tempcompt==68)
		{
			tempcompt=1;
			angleCloche=4;
		}

		if (angleCloche==18 || angleCloche==-13)
		{
			PlaySound(TEXT("cloche3.wav"), NULL, SND_FILENAME|SND_ASYNC);
		}
		
		glutPostRedisplay();
		
		break;  
	case 't':
		monte();
		
		PlaySound(TEXT("tchou tchou.wav"), NULL, SND_FILENAME|SND_ASYNC);
		
		descend();
		break;
	case 'q' : /*la touche 'q' permet de quitter le programme */
		exit(0);
	}
}

int main(int argc,char **argv) {
	trigo();
	
	themeCourse();

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500,500); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("Petit train");
	myinit();
    
    loadJpegImage("herbe4.jpg", idTextureHerbe);
    
    glEnable(GL_NORMALIZE);
	//pour le recouvrement
	glEnable(GL_DEPTH_TEST) ;

	creationMenuBasique();
	setParametresPerspectiveBasique(65.0F,1.0F,1.0F,100.0F,0.0F,0.0F,-5.0F);
	
    //setParametresPerspectiveBasique(90.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-5.0F);
	setManipulateurDistance(10.0F);
	glutReshapeFunc(reshapePerspectiveBasique);
	
    glutKeyboardFunc(keyBasique);
	glutSpecialFunc(special);
    
	glutMotionFunc(motionBasique);
	glutMouseFunc(sourisBasique);
	glutDisplayFunc(display);

	//pour interagir avec la loco
	glutKeyboardFunc(clavier);

	glutMainLoop();
	return(0);
}


