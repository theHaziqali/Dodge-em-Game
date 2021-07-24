//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
//#include "write.cpp"
#include<fstream>
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<sstream>
using namespace std;
int path1;
int path2;
//int x=0;
float xx = 370; //x co-ordinate of the opponent car
float yy = 40;// y co-ordinate of the opponent car
float xx1=370;//x co-ordinate of the user car
float yy1=40;//y co-ordinate of the user car
int xfood=30;// x co-ordinate of food
int yfood=730;// y co-ordinate of food
int power=0;
int foodraidus1=10,foodraidus2=10,foodraidus3=10,foodraidus4=10,foodraidus5=10;
int mycarkey=1;
int stop=0;
int Hscore;
//foodcounter=0;
int sx = 20;
int sy = 10;
int menu=0;
int revolution=0;
int gate=0;
int n=0;
int nscore=0;
int nlevel=1;
int life=3;
int k=2;
//string sscore="score=";
void car5()
{	float x13 = 200;
	float y13 = 360;
	float height=7;
	float width=7;
	float radius=5;
	float* carcolor = colors[RED]; 
	DrawRoundRect(x13,y13,width,height,carcolor,radius); // bottom left tyre
	DrawRoundRect(x13+width*3,y13,width,height,carcolor,radius); // bottom right tyre
	DrawRoundRect(x13+width*3,y13+height*4,width,height,carcolor,radius); // top right tyre
	DrawRoundRect(x13,y13+height*4,width,height,carcolor,radius); // top left tyre
	DrawRoundRect(x13+width, y13+height, width*2, height*3, carcolor, radius/2); // body center rect
}
void car6()
{
	float x14 = 100;
	float y14 = 360;
	float height=7;
	float width=7;
	float radius=5;
	float* carcolor = colors[WHITE]; 
	DrawRoundRect(x14,y14,width,height,carcolor,radius); // bottom left tyre
	DrawRoundRect(x14+width*3,y14,width,height,carcolor,radius); // bottom right tyre
	DrawRoundRect(x14+width*3,y14+height*4,width,height,carcolor,radius); // top right tyre
	DrawRoundRect(x14,y14+height*4,width,height,carcolor,radius); // top left tyre
	DrawRoundRect(x14+width, y14+height, width*2, height*3, carcolor, radius/2); // body center rect

}

int opponentcarx[140]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int opponentcary[140]=  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
int arrayleftdotsx[140]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int arrayleftdotsy[140]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int array2dotsx[112]=  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0};
int array2dotsy[112]=  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0};
int array3dotsx[80]=   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0};  
int array3dotsy[80]=   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			 0,0,0,0,0,0,0,0,0,0,0,0};
int array4dotsx[56]=   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int array4dotsy[56]=   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int z=0;
	float xd = 20; 
	float yd = 50; 
	float widthd = 8; 
	float heightd = 8;
	float* colord = colors[GRAY]; 
	float radiusd = 2.0;
void usercarloop()
{
/*
if(xx1>40 && xx1<=750 && yy1==40)
{
//cout<<xx1<<endl;
//cout<<yy1<<endl;
xx1-=2;}
else if(yy1>=40 && yy1<744 && xx1==30)
{//cout<<xx1<<endl;
//cout<<yy1<<endl;
yy1+=2;
}
else if(xx1<750 && xx1>=40 && yy1==744)
{
xx1+=2;
}
else if(yy1<=744 && yy1>40 && xx1==750)
{
yy1-=2;
}
else if(xx1>120 && xx1<=672 && yy1==120)
{//cout<<xx1<<endl;
//cout<<yy1<<endl;

xx1-=2;}
else if(yy1>=120 && yy1<666 && xx1==120)
{//cout<<xx1<<endl;
//cout<<yy1<<endl;
yy1+=2;}
else if(xx1<672 && xx1>=120 && yy1==666)
{
xx1+=2;}
else if(yy1<=666 && yy1>120 && xx1==672)
{
yy1-=2;}
*/



	//user car loop for outer ring
for(int i=1;i<=4;i++)
	{
	if(xx1>=30 && yy1==40)
	xx1=xx1-k;
	if(yy1>=40 && xx1==30)
	if(yy1<=740)
	yy1=yy1+k;
	if(yy1>=740)
	if(xx1<750)
	xx1=xx1+k;
	if(xx1>=750)
	if(yy1>30)
	yy1=yy1-k;
	if(xx1>=110&&xx1<=120)
	if(yy1>90&&yy1<=660)
	yy1=yy1+k;
	if(xx1<=690&&xx1>=110)
	if(yy1>=120&&yy1<=130)
	xx1=xx1-k;	
	if(yy1>=660&&yy1<=670)
	if(xx1>=114&&xx1<=690)
	xx1=xx1+k;
	if(xx1>=660&&xx1<=670)
	if(yy1<=670&&yy1>=130)
	yy1=yy1-k;
	if((yy1>=190&&yy1<=200)&&(xx1<=610&&xx1>=190))  //track 3
	xx1=xx1-k;
	if((xx1>=180&&xx1<=190)&&(yy1>=190&&yy1<=590))
	yy1=yy1+k;
	if((xx1>=180&&xx1<=600)&&(yy1>=590&&yy1<=610))
	xx1=xx1+k;
	if((xx1>=600&&xx1<=610)&&(yy1<=610&&yy1>=200))
	yy1=yy1-k;					//track 3 ends
	if((yy1>=250&&yy1<=270)&&(xx1<=540&&xx1>=250))  //track 4
	xx1=xx1-k;
	if((xx1>=240&&xx1<=260)&&(yy1>=250&&yy1<=520))
	yy1=yy1+k;
	if((xx1>=250&&xx1<=540)&&(yy1>=520&&yy1<=540))
	xx1=xx1+k;
	if((xx1>=530&&xx1<=550)&&(yy1<=540&&yy1>=250))
	yy1=yy1-k;					//track 4 ends
		 
}
}
void opponentcarloop()
{
	//opponent car loop for outer ring
	for(int i=1;i<=4;i++)
	{
	if((xx<=800) && (yy==40))
		xx=xx+02;
	if(yy>=40 && xx>=750)
	if(yy<=780)
		yy=yy+2;
	if(yy>=740&&yy<=780)
		xx=xx-2;
	if(xx<=30)
		yy=yy-2;
	if((yy>=650&&yy<=680)&&(xx<=680&&xx>=120))
		xx=xx-2;
	if((xx>=100&&xx<=120)&&(yy>=120&&yy<=680))
		yy=yy-2;	
	if((yy>=100&&yy<=120)&&(xx>=100&&xx<=670))	
	{	xx=xx+2;
		if(revolution==1) {
		cout<<"haziq";
		if((xx>=370&&xx<=420)&&(yy>=100&&yy<=120)) 
		{yy=yy-78;revolution=0;cout<<"hazia";		}
	}}
	if((yy>=100&&yy<=680)&&(xx>=670&&xx<=680))
		{yy=yy+2; }
	if((xx1>=300&&xx1<=720)&&(yy1>=300&&yy1<=720))
		revolution=1;
	if(!((xx1>=300&&xx1<=720)&&(yy1>=300&&yy1<=720)))
		revolution=0;	
}
}
void foodcheck()
{// food intializer
z=0;
for(int n=0;n<35;n++){ 

z=z+20;
arrayleftdotsx[n]=(xd)+widthd*3;
arrayleftdotsy[n]=(yd+z)+heightd*2;//cout<<(yd+z)+heightd*2;
}
z=0;
for(int n=35;n<70;n++)
{
z=z+20;
arrayleftdotsx[n]=(xd+z)+widthd*3;
arrayleftdotsy[n] = yd+heightd*2;
}
z=0;
for(int n=70;n<105;n++)
{
z=z+20;//
arrayleftdotsx[n]=(xd+z)+widthd*3; 
arrayleftdotsy[n]=(yd+700)+heightd*2;
}
z=0;
for(int n=105;n<140;n++)
{
z=z+20;
arrayleftdotsx[n]=(xd+720)+widthd*3; 
arrayleftdotsy[n]=(yd+z)+heightd*2;
}
z=0;
for(int n=0;n<28;n++)
{
z=z+20;
array2dotsx[n]=(xd+90)+widthd*3; 
array2dotsy[n]=(yd+z)+80;
}
z=0;
for(int n=28;n<56;n++)
{
z=z+20;
array2dotsx[n]=(xd+640)+widthd*3; 
array2dotsy[n]=(yd+z)+80;
}
z=0;
for(int n=56;n<84;n++)
{
z=z+20;
array2dotsx[n]=(xd+85+z)+widthd*3; 
array2dotsy[n]=yd+90;
}
z=0;
for(int n=84;n<112;n++)
{
z=z+20;
array2dotsx[n]=(xd+85+z)+widthd*3; 
array2dotsy[n]= yd+640;
}
z=0;
for(int n=0;n<20;n++)
{
z=z+20;
array3dotsx[n]=(xd+140+z)+widthd*3; 
array3dotsy[n]= yd+570;
}
z=0;
for(int n=20;n<40;n++)
{
z=z+20;
array3dotsx[n]=(xd+140+z)+widthd*3; 
array3dotsy[n]= yd+170;
}
z=0;
for(int n=40;n<60;n++)
{
z=z+20;
array3dotsx[n]=(xd+570)+widthd*3; 
array3dotsy[n]=(yd+z)+170;
}
z=0;
for(int n=60;n<80;n++)
{
z=z+20;
array3dotsx[n]=(xd+160)+widthd*3; 
array3dotsy[n]=(yd+z)+170;
}
z=0;
for(int n=0;n<14;n++)
{
z=z+20;
array4dotsx[n]=(xd+230)+widthd*3; 
array4dotsy[n]=(yd+z)+220;
}
z=0;
for(int n=14;n<28;n++)
{
z=z+20;
array4dotsx[n]=(xd+500)+widthd*3; 
array4dotsy[n]=(yd+z)+220;
}
z=0;
for(int n=28;n<41;n++)
{
z=z+20;
array4dotsx[n]=(xd+230+z)+widthd*3; 
array4dotsy[n]=(yd)+230;
}
z=0;
for(int n=42;n<54;n++)
{
z=z+20;
array4dotsx[n]=(xd+230+z)+widthd*3;  
array4dotsy[n]=yd+500;
}
z=0;
}

void drawfood()
{
for(int n=0;n<140;n++)
{
if(((arrayleftdotsx[n]>=xx1)&&(arrayleftdotsx[n]<=xx1+36)&&((arrayleftdotsy[n]>=yy1)&&(arrayleftdotsy[n]<=yy1+36))))
{arrayleftdotsx[n]=-20;nscore++;}
}
for(int n=0;n<112;n++)
{
if (((array2dotsx[n]>=xx1)&&(array2dotsx[n]<=xx1+36)&&((array2dotsy[n]>=yy1)&&(array2dotsy[n]<=yy1+36))))
{array2dotsx[n]=-20;nscore++;}
}
for(int n=0;n<80;n++)
{
if (((array3dotsx[n]>=xx1)&&(array3dotsx[n]<=xx1+36)&&((array3dotsy[n]>=yy1)&&(array3dotsy[n]<=yy1+36))))
{array3dotsx[n]=-20;nscore++;}
}
for(int n=0;n<56;n++)
{
if (((array4dotsx[n]>=xx1)&&(array4dotsx[n]<=xx1+36)&&((array4dotsy[n]>=yy1)&&(array4dotsy[n]<=yy1+36))))
{array4dotsx[n]=-20;nscore++;}
}
for(int n=0;n<140;n++)
{ 
DrawRoundRect(arrayleftdotsx[n],arrayleftdotsy[n] , widthd, heightd, colord, radiusd/2);// outer left
}
for(int n=0;n<112;n++)
{
DrawRoundRect(array2dotsx[n],array2dotsy[n],  widthd, heightd, colord, radiusd/2);//left outer+1
}

for(int n=0;n<80;n++)
{
DrawRoundRect(array3dotsx[n],array3dotsy[n], widthd, heightd, colord, radiusd/2);
}

z=0;
for(int n=0;n<56;n++)
{
z=z+20;
DrawRoundRect(array4dotsx[n],array4dotsy[n], widthd, heightd, colord, radiusd/2);
}
}
void file_handling()
{


	int high_Scores[10] = { 200, 180, 170, 160}; //scores array
	
	//writing to a file
	ofstream fout;
	fout.open ("high score.txt"); //this function takes the name of the file that you are writing to
	
	for (int i = 0; i < 10; i++){
		fout << high_Scores[i] << endl;
	}
		
	fout.close();
	
	//reading from a file
	string score;
	ifstream fin ("high score.txt"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, score) ) //this loop will run depending on the number of lines in the file
		{
		  cout << score << '\n';
		  
		  //HINT: use stoi() to convert string into Integer
		  
		}
		fin.close();
	}
	
	else 
		cout << "Unable to open file"; 
	
	


}

 void DrawingArena()
{
// Drawing Arena
	int gap_turn = 60;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
}
void rectangle1()
{	

	//drawing rectangle 1
        int gap_turn1 = 60;
	int width1 = 800/2 - gap_turn1/2; // half width (width of the rectangle)
	int height1 = 10;//width of a line
	float *color1 = colors[BLUE];
	DrawRectangle(sx+(width1-290), sy+100, width1-90, height1, color1); // bottom left
	DrawRectangle(sx + width1 + gap_turn1,sy+100, width1-90, height1, color1); // bottom right
	DrawRectangle(sx+width1*2+gap_turn1-100, sy+height1+100, height1, width1-100, color1); // right down
	DrawRectangle(sx+width1*2+gap_turn1-100, sy+height1+width1+gap_turn1-0, height1, width1-100,color1); // right up
	DrawRectangle(sx + (width1) + gap_turn1, sy+710, width1-90, height1, color1); // top left line(right)
	DrawRectangle(sx+(width1-290), sy+710, width1-90, height1, color1); // top right line(left)

	DrawRectangle((sx-height1*2)+100, sy+height1+width1+gap_turn1, height1, width1-100, color1); // left up
	DrawRectangle((sx-height1*2)+100, sy+height1+100, height1, width1-105, color1); // left down
}
void rectangle2()
{	//drawing rectangle 2
        int gap_turn2 = 60;
	int width2 = 800/2 - gap_turn2/2; // half width (width of the rectangle)
	int height2 = 10;//width of a line
	float *color2 = colors[WHITE];
	DrawRectangle(sx+(width2-220), sy+170, width2-160, height2, color2); // bottom left
	DrawRectangle(sx + width2 + gap_turn2,sy+171, width2-160, height2, color2); // bottom right
	DrawRectangle(sx+width2*2+gap_turn2-170, sy+height2+170, height2, width2-171, color2); // right down
	DrawRectangle(sx+width2*2+gap_turn2-170, sy+height2+width2+gap_turn2-0, height2, width2-168,color2); // right up
	DrawRectangle(sx + (width2) + gap_turn2, sy+640, width2-160, height2, color2); // top left line(right)
	DrawRectangle(sx+(width2-220), sy+640, width2-160, height2, color2); // top right line(left)
	DrawRectangle((sx-height2*2)+170, sy+height2+width2+gap_turn2, height2, width2-168, color2); // left up
	DrawRectangle((sx-height2*2)+170, sy+height2+169, height2, width2-169, color2); // left down
	
}
void rectangle3()
{//drawing rectangle 3
        int gap_turn3 = 60;
	int width3 = 800/2 - gap_turn3/2; // half width (width of the rectangle)
	int height3 = 10;//width of a line
	float *color3 = colors[GREEN];
	DrawRectangle(sx+(width3-150), sy+240, width3-240, height3, color3); // bottom left
	DrawRectangle(sx + width3 + gap_turn3,sy+241, width3-230, height3, color3); // bottom right
	DrawRectangle(sx+width3*2+gap_turn3-240, sy+height3+240, height3, width3-241, color3); // right down
	DrawRectangle(sx+width3*2+gap_turn3-240, sy+height3+width3+gap_turn3-0, height3, width3-239,color3); // right up
	DrawRectangle(sx + (width3) + gap_turn3, sy+570, width3-230, height3, color3); // top left line(right)
	DrawRectangle(sx+(width3-150), sy+570, width3-240, height3, color3); // top right line(left)

	DrawRectangle((sx-height3*2)+240, sy+height3+width3+gap_turn3, height3, width3-239, color3); // left up
	DrawRectangle((sx-height3*2)+240, sy+height3+239, height3, width3-239, color3); // left down
	
}
void rectangle4()
{
	//drawing rectangle 4
	int gap_turn4 = 60;
	int width4 = 800/2 - gap_turn4/2; // half width (width of the rectangle)
	int height4 = 10;//width of a line
	float *color4 = colors[YELLOW];
	//DrawRectangle(sx+(width4-80), sy+310, width4-310, height4, color4); // bottom left
	DrawRectangle(sx + width4 + gap_turn4-140,sy+311, width4-160, height4, color4); // bottom right
	DrawRectangle(sx+width4*2+gap_turn4-310, sy+height4+310, height4, width4-311, color4); // right down
	DrawRectangle(sx+width4*2+gap_turn4-310, sy+height4+width4+gap_turn4-0, height4, width4-309,color4); // right up
	DrawRectangle(sx + (width4)-140 + gap_turn4, sy+500, width4-160, height4, color4); // top left line(right)
	//DrawRectangle(sx+(width4-80), sy+500, width4-310, height4, color4); // top right line(left)

	DrawRectangle((sx-height4*2)+310, sy+height4+width4+gap_turn4, height4, width4-309, color4); // left up
	DrawRectangle((sx-height4*2)+310, sy+height4+309, height4, width4-309, color4); // left down
}
void swapgates()
{
//swapgateright
if (xx1>=800 && (yy1>=370 && yy1<=420))
{xx1=40;}
//swapgateleft
if (xx1<=20 && (yy1>=370 && yy1<=420) )
{xx1=790;}
//swapgatetop
if ((xx1>=370 && xx1<=420) && yy1>790)
{yy1=30;}
//swapgatebottom
if ((xx1>=370&& xx1<420) && yy1<=20)
{yy1=760;}
}
void collisiondetection()
{
//car collision detection
	if((xx1+44>=xx&&xx1<=xx+36)&&(yy1<=yy+44&&yy1+44>=yy))
	{  xx=420;yy=40;
	   xx1=370;yy1=40;
	   life--;
	foodcheck();
	drawfood();
	nscore=0;

	}
}
/*void scorelives()

{
	DrawString( 50, 800, "Score=", colors[MISTY_ROSE]);
	DrawString( 700, 800, "lives=", colors[MISTY_ROSE]);
score<<nscore;
	lives<<nlives;
	DrawString( 50, 800, score.str(), colors[MISTY_ROSE]);
	DrawString( 770, 800, lives.str(), colors[MISTY_ROSE]);
//stringstream 


}*/

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0,/*red Component*/ 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students
if(menu==0)
{	
	
	DrawString( 300, 500, "press 1:to play game", colors[BLUE_VIOLET]);
	DrawString( 300, 400, "press 2:to for help", colors[BLUE_VIOLET]);
	DrawString( 300, 300, "press 3:to exit", colors[BLUE_VIOLET]);
}
if(menu==2)
{
DrawString( 50, 600, "1.Use arrow keys to control the your car " , colors[WHITE]);
	DrawString( 50, 575, "2.Your car color is RED ", colors[WHITE]);
	DrawString( 50, 550,  "3.Opponent car color is purple", colors[WHITE]);
	DrawString( 50, 525,  "4.Use spacebar to increase the speed of your car", colors[WHITE]);
	DrawString( 50, 500,  "5.Try to eat the dots without being caught by the police", colors[WHITE]);
	DrawString( 50, 475,  "6.Avoid the boundary walls", colors[WHITE]);
	DrawString( 50, 450,  "7.You have three lives", colors[WHITE]);
car5();

 car6();
}
if(!stop)
{
if(menu==1)
{
//int main(int argc, char*argv[]);
	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	stringstream score;
	score<<nscore;
	stringstream lives;
	lives<<life;
	stringstream level;
	level<<nlevel;

	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine( int x1, int y1, int x2 , int y2,int lwidth ,float*colour)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

	//DrawRoundRect(xx,yy+height*2, width, height, color, radius/2); // body left rect
	//DrawRoundRect(xx+width*3, yy+height*2, width, height, color, radius/2); // body right rect{
	//DrawRoundRect(xx1+width*3, yy1+height*2, width, height, carcolor, radius/2); // body right rect
  	//usercarcenter=(((xx1+xx1+width*3)/2) +((yy1+height*2)+(yy1+height*2))/2);cout<<usercarcenter<<endl;
	//DrawRoundRect(xx1,yy1+height*2, width, height, carcolor, radius/2); // body left rect
	//opponentcarcenter=(((xx+xx+width*3)/2) +((yy+height*2)+(yy+height*2))/2);//cout<<opponentcarcenter<<endl;



	glutPostRedisplay();
	if(life>0)
	{
	DrawingArena();
	DrawString(350,790,"Level :",colors[WHITE]);
	DrawString(450,790,level.str(),colors[WHITE]);
	DrawString(100,790,"Score=",colors[WHITE]);
	DrawString(200,790,score.str(),colors[WHITE]);
	DrawString(700,790,"lives=",colors[WHITE]);
	DrawString(770,790,lives.str(),colors[WHITE]);
	//stream.clear();
	// Drawing opponent car 
	float width = 10; 
	float height = 10;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;
	DrawRoundRect(xx,yy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(xx+width*3,yy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(xx+width*3,yy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(xx,yy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(xx+width, yy+height, width*2, height*3, color, radius/2); // body center rect
	
	
	//Drwaing user car

	float* carcolor = colors[RED]; 
	DrawRoundRect(xx1,yy1,width,height,carcolor,radius); // bottom left tyre
	DrawRoundRect(xx1+width*3,yy1,width,height,carcolor,radius); // bottom right tyre
	DrawRoundRect(xx1+width*3,yy1+height*4,width,height,carcolor,radius); // top right tyre
	DrawRoundRect(xx1,yy1+height*4,width,height,carcolor,radius); // top left tyre
	DrawRoundRect(xx1+width, yy1+height, width*2, height*3, carcolor, radius/2); // body center rect
	
	
	rectangle1();
	rectangle2();
	rectangle3();
	rectangle4();
	swapgates();
	//scorelives();	
	collisiondetection();
	drawfood();
	opponentcarloop();
	usercarloop();
		}   
		else{
	//if(life<1){
//	cout << menu << endl;
DrawString( 350, 500, "Game Over", colors[WHITE]);
//menu=5;}
//if(menu==5)
//{
//DrawSquare( 250 , 250 ,20,colors[GREEN]);

//DrawString( 500, 500, "Game Over", colors[WHITE]);
}
//DrawSquare(340,460,"GAME OVER",colors[BLACK]);
//}

/*	for(int i=1;i<=4;i++)
	{
	if(xx<=800 && yy==40)
	xx=xx+02;
	if(yy>=40 && xx>=750)
	if(yy<=780)
	yy=yy+2;
	if(yy>=740&&yy<=780)
	xx=xx-2;
	if(xx<=30)
	yy=yy-2;
	}*/
	//x=0;
	// file handling


if(nscore>=383)
nlevel=2;
//Opponent car intelligence
	if(nlevel==1)
	{
	if((xx1>=100&&xx1<=160)&&(yy1>=370&&yy1<=420) && gate==0)
	{gate=GetRandInRange(1,2);revolution=1;	}	
	if((xx>=370&&xx<=420)&&(yy>=730&&yy<=780)and gate == 1)
	{ yy=yy-70;gate=0;}
	if((xx>=370&&xx<=420)&&(yy>=30&&yy<=80)and gate == 2)
	{ yy=yy+70;gate=0;}
	}
	if(nlevel==2)
	{	
	glutPostRedisplay();

	drawfood();
	foodcheck();
	if((xx1>=100&&xx1<=160)&&(yy1>=370&&yy1<=420) && gate==0)
		{gate=GetRandInRange(1,3);revolution=1;	}	
	if((xx>=370&&xx<=420)&&(yy>=730&&yy<=780)and gate == 1)
		{ yy=yy-70;gate=0;}
	if((xx>=370&&xx<=420)&&(yy>=30&&yy<=80)and gate == 2)
		{ yy=yy+70;gate=0;}
	if((yy>=370&&yy<=420)&&(xx>=710&&yy<=730)and gate == 3)
		{xx=xx-70;gate=0;}	
	}
if(nscore>=1000)
{nlevel=3;
}
	if(nlevel==3)
{k=k+3;
}
}


}	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	

}



/*This function is called (automatically) w

 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y )
{
	
	if (key	== GLUT_KEY_LEFT) /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/ 
  	{
	if(!((((yy1>=0&&yy1<=370) || (yy1>=420&&yy1<=1000))&&(xx1<=30))))	
		{xx1=xx1-10;}
	//else if(!((((yy1>=0&&yy1<=370) || (yy1>=420&&yy1<=1000))&&(xx1>=110&&xx1<=130))))	
	//	{xx1=xx1-10;}
		
	if(yy1>=370 && yy1<420)
	xx1=xx1-10;
	

	}
	

		// what to do when left key is pressed...

	 else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {	
	if(!((((yy1>=0&&yy1<=370) || (yy1>=420&&yy1<=1000))&&(xx1>=780))))	
	{xx1=xx1+10;}
	if(yy1>=370 && yy1<420)
	xx1=xx1+10;
	if((xx1>=30 && xx1<60)&&(yy1>=370&&yy1<=420))		
	xx1=xx1+70;

	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	if(yy1>=60 && yy1<=70){	//blue line (bottom)
		if(!((((xx1>=100&&xx1<=370) || (xx1>=420&&xx1<=700))&&(yy1>=60&&yy1<=70))))	
		{yy1=yy1+10;}}
	else if(yy1>=760){//upper border
		if (!((((xx1>=0&&xx1<=370) || (xx1>=420&&xx1<=690))&&(yy1>=760))))	
		{yy1=yy1+10;}}
	else if((yy1>=130)&&(yy1<=140)){//white line(bottom)
		if((!((((xx1>=160&&xx1<=370) || (xx1>=420&&xx1<=630))&&(yy1>=130&&yy1<=140)))))
		yy1=yy1+10;}
	else if(yy1>=200&&yy1<=210){//green line (bottom)
		if((!((((xx1>=200&&xx1<=370) || (xx1>=420&&xx1<=580))&&(yy1>=200&&yy1<=210)))))
		yy1=yy1+10;}
	else if(yy1>=270&&yy1<=280){ //light green (bottom)
		if((!((((xx1>=280&&xx1<=510) || (xx1>=420&&xx1<=510))&&(yy1>=270&&yy1<=280)))))
		yy1=yy1+10;}
	else if((yy1>=460)&&(yy1<=470)){//light green (up) 
		if((!((((xx1>=280&&xx1<=510) || (xx1>=420&&xx1<=510))&&(yy1>=460&&yy1<=470)))))
		yy1=yy1+10;}
	else if(yy1>=530&&yy1<=540){//green line (up)
		if((!((((xx1>=200&&xx1<=370) || (xx1>=420&&xx1<=580))&&(yy1>=530&&yy1<=540)))))
		yy1=yy1+10;}
	else if((yy1>=600)&&(yy1<=610)){//white line(up)
		if((!((((xx1>=170&&xx1<=370) || (xx1>=420&&xx1<=650))&&(yy1>=600&&yy1<=610)))))
		yy1=yy1+10;}
	else if(yy1>=670 && yy1<=680){	//blue line (up)
		if(!((((xx1>=100&&xx1<=370) || (xx1>=420&&xx1<=700))&&(yy1>=670&&yy1<=680))))	
		{yy1=yy1+10;}}

	else 
	yy1=yy1+10;
	if((yy>=40&&yy<=60)&&(xx1>=370 && xx1<=420))
	yy1=yy1+70;
	else if((yy>=100&&yy<=120)&&(xx1>=370 && xx1<=420))
	yy1=yy1+70;
	else if((yy>=150&&yy<=170)&&(xx1>=370 && xx1<=420))
	yy1=yy1+50;
}
	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	if(yy1>=110 && yy1<=120){ 	//bottom line(blue line)
		if(!((((xx1>=100&&xx1<=370) || (xx1>=420&&xx1<=700))&&(yy1>=110&&yy1<=120))))	
		{yy1=yy1-10;}		}
	else if( yy1>=0&&yy1<=30){ //border line(bottom)
		if(!((((xx1>=0&&xx1<=370) || (xx1>=420&&xx1<=1000))&&(yy1<=30))))	
		{yy1=yy1-10;}}
	else if((yy1>=180)&&(yy1<=190)){//white line(bottom)
		if((!((((xx1>=180&&xx1<=370) || (xx1>=420&&xx1<=620))&&(yy1>=180&&yy1<=190)))))
		yy1=yy1-10;}
	else if(yy1>=250&&yy1<=260){//green(bottom)
		if((!((((xx1>=200&&xx1<=370) || (xx1>=420&&xx1<=550))&&(yy1>=250&&yy1<=260)))))
		yy1=yy1-10;}
	else if(yy1>=320&&yy1<=330){ //light green(bottom)
		if((!((((xx1>=300&&xx1<=510) || (xx1>=420&&xx1<=510))&&(yy1>=320&&yy1<=330)))))
		yy1=yy1-10;}

	else if((yy1>=510)&&(yy1<=520)){//light green (up) 
		if((!((((xx1>=280&&xx1<=510) || (xx1>=420&&xx1<=510))&&(yy1>=510&&yy1<=520)))))
		yy1=yy1-10;}
	else if(yy1>=580&&yy1<=590){//green line (up)
		if((!((((xx1>=200&&xx1<=370) || (xx1>=420&&xx1<=580))&&(yy1>=580&&yy1<=590)))))
		yy1=yy1-10;}
	else if((yy1>=650)&&(yy1<=660)){//white line(up)
		if((!((((xx1>=170&&xx1<=370) || (xx1>=420&&xx1<=650))&&(yy1>=650&&yy1<=660)))))
		yy1=yy1-10;}
	else if(yy1>=720 && yy1<=730){	//blue line (up)
		if(!((((xx1>=100&&xx1<=370) || (xx1>=420&&xx1<=720))&&(yy1>=720&&yy1<=730))))	
		{yy1=yy1-10;}}	
	else
	yy1=yy1-10;
	if((yy>=100&&yy<=120)&&(xx1>=370 && xx1<420))
	yy1=yy1-70;
	}
/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == '3'/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == '1')
			{
		menu=1;
			}
			if(key=='2')
			{
			menu=2;
			}
	if(int (key)=='p' || int (key)=='P')
	{	
	  stop=!stop;
	}
if(int (key)==' ')
{
if(k%2==0)
k=k+1;
else 
k=k-1;
}
if(int (key)=='4'){

	ifstream hs;
	hs.open("high_score.txt");
	hs>>Hscore;
	hs.close();
		if(Hscore< nscore)
		{
			Hscore= nscore;
		}
	ofstream hos;
	hos.open("high_score.txt");
	hos<<Hscore;
	hos.close();
menu=4;
}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	foodcheck();
	
	//int b = new Board(60, 60); // create a new board object to use in the Display Function ...
 file_handling();
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
