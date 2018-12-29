#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>

int i;
 char j;   char scr[20];
 int k;   int p=1,p2=1,p3=1; int up=1,up1=1,up2=1;
 int skore=0;    int r;  int r1,r2,r3,r4=235,r5=250,r6=300;
  int input;
 int h,h1,h3;  //neche wale hurdles k x axis
 int no1=0,no2=0,no3=0;
 int u1,u2,u3;
		    int m=40;
//******************* all function declarations****************//
void bird(void);
void fpage(void);
void scoreboard(void);
void out(void);
void upperdeadline(void);
void gravity(void);
void deadline(void);
void gameover(void);
void printgameover(void);
void fly(void);
void hurdle1(void);
void hurdle2(void);
void hurdle3(void);
void uphurdle(void);
void uphurdle1(void);
void uphurdle2(void);
void score(void);
void graph(int,int,int);
//***********************  MAIN   *********************************//
main() {
      char x; char a;
      h=400;
h1=200;
h3=600;
u3=600;
u2=200;
u1=400;
p=1; p2=1 ;p3=1; up=1 ; up1=1 ;up2=1;


int gm=DETECT,gd;
initgraph(&gm,&gd,"C://Tc//bgi");
cleardevice();

fpage();
scanf("%d",&input);
switch(input)
{
case 1:
setbkcolor(0);
r=rand()%150  ;
srand(time(NULL));
setbkcolor(0);
gravity();
break;

case 2:
cleardevice();
scoreboard();
outtextxy(0,400,"press enter  for main menu");
 a=getch();
if(a==13)
{ main(); }


break;

case 3:
cleardevice();
setbkcolor(BLACK);
settextstyle(3,0,7);
outtextxy(130,10,"INSTRUCTIONS");
setcolor(RED);
settextstyle(1,0,2);
outtextxy(20,150,"1. The bird is constantly moving downward.");
outtextxy(20,180,"2. Press spacebar to fly and save the bird.");
outtextxy(20,210,"3. There will come hurdles,but you gotta save the bird.");
outtextxy(20,240,"4. There are deadlines at top and bottom.");
outtextxy(20,270,"5. You shoudn't touch them.");
//outtextxy(20,300,"6. Press backpsace to get back to main menu");
outtextxy(20,330,"press enter  for main menu");
 a=getch();
if(a==13)
{ main(); }
break;

case 4:
cleardevice();
graph(no1,no2,no3);
outtextxy(0,450,"press enter  for main menu");
 a=getch();
if(a==13)
{ main(); }
break;


case 5:
exit(1);
break;

default :
main();
break;
}



//rectangle(640,20,660,200);
getch();
closegraph();
}
/////*******************FUNCTIONS*********************//

///***********************BIRD***********************//
void bird(void)
{
circle(m,i,10);
}

//______________________ end___________________________//



//******************* GRAVITY**************************//
void gravity(void)
{   for(i=200;i<=450;i++)
 {

   if((i==390 || i<30) || (i>r6 && h==50))
   { cleardevice();
    printgameover();
    getch();
    break;
   }

 if(i>r5 && h1==50)
   { cleardevice();
    printgameover();
    getch();
    break;
   }

  if (i>r4 && h3==50)
   { cleardevice();
    printgameover();
    getch();
    break;
   }
if(h==50 && r6==(k+10))
 { cleardevice();
    printgameover();
    getch();
    break;
   }

if(u1==50 && i<(r6-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }
   if(u2==50 && i<(r5-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }

   if(u3==50 && i<(r4-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }
setcolor(WHITE);
 uphurdle();
uphurdle1();
 uphurdle2();
 hurdle1();
hurdle2();
 hurdle3();
 fly();
 deadline();
 bird();
  deadline();
 delay(8);
cleardevice();
 score();
 }
}

//************************ LOWER LINE ************************//

void deadline(void)
{ upperdeadline();
 line(0,400,640,400);
 rectangle(0,400,150,500);
 rectangle(150,400,450,500);
 rectangle(450,400,640,500);
 }


   ///****************  PRINTING GAME OVER *********************//

void printgameover(void)

{ setcolor(RED);
settextstyle(10,0,4);
 outtextxy(180,200,"GAME OVER");
  line(100,280,600,280);
  delay(1000);
  main();
 }
// ************************** FLYING *******************
void fly(void)
{
if(kbhit())
{
j=getch();
if(j==' ')
{
for(k=1;k<=30;k++)
{ i=i-1;
score();
hurdle1();
hurdle2();
hurdle3();
uphurdle();
uphurdle1();
uphurdle2();
bird();  deadline();
 delay(8);
 cleardevice();

 if(i>r5 && h1==50)
   { cleardevice();
    printgameover();
    getch();
    break;
   }

  if (i>r6 && h==50)
   { cleardevice();
    printgameover();
    getch();
    break;
   }
  if (i>r4 && h3==50)
   { cleardevice();
    printgameover();
    getch();
    break;
   }


if(u1==50 && i<(r6-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }
   if(u2==50 && i<(r5-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }

   if(u3==50 && i<(r4-80))
 { cleardevice();
    printgameover();
    getch();
    break;
   }



}
}

}}
// *************************** UPPER DEADLINE **********************
void upperdeadline(void)
{
line(0,20,1000,20);    }


void hurdle1(void)         // range iski rakho 640---700
{  h=400+p;
   rectangle(h,r6,h+30,400);

   p-- ;
  if(h==0)
  { skore++;
  r6=250+rand()%100 ;
    p=250; }

}
void hurdle2(void)            // 800----900
{ h1=200+p2;
 rectangle(h1,r5,h1+30,400);
 p2-- ;
   if(h1==0)
   {skore++;
   r5=225+rand()%75;
    p2=450; }

 }


void hurdle3(void)

{
rectangle(h3,r4,h3+30,400);
  h3=600+p3 ;
  p3-- ;
  if(h3==0)
 {skore++;
 p3=50 ;
 r4=260+rand()%100 ;}
 }

void uphurdle(void)
{u1=400+up;
  up--;
 rectangle(u1,r6-80,u1+30,20);
 if(u1==0)
 {up=250 ;
  r3=rand()%200;}


 }



void uphurdle1(void)
{ u2=200+up1;
up1-- ;
rectangle(u2,r5-80,u2+30,20);
 if(u2==0)
 {up1=450 ;
 r1=rand()%160 ;}

 }

void uphurdle2(void)
{ u3=600+up2 ;
 rectangle(u3,r4-80,u3+30,20);
 if(u3==0)
 {up2=50 ; }
 up2--;

 }


void score(void)
{
 sprintf(scr,"h= %d h1= %d" ,h,h1);
 settextstyle(2,0,6);
 outtextxy(10,420,scr);
   outtextxy(230,420,"player name");
 outtextxy(530,420,"level 1");

}
///////////////// hurdle se takrane pe out hone ki condition///////


 void fpage(void) {
 settextstyle(7,0,7);
 setcolor(RED);
 outtextxy(50,50,"SAVE THE BIRD");
 settextstyle(1,0,4);
 setcolor(1);
 outtextxy(150,180,"1) START GAME");
 outtextxy(150,240,"2) HIGH SCORES");
 outtextxy(150,300,"3) INSTRUCTIONS");
 outtextxy(150,360,"4) GRAPHS");
 outtextxy(150,420,"5) EXIT");
 }


 void graph(int y1, int y2, int y3)
{
settextstyle(DEFAULT_FONT,0,1);
setcolor(YELLOW);
line(100,100,100,400);        // Y AXIS
line(100,400,400,400);         // X AXIS
line(90,100,100,100);
outtextxy(70,100,"300");
line(90,200,100,200);
outtextxy(70,200,"200");
line(90,300,100,300);
outtextxy(70,300,"100");
outtextxy(90,410,"0");
line(200,410,200,400);
outtextxy(200,420,"1");
line(300,410,300,400);
outtextxy(300,420,"2");
line(400,410,400,400);
outtextxy(400,420,"3");
outtextxy(90,90,"Y-AXIS");
outtextxy(420,400,"X-AXIS");
 line(200,400-y1,200,400);
 line(300,400-y2,300,400);
 line(400,400-y3,400,400);
}

 void scoreboard(void)
{
  settextstyle(7,0,6);
  outtextxy(100,50,"SCORE BOARD");
  settextstyle(7,0,2);
  setcolor(15);
  outtextxy(100,200,"position");
  outtextxy(230,200,"player name");
  outtextxy(400,200,"score");
  settextstyle(1,0,1);
  outtextxy(120,250,"1-");
  outtextxy(120,300,"2-");
  outtextxy(120,350,"3-");
   outtextxy(250,250,"player 1");
  outtextxy(250,300,"player 2");
   outtextxy(250,350,"player 3");
    outtextxy(400,250,"score 1");
     outtextxy(400,300,"score 2");
     outtextxy(400,350,"score 3");
     rectangle(90,190,500,380);
     line(220,190,220,380);
     line(390,190,390,380);
     line(90,230,500,230);

}













