
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h> 


#include "ModuleCouleurs.h"
#include "ModuleManipulateur.h"
#include "ModuleMenus.h"
#include "ModuleReshape.h"
#include "ModuleCylindres.h"
#include "ModuleRoue.h"


static float anglex = 0.0F ;
static float angley = 0.0F ;
static int az = 6 ;
static int a = 0 ;
static float PI = 3.14;//159265;
static float monCosinus[360];
static float monSinus[360];

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

void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor4fv(couleurNoir());
  
  //pour le recpouvremment: dessine ce qu'il faut
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

  GLUquadric* param = gluNewQuadric(); 
  
  glPushMatrix(); 
  
      manipulateurSouris();
      manipulateurClavier();
      
      //rotation de toute la scene
        glRotatef(angley,0.0F,1.0F,0.0F) ;
        glRotatef(anglex,1.0F,0.0F,0.0F) ;
       
      //création de l'avant de la loco
      glPushMatrix();
         glColor4fv(couleurRougeFonce());
         glTranslatef(-1, 0.2, 0);
         glRotatef(90, 0, 0, 1);
         solidCylindre(0.7,1.7,20,10);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-1.85, 0.2, 0);
         glRotatef(-90, 0, 1, 0);
         gluCylinder(param,0.7,0,0.3,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-2, 0.2, 0);
         gluSphere(param,0.2,20,20);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurJaune());
         glTranslatef(-2.02, 0.2, 0);
         gluSphere(param,0.19,20,20);
      glPopMatrix();
      
      //création de la cheminée
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-1.6, 1.1, 0);
         solidCylindre(0.2,0.4,20,10);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurJaune());
         glTranslatef(-1.6, 1.1, 0);
         glRotatef(-90, 1, 0, 0);  
         gluCylinder(param,0.18,0.4,0.4,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurVert());
         glTranslatef(-1.6, 1.5, 0);
         glRotatef(-90, 1, 0, 0);      
         gluCylinder(param,0.4,0.18,0.4,20,1);
      glPopMatrix();
      
      //création de la cloche
      glPushMatrix();
         glColor4fv(couleurVert());
         glTranslatef(-1.05, 1, 0);
         glRotatef(-90, 1, 0, 0);         
         gluCylinder(param,0.2,0.1,0.3,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-1.05, 1, 0);
         glRotatef(-90, 1, 0, 0);         
         gluCylinder(param,0.25,0.2,0.05,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-1.05, 1.3, 0);
         gluSphere(param,0.1,20,20);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurVert());
         glTranslatef(-1.05, 1.4, 0);
         gluSphere(param,0.07,20,20);
      glPopMatrix();
      
      //création de l'accroche cloche
      glPushMatrix();
         glColor4fv(couleurBleu());
         glTranslatef(-1.05, 1.12, 0.3);
         solidCylindre(0.025,0.6,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurBleu());
         glTranslatef(-1.05, 1.12, -0.3);
         solidCylindre(0.025,0.6,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurBleu());
         glTranslatef(-1.05, 1.4, 0);
         glRotatef(90, 1, 0, 0);
         solidCylindre(0.025,0.58,20,10);
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-1.05, 1.4, 0.3);
         gluSphere(param,0.04,20,20);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-1.05, 1.4, -0.3);
         gluSphere(param,0.04,20,20);
      glPopMatrix();
      
      //intérieur cloche
      glPushMatrix();
         glColor4fv(couleurJaune());
         glTranslatef(-1.05, 1.12, 0);
         solidCylindre(0.025,0.3,20,10); 
     glPopMatrix();
     
     glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-1.05, 1, 0);
         gluSphere(param,0.07,20,20);
      glPopMatrix();
      
      //soupape
      glPushMatrix();
         glColor4fv(couleurVert());
         glTranslatef(-0.52, 0.8, 0);
         glRotatef(-90, 1, 0, 0);         
         gluCylinder(param,0.3,0.2,0.15,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRouge());
         glTranslatef(-0.52, 1, 0);
         solidCylindre(0.2,0.2,20,10);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurRose());
         glTranslatef(-0.52, 1, 0);
         glRotatef(-90, 1, 0, 0);         
         gluCylinder(param,0.25,0.2,0.12,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurCyan());
         glTranslatef(-0.52, 1.12, 0);
         glRotatef(-90, 1, 0, 0);         
         gluCylinder(param,0.2,0.05,0.05,20,1);
      glPopMatrix();
      
      glPushMatrix();
         glColor4fv(couleurBleu());
         glTranslatef(-0.52, 1.15, 0);
         gluSphere(param,0.05,20,20);
      glPopMatrix();
      
      
      //création de la cabine
                 //création du côté
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(-0.1, 0.7, 0.75);
                     glScalef(0.2,2.4,0.1);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(1.3, 0.7, 0.75);
                     glScalef(0.2,2.4,0.1);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(0.6, 0.2, 0.75);
                     glScalef(1.2,1.4,0.1);
                    glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBleu());
                     glTranslatef(0.6, 1.8, 0.75);
                     glScalef(1.2,0.2,0.1);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 
                 glPushMatrix();
                     glColor4fv(couleurVert());
                     glTranslatef(0.025, 1.3, 0.775);
                     glScalef(0.05,0.8,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurVert());
                     glTranslatef(1.175, 1.3, 0.775);
                     glScalef(0.05,0.8,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(0.6, 0.925, 0.775);
                     glScalef(1.1,0.05,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(0.6, 1.675, 0.775);
                     glScalef(1.1,0.05,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 //création du côté en face
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(-0.1, 0.7, -0.75);
                     glScalef(0.2,2.4,0.1);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(1.3, 0.7, -0.75);
                     glScalef(0.2,2.4,0.1);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(0.6, 0.2, -0.75);
                     glScalef(1.2,1.4,0.1);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurBrun());
                     glTranslatef(0.6, 1.8, -0.75);
                     glScalef(1.2,0.2,0.1);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(0.025, 1.3, -0.775);
                     glScalef(0.05,0.8,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(1.175, 1.3, -0.775);
                     glScalef(0.05,0.8,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(0.6, 0.925, -0.775);
                     glScalef(1.1,0.05,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(0.6, 1.675, -0.775);
                     glScalef(1.1,0.05,0.15);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 //création de la face avant
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(-0.15, 1.8, 0);
                     glScalef(0.1,0.2,1.4);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(-0.15, 0.2, 0);
                     glScalef(0.1,1.4,1.4);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(-0.15, 1.3, -0.6);
                     glScalef(0.1,0.8,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(-0.15, 1.3, 0.6);
                     glScalef(0.1,0.8,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurVert());
                     glTranslatef(-0.175, 1.3, 0.475);
                     glScalef(0.15,0.8,0.05);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurVert());
                     glTranslatef(-0.175, 1.3, -0.475);
                     glScalef(0.15,0.8,0.05);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(-0.175, 0.925, 0);
                     glScalef(0.15,0.05,0.9);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(-0.175, 1.675, 0);
                     glScalef(0.15,0.05,0.9);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 //création de la face arrière (côté porte)
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(1.35, 1.8, 0);
                     glScalef(0.1,0.2,1.4);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(1.35, 0.6, -0.6);
                     glScalef(0.1,2.2,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRose());
                     glTranslatef(1.35, 0.6, 0.6);
                     glScalef(0.1,2.2,0.2);
                     glutSolidCube(1.0); 
                 glPopMatrix();
                 
                 //création du sol
                 glPushMatrix();
                     glColor4fv(couleurGrisClair());
                     glTranslatef(0.6, -0.475, 0);
                     glScalef(1.4,0.05,1.4);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //création du toit
                 glPushMatrix();
                     glColor4fv(couleurCyan());
                     glTranslatef(0.6, 2.11, 0.42);
                     glRotatef(-60, 1, 0, 0);
                     glScalef(2,1,0.05);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 glPushMatrix();
                     glColor4fv(couleurRouge());
                     glTranslatef(0.6, 2.11, -0.42);
                     glRotatef(60, 1, 0, 0);
                     glScalef(2,1,0.05);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //les pinions
               glBegin(GL_POLYGON);
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,2.35, 0);
                  
                  glColor4fv(couleurRose());
                  glVertex3f(1.4,1.9, -0.8);//sommet           
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurJaune());
                  glVertex3f(1.3,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurJaune());
                  glVertex3f(1.3,2.35, 0);
                  
                  glColor4fv(couleurJaune());
                  glVertex3f(1.3,1.9, -0.8);//sommet  
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurVert());
                  glVertex3f(-0.1,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurVert());
                  glVertex3f(-0.1,2.35, 0);
                  
                  glColor4fv(couleurVert());
                  glVertex3f(-0.1,1.9, -0.8);//sommet  
               glEnd();
               
               glBegin(GL_POLYGON);
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,1.9, 0.8);//sommet
                  
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,2.35, 0);
                  
                  glColor4fv(couleurRose());
                  glVertex3f(-0.2,1.9, -0.8);//sommet  
               glEnd();
               
               //ajout des poignees
               
               //poignee 1
               glPushMatrix();
                 glColor4fv(couleurGrisClair());
                 glTranslatef(1.5, 0.6, 0.6);
                 solidCylindre(0.03,1.2,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.45, 0, 0.6);
                 glRotatef(90, 0, 0, 1);
                 solidCylindre(0.03,0.15,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.45, 1.2, 0.6);
                 glRotatef(90, 0, 0, 1);
                 solidCylindre(0.03,0.15,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.5, 0, 0.6);
                 gluSphere(param,0.035,20,20);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.5, 1.2, 0.6);
                 gluSphere(param,0.035,20,20);
              glPopMatrix();
              
              //poignee2
              glPushMatrix();
                 glColor4fv(couleurGrisClair());
                 glTranslatef(1.5, 0.6, -0.6);
                 solidCylindre(0.03,1.2,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.45, 0, -0.6);
                 glRotatef(90, 0, 0, 1);
                 solidCylindre(0.03,0.15,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.45, 1.2, -0.6);
                 glRotatef(90, 0, 0, 1);
                 solidCylindre(0.03,0.15,20,10);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.5, 0, -0.6);
                 gluSphere(param,0.035,20,20);
              glPopMatrix();
              
              glPushMatrix();
                 glColor4fv(couleurGrisFonce());
                 glTranslatef(1.5, 1.2, -0.6);
                 gluSphere(param,0.035,20,20);
              glPopMatrix();
              
               
               
      //création des roues
                 //roue 1                
                      glPushMatrix();
                         glTranslatef(0.78, -0.65, 0.83);
                         glRotatef(a,0.0,0.0,1.0);
                         Roue(couleurNoir(), couleurVert(), couleurRouge());
                     
                     
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
                         Roue(couleurNoir(), couleurVert(), couleurRouge());
                     
                     
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
                     Roue(couleurNoir(), couleurVert(), couleurRouge());
                     
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
                     Roue(couleurNoir(), couleurVert(), couleurRouge());
                     
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
                     glColor4fv(couleurBleu());
                     glTranslatef(-0.3, -0.70, 0);
                     glScalef(3.2,0.4,0.4);
                     glutSolidCube(1.0);  
                 glPopMatrix();
                 
                 //axe roues droite////////////////////////////////////////////////////////////////////////////////
                 
                 glPushMatrix();
                     tournerRoue();
                     glTranslatef(0.06, -0.1, 0);     
                           
                           //axe entre roue 1 et roue2
                           glPushMatrix();
                                 glColor4fv(couleurJaune());
                                 glTranslatef(0, 0, 1.06);
                                 glScalef(1.35,0.14,0.1);
                                 glutSolidCube(1.0);
                           glPopMatrix();
                           
                          glPushMatrix();
                             glColor4fv(couleurJaune());
                             glTranslatef(0.7, 0, 1.07);
                             glScalef(1,1,0.5);
                             gluSphere(param,0.14,20,20);
                          glPopMatrix();
                          
                          glPushMatrix();
                             glColor4fv(couleurJaune());
                             glTranslatef(-0.6, 0, 1.07);
                             glScalef(1,1,0.5);
                             gluSphere(param,0.14,20,20);
                          glPopMatrix();
                           
                           glPushMatrix();
                                 glColor4fv(couleurGrisFonce());
                                 glTranslatef(0.7, 0, 1.15);
                                 glRotatef(90, 0, 0, 1);
                                 glScalef(0.13,0.13,1);
                                 glutSolidTorus(0.2,0.4,2,6);
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
                                 glutSolidTorus(0.2,0.4,2,6);
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
                           
                           //axe entre roue 1 et roue2
                           glPushMatrix();
                                 glColor4fv(couleurJaune());
                                 glTranslatef(0, 0, -1.06);
                                 glScalef(1.35,0.14,0.1);
                                 glutSolidCube(1.0);
                           glPopMatrix();
                           
                          glPushMatrix();
                             glColor4fv(couleurJaune());
                             glTranslatef(0.7, 0, -1.07);
                             glScalef(1,1,0.5);
                             gluSphere(param,0.14,20,20);
                          glPopMatrix();
                          
                          glPushMatrix();
                             glColor4fv(couleurJaune());
                             glTranslatef(-0.6, 0, -1.07);
                             glScalef(1,1,0.5);
                             gluSphere(param,0.14,20,20);
                          glPopMatrix();
                           
                           glPushMatrix();
                                 glColor4fv(couleurGrisFonce());
                                 glTranslatef(0.7, 0, -1.15);
                                 glRotatef(90, 0, 0, 1);
                                 glScalef(0.13,0.13,1);
                                 glutSolidTorus(0.2,0.4,2,6);
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
                                 glutSolidTorus(0.2,0.4,2,6);
                           glPopMatrix();
                           
                           glPushMatrix();
                                 glColor4fv(couleurNoir());
                                  glTranslatef(-0.6, 0, -1.13);
                                 glRotatef(90, 1, 0, 0);
                                 solidCylindre(0.08,0.045,6,10);       
                          glPopMatrix();
                          
                     glPopMatrix();
                  /////////////////////////////////////////////////////////////////////////// 
                       
                 
                 //pointe
                 //fixation
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
                 
                 
      
      
  glPopMatrix();
  

  glFlush();
  glutSwapBuffers();
} 
  
void myinit(void) { 
  glClearColor(1.0,1.0,1.0,1.0);
} 
  
void special(int key,int x,int y) {
  switch(key) {
    case GLUT_KEY_UP    : anglex--; 
                          break;
    case GLUT_KEY_DOWN  : anglex++; 
                          break;
    case GLUT_KEY_LEFT  : angley--; 
                          break;
    case GLUT_KEY_RIGHT : angley++; 
                          break; }
  glutPostRedisplay() ;
}

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'a':
      az = (az+ 5)%360;
      a = a+5;
      glutPostRedisplay() ;
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
    exit(0);
    
   }
}
int main(int argc,char **argv) {
  trigo();
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(500,500); 
  glutInitWindowPosition(100,100); 
  glutCreateWindow("Petit train"); 
  myinit();
  
  //pour le recouvrement
  glEnable(GL_DEPTH_TEST) ;
  
  creationMenuBasique();
  setParametresPerspectiveBasique(65.0F,1.0F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  setManipulateurDistance(5.0F);
  glutReshapeFunc(reshapePerspectiveBasique);
  glutKeyboardFunc(keyBasique);
  glutSpecialFunc(special);
  
  glutMotionFunc(motionBasique);
  glutMouseFunc(sourisBasique);
  glutDisplayFunc(display);
  
  //pour faire tounrer les roues
  glutKeyboardFunc(clavier);
  
  glutMainLoop();
  return(0);
}


