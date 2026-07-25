#include <stdio.h>
                       #include <math.h>
                     #include <stdlib.h>
                   #include <unistd.h>
                  typedef struct{float x,y,z;}V;static V S
                  (V a,V b){return(V){a.x-b.x,a.y-b.y,a.z-b
                  .z};}static V A(V a,V b){return(V){a.x+b.
                x,a.y+b.y,a.z+b.z};}static V K(V a,float s)
                {return(V){a.x*s,a.y*s,a.z*s};}static float
                D(V a,V b){return a.x*b.x+a.y*b.y+a.z*b.z;}
                static float L(V a){return sqrtf(D(a,a));}
                  static V N(V a){float l=L(a);if(l<1e-6f)l
                  =1e-6f;return K(a,1.0f/l);}static V Y(V p
                 ,float a){float c=cosf(a),s=sinf(a);return(V
                 ){c*p.x+s*p.z,p.y,-s*p.x+c*p.z};}static
                 float E(V p,V r){V q={p.x/r.x,p.y/r.y,p.z/r.z};
               float k0=L(q);V q2={p.x/(r.x*r.x),p.y/(r.y*r.y),p.
             z/(r.z*r.z)};float k1=L(q2);if(k1<1e-6f)k1=1e-6f;
          return k0*(k0-1.0f)/k1;}static float G=0;static float M(V p,
       int*m){p=Y(p,G);float d=1e9f,t;*m=0;t=E(S(p,(V){0,-.35f,0}),(V){
     1.2f,.98f,.92f});if(t<d){d=t;*m=1;}t=E(S(p,(V){0,-.4f,-.55f}),(V){
    .66f,.8f,.55f});if(t<d){d=t;*m=2;}t=E(S(p,(V){0,.98f,.02f}),(V){.6f,.58f
  ,.54f});if(t<d){d=t;*m=1;}t=E(S(p,(V){.26f,1.15f,-.34f}),(V){.3f,.27f,.26f}
  );if(t<d){d=t;*m=2;}t=E(S(p,(V){-.26f,1.15f,-.34f}),(V){.3f,.27f,.26f});if(t<
 d){d=t;*m=2;}t=E(S(p,(V){0,.9f,-.68f}),(V){.24f,.16f,.3f});if(t<d){d=t;*m=3;}t=
E(S(p,(V){.27f,1.17f,-.56f}),(V){.12f,.13f,.13f});if(t<d){d=t;*m=4;}t=E(S(p,(V){-
.27f,1.17f,-.56f}),(V){.12f,.13f,.13f});if(t<d){d=t;*m=4;}t=E(S(p,(V){.5f,-1.32f,-
.35f}),(V){.34f,.14f,.5f});if(t<d){d=t;*m=3;}t=E(S(p,(V){-.5f,-1.32f,-.35f}),(V){
.34f,.14f,.5f});if(t<d){d=t;*m=3;}t=E(S(p,(V){1,-.15f,0}),(V){.26f,.88f,.44f});if(t<d){d=t;
*m=1;}t=E(S(p,(V){-1,-.15f,0}),(V){.26f,.88f,.44f});if(t<d){d=t;*m=1;}return d;}static V Gn
(V p){float e=.001f;int m;float dx=M(A(p,(V){e,0,0}),&m)-M(S(p,(V){e,0,0}),&m);float dy=M(A
(p,(V){0,e,0}),&m)-M(S(p,(V){0,e,0}),&m);float dz=M(A(p,(V){0,0,e}),&m)-M(S(p,(V){0,0,e}),&
m);return N((V){dx,dy,dz});}static int R(V ro,V rd,float*od,int*om,V*on){float t=0;for(
int i=0;i<120;i++){V p=A(ro,K(rd,t));int m;float d=M(p,&m);if(d<.001f){*od=t;*om=m;*on=
Gn(p);return 1;}t+=d*.6f;if(t>20)break;}return 0;}int main(int c,char**v){V ld=N((V){.6f,.8f,-.5f});
const char*rp=" .:-=+*#%@";int W=80,H=28,mf=c>1?atoi(v[1]):-1,f=0;printf("\x1b[2J\x1b[?25l");for(;;){
printf("\x1b[H");for(int y=0;y<H;y++){for(int x=0;x<W;x++){float u=(x-W/2.0f)/(W/2.0f),vv=-((y-H/2.0f)/
(H/2.0f)*.62f);V ro={0,0,-6.3f},rd=N((V){u,vv,1.6f});float ds;int mt;V n;if(R(ro,rd,&ds,&mt,&n)){float df=D
(n,ld);if(df<0)df=0;int Rr,Gg,Bb;if(mt==1){Rr=50;Gg=50;Bb=58;}else if(mt==2){Rr=238;Gg=238;Bb=238;}else if
(mt==3){Rr=232;Gg=155;Bb=15;}else{Rr=6;Gg=6;Bb=8;}float am=mt==1?.24f:(mt==4?.35f:.62f),it=am+(1-am)*df;V vd=
K(rd,-1.0f),rf=S(K(n,2.0f*D(n,ld)),ld);float sp=D(rf,vd);if(sp<0)sp=0;sp=powf(sp,60.0f)*.5f;if(mt==4)sp*=
.15f;int ix=(int)(it*9);if(ix>9)ix=9;if(ix<0)ix=0;Rr=(int)(Rr*it+90*sp);Gg=(int)(Gg*it+90*sp);Bb=(int)
(Bb*it+90*sp);if(Rr>255)Rr=255;if(Gg>255)Gg=255;if(Bb>255)Bb=255;printf("\x1b[38;2;%d;%d;%dm%c",
Rr,Gg,Bb,rp[ix]);}else printf(" ");}printf("\x1b[0m\n");}G+=.06f;f++;if(mf>0&&f>=mf)
break;usleep(40000);}printf("\x1b[?25h");return 0;}
