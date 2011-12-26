#include "MonModuleSouris.h"

using namespace std;

static int sourisPresse = 0, 
    sourisxold = 0,
    sourisyold = 0;

int sourisanglex = 0;
int sourisangley = 0;

void mouse(int button, int state,int x,int y)
{
#if defined(debug_souris) && debug_souris == 1
    cout << "dans le mouse" << endl;
#endif
    /* si on appuie sur le bouton gauche */
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
#if defined(debug_souris) && debug_souris == 1
        cout << "clique" << endl;
#endif
        sourisPresse = 1; /* le booleen presse passe a 1 (vrai) */
        sourisxold = x; /* on sauvegarde la position de la souris */
        sourisyold = y;
    }
    /* si on relache le bouton gauche */
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
#if defined(debug_souris) && debug_souris == 1
        cout << "relache" << endl;
#endif
        sourisPresse = 0; /* le booleen presse passe a 0 (faux) */
    }
}

void mousemotion(int x,int y)
{
    if (sourisPresse) /* si le bouton gauche est presse */
    {
#if defined(debug_souris) && debug_souris == 1
        cout << "presse" << endl;
#endif
        /* on modifie les angles de rotation de l'objet
        en fonction de la position actuelle de la souris et de la derniere
        position sauvegardee */
        sourisanglex = sourisanglex + (x - sourisxold); 
        sourisangley = sourisangley + (y - sourisyold);
#if defined(debug_souris) && debug_souris == 1
        cout << "sourisx, sourisxold (" << x << ", " << sourisxold << ")" << endl;
        cout << "sourisy, sourisyold (" << y << ", " << sourisyold << ")" << endl;
        cout << "sourisanglex, sourisangley (" << sourisanglex << ", " << sourisangley << ")" << endl;
        cout << "------------------------------" << endl;
#endif
        glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
    
    sourisxold = x; /* sauvegarde des valeurs courante de le position de la souris */
    sourisyold = y;
}

void doActionSouris()
{
    glRotatef(-sourisangley, 1.0, 0.0, 0.0);
    glRotatef(-sourisanglex, 0.0, 1.0, 0.0);
}
