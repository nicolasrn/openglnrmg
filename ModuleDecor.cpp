#include "ModuleDecor.h"
#include "ModuleCylindres.h"

using namespace std;

GLUquadric* param = gluNewQuadric(); 
  
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
/*
void creerTerrain(GLuint *tabTexture)
{
    if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glColor3fv(couleurBlanc(1));
            glTranslatef(0, -2.1, 0);
            //glRotatef(90, 0, 0, 1);
            glRotatef(90, 1, 0, 0);
            //glScalef(100, 100, 100);
            
            glBindTexture(GL_TEXTURE_2D, tabTexture[0]);
            //monGlutSolidCube(1, 10, &NormalSol);
            creerSol(100);
        glPopMatrix();
        
//ici test == 1 donc on est dans le else 
//utilisé juste pour voir la différence
//bien sur selon les murs la lumière est différente
#if defined(testTerrain) && !testTerrain
        glPushMatrix();
            glColor3fv(couleurBlanc(0));
            glTranslatef(0, 26/2, 0);
            glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
            //glTranslatef(50, 0, 0);
            //glScalef(1, 100, 100);
            //monGlutSolidCube(100, 5);
            solidCylindre(50, 30, 20, 1, true);
        glPopMatrix();
#else
        glPushMatrix();
            glColor3fv(couleurBlanc(1));
            glTranslatef(0, 22.5, 0);
            //glScalef(100, 100, 100);
            glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
            glPushMatrix();
                glTranslatef(-50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1, 1); //Ouest
            glPopMatrix();
            
            glPushMatrix();
                glTranslatef(50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1, 1); //Est
            glPopMatrix();
            
            glPushMatrix();
                glRotatef(90, 0, 1, 0);
                glTranslatef(-50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1, 1); //Sud
            glPopMatrix();
            
            glPushMatrix();
                glRotatef(90, 0, 1, 0);
                glTranslatef(50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1, 1); //Nord
            glPopMatrix();
        glPopMatrix();
#endif
	if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
}
//*/
void creerTerrain(GLuint *tabTexture, int index)
{
        glPushMatrix();
            if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
            glColor3fv(couleurBlanc(1));
            glTranslatef(0, -1.78, 0);
            //glRotatef(90, 0, 0, 1);
            //glScalef(1, 100, 100);
            
            if (tabTexture != NULL)
                glBindTexture(GL_TEXTURE_2D, tabTexture[0]);
            //glCallList(index);
            
            for(int i = -49; i <= 49; i++)
            {
                for(int j = -49; j <= 49; j++)
                {
                    glPushMatrix();
                        glTranslatef(i*1, 0, j*1);
                        
                        //soleil
                        //*
                        monGlutSolidCube(1, 1, i*1, j*1);
                        //*/
                        
                        //phare
                        /*
                        if (i - j > 0)
                            monGlutSolidCube(1, 1, &NormalSolPos);
                        else
                            monGlutSolidCube(1, 1, &NormalSolNeg);
                        //*/
                        
                    glPopMatrix();
                }
            }
            
            /*for(int i = -49; i <= 49; i++)
            {
                for(int j = -49; j <= 49; j++)
                {
                    glPushMatrix();
                        glTranslatef(i, 0, j);
                        if (0 < angleTrain && angleTrain < 90)
                            monGlutSolidCube(1, 1, &NormalSolNeg);
                        else if (90 < angleTrain && angleTrain < 180)
                            monGlutSolidCube(1, 1, &NormalSolNeg);
                            
                        else if (180 < angleTrain && angleTrain < 270)
                            monGlutSolidCube(1, 1, &NormalSolPos);
                        else if (270 < angleTrain && (angleTrain < 360 || angleTrain > 0))
                            monGlutSolidCube(1, 1, &NormalSolPos);
                        else
                            monGlutSolidCube(1, 1);
                        
                            //attention selon que l'on se trouve dans la partie z > 0 => 1 sinon -1 
                    glPopMatrix();
                }
            }*/ 
	       if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
        glPopMatrix();

        glPushMatrix();
            glColor3fv(couleurBlanc(1));
            glTranslatef(0, (50-2.78)/2, 0);
            //glScalef(100, 100, 100);
            glPushMatrix();
    	        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                glTranslatef(-50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1); //Ouest
    	        if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
            glPopMatrix();
            
            glPushMatrix();
    	        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                glTranslatef(50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1); //Est
    	        if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
            glPopMatrix();
            
            glPushMatrix();
    	        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                glRotatef(90, 0, 1, 0);
                glTranslatef(-50, 0, 0);
                glScalef(1, 50, 100);
                monGlutSolidCube(1); //Sud
    	        if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
            glPopMatrix();
            
            glPushMatrix();
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glPushMatrix() ;
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(50, 0, 0);
                    glPushMatrix();
                        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurBlanc(0)) ;
                        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                        if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                        glScalef(1, 50, 100);
                        monGlutSolidCube(1, 1); //Nord
        	            if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
                    glPopMatrix();
                    
                    //zone transparente
                    glPushMatrix();
                        glDisable(GL_COLOR_MATERIAL);
                        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, couleurBlanc(0.1)) ;
                        glRotatef(90, 0, 0, 1);
                        glTranslatef(0, 1.1, 0);
                        //glScalef(0.1, 1, 0.1);
                        creerMur(25, 50, 1, 5);
                    glPopMatrix();
                    glEnable(GL_COLOR_MATERIAL);
                    remiseZero();
                    glDisable(GL_BLEND);
                glPopMatrix() ;
                /*
                glPushMatrix();
        	        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                    if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(50, 0, 0);
                    glRotatef(90, 0, 0, 1);
                    double mx = 49/2+1, my = 49;
                    creerMur(mx, my, 1, 5);
    	            if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                
                glPushMatrix();
        	        if (tabTexture != NULL) glEnable(GL_TEXTURE_2D);
                    if (tabTexture != NULL) glBindTexture(GL_TEXTURE_2D, tabTexture[1]);
                    glRotatef(90, 0, 1, 0);
                    glTranslatef(50, 0, 0);
                    glScalef(1, 50, 100);
                    monGlutSolidCube(1, 1); //Nord
    	            if (tabTexture != NULL) glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                //*/
            glPopMatrix();
        glPopMatrix();
}
//*/

void creerMur(int mx, int my, int taille, int tailleTexture)
{ 
    for(int i = -mx; i <= mx; i++) // il faut aussi le i*taille et j*taille
    {
        for(int j = -my; j <= my; j++)
        {
            glPushMatrix();
                int posx = i*taille, posy = j*taille;
                glTranslatef(posx, 0, posy);
                monGlutSolidCube(taille, tailleTexture, posx, posy);
            glPopMatrix();
        }
    }
}

void creerSapin()
{
     glPushMatrix();
         glPushMatrix();
        		glColor4fv(newCouleur(0.03543,0.322834,0.15748,1));
        		glRotatef(90, 1, 0, 0);  
        		gluCylinder(param,0.5,1,1,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(newCouleur(0.03543,0.322834,0.15748,1));
        		glTranslatef(0, 1, 0); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.3,0.7,1,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(newCouleur(0.03543,0.322834,0.15748,1));
        		glTranslatef(0, 2, 0); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0,0.5,1,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(newCouleur(0.34645,0.1614,0,1));
        		glTranslatef(0, -0.5, 0); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.2,0.2,1,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(newCouleur(0.34645,0.1614,0,1));
        		glTranslatef(0, -1.5, 0); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.18,0.6,0.1,20,1);
     	 glPopMatrix();
   	 glPopMatrix();
}

void creerMouton()
{
     glPushMatrix();
     
         glPushMatrix();
             glColor4fv(couleurRose());
             glScalef(1.6,1.1,1);
             //glTranslatef(0, 0.4, 0.6);
             gluSphere(param,1,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, 1, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, -1, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, 0.95, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, -0.95, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, 0.95, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, -0.95, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.2, 0.9, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.2, -0.9, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.2, 0.9, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.2, -0.9, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.2, 0.9, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.2, -0.9, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.2, 0.9, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.2, -0.9, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, 0.85, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, -0.85, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, 0.85, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, -0.85, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, 0.85, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, -0.85, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, 0.85, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, -0.85, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, 0.75, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, -0.75, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, 0.75, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, -0.75, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, 0.75, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, -0.75, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, 0.75, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, -0.75, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, 0.6, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, -0.6, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, 0.6, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, -0.6, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 0.6, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, -0.6, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 0.6, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, -0.6, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
     
     glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.8, 0.4, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.8, -0.4, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.8, 0.4, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.8, -0.4, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.8, 0.4, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.8, -0.4, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.8, 0.4, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.8, -0.4, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, 0.85, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, -0.85, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, 0.85, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, -0.85, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, 0.7, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, -0.7, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, 0.7, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, -0.7, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, 0.55, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, -0.55, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, 0.55, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, -0.55, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(2, 0, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-2, 0, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.9, 0, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.9, 0, 0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.9, 0, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.9, 0, -0.4);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, -0.8, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, 0.8, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, -0.8, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, 0.8, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, -0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, 0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, -0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.4, 0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, -0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, 0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, -0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.4, 0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, -0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, 0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, -0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.8, 0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, -0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, 0.7, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, -0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.8, 0.7, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, -0.6, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, 0.6, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, -0.6, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.2, 0.6, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, -0.6, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, 0.6, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, -0.6, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.2, 0.6, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, -0.5, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, 0.5, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, -0.5, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.6, 0.5, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, -0.5, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, 0.5, 0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, -0.5, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.6, 0.5, -0.6);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, 0, 0.7);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 0, 0.7);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 0, -0.7);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1.4, 0, -0.7);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, 0.2, 0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, 0.2, 0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, 0.2, -0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, 0.2, -0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, -0.2, 0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, -0.2, 0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1, -0.2, -0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-1, -0.2, -0.8);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, 0.2, 0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, 0.2, 0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, 0.2, -0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, 0.2, -0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
           glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, -0.2, 0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, -0.2, 0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0.6, -0.2, -0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(-0.6, -0.2, -0.9);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, 0.2, 1);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, -0.2, 1);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, 0.2, -1);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(0, -0.2, -1);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          
          //tête
          
          glPushMatrix();
             glColor4fv(couleurRose());
             glScalef(1.6,1.1,1);
             glTranslatef(1.3, 1.1, 0);
             gluSphere(param,0.6,20,20);
          glPopMatrix();
          
          //oreilles
          
          glPushMatrix();
             glColor4fv(couleurRose());
             glTranslatef(1.7, 1.6, 0.5);
             glRotatef(45, 1,0,0);
             glScalef(0.7,2,1);             
             gluSphere(param,0.2,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurRose());
             glTranslatef(1.7, 1.6, -0.5);
             glRotatef(-45, 1,0,0);
             glScalef(0.7,2,1);             
             gluSphere(param,0.2,20,20);
          glPopMatrix();
          
          //yeux
          glPushMatrix();
             glColor4fv(couleurNoir());
             glTranslatef(2.2, 1.5, 0.5);
             gluSphere(param,0.1,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurNoir());
             glTranslatef(2.2, 1.5, -0.5);           
             gluSphere(param,0.1,20,20);
          glPopMatrix();
          
          //cheveux
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.7, 1.6, 0);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 1.3, 0.2);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurBlanc());
             glTranslatef(1.4, 1.3, -0.2);
             gluSphere(param,0.4,20,20);
          glPopMatrix();
          
          //jambes
          glPushMatrix();
        		glColor4fv(couleurRose());
        		glTranslatef(1, -0.9, 0.6); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.2,0.2,1.5,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(couleurRose());
        		glTranslatef(1, -0.9, -0.6); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.2,0.2,1.5,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(couleurRose());
        		glTranslatef(-1, -0.9, 0.6); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.2,0.2,1.5,20,1);
     	 glPopMatrix();
     	 
     	 glPushMatrix();
        		glColor4fv(couleurRose());
        		glTranslatef(-1, -0.9, -0.6); 
                glRotatef(90, 1, 0, 0);
                gluCylinder(param,0.2,0.2,1.5,20,1);
     	 glPopMatrix();
          
          
     glPopMatrix();
}

 void creerMaison()
 {
      glPushMatrix();
          glPushMatrix();
            glColor4fv(newCouleur(1,0.9568,0.55294,1));
    		glScalef(6,4,4);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          //le toit
          glPushMatrix();
            glColor4fv(newCouleur(0.6574,0.33464,0.00787,1));
            glTranslatef(0,2,0);
            glRotatef(45,1,0,0);
    		glScalef(5.99,3,3);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          //la cheminée
          glPushMatrix();
            glColor4fv(newCouleur(1,0.9568,0.55294,1));
            glTranslatef(2,3.2,0.5);
    		glScalef(0.6,2.5,0.6);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
            glColor4fv(newCouleur(1,0.9568,0.55294,1));
            glTranslatef(2,4.6,0.5);
    		glScalef(0.8,0.2,0.8);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
            glColor4fv(couleurNoir());
            glTranslatef(2,3.46,0.5);
    		glScalef(0.5,2.5,0.5);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          //la porte
          glPushMatrix();
            glColor4fv(newCouleur(0.59055,0.51574,0.92913,1));
            glTranslatef(0,0,1.91);
    		glScalef(1.5,2.5,0.2);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
             glColor4fv(couleurNoir());
             glTranslatef(-0.5, 0.2,1.91);
             gluSphere(param,0.2,20,20);
          glPopMatrix();
          
          //les fenetres
          glPushMatrix();
            glColor4fv(newCouleur(0.59055,0.51574,0.92913,1));
            glTranslatef(2,0.5,1.91);
    		glScalef(1.5,1.5,0.2);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
            glColor4fv(newCouleur(0.9843,0.98823,0.98039,1));
            glTranslatef(2,0.5,1.92);
    		glScalef(1.3,1.3,0.2);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
            glColor4fv(newCouleur(0.59055,0.51574,0.92913,1));
            glTranslatef(-2,0.5,1.91);
    		glScalef(1.5,1.5,0.2);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
            glColor4fv(newCouleur(0.9843,0.98823,0.98039,1));
            glTranslatef(-2,0.5,1.92);
    		glScalef(1.3,1.3,0.2);
    		glutSolidCube(1.0);             
          glPopMatrix();
          
          //un sapin devant
          glPushMatrix();
            glTranslatef(-3.2, 1.4, 3);
           	glScalef(1.15,1.7,1.15);
            creerSapin();
        glPopMatrix();
          
      glPopMatrix();
 }
 
 void creerTunnel()
 {
      glPushMatrix();
          glPushMatrix();
                glColor4fv(newCouleur(1,0.9568,0.55294,1));
                glTranslatef(0, 0.5, -2);
        		glScalef(7,4,0.2);
        		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
                glColor4fv(newCouleur(1,0.9568,0.55294,1));
                glTranslatef(0, 0.5, 2);
        		glScalef(7,4,0.2);
        		glutSolidCube(1.0);             
          glPopMatrix();
          
          glPushMatrix();
                glColor4fv(newCouleur(1,0.9568,0.55294,1));
                glTranslatef(0, 2.5, 0);
        		glScalef(7,0.2,4.2);
        		glutSolidCube(1.0);             
          glPopMatrix();
          
          
      glPopMatrix();
}

void decoSapin()
{
    glPushMatrix();
        glTranslatef(-25, 1.4, 0);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-27, 0.5, 4);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-27, 1.4, 2);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-29, 0.5, 5);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-30, 1.4, 2);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-30, 0.5, 5);
        creerSapin();
    glPopMatrix();
    
    ///////////////////////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(23, 1.4, 20);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(25, 0.5, 24);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(25, 1.4, 22);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(27, 0.5, 25);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(28, 1.4, 22);
       	glScalef(1.15,1.7,1.15);
        creerSapin();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(28, 0.5, 25);
        creerSapin();
    glPopMatrix();
}

void decoMouton()
{
    glPushMatrix();
         glTranslatef(0, -0.7, -5);
         glRotatef(90,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
    
    glPushMatrix();
         glTranslatef(-2, -0.7, -3);
         glRotatef(33,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
    
    glPushMatrix();
         glTranslatef(2, -0.7, -2);
         glRotatef(20,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
    
    glPushMatrix();
         glTranslatef(7, -0.7, -5);
         glRotatef(-20,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
    
    glPushMatrix();
         glTranslatef(7, -0.7, -8);
         glRotatef(-46,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
    
    glPushMatrix();
         glTranslatef(-7, -0.7, -8);
         glRotatef(33,0,1,0);
         glScalef(0.25,0.25,0.25);
         creerMouton();
    glPopMatrix();
}
