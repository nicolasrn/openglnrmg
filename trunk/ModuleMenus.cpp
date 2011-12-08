
/* Gestion des menus                */


#include "ModuleMenus.h"

using namespace std;

static  void select(int selection) 
{
    switch (selection) 
    {
        case 0 :
            exit(0); 
    }
    glutPostRedisplay();
}

static  void selectCouleur(int selection)
{
    switch(selection)
    {
        case 11:
            themeFille();
            break;
        case 12:
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

static  void themeCourse()
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
}

static  void themeFille()
{
    couleurCylindre = couleurFilleCylindre;
    cout << couleurCylindre[0] << " " << couleurCylindre[1] << " " << couleurCylindre[2] << " " << endl;
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
}
