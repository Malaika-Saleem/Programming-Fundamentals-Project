#include<SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<sstream>
using namespace sf;
/*void scr()
{
if (!isMoving)
{
for(int i=8;i>0; i--) 
for (int j=1;j<=8;j++)
{
if (grid[i][j].match)
{
score++;
ssScore.str("");
ssScore<<"Score "<<score;
lblScore.setString(ssScore.str());
}
}*/

int tlsz=54; //tile size

Vector2i offset (48,24);

struct piece 
{int x,y,col, row, kind, match, alpha;

piece() {match=0; alpha=255;}

} grid[10][10];

void swap(piece pc1,piece pc2)
{
std::swap(pc1.col,pc2.col); 
std::swap(pc1.row,pc2.row);

grid[pc1.row][pc1.col]=pc1; 
grid[pc2.row][pc2.col]=pc2;
}

int main()
{
srand(time(0));

RenderWindow app(VideoMode(740,480), "Avengers Assemble!"); 
app.setFramerateLimit(60);

Texture t1, t2;

t1.loadFromFile("background3.jpeg"); 
t2.loadFromFile("gems1.jpeg");

Sprite background(t1), gems(t2);

for (int i=1;i<=8;i++) 
for (int j=1;j<=8;j++)
{
grid[i][j].kind=rand()%7; 
grid[i][j].col=j;
grid[i][j].row=i; 
grid[i][j].x=j*tlsz;
grid[i][j].y=i*tlsz;
}
int x0,y0,x,y;
int click=0;
Vector2i pos;
bool isSwap=false, isMoving=false;
while (app.isOpen())
{
sf::Event event;
while (app.pollEvent(event))
{
switch(event.type)
{
case sf::Event::Closed:
app.close();
break;
}
//case sf::Event::KeyPressed:

//case sf::Event::MouseButtonPressed:
if (event.type==Event::MouseButtonPressed) 

switch(event.key.code)

case sf::Mouse::Left:
{
if(!isSwap && !isMoving)
click++;

pos=Mouse::getPosition(app)-offset;
break;
}
}
// mouse click 
switch(click)
{
case 1:
{
x0=pos.x/tlsz+1; 
y0=pos.y/tlsz+1;
}
case 2:
{
x=pos.x/tlsz+1; 
y=pos.y/tlsz+1;

if (abs(x-x0)+abs(y-y0)==1)
{
swap(grid[y0][x0], grid[y][x]); isSwap=1;click=0;
}
else if (abs(x-x0)+abs(y-y0)!=1)
{click=1;}
}
}

//Match finding

for(int i=1;i<=8;i++) 
for (int j=1;j<=8;j++)
{
if (grid[i][j].kind==grid[i+1][j].kind) 
if (grid[i][j].kind==grid[i-1][j].kind)

for(int n=-1;n<=1;n++) grid[i+n][j].match++;

if (grid[i][j].kind==grid[i][j+1].kind)

if (grid[i][j].kind==grid[i][j-1].kind) 
for(int n=-1;n<=1;n++) grid[i][j+n].match++;
}
//Moving animation 
isMoving=false;
for (int i=1;i<=8;i++)

for (int j=1;j<=8;j++)
{
piece &p= grid[i][j]; 
int dx,dy;
for(int n=0;n<4;n++)	//4-speed
{dx=p.x-p.col*tlsz; 
dy=p.y-p.row*tlsz;
if (dx) p.x-=dx/abs(dx);
if (dy) p.y-=dy/abs(dy);
}
if(dx||dy) isMoving=1;
}

//Deleting animation 
if (!isMoving)

for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)
if (grid[i][j].match) if (grid[i][j].alpha>10) {grid[i][j].alpha-=10; isMoving=true;}

/*
//score 
int score=0;
sf::Font arial;
arial.loadFromFile("arial.ttf");
std::ostringstream ssScore; //standard output string stream
ssScore<<"Score: "<<score;
sf::Text lblScore;

lblScore.setCharacterSize(30);
lblScore.setPosition({ 480,10 });
lblScore.setFont(arial);
lblScore.setString(ssScore.str());
score();*/

//Get score 
int score=0;
sf::Font arial;
arial.loadFromFile("arial.ttf");
std::ostringstream ssScore; //standard output string stream
ssScore<<"Score: "<<score;
sf::Text lblScore;

lblScore.setCharacterSize(30);
lblScore.setPosition({ 480,10 });
lblScore.setFont(arial);
lblScore.setString(ssScore.str());
 
for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)

if(grid[i][j].match)
{
score++;
ssScore.str("");
ssScore<<"Score "<<score;
lblScore.setString(ssScore.str());
}

//second swap if no match
if(isSwap && !isMoving)
{if(!score) swap(grid[y0][x0],grid[y][x]); isSwap=0;}

//Update grid 

if (!isMoving)
{
for(int i=8;i>0; i--) 
for (int j=1;j<=8;j++)

if (grid[i][j].match)


for(int n=i;n>0;n--)

if (!grid[n][j].match) {swap(grid[n][j],grid[i][j]); break;};



for(int j=1;j<=8;j++) 
for (int i=8,n=0;i>0;i--)
if (grid[i][j].match)
{
grid[i][j].kind=rand()%7;

grid[i][j].y=-tlsz*n++;
grid[i][j].match=0;
grid[i][j].alpha=255;
}


}
//scoredisp
for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)

if(grid[i][j].match)
{
score++;
ssScore.str("");
ssScore<<"Score "<<score;
lblScore.setString(ssScore.str());
}

/*if (!isMoving)
{
for(int i=8;i>0; i--) 
for (int j=1;j<=8;j++)
{
if (grid[i][j].match)
{
score++;
ssScore.str("");
ssScore<<"Score "<<score;
lblScore.setString(ssScore.str());
}*/
//draw
app.draw(background);
app.draw(lblScore);
for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)
{
piece pc=grid[i][j];

gems.setTextureRect( IntRect(pc.kind*49,0,49,49)); 
gems.setColor(Color(255,255,255,pc.alpha));
gems.setPosition(pc.x,pc.y); 
gems.move(offset.x-tlsz, offset.y-tlsz);
app.draw(gems);
}

app.display();

}
return 0;
}


