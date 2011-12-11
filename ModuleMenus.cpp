
/* Gestion des menus                */


#include "ModuleMenus.h"

float *couleurCylindre = NULL;
float *couleurAvant = NULL;
float *couleurOptique = NULL;
float *couleurPhare = NULL;
float *couleurGdPhare = NULL;
float *couleurGdPhare2 = NULL;
float *couleurToit = NULL;
float *couleurCadre = NULL;
float *couleurMur = NULL;
float *couleurFlanRoue = NULL;
float *couleurRoueInterieur = NULL;
float *couleurRoueExterieur = NULL;
float *couleurAxe = NULL;
float *couleurGrille = NULL;
float *couleurSol = NULL;
float *couleurCloche1 = NULL;
float *couleurCloche2 = NULL;
float *couleurClocheAccroche = NULL;
float *couleurClocheBaton = NULL;
float *couleurChemine = NULL;
float *couleurSoupape1 = NULL;
float *couleurSoupape2 = NULL;
float *couleurWagon1 = NULL;
float *couleurWagon2 = NULL;
void(*effetComplexOr)() = NULL;
void(*effetComplexChrome)() = NULL;
void(*effetComplexArgent)() = NULL;

void select(int selection) 
{
    switch (selection) 
    {
        case 0 :
            exit(0); 
    }
    glutPostRedisplay();
}

void selectCouleur(int selection)
{
    switch(selection)
    {
        case 11:
            themeFille();
            break;
        case 12:
             themeGarcon();
            break;
        case 13:
            themeCourse();
            break;
        case 14:
            break;
    }
    glutPostRedisplay();
}

void creationMenuBasique(void)
{
    int menuCouleur = glutCreateMenu(selectCouleur);
    glutAddMenuEntry("Fille", 11);
    glutAddMenuEntry("Garcon", 12);
    glutAddMenuEntry("Course", 13);
    glutAddMenuEntry("Vieux", 14);
    
    glutCreateMenu(select);
    glutAddSubMenu("Mode", menuCouleur);
    glutAddMenuEntry("Quitter",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void themeCourse()
{
    couleurCylindre = couleurCourseCylindre;
    couleurAvant = couleurCourseAvant;
    couleurOptique = couleurCourseOptique;
    couleurPhare = couleurCoursePhare;
    couleurGdPhare = couleurCourseGdPhare;
    couleurGdPhare2 = couleurCourseGdPhare2;
    couleurToit = couleurCourseToit;
    couleurCadre = couleurCourseCadre;
    couleurMur = couleurCourseMur;
    couleurFlanRoue = couleurCourseFlanRoue;
    couleurRoueInterieur = couleurCourseRoueInterieur;
    couleurRoueExterieur = couleurCourseRoueExterieur;
    couleurAxe = couleurCourseAxe;
    couleurGrille = couleurCourseGrille;
    couleurSol = couleurCourseSol;
    couleurCloche1 = couleurCourseCloche1;
    couleurCloche2 = couleurCourseCloche2;
    couleurClocheAccroche = couleurCourseClocheAccroche;
    couleurClocheBaton = couleurCourseClocheBaton;
    couleurChemine = couleurCourseChemine;
    couleurSoupape1 = couleurCourseSoupape1;
    couleurSoupape2 = couleurCourseSoupape2;
    couleurWagon1 = couleurCourseWagon1;
    couleurWagon2 = couleurCourseWagon2;
    
   	effetComplexOr = &effetOr;
	effetComplexChrome = &effetChrome;
	effetComplexArgent = &effetArgent;
}

void themeFille()
{
    couleurCylindre = couleurFilleCylindre;
    //printf("%d, %d, %d\n",couleurCylindre[0], couleurCylindre[1], couleurCylindre[2]);
    couleurAvant = couleurFilleAvant;
    couleurOptique = couleurFilleOptique;
    couleurPhare = couleurFillePhare;
    couleurGdPhare = couleurFilleGdPhare;
    couleurGdPhare2 = couleurFilleGdPhare2;
    couleurToit = couleurFilleToit;
    couleurCadre = couleurFilleCadre;
    couleurMur = couleurFilleMur;
    couleurFlanRoue = couleurFilleFlanRoue;
    couleurRoueInterieur = couleurFilleRoueInterieur;
    couleurRoueExterieur = couleurFilleRoueExterieur;
    couleurAxe = couleurFilleAxe;
    couleurGrille = couleurFilleGrille;
    couleurSol = couleurFilleSol;
    couleurCloche1 = couleurFilleCloche1;
    couleurCloche2 = couleurFilleCloche2;
    couleurClocheAccroche = couleurFilleClocheAccroche;
    couleurClocheBaton = couleurFilleClocheBaton;
    couleurChemine = couleurFilleChemine;
    couleurSoupape1 = couleurFilleSoupape1;
    couleurSoupape2 = couleurFilleSoupape2;
    couleurWagon1 = couleurFilleWagon1;
    couleurWagon2 = couleurFilleWagon2;
    
   	effetComplexOr = &effetPlastique;
	effetComplexChrome = effetComplexOr;
	effetComplexArgent = effetComplexOr;
}

 void themeGarcon()
{
    couleurCylindre = couleurGarconCylindre;
    //printf("%d, %d, %d\n",couleurCylindre[0], couleurCylindre[1], couleurCylindre[2]);
    couleurAvant = couleurGarconAvant;
    couleurOptique = couleurGarconOptique;
    couleurPhare = couleurGarconPhare;
    couleurGdPhare = couleurGarconGdPhare;
    couleurGdPhare2 = couleurGarconGdPhare2;
    couleurToit = couleurGarconToit;
    couleurCadre = couleurGarconCadre;
    couleurMur = couleurGarconMur;
    couleurFlanRoue = couleurGarconFlanRoue;
    couleurRoueInterieur = couleurGarconRoueInterieur;
    couleurRoueExterieur = couleurGarconRoueExterieur;
    couleurAxe = couleurGarconAxe;
    couleurGrille = couleurGarconGrille;
    couleurSol = couleurGarconSol;
    couleurCloche1 = couleurGarconCloche1;
    couleurCloche2 = couleurGarconCloche2;
    couleurClocheAccroche = couleurGarconClocheAccroche;
    couleurClocheBaton = couleurGarconClocheBaton;
    couleurChemine = couleurGarconChemine;
    couleurSoupape1 = couleurGarconSoupape1;
    couleurSoupape2 = couleurGarconSoupape2;
    couleurWagon1 = couleurGarconWagon1;
    couleurWagon2 = couleurGarconWagon2;
    
   	effetComplexOr = &effetPlastique;
	effetComplexChrome = effetComplexOr;
	effetComplexArgent = effetComplexOr;
}

void effetOr()
{
     GLfloat cAmbient[] = {0.24725,0.1995,0.0745,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {0.75164,0.60648,0.22648,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0.628281,0.555802,0.366065,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 51.2;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}

void effetChrome()
{
     GLfloat cAmbient[] = {0.25,0.25,0.25,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {0.4,0.4,0.4,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0.774597,0.774597,0.774597,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 76.8;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}

void effetArgent()
{
     GLfloat cAmbient[] = {0.19225,0.19225,0.19225,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {0.50754,0.50754,0.50754,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0.508273,0.508273,0.508273,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 51.2;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}

void effetPlastique()
{
     GLfloat cAmbient[] = {0.02,0.02,0.02,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cAmbient);
     GLfloat cDiffuse[] = {0.01,0.01,0.01,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cDiffuse);
     GLfloat cSpec[] = {0.4,0.4,0.4,1.0};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cSpec);
     GLfloat cShin = 10;
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cShin);
}
