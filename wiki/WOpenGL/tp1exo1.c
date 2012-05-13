#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>


int couleur;

void GereMenuPrincipal(int valeur)
    {
    switch(valeur)
        {
        case 10: glFlush();
            break;
        case 11: exit(0);
        }
    }

void GereMenuCouleur(int valeur)
    {
    switch(valeur)
        {
        case 1: glClearColor(0,0,0,1);couleur=1;
            break;
        case 2: glClearColor(1,0,0,1);couleur=2;
            break;
        case 3: glClearColor(0,1,0,1);couleur=3;
            break;
        case 4: glClearColor(0,0,1,1);couleur=4;
            break;
        case 5: glClearColor(1,1,1,1);couleur=5;
            break;
        }
    glClear(GL_COLOR_BUFFER_BIT);glFlush();
    }

void CreerMenu()
    {
    int id_sous_menu_couleur;
    id_sous_menu_couleur=glutCreateMenu(GereMenuCouleur);
    /* Articles de sous-menus */
    glutAddMenuEntry("Noir",1);
    glutAddMenuEntry("Rouge",2);
    glutAddMenuEntry("Vert",3);
    glutAddMenuEntry("Bleu",4);
    glutAddMenuEntry("Blanc",5);
    
    /* Création du menu principal */
    glutCreateMenu(GereMenuPrincipal);
    glutAddSubMenu("Couleur",id_sous_menu_couleur);
    glutAddMenuEntry("Rafraîchir",10);
    glutAddMenuEntry("Quitter",11);
    /* Associer le bouton droit aux sous-menus */
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
    
    

void affichage(void)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    }

void redim(int l,int h)
    {
    glViewport(0,0,l,h);
    }

void souris(int button,int state,int x,int y)
    {
    switch(button)
        {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                couleur=(couleur)%5+1;
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
                {
                glClearColor(1,1,0,1);
                glutPostRedisplay(); /* glPostRedisplay(); */
                return;
                }
        }
    switch(couleur)
        {
        case 1: glClearColor(0,0,0,1);
            break;
        case 2: glClearColor(1,0,0,1);
            break;
        case 3: glClearColor(0,1,0,1);
            break;
        case 4: glClearColor(0,0,1,1);
            break;
        case 5: glClearColor(1,1,1,1);
            break;
        }
    glClear(GL_COLOR_BUFFER_BIT);glFlush();
    }

void clavier(unsigned char key,int x,int y)
    {
    switch(key)
        {
        case '1': glClearColor(0,0,0,1);couleur=1;
            break;
        case '2': glClearColor(1,0,0,1);couleur=2;
            break;
        case '3': glClearColor(0,1,0,1);couleur=3;
            break;
        case '4': glClearColor(0,0,1,1);couleur=4;
            break;
        case '5': glClearColor(1,1,1,1);couleur=5;
            break;
        case 27: exit(0);
        }
    glClear(GL_COLOR_BUFFER_BIT);glFlush();
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
    glutCreateWindow("Premier essai");
    
    /* Association d'évènements */
    glutDisplayFunc(affichage);
    glutReshapeFunc(redim);
    glutKeyboardFunc(clavier);
    glutMouseFunc(souris);
    
    /* Initialisation de OpenGL */
    glClearColor(1,0,0,1);
    couleur=2;
    
    CreerMenu();
    
    glutMainLoop();

    return 0;
    }
    
