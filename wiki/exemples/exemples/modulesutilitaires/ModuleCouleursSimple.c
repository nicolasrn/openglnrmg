/* Module de gestion des couleurs         */

#include <stdlib.h>

static float blanc[] = { 1.0F,1.0F,1.0F,1.0F };
static float jaune[] = { 1.0F,1.0F,0.0F,1.0F };
static float cyan[] = { 0.0F,1.0F,1.0F,1.0F };
static float magenta[] = { 1.0F,0.0F,1.0F,1.0F };
static float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static float bleu[] = { 0.0F,0.0F,1.0F,1.0F };
static float noir[] = { 0.0F,0.0F,0.0F,1.0F };
static float grisTresFonce[] = { 0.1F,0.1F,0.1F,1.0F };
static float grisFonce[] = { 0.25F,0.25F,0.25F,1.0F };
static float grisMoyen[] = { 0.5F,0.5F,0.5F,1.0F };
static float grisClair[] = { 0.75F,0.75F,0.75F,1.0F };
static float jauneClair[] = { 0.75F,0.75F,0.0F,1.0F };
static float jauneFonce[] = { 0.5F,0.5F,0.0F,1.0F };
static float cyanFonce[] = { 0.0F,0.5F,0.5F,1.0F };
static float magentaFonce[] = { 0.5F,0.0F,0.5F,1.0F };
static float rougeFonce[] = { 0.5F,0.0F,0.0F,1.0F };
static float vertFonce[] = { 0.0F,0.5F,0.0F,1.0F };
static float bleuFonce[] = { 0.0F,0.0F,0.5F,1.0F };
static float brun[] = { 0.8F,0.6F,0.4F,1.0F };
static float rose[] = { 1.0F,0.65F,0.65F,1.0F };
static float roseFonce[] = { 0.6F,0.25F,0.25F,1.0F };
static float bleuCiel[] = { 0.5F,0.5F,1.0F,1.0F };
static float bleuCielFonce[] = { 0.25F,0.25F,0.5F,1.0F };

float *couleurBlanc(void) {
  return(blanc);
}

float *couleurNoir(void) {
  return(noir);
}
float *couleurJaune(void) {
  return(jaune);
}

float *couleurCyan(void) {
  return(cyan);
}

float *couleurMagenta(void) {
  return(magenta);
}

float *couleurRouge(void) {
  return(rouge);
}

float *couleurVert(void) {
  return(vert);
}

float *couleurBleu(void) {
  return(bleu);
}



float *couleurGrisTresFonce(void) {
  return(grisTresFonce);
}

float *couleurGrisFonce(void) {
  return(grisFonce);
}

float *couleurGrisMoyen(void) {
  return(grisMoyen);
}

float *couleurGrisClair(void) {
  return(grisClair);
}

float *couleurJauneClair(void) {
  return(jauneClair);
}

float *couleurJauneFonce(void) {
  return(jauneFonce);
}

float *couleurCyanFonce(void) {
  return(cyanFonce);
}

float *couleurMagentaFonce(void) {
  return(magentaFonce);
}

float *couleurRougeFonce(void) {
  return(rougeFonce);
}

float *couleurVertFonce(void) {
  return(vertFonce);
}

float *couleurBleuFonce(void) {
  return(bleuFonce);
}

float *couleurBrun(void) {
  return(brun);
}

float *couleurRose(void) {
  return(rose);
}

float *couleurRoseFonce(void) {
  return(roseFonce);
}

float *couleurBleuCiel(void) {
  return(bleuCiel);
}

float *couleurBleuCielFonce(void) {
  return(bleuCielFonce);
}




