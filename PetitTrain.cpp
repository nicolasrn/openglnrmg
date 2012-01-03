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
#include "MonModuleSouris.h"
#include "MonModuleCamera.h"
#include "ModuleDecor.h"

using namespace std;

//variables qui dépendent du train
//static int angle = 90;
//static int angleTrain = 0;
float up = 0.0F ;
int az = 6 ;
int a = 0 ;
float PI = 3.14;//159265;
//static float monCosinus[360];
//static float monSinus[360];
int angleCloche = 4;
int tempcompt = 1;

//dépend de lookAt
//static int x=1, y=1, z=1;
//static float dist = 4.5, hauteurCam = 4.5;
//static float depCamX = 0.0, depCamY = 0.0, depCamZ = 0.0;
/*Camera cameraLibre;
Camera cameraCabine;
Camera *cameraCourante;*/
//static float dist = 4.5;

//pour l'animation
void (*idleFunc)() = NULL;

//texture
GLuint tabTexture[2];

int indexList;

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
    GLfloat L1dif[]={ 1, 1, 1};
    GLfloat L1spec[]={ 1, 1, 1};
    
    glLightfv(GL_LIGHT1,GL_DIFFUSE,L1dif);
    glLightfv(GL_LIGHT1,GL_SPECULAR,L1spec);
    
    glLightfv(GL_LIGHT2,GL_DIFFUSE,L1dif);
    glLightfv(GL_LIGHT2,GL_SPECULAR,L1spec);
    
    GLfloat direction2[]={-10, -.02, -1.6};
    GLfloat direction1[]={-10, -.02, 1.6};
    
    //float lpos2[] = {-1.93, -0.4, -0.672, 1}; //phare gauche
    //float lpos1[] = {-1.93, -0.4,  0.672, 1}; //phare droit
    
    float lpos2[] = {0.52, -0.4, -0.672, 1}; //phare gauche
    float lpos1[] = {0.52, -0.4,  0.672, 1}; //phare droit
    
    float angle = 10., attenuation = .01;
	//phares
	//droit
    glPushMatrix();
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
            glPushMatrix();
                //glRotatef(180 - angle, 0, 1, 0);
                glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, angle); // ce spot ?clairera jusqu'? 45? autour de son axe 
                glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction1);
                glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, attenuation);// coefficient d'att?nuation angulaire
                glLightfv(GL_LIGHT1,GL_POSITION,lpos1);
                //glRotatef(-90, 0, 1, 0);
            glPopMatrix();
            
    		glColor4fv(couleurPhare);
    		if (glIsEnabled(GL_LIGHT1))
    		  glMaterialfv(GL_FRONT,GL_EMISSION, couleurBlanc());
    		glTranslatef(-1.93, -0.4, 0.672);
    		gluSphere(param,0.21,20,20);
    		if (glIsEnabled(GL_LIGHT1))
    		  glMaterialfv(GL_FRONT,GL_EMISSION, newCouleur(0, 0, 0, 1));
    	glPopMatrix();
	glPopMatrix();
	
	//gauche
	glPushMatrix();
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
            glPushMatrix();
                //glRotatef(180 - angle, 0, 1, 0);
                glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, angle); // ce spot ?clairera jusqu'? 45? autour de son axe 
                glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction2);
                glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, attenuation);// coefficient d'att?nuation angulaire
                glLightfv(GL_LIGHT2,GL_POSITION,lpos2);
                //glRotatef(-90, 0, 1, 0);
            glPopMatrix();
            
    		glColor4fv(couleurPhare);
    		if (glIsEnabled(GL_LIGHT2))
    		  glMaterialfv(GL_FRONT,GL_EMISSION, couleurBlanc());
    		glTranslatef(-1.93, -0.4, -0.672);
            gluSphere(param,0.21,20,20);
    		if (glIsEnabled(GL_LIGHT2))
    		  glMaterialfv(GL_FRONT,GL_EMISSION, newCouleur(0, 0, 0, 1));
    	glPopMatrix();
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

void initLumiere()
{
	//initialisation de la lumière soleil directionnel
    GLfloat L0pos[]={ 0, 10, 0, 1};
    GLfloat L0dif[]={ 1, 1, 1};
    
    //position et direction
    glLightfv(GL_LIGHT0, GL_POSITION, L0pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, L0dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, L0dif);
    
    //spot
    GLfloat attenuation = 10;
    GLfloat langle = 20;
    GLfloat L3pos[]={ 0, 1, 0, 1};
    GLfloat L3dif[]={ .8, .8, .8 };
    GLfloat direction[]={0, -.02, -1};
    
    glLightfv(GL_LIGHT3, GL_POSITION, L3pos);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, L3dif);
    glLightfv(GL_LIGHT3, GL_SPECULAR, L3dif);
    
    //parametres avances 
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction);
    glLightf (GL_LIGHT3, GL_SPOT_CUTOFF, langle); 
    glLightf (GL_LIGHT3, GL_SPOT_EXPONENT, attenuation);
}

void display(void)
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor4fv(couleurNoir());
	
	//pour le recpouvremment: dessine ce qu'il faut
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	
	//Matrice de la scene
	glPushMatrix();
        manipulateurSouris();
		manipulateurClavier();
        
        //via la souris
        if (doActionSourisRotation != NULL)
            doActionSourisRotation();
        
        //rotation de toute la scene via le clavier
        if (doActionClavierRotation != NULL)
        {
    		glRotatef(anglex,1.0F,0.0F,0.0F);
    		glRotatef(angley,0.0F,1.0F,0.0F);
    		glRotatef(anglez,0.0F,0.0F,1.0F);
        }
        
        //*/
        lookAt(cameraCourante, trajectoireCourante);
        initLumiere();
        //*/
        
        /*
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
        glPushMatrix() ;
            glPushMatrix();
                glEnable(GL_COLOR_MATERIAL);
                remiseZero();
                if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                creerMur(2, 2, 1, 5);
	            if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
            glPopMatrix();
            
            glPushMatrix();
                glDisable(GL_COLOR_MATERIAL);
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurBlanc(0.5)) ;
                glPushMatrix();
                    glTranslatef(0, 0.5, 0);
                    glutSolidCube(1.0) ;
                glPopMatrix();
            glPopMatrix();
        glPopMatrix() ;
    	//*/
        
		glPushMatrix();
    		glColor4fv(couleurRouge());
            glutSolidSphere(.5, 50, 50);
        glPopMatrix();
        
        glCallList(indexList);
        
        /*
        glPushMatrix();
            creerTerrain(tabTexture);
        glPopMatrix();
        
        //décorations :  des sapins
        decoSapin();
        
        //décorations: des moutons
        decoMouton();
        
        //décoration : maison
        glPushMatrix();
            glTranslatef(19, 0, -19);
            glRotatef(-45,0,1,0);
            creerMaison();
        glPopMatrix();
        
        //décoration : tunnel
        glPushMatrix();
            glTranslatef(0, 0, 19);
            creerTunnel();
        glPopMatrix();
        //*/
        
        //creation du train dans la scene
        glPushMatrix();
            glRotatef(angleTrain, 0, 1, 0);
            glTranslatef(0, 0, -19);
            creerRail();
            
            glPushMatrix();
                glTranslatef(-2.2, 0, 0.125);
                glRotatef(5, 0, 1, 0);
                creerTrain();
            glPopMatrix();
            
            //creation du wagon
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

void idle()
{
    //deplacement du train
    az = (az+ 5)%360;
	a = a+5;
	angleTrain = (angleTrain + 1) % 360;
	angleTrainCamera = (angleTrainCamera + 1) % 360;
	cout << angleTrain << endl;
	
	//raffichage
    glutPostRedisplay();
}

void sonnerCloche()
{
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
}

void myinit(void) { 
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    
    glDepthFunc(GL_LESS);
    
    //pour le recouvrement
	glEnable(GL_DEPTH_TEST) ;

    //initialisation des variables dépendant de la caméra
    resetDataLibre();
    
    //initialisation de la camera
    initCamera(&cameraLibre, dist * monCosinus[angle], dist, dist * monSinus[angle]);
    initCamera(&cameraCabine);
    cameraCourante = &cameraLibre;
    
    //pour la trajectoire de la caméra
    trajectoireCourante = &trajectoireLibre;
} 

void special(int key,int x,int y) {
    if (doActionClavierRotation != NULL)
    	doActionClavierRotation(key);
}

void clavier(unsigned char touche,int x,int y)
{
    //lumière
	switch (touche)
	{
	case 'k':
        activerDesactiverSpot();
        glutPostRedisplay();
		break;
	case 'l':
		activerDesactiverSoleil();
        glutPostRedisplay();
		break;
    case 'm':
		activerDesactiverPhare();
        glutPostRedisplay();
		break;
    }
    
    //manipulation de la scene
    if (doActionClavierRotation)
        doActionClavierRotation(touche);
    
    //manipulation de la camera
    switch(touche)
    {
    case 'o':
		angle+=1;
		if (angle>=360)
			angle-=360;
		//setEyeZ(cameraCourante, dist * monSinus[angle]);
		//setEyeX(cameraCourante, dist * monCosinus[angle]);
		glutPostRedisplay();
		break;
	case 'p' :
		angle-=1;
		if (angle<0)
			angle+=360;
		//setEyeZ(cameraCourante, dist * monSinus[angle]);
		//setEyeX(cameraCourante, dist * monCosinus[angle]);
		glutPostRedisplay();
		break;
	case 'i' :
        hauteurCam += 2;
        //setEyeY(cameraCourante, cameraCourante->eyeY + 2);
        glutPostRedisplay();
        break;
    case 'u' :
        hauteurCam -= 2;
        //setEyeY(cameraCourante, cameraCourante->eyeY - 2);
        glutPostRedisplay();
        break;
    case '6':
        depCamX += 2;
        //setCenterX(cameraCourante, cameraCourante->centerX + 2);
        glutPostRedisplay();
        break;
    case '4':
        depCamX -= 2;
        //setCenterX(cameraCourante, cameraCourante->centerX - 2);
        glutPostRedisplay();
        break;
    case '8':
        depCamY += 2;
        //setCenterY(cameraCourante, cameraCourante->centerY + 2);
        glutPostRedisplay();
        break;
    case '2':
        depCamY -= 2;
        //setCenterY(cameraCourante, cameraCourante->centerY - 2);
        glutPostRedisplay();
        break;
    case '9':
        depCamZ += 2;
        //setCenterZ(cameraCourante, cameraCourante->centerZ + 2);
        glutPostRedisplay();
        break;
    case '1':
        depCamZ -= 2;
        //setCenterZ(cameraCourante, cameraCourante->centerZ - 2);
        glutPostRedisplay();
        break;
	case '+':/*gluLookAt   (
                        dist * monCosinus[angle], hauteurCam, dist * monSinus[angle], 
                        depCamX, depCamY, depCamZ, 
                        0.0, 1.0, 0.0
                    );*/
		dist -= .5;
		//setEyeZ(cameraCourante, dist * monSinus[angle]);
		//setEyeX(cameraCourante, dist * monCosinus[angle]);
		glutPostRedisplay();
		break;
	case '-':
		dist += .5;
		//setEyeZ(cameraCourante, dist * monSinus[angle]);
		//setEyeX(cameraCourante, dist * monCosinus[angle]);
		glutPostRedisplay();
		break;
    }
    
	//animation de la scene
    switch(touche)
    {
	//deplacement du train
	case 'a':
		idle();
		break;
	//annimation de la cloche
	case 'b':
		sonnerCloche();
		glutPostRedisplay();
		break;  
	//annimation soupape
	case 't':
		monte();
		PlaySound(TEXT("tchou tchou.wav"), NULL, SND_FILENAME|SND_ASYNC);
		break;
	case 'r':
        descend();
		break;
	//animation via idle
	case 'I':
        if (idleFunc == NULL)
            idleFunc = &idle;
        else
            idleFunc = NULL;
        
        glutIdleFunc(*idleFunc);
        break;
    //pour quitter
	case 'q' : /*la touche 'q' permet de quitter le programme */
		exit(0);
	}
}

int initList()
{
    // create one display list
    GLuint index = glGenLists(1);
    
    // compile the display list
    glNewList(index, GL_COMPILE);
        glPushMatrix();
            creerTerrain(tabTexture);
        glPopMatrix();
        
        //décorations :  des sapins
        decoSapin();
        
        //décorations: des moutons
        decoMouton();
        
        //décoration : maison
        glPushMatrix();
            glTranslatef(19, 0, -19);
            glRotatef(-45,0,1,0);
            creerMaison();
        glPopMatrix();
        
        //décoration : tunnel
        glPushMatrix();
            glTranslatef(0, 0, 19);
            creerTunnel();
        glPopMatrix();
    glEndList();
    
    return index;
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
	
    loadJpegImage("herbe2.jpg", &tabTexture[0]);
    loadJpegImage("ciel03.jpg", &tabTexture[1]);
    
    indexList = initList();
    
	creationMenuBasique();
	//                             angle, ratio, clipping min, max , dx  , dy   , dz
	setParametresPerspectiveBasique(65.0F, 1.0F, .1F       , 200.0F, 0.0F, 0.0F, -5.0F);
	
    setManipulateurDistance(10.0F);
	glutReshapeFunc(reshapePerspectiveBasique);
	
    glutKeyboardFunc(keyBasique);
	glutSpecialFunc(special);
    
	glutDisplayFunc(display);
    
	//pour interagir avec la loco
	glutKeyboardFunc(clavier);

	glutMainLoop();
	return(0);
}


