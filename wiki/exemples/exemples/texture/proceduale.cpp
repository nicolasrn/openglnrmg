#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../modulesutilitaires/ModuleMenus.h"

int gl_xmax = 240 ;
int gl_ymax = 150 ;

int operation = 0 ;
int fenetrePrincipale ;
int txFenetre ;
int tyFenetre ;

#define snoise(x) (2 * ((float) noise((x))) - 1)
#define boxstep(a,b,x) (clamp(((x)-(a))/((b)-(a)),0,1))
#define MINFILTERWIDTH 1.0e-7
#define B 0x100
#define BM 0xff
#define NNNN 0x1000
#define NP 12
#define NM 0xfff
#define s_curve(t) ( t * t * (3. - 2. * t) )
#define lerp(t,a,b) ( a + t * (b - a) )
#define setup(i,b0,b1,r0,r1) t = vec[i] + NNNN;b0 = ((int)t) & BM;b1 = (b0+1) & BM;r0 = t - (int)t;r1 = r0 - 1.;
#define at2(rx,ry) ( rx * q[0] + ry * q[1] )
#define at3(rx,ry,rz) ( rx * q[0] + ry * q[1] + rz * q[2] )

static int p[B + B + 2];
static float g3[B + B + 2][3];
static float g2[B + B + 2][2];
static float g1[B + B + 2];
static int start = 1;

float persistence = 0.25 ;
int Number_Of_Octaves = 4 ;

float Interpolate(float a,float b,float x){
  float ft = x * 3.1415927 ;
  float f = (1 - cos(ft)) * .5 ;
  return  (a*(1-f) + b*f) ;
  }

float Noise(int x) {
  x = (x<<13)^x;
  return ( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
  }

float Noise(int x, int y) {
  int n = x + y * 57 ;
  n = (n<<13) ^ n;
  return ( 1.0 - ( (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0); 
  }
    
float SmoothedNoise_1(float x) {
  return (Noise((int) x)/2  +  Noise((int) x-1)/4  +  Noise((int) x+1)/4) ;
  }

float SmoothedNoise_1(float x, float y) {
  float corners = ( Noise((int) x-1,(int) y-1)+Noise((int) x+1,(int) y-1)+Noise((int) x-1,(int) y+1)+Noise((int) x+1,(int) y+1) ) / 16 ;
  float sides   = ( Noise((int) x-1,(int) y)  +Noise((int) x+1,(int) y)  +Noise((int) x,(int) y-1)  +Noise((int) x,(int) y+1) ) /  8 ;
  float center  =  Noise((int) x,(int) y) / 4 ;
  return (corners + sides + center) ;
  }
 
float InterpolatedNoise_1(float x) {     
  int integer_X =(int) floor(x) ;
  float fractional_X = x - integer_X ;
  float v1 = SmoothedNoise_1(integer_X) ;
  float v2 = SmoothedNoise_1(integer_X + 1) ;
  return (Interpolate(v1 , v2 , fractional_X)) ;
  }

float InterpolatedNoise_1(float x, float y) {
  int integer_X =(int) floor(x) ;
  float fractional_X = x - integer_X ;
  int integer_Y =(int) floor(y) ;
  float fractional_Y = y - integer_Y ;
  float v1 = SmoothedNoise_1(integer_X,     integer_Y) ;
  float v2 = SmoothedNoise_1(integer_X + 1, integer_Y) ;
  float v3 = SmoothedNoise_1(integer_X,     integer_Y + 1) ;
  float v4 = SmoothedNoise_1(integer_X + 1, integer_Y + 1) ;
  float i1 = Interpolate(v1 , v2 , fractional_X) ;
  float i2 = Interpolate(v3 , v4 , fractional_X) ;
  return (Interpolate(i1 , i2 , fractional_Y)) ;
  }

float PerlinNoise_1D(float x) {
  float total = 0 ;
  float p = persistence ;
  int n = Number_Of_Octaves - 1 ;
  for ( int i = 0 ; i <= n ; i++ ) {
    float frequency = 2<<i ;
    float amplitude = pow(p,i) ;
    total += InterpolatedNoise_1(x * frequency) * amplitude ; }
  return (total) ;
  }

float PerlinNoise_2D(float x, float y) {
  float total = 0 ;
  float p = persistence ;
  int n = Number_Of_Octaves - 1 ;
  for ( int i = 0 ; i <= n ; i++ ) {
    float frequency = 2<<i ;
    float amplitude = pow(p,i) ;
    total += InterpolatedNoise_1(x * frequency,y*frequency) * amplitude ; }
  return (total) ;
  }

static void normalize2(float v[2]) {
  float s;
  s = sqrt(v[0] * v[0] + v[1] * v[1]);
  v[0] = v[0] / s;
  v[1] = v[1] / s;
}

static void normalize3(float v[3]) {
  float s;
  s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  v[0] = v[0] / s;
  v[1] = v[1] / s;
  v[2] = v[2] / s;
}

static void init(void) {
  int i,j,k;
  for (i = 0 ; i < B ; i++) {
    p[i] = i;
    g1[i] = (float)((rand() % (B + B)) - B) / B;
    for (j = 0 ; j < 2 ; j++)
      g2[i][j] = (float)((rand() % (B + B)) - B) / B;
    normalize2(g2[i]);
    for (j = 0 ; j < 3 ; j++)
      g3[i][j] = (float)((rand() % (B + B)) - B) / B;
    normalize3(g3[i]); }
  while (--i) {
    k = p[i];
    p[i] = p[j = rand() % B];
    p[j] = k; }
  for (i = 0 ; i < B + 2 ; i++) {
    p[B + i] = p[i];
    g1[B + i] = g1[i];
    for (j = 0 ; j < 2 ; j++)
      g2[B + i][j] = g2[i][j];
    for (j = 0 ; j < 3 ; j++)
      g3[B + i][j] = g3[i][j]; }
}
 
double noise1(double arg) {
  int bx0,bx1;
  float rx0,rx1,sx,t,u,v,vec[1];
  vec[0] = arg;
  if (start) {
    start = 0;
    init(); }
  setup(0,bx0,bx1,rx0,rx1);
  sx = s_curve(rx0);
  u = rx0 * g1[ p[ bx0 ] ];
  v = rx1 * g1[ p[ bx1 ] ];
  return lerp(sx,u,v);
}

float noise2(float vec[2]) {
  int bx0,bx1,by0,by1,b00,b10,b01,b11;
  float rx0,rx1,ry0,ry1,*q,sx,sy,a,b,t,u,v;
  int i,j;
  if (start) {
    start = 0;
    init(); }
  setup(0,bx0,bx1,rx0,rx1);
  setup(1,by0,by1,ry0,ry1);
  i = p[bx0];
  j = p[bx1];
  b00 = p[i+by0];
  b10 = p[j+by0];
  b01 = p[i+by1];
  b11 = p[j+by1];
  sx = s_curve(rx0);
  sy = s_curve(ry0);
  q = g2[b00] ; 
  u = at2(rx0,ry0);
  q = g2[b10] ;
  v = at2(rx1,ry0);
  a = lerp(sx,u,v);
  q = g2[b01] ;
  u = at2(rx0,ry1);
  q = g2[b11] ;
  v = at2(rx1,ry1);
  b = lerp(sx,u,v);
  return lerp(sy,a,b);
}

float noise3(float vec[3]) {
  int bx0,bx1,by0,by1,bz0,bz1,b00,b10,b01,b11;
  float rx0,rx1,ry0,ry1,rz0,rz1,*q,sy,sz,a,b,c,d,t,u,v;
  int i,j;
  if (start) {
    start = 0;
    init();  }
  setup(0,bx0,bx1,rx0,rx1);
  setup(1,by0,by1,ry0,ry1);
  setup(2,bz0,bz1,rz0,rz1);
  i = p[ bx0 ];
  j = p[ bx1 ];
  b00 = p[ i + by0 ];
  b10 = p[ j + by0 ];
  b01 = p[ i + by1 ];
  b11 = p[ j + by1 ];
  t  = s_curve(rx0);
  sy = s_curve(ry0);
  sz = s_curve(rz0);
  q = g3[ b00 + bz0 ] ;
  u = at3(rx0,ry0,rz0);
  q = g3[ b10 + bz0 ] ;
  v = at3(rx1,ry0,rz0);
  a = lerp(t,u,v);
  q = g3[ b01 + bz0 ] ;
  u = at3(rx0,ry1,rz0);
  q = g3[ b11 + bz0 ] ;
  v = at3(rx1,ry1,rz0);
  b = lerp(t,u,v);
  c = lerp(sy,a,b);
  q = g3[ b00 + bz1 ] ;
  u = at3(rx0,ry0,rz1);
  q = g3[ b10 + bz1 ] ;
  v = at3(rx1,ry0,rz1);
  a = lerp(t,u,v);
  q = g3[ b01 + bz1 ] ;
  u = at3(rx0,ry1,rz1);
  q = g3[ b11 + bz1 ] ;
  v = at3(rx1,ry1,rz1);
  b = lerp(t,u,v);
  d = lerp(sy,a,b);
  return lerp(sz,c,d);
}

struct color {
  float r ;
  float v ;
  float b ; } ;

struct normal {
  float x ;
  float y ;
  float z ; } ;

struct point {
  float x ;
  float y ;
  float z ; } ;

float du = 0.0F ;
float dv = 0.0F ;
point N = { 0.0F,0.0F,1.0F } ;
point I = { 0.0F,0.0F,-1.0F } ;
color Ci = { 1.0F,1.0F,1.0F } ;
color Oi = { 1.0F,1.0F,1.0F } ;
color Cs = { 1.0F,1.0F,1.0F } ;
color Os = { 1.0F,1.0F,1.0F } ;

point toPoint(normal norm) {
  point p = {norm.x,norm.y,norm.z} ;
  return(p) ;
  }

void affectation(normal &N,point P) {
  N.x = P.x ;
  N.y = P.y ;
  N.z = P.z ;
  }

void multiplication(color &c,float f) {
  c.r *= f ;
  c.v *= f ;
  c.b *= f ;
  }

point normalize(point V) {
  point v ;
  float d =(float) sqrt(V.x*V.x+V.y*V.y+V.z*V.z) ;
  if ( d != 0.0F ) {
    v.x = V.x / d ;
    v.y = V.y / d ;
    v.z = V.z / d ; }
    else
    v.x = v.y = v.z = 0.0F ;
  return(V) ;
  }

point inverse(point V) {
  point v = { -V.x,-V.y,-V.z } ;
  return(v) ;
  }

point faceforward(point V,point R) {
  point v = V ;
  return(v) ;
  }

float noise(float s) {
  return((float) (1+PerlinNoise_1D(s))/2.0F) ;
  }

float noise(float s,float t) {
//  float v[2] = { s,t } ;
  return((1+PerlinNoise_2D(s,t))/2.0F) ;
  }

void addition(point &p,point pp) {
  p.x += pp.x ;
  p.y += pp.y ;
  p.z += pp.z ;
  }

point noise(point p) {
  point pp = { noise(p.x,p.y),noise(p.y,p.x*2) } ;
  return(pp) ;
  }

float vvvvnoise(point p) {
  return(noise(p.x,p.y));
  }

float Du(float s) {
  return(0.0F) ;
  }

float Dv(float s) {
  return(0.0F) ;
  }

float clamp(float v,float min,float max) {
  if ( v < min )
    return(min) ;
  if ( v > max )
    return(max) ;
  return(v) ;
  }

float smoothstep(float min,float max,float val) {
  if ( val < min )
    return(min) ;
  if ( val > max )
    return(max) ;
  return((max-min)*val+min) ;
  }

color mix(color min,color max,float val) {
  color c ;
  c.r = (1-val)*min.r+val*max.r ;
  c.v = (1-val)*min.v+val*max.v ;
  c.b = (1-val)*min.b+val*max.b ;
  return(c) ;
  }

typedef float matrice[4][4] ;

matrice m2 = { -0.5F, 1.5F,-1.5F, 0.5F,
                1.0F,-2.5F, 2.0F,-0.5F,
               -0.5F, 0.0F, 0.5F, 0.0F,
                0.0F, 1.0F, 0.0F, 0.0F } ;

color lisse(color *c,float t,matrice m) { 
  int j,k ;
  float tt[4],ttt[4],x,y,z ;
  tt[0] = t*t*t ;
  tt[1] = t*t ;
  tt[2] = t ;
  tt[3] = 1 ;
  for ( j = 0 ; j < 4 ; j++ )
    for ( k = 0,ttt[j] = 0 ; k < 4 ; k++ )
      ttt[j] += tt[k] * m[k][j] ;
  x = y = z = 0 ;
  for ( j = 0 ; j < 4 ; j++ ) {
    x += ttt[j] * c[j].r ;
    y += ttt[j] * c[j].v ;
    z += ttt[j] * c[j].b ; }
  color co = {x,y,z} ;
  return(co) ;
}

color spline(float csp,
             color c1,
             color c2,
             color c3,
             color c4,
             color c5,
             color c6,
             color c7,
             color c8,
             color c9,
             color c10,
             color c11,
             color c12,
             color c13) {
  int p =(int) (csp*10) ;
  if ( p == 10 )
    p = 9 ;
  float tt = csp*10 - p ;
  color t[4] ;
  switch ( p ) {
    case 0  : t[0] = c1 ;
              t[1] = c2 ;
              t[2] = c3 ;
              t[3] = c4 ;
              break ;
    case 1  : t[0] = c2 ;
              t[1] = c3 ;
              t[2] = c4 ;
              t[3] = c5 ;
              break ;
    case 2  : t[0] = c3 ;
              t[1] = c4 ;
              t[2] = c5 ;
              t[3] = c6 ;
              break ;
    case 3  : t[0] = c4 ;
              t[1] = c5 ;
              t[2] = c6 ;
              t[3] = c7 ;
              break ;
    case 4  : t[0] = c5 ;
              t[1] = c6 ;
              t[2] = c7 ;
              t[3] = c8 ;
              break ;
    case 5  : t[0] = c6 ;
              t[1] = c7 ;
              t[2] = c8 ;
              t[3] = c9 ;
              break ;
    case 6  : t[0] = c7 ;
              t[1] = c8 ;
              t[2] = c9 ;
              t[3] = c10 ;
              break ;
    case 7  : t[0] = c8 ;
              t[1] = c9 ;
              t[2] = c10 ;
              t[3] = c11 ;
              break ;
    case 8  : t[0] = c9 ;
              t[1] = c10 ;
              t[2] = c11 ;
              t[3] = c12 ;
              break ;
    case 9  : t[0] = c10 ;
              t[1] = c11 ;
              t[2] = c12 ;
              t[3] = c13 ;
              break ; }
  color c = lisse(t,tt,m2) ;
  return(c) ;
  }

color ambient(void) {
  color c = { 0.0F,0.0F,0.0F } ;
  return(c) ;
  }

color diffuse(point norm) {
  color c = { 1.0F,1.0F,1.0F } ;
  return(c) ;
  }

color specular(point norm,point eye,float roughness) {
  color c = { 0.0F,0.0F,0.0F } ;
  return(c) ;
  }

float myMax(float a,float b) {
  return((a > b) ? a : b);
}

void plank(float s,float t,float Kd,
  float ringscale,float grainscale,
  float txtscale,
  color lightwood,
  color darkwood,
  color groovecolor,
  float plankwidth,float planklength,float groovewidth,
  float plankvary,
  float grainy,float wavy) {
  float r,r2;
  float whichrow,whichplank;
  float swidth,twidth,fwidth,ss,tt,w,h,fade,ttt;
  color Ct,woodcolor;
  float groovy;
  float PGWIDTH,PGHEIGHT,GWF,GHF;
  PGWIDTH = plankwidth+groovewidth;
  PGHEIGHT = planklength+groovewidth;
  GWF = groovewidth*0.5/PGWIDTH;
  GHF = groovewidth*0.5/PGHEIGHT;
  swidth = MINFILTERWIDTH/PGWIDTH*txtscale;
  twidth = MINFILTERWIDTH/PGHEIGHT*txtscale;
  fwidth = myMax(swidth,twidth);
  ss = txtscale*s/PGWIDTH;
  whichrow = floor(ss);
  ss -= whichrow;
  tt = (txtscale*t/PGHEIGHT) + 10*snoise(0.5+whichrow);
  whichplank = floor(tt);
  tt -= whichplank;
  whichplank += 20*whichrow;
  if ( swidth >= 1 )
    w = 1 - 2*GWF;
    else
    w = clamp(boxstep(GWF-swidth,GWF,ss),myMax(1-GWF/swidth,0),1)-clamp (boxstep(1-GWF-swidth,1-GWF,ss),0,2*GWF/swidth);
  if ( twidth >= 1 )
    h = 1-2*GHF;
    else
    h = clamp(boxstep(GHF-twidth,GHF,tt),myMax(1-GHF/twidth,0),1)-clamp(boxstep(1-GHF-twidth,1-GHF,tt),0,2*GHF/twidth);
  groovy = w*h;
  fade = smoothstep (1/ringscale,8/ringscale,fwidth);
  if (fade < 0.999) {
    ttt = tt+whichplank/28.38 + wavy * noise(8*ss,tt);
    r = ringscale * noise(ss-whichplank,ttt);
    r -= floor(r);
    r =(float) (0.3F + 0.7F * smoothstep(0.2F,0.55F,r) * (1-smoothstep(0.75F,0.8F,r)));
    r = (1-fade)*r + 0.65*fade;
    fade = smoothstep (2/grainscale,8/grainscale,fwidth);
    if (fade < 0.999) {
       r2 = 1.3 - noise(ss*grainscale,tt*grainscale);
      r2 = grainy * r2*r2 + (1-grainy);
      r *= (1-fade)*r2 + (0.75*fade); }
      else
      r *= 0.75F; }
    else
    r = 0.4875F;
  woodcolor = mix(lightwood,darkwood,r);
  multiplication(woodcolor,(1-plankvary/2+plankvary*(noise(whichplank+0.5))));
  Ct = mix(groovecolor,woodcolor,groovy);
  Oi = Os ;
  color dcolor = { 1.0F,1.0F,1.0F } ;
  Ci.r = Os.r*(Ct.r*(Kd*dcolor.r));
  Ci.v = Os.v*(Ct.v*(Kd*dcolor.v));
  Ci.b = Os.b*(Ct.b*(Kd*dcolor.b));
}

void wood(float s,float t,float ringscale,
          color lightwood,
          color darkwood,
          float Kd) {
  float y,z,r;
  point PP = { s*2,t*2 } ;
  addition(PP,noise(PP));
  y = PP.x;
  z = PP.y;
  r = sqrt(y*y+z*z);
  r *= ringscale;
  r += fabs(noise(r));
  r -= floor(r);
  r =(float) (smoothstep(0,0.8F,r) - smoothstep(0.83F,1.0F,r));
  Ci = mix(lightwood,darkwood,r);
  Oi = Os;
  color dcolor = { 1.0F,1.0F,1.0F } ;
  Ci.r = Oi.r * Ci.r * 3*(Kd * dcolor.r);
  Ci.v = Oi.v * Ci.v * 3*(Kd * dcolor.v);
  Ci.b = Oi.b * Ci.b * 3*(Kd * dcolor.b);
}

void blue_marble(float s,float t,float Kd,float txtscale) {
  float pixelsize,twice,scale,weight,turbulence;
  pixelsize = 0.01F;
  twice = 2 * pixelsize;
  turbulence = 0;
  point AP = { s*8,t*8 } ;
  point PP ;
  PP = AP ;
  for ( scale = 1.0F ; scale > twice ; scale /= 2.0F ) {
    PP.x /= scale ;
    PP.y /= scale ;
    PP.z /= scale ;
    turbulence += scale * vvvvnoise(PP); }
  PP = AP ;
  if ( scale > pixelsize ) {
    weight = (scale / pixelsize) - 1;
    weight = clamp(weight,0,1);
    PP.x /= scale ;
    PP.y /= scale ;
    PP.z /= scale ;
    turbulence += weight * scale * vvvvnoise(PP); }
  float csp = clamp(4*turbulence-3,0,1);
  color c1 = {0.25F, 0.25F, 0.35F} ;
  color c2 = {0.25F, 0.25F, 0.35F} ;
  color c3 = {0.20F, 0.20F, 0.30F} ;
  color c4 = {0.20F, 0.20F, 0.30F} ;
  color c5 = {0.20F, 0.20F, 0.30F} ;
  color c6 = {0.25F, 0.25F, 0.35F} ;
  color c7 = {0.25F, 0.25F, 0.35F} ;
  color c8 = {0.15F, 0.15F, 0.26F} ;
  color c9 = {0.15F, 0.15F, 0.26F} ;
  color c10 = {0.10F, 0.10F, 0.20F} ;
  color c11 = {0.10F, 0.10F, 0.20F} ;
  color c12 = {0.25F, 0.25F, 0.35F} ;
  color c13 = {0.10F, 0.10F, 0.20F} ;
  Ci = spline(csp,
              c1,
              c2,
              c3,
              c4,
              c5,
              c6,
              c7,
              c8,
              c9,
              c10,
              c11,
              c12,
              c13);
  color dcolor = { 1.0F,1.0F,1.0F } ;
  Oi = Os;
  Ci.r *= Oi.r*1.5*(Kd*dcolor.r);
  Ci.v *= Oi.v*1.5*(Kd*dcolor.v);
  Ci.b *= Oi.b*1.5*(Kd*dcolor.b);
  }

void granite(float s,float t,float Kd) {
  float sum = 0;
  float freq = 1.0;
  for ( int i = 0 ; i < 6 ; i++ ) {
    sum += fabs(.5 - noise(12*freq*s,12*freq*t))/freq*1.4 ;
    freq *= 2; }
  if ( sum > 1/Kd )
     sum = 1/Kd ;
  Ci.r = sum * Kd ;
  Ci.v = sum * Kd ;
  Ci.b = sum * Kd ;
}

void display(void)
  { glClearColor(0.0F,0.0F,0.0F,1.0F) ;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;
    glPushMatrix();
    GLubyte *im ;
    int t = gl_xmax*gl_xmax*3 ;
    im =(GLubyte *) calloc(t,sizeof(GLubyte));
    for ( int i = 0 ; i < gl_ymax ; i++ ) {
//      printf("%d ",i);
      float t =(float) i/(gl_xmax-1) ;
      for ( int j = 0 ; j < gl_xmax ; j++ ) {
        int ind = (i*gl_xmax+j)*3 ;
        float s =(float) j/(gl_xmax-1) ;
        switch ( operation ) {
          case 0 : { Ci.r = 0.0F ;
                     Ci.v = 0.0F ;
                     Ci.b = 0.0F ; }
                   break ;
          case 1 : { float Kd = 0.75;
                     float ringscale = 15,grainscale = 60;
                     float txtscale = 0.3F;
                     color lightwood = { 0.57F,0.292F,0.125F } ;
                     color darkwood  = { 0.275F,0.15F,0.06F } ;
                     color groovecolor = { 0.05F,0.04F,0.015F } ;
                     float plankwidth = 0.05F,planklength = 1.0F,groovewidth = 0.001F;
                     float plankvary = 0.8F;
                     float grainy = 1,wavy = 0.018F;
                     plank(s,t,Kd,
                           ringscale,grainscale,
                           txtscale,
                           lightwood,
                           darkwood,
                           groovecolor,
                           plankwidth,planklength,groovewidth,
                           plankvary,
                           grainy,wavy) ; }
                   break ;
          case 2 : { float ringscale = 10;
                     color lightwood = { 0.3F,0.12F,0.03F } ;
                     color darkwood = { 0.05F,0.01F,0.005F} ;
                     float Kd = 0.4F;
                     wood(s,t,ringscale,
                          lightwood,
                          darkwood,
                          Kd) ; }
                   break ;
          case 3 : { float txtscale = 0.3F;
                     float Kd = 0.6F;
                     blue_marble(s,t,Kd,txtscale) ; }
                   break ;
          case 4 : { float Kd = 0.8F;
                     granite(s,t,Kd) ; }
                   break ; }
        im[ind] =(int) (Ci.r*255) ;
        im[ind+1] =(int) (Ci.v*255) ;
        im[ind+2] =(int) (Ci.b*255) ; } }
    glRasterPos2f(0.0F,0.0F) ;
    glDrawPixels(gl_xmax,gl_ymax,GL_RGB,GL_UNSIGNED_BYTE,im) ;
    free(im) ;
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
  }

void myinit (void) 
  { glShadeModel(GL_SMOOTH) ;
    glEnable(GL_DEPTH_TEST) ;
    glEnable(GL_LIGHTING) ;
    glEnable(GL_LIGHT0) ;
    glEnable(GL_NORMALIZE) ;
    glDepthFunc(GL_LESS) ;
  }

void reshape(int w,int h) {
  glViewport(0,0,w,h) ;
  txFenetre = w ;
  tyFenetre = h ;
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  glOrtho(0,gl_xmax,0,gl_ymax,-1000.,1000.); 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
}

void key(unsigned char key,int x,int y) {
  switch ( key ) {
    case 'a'    : operation = 1 ;
                  break ;
    case 'b'    : operation = 2 ;
                  break ;
    case 'c'    : operation = 3 ;
                  break ;
    case 'd'    : operation = 4 ;
                  break ;
    case ' '    : operation = 0 ;
                  break ;
    case '\033' : printf("Quitter\n") ;
                  exit(0);
                  break ; }
  glutPostRedisplay();
}

void select(int selection) {
  switch (selection) {
    case 0  : exit(0);
              break; }
  glutPostRedisplay();
}

void creationMenus(void) {
  glutCreateMenu(select);
  glutAddMenuEntry("Quitter",0);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  init() ;
  glutInitWindowPosition(50,50);
  glutInitWindowSize(gl_xmax,gl_ymax);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  fenetrePrincipale = glutCreateWindow("Textures mathematiques");
  myinit() ;
  creationMenus();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key);
  glutMainLoop();
  return(0) ;
}


