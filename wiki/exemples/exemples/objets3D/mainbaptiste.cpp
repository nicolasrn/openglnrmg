/* 
TP4, Carine Baptiste, Pierre Rozanski
interration: 
  - souris + bouton gauche enfoncé: rotation de l'utilisateur autour du gyroscope.
  - click droit -> accès au menu
          vue: changement du point de vue (la rotation de l'utilisateur fonctionne 
          toujours, mais ne sauvegarde pas vraiment la position initiale)
          Quitter: ...
*/


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "../modulesutilitaires/ModuleCouleurs.h"
#include "../modulesutilitaires/ModuleManipulateur.h"
#include "../modulesutilitaires/ModuleMenus.h"
#include "../modulesutilitaires/ModuleReshape.h"

static int year = 0;
static int day = 0; 
static int rotationlune = 0; 

int camera_angle_longitude;
int camera_angle_latitude;
char presse;
int anglex,angley,x,y,xold,yold;
float distance_camera = 5;


float camera_x = 5.0;
float camera_y = 0.0;
float camera_z = 0.0;
float orientation_x = 0.0;
float orientation_y = 1.0;
float orientation_z = 0.0;



float angle_1 = 0.0;
float angle_2 = 0.0;
float angle_3 = 0.0;

// les identifiants des fenetres
int fenetre_1;

// fonction permettant le rafraichissement de toutes les vues
void rafraichir_vues(void) {
  glutPostWindowRedisplay(fenetre_1);
}

void key(unsigned char key,int x,int y) {
  if ( keyManipulateur(key,x,y) )
    glutPostRedisplay();
    else
    switch ( key ) {
      case '2' : day = (day + 10) % 360;
                 rafraichir_vues();
                 break;
      case '8' : day = (day - 10) % 360;
                 rafraichir_vues();
                 break;
      case '4' : year = (year + 5) % 360;
                 rafraichir_vues();
                 break;
      case '6' : year = (year - 5) % 360;
                 rafraichir_vues();
                 break; }
}

// definition d'un materiau rouge
void materiau_2(){
     GLfloat diffu[] = {0.7,0.0,0.0,1.0};
     GLfloat specular[] = {1.0,0.8,0.8,1.0};
     GLfloat ambiant[] = {0.2,0.0,0.0,1.0};
     GLfloat  shininess[] = {70.0F};
     glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,diffu);
     glMaterialfv(GL_FRONT,GL_AMBIENT,ambiant);
     glMaterialfv(GL_FRONT,GL_SHININESS,shininess);
}

// definition d'un materiau gris
void materiau_1(){
     GLfloat diffu[] = {0.6,0.6,0.6,1.0};
     GLfloat specular[] = {1.5,1.5,1.5,1.0};
     GLfloat ambiant[] = {0.2,0.2,0.2,1.0};
     GLfloat  shininess[] = {10.0F}; 
     glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,diffu);
     glMaterialfv(GL_FRONT,GL_AMBIENT,ambiant);
     glMaterialfv(GL_FRONT,GL_SHININESS,shininess);
}

// création d'un cylindre
void solidCylindre(float r,float h,int n,int m) {
  glPushMatrix();
  glRotatef(90.0F,1.0F,0.0F,0.0F);
  glTranslatef(0.0F,0.0F,-h/2);
  GLUquadricObj *qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj,GLU_FILL);
  gluCylinder(qobj,r,r,h,n,m);
  gluDeleteQuadric(qobj);  
  glPopMatrix();
}


void gyroscope(){
// la partie mobile de l'objet
  glPushMatrix();
  // une homothétie est utilisée pour faire rentrer l'objet dans le champ de vision.
  glScalef(0.75,0.75,0.75);
  glTranslatef(0.0F,0.3F,0.0F) ;
  
  // début matrice anneau 1
  glPushMatrix();
  glRotatef(angle_1,0.0F,1.0F,0.0F) ;
  
  // début matrice anneau 2
  glPushMatrix();
  glRotatef(angle_2,1.0F,0.0F,0.0F) ;
  
  // début matrice theière
  glPushMatrix();
  glRotatef(angle_3,0.0F,1.0F,0.0F) ;
  
  
  //création de la théière
  glPushMatrix() ;
  glTranslatef(0.0F,0.0F,0.0F) ;
  // definition de matériaux
  materiau_2();
  glutSolidTeapot(0.2);
  glPopMatrix() ;
  
  // - fin matrice theiere
  glPopMatrix() ;
  
  // axe de la théière
  materiau_1();
  solidCylindre(0.02,0.8,5,5);
  
  // anneau interne
  glutSolidTorus(0.035,0.42,15,30) ;
  
  // - fin matrice anneau 2
  glPopMatrix() ;
  
  // anneau externe
  glutSolidTorus(0.035,0.55,15,30) ;
  
  // axe 1
  glPushMatrix() ;
  glRotatef(90,0.0F,0.0F,1.0F) ;
  glTranslatef(0.0F,0.5F,0.0F) ;
  solidCylindre(0.02,0.15,5,5);
  glPopMatrix() ;
  
  // axe 2
  glPushMatrix() ;
  glRotatef(90,0.0F,0.0F,1.0F) ;
  glTranslatef(0.0F,-0.5F,0.0F) ;
  solidCylindre(0.02,0.15,5,5);
  glPopMatrix() ;
   
  
  // axe bas
  glPushMatrix() ;
  glTranslatef(0.0F,-0.65F,0.0F) ;
  solidCylindre(0.02,0.15,5,5);
  glPopMatrix() ;
  
  // - fin matrice anneau 1
  glPopMatrix() ;
  
  // pied
  glPushMatrix() ;
  glTranslatef(0.0F,-0.9F,0.0F) ;
  solidCylindre(0.07,0.4,5,5);
  glPopMatrix() ;
  
  // le socle: 
  glPushMatrix() ;
  glTranslatef(0.0F,-1.1F,0.0F) ;
  glScalef(1.0,0.1,1.0);
  glutSolidCube(0.9) ;
  glPopMatrix() ;
  
  glPopMatrix() ;     
}

// definition de la géométrie
// fonction appelée par les fonction d'affichage
void dessiner_geometrie(){
     gyroscope();
     

  
  glPushMatrix(); 
  glRotatef((GLfloat) year,0.0,1.0,0.0); 
  glTranslatef(2.0,0.0,0.0);
  glRotatef((GLfloat) day,0.0,1.0,0.0);
  
  
  glutSolidSphere(0.2,20,20); 
  
  glPushMatrix(); 
  glRotatef((GLfloat) rotationlune,0.0,1.0,0.0); 
  glTranslatef(0.4,0.0,0.0);
  glutSolidSphere(0.05,15,15); 
  glPopMatrix();

  
  glPopMatrix();
}

void display(void) { 
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
           
           
   gluLookAt (camera_x, camera_y, camera_z, 0.0, 0.0, 0.0, orientation_x, orientation_y, orientation_z);

   dessiner_geometrie();


  glutSwapBuffers();
} 


  
void myinit(void) { 
    glClearColor(0.0,0.0,0.0,1.0);
  glEnable(GL_DEPTH_TEST) ;
  glEnable(GL_LIGHTING) ;
  glEnable(GL_LIGHT0) ;
  glEnable(GL_AUTO_NORMAL) ;
  glEnable(GL_NORMALIZE) ;
  float dir[] = { 0.1F,0.8F,1.6F,0.0F } ;
  glLightfv(GL_LIGHT0,GL_POSITION,dir) ;
   glShadeModel (GL_SMOOTH);   
} 

void selectVue(int selection) {
  switch (selection) {
  // dessus
  case 1  : camera_x = 0.0;
              camera_y = 10.0;
              camera_z = 0.0;
              orientation_x = 1.0;
              orientation_y = 0.0;
              orientation_z = 0.0; break;
  // face
    case 2  : camera_x = 0.0;
              camera_y = 0.0;
              camera_z = 10.0;
              orientation_x = 0.0;
              orientation_y = 1.0;
              orientation_z = 0.0; break;
    // Coté droit
    case 3  : camera_x = 10.0;
              camera_y = 0.0;
              camera_z = 0.0;
              orientation_x = 0.0;
              orientation_y = 1.0;
              orientation_z = 0.0; break;
    //derrière
    case 4  : camera_x = 0.0;
              camera_y = 0.0;
              camera_z = -10.0;
              orientation_x = 0.0;
              orientation_y = 1.0;
              orientation_z = 0.0; break;   
    // dessous
    case 5  : camera_x = 0.0;
              camera_y = -10.0;
              camera_z = 0.0;
              orientation_x = 1.0;
              orientation_y = 0.0;
              orientation_z = 0.0; break;    
    // Coté gauche
    case 6  : camera_x = -10.0;
              camera_y = 0.0;
              camera_z = 0.0;
              orientation_x = 0.0;
              orientation_y = 1.0;
              orientation_z = 0.0; break;   
    case 0  : exit(0); }
  rafraichir_vues();
}

void select(int selection) {
  switch (selection) {
    case 0  : exit(0); }
  rafraichir_vues();
}


void menu(){
    
    int menuVue = glutCreateMenu(selectVue);
    glutAddMenuEntry("Dessus",1);
    glutAddMenuEntry("Face",2);
    glutAddMenuEntry("Coté droit",3);
    glutAddMenuEntry("Derrière",4);
    glutAddMenuEntry("Dessous",5);
    glutAddMenuEntry("Coté gauche",6);
    
    glutCreateMenu(select);
    glutAddSubMenu("Vue",menuVue);
    glutAddMenuEntry("Quitter",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void idle(){
     angle_1 = angle_1 + 1;
     angle_2 = angle_2 + 1;
     angle_3 = angle_3 + 1;
     year ++;
     day ++;
     rotationlune ++;
     glutPostWindowRedisplay(fenetre_1);
}

// calcul les paramatres de glulookat en fonction de l'entree souris
void calculer_position_camera(){
     camera_x = cos(camera_angle_longitude/100.0) * distance_camera * cos(camera_angle_latitude/100.0);
     camera_z = sin(camera_angle_longitude/100.0) * distance_camera * cos(camera_angle_latitude/100.0);
     camera_y = sin(camera_angle_latitude/100.0) * distance_camera;
}

void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y)
  {
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      camera_angle_longitude=camera_angle_longitude+(x-xold); 
      camera_angle_latitude=camera_angle_latitude+(y-yold);
      calculer_position_camera();
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
    
    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
  }
  
int main(int argc,char **argv) {
  glutInit(&argc,argv);
    
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);

  glutInitWindowSize(600,600); 
  glutInitWindowPosition(50,50); 
  fenetre_1 = glutCreateWindow("Système Terre-Lune"); 
  myinit(); 
  menu();
  setParametresPerspectiveBasique(36.0F,1.5F,1.0F,20.0F,0.0F,0.0F,-5.0F);
  setManipulateurDistance(5.0F);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
    glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);
  
  
  glutMainLoop();
  return(0);
}

