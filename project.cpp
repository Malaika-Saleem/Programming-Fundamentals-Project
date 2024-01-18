#include<SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<sstream>
using namespace sf;

int tlsz=54; // here we declare the tile size equal to 54

Vector2i offset (48,24);  

struct piece  //construction of grid through struct (construction) function
{int x,y,col, row, type, same, var;  

piece() {type=0; var=255;} //declaring rows columns //type is for checking if the pics on the grid are  same //if kind is samen then they match


} grid[10][10];   //this is a 2 d array having 10 10 elements but we will make a grid of only 8 8


void swap(piece pc1,piece pc2)
{
std::swap(pc1.col,pc2.col);  //swapping two pieces in same column
std::swap(pc1.row,pc2.row); //swapping two pieces in same row


grid[pc1.row][pc1.col]=pc1;  //piece 1 of row and piece 1 of col
grid[pc2.row][pc2.col]=pc2;  //piece 2 of row and piece 2 of col
}

void matched() //creating a funtion called matched that works when 3 consecutive tiles match
{
	for(int i=1;i<=8;i++) //leaving first and last element empty of grid so i starts from 1 and reaches till 8
	{
		for (int j=1;j<=8;j++)  //leaving first and last element empty of grid so j starts from 1 and reaches till 8
		{
		if (grid[i][j].type==grid[i+1][j].type)  //  checking if the piece above a certain piece are same or not
		if (grid[i][j].type==grid[i-1][j].type)  //  checking if the piece below a certain piece are same or not

		for(int k=-1;k<=1;k++)  //k starts from -1 as to start the count below the piece itself
			{
				grid[i+k][j].same++;  //it increases count whenever the 3 consecutive pieces are same
			}

		if (grid[i][j].type==grid[i][j+1].type) //  checking if the piece on the right a certain piece are same or not
		if (grid[i][j].type==grid[i][j-1].type) //  checking if the piece on the left a certain piece are same or not 
		
		for(int k=-1;k<=1;k++)  //k starts from -1 as to start the count one left to the piece itself
			{
				grid[i][j+k].same++; //it increases count whenever the 3 consecutive pieces are same
			}
		}
	}
}

int main()
{
srand(time(0));

RenderWindow app(VideoMode(740,480), "Avengers Assemble!");  //our game is called Avengers Assemble
app.setFramerateLimit(60);

Texture text1, text2; //declaring two textures

text1.loadFromFile("background3.jpeg"); //loadFromFile function inputs that file from given location
text2.loadFromFile("gems1.jpeg");    //loadFromFile function inputs that file from given location

Sprite background(text1), gems(text2);  //taking background and tile sprites 

int x,y;
	for (int i=1;i<=8;i++)   //leaving first and last element empty of grid so i starts from 1 and reaches till 8
	for (int j=1;j<=8;j++)  //leaving first and last element empty of grid so i starts from 1 and reaches till 8
		{
		grid[i][j].type=rand()%7;   //rand function used to pick any random tile from all of the tiles
		grid[i][j].col=j;  //place apiece in column  
		grid[i][j].row=i;  //place apiece in row
		grid[i][j].x=j*tlsz; //adjust tilesze of piece in column 
		grid[i][j].y=i*tlsz;   //adjust tilesze of piece in row
		}
	int xprime,yprime;  //initializing variables
	int click=0; 
	//variable to put in positions where pieces are removed after a match
	Vector2i position;  
	bool swapping=false, moving=false;   //bools to check if piece is able to move or not i.e forms a match or not
		while (app.isOpen())   //while the app is open means while the window displays the game
		{
			sf::Event event;  //Events is a function in sfml that intakes actions occured by mouse or keyboard
			while (app.pollEvent(event)) //event poll caters different types of events
			{
				switch(event.type) //switch statement to check different types of events
				{
					case sf::Event::Closed: //Event type is clicking of close button on window
					app.close();  //when the cross button is clicked the app is closed
					break;
				}
			
			//case sf::Event::KeyPressed:
		if (event.type==Event::MouseButtonPressed)  //event is when mouse button is pressed
		switch(event.key.code)  // switch to check event key code

		case sf::Mouse::Left:  // when left button of mouse is clicked or pressed
		{
			if(!swapping && !moving) // when left button of mouse is clicked or pressed and the piesec are not same then click would be increased by one. if user runs out of certain number of clicks then game will be over
			click++;
			
		position=Mouse::getPosition(app)-offset; //if position of mouse is not in the window
		break;
		}
			}
// ewhen mouse is clicked
switch(click)  //switch statement for clicks
	{
	case 1:
	{
		xprime=position.x/tlsz+1;   //setting x prime according to the position and size of x
		yprime=position.y/tlsz+1;   //setting y prime according to the position and size of y
	}
	case 2:
	{
		x=position.x/tlsz+1;   //setting x according to the position and size of x
		y=position.y/tlsz+1;  //setting y according to the position and size of y

		if (abs(x-xprime)+abs(y-yprime)==1) //abs function returns absloute value // if statemet if equal to 1
		{
			swap(grid[yprime][xprime], grid[y][x]); //swapping the previous tiles with the x and y prime tiles
			 swapping=1; //swapping is equal to 1
			 click=0;
		}
		else if (abs(x-xprime)+abs(y-yprime)!=1) //abs function returns absloute value  // if statemet if not equal to 1
		
		{	click=1;	} //clicks become 1
	}
	}
//match finding
matched(); 

//Moving the tiles //is the piece is not moving
moving=false;
	for (int i=1;i<=8;i++)//leaving first and last element empty of grid so i starts from 1 and reaches till 8

	for (int j=1;j<=8;j++)//leaving first and last element empty of grid so j starts from 1 and reaches till 8
	{
		piece &pc= grid[i][j]; 
		int dx,dy;
		for(int k=0;k<4;k++)	//4-speed
		{
		dx=pc.x-pc.col*tlsz;  //swapping speed is set for x
		dy=pc.y-pc.row*tlsz;  //swapping speed is set for y
		
		if (dx) pc.x-=dx/abs(dx); //for dx
		if (dy) pc.y-=dy/abs(dy); //for dy
		}
	if(dx||dy) 
	moving=1;  //if any is true then piece will move
	}

// For Deleting the tiles
if (!moving)

for (int i=1;i<=8;i++) //leaving first and last element empty of grid so i starts from 1 and reaches till 8
for (int j=1;j<=8;j++) //leaving first and last element empty of grid so j starts from 1 and reaches till 8
if (grid[i][j].same)  //if the tiles are same
if (grid[i][j].var>10) 
 {
 grid[i][j].var-=10; //subtract ten from value of grid to keep the range within 10
  moving=true; //tiles will move
  }

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

	//score 
	int score=0;
	sf::Font arial; //declare font as arial
	arial.loadFromFile("arial.ttf"); //call the text file from the folder
	std::ostringstream ssScore; //standard output string stream
	ssScore<<"Score: "<<score; // sfml method of cout
	sf::Text lblScore; //label score= lblScore

	lblScore.setCharacterSize(30); //font size is 30
	lblScore.setPosition({ 480,10 }); //text position
	lblScore.setFont(arial); //text font
	lblScore.setString(ssScore.str()); //string method
 
for (int i=1;i<=8;i++)//leaving first and last element empty of grid so i starts from 1 and reaches till 8
for (int j=1;j<=8;j++)//leaving first and last element empty of grid so j starts from 1 and reaches till 8

	if(grid[i][j].same) //if tiles are same
	{
	score++;
	ssScore.str(""); //so that score doesnt appear again on the window but the previous one is edited
	ssScore<<"Score "<<score; //sstring way of cout
	lblScore.setString(ssScore.str()); //string method
	}

//second swap if no match
if(swapping && !moving) //if tiles are not same swapping is not possible
{
if(!score) //if score is not added
{
swap(grid[yprime][xprime],grid[y][x]); //then swap them back into previou positions
swapping=0;//thus there will be no swapping
}
}
//Update grid 

if (!moving) //if the tiles are not moving 
{
for(int i=8;i>0; i--) 
for (int j=1;j<=8;j++)

if (grid[i][j].same) //if tiles are same


for(int k=i;k>0;k--) //for rows they come down

if (!grid[k][j].same)  //if still tiles dont match
{
swap(grid[k][j],grid[i][j]); //then swap original rows
break;
}



for(int j=1;j<=8;j++)  //now if columns 
for (int i=8;i>0;i--)
if (grid[i][j].same) //if they are same
{
int k=0;
grid[i][j].type=rand()%7; //add random tile and update grid

grid[i][j].y=-tlsz*k++; //according to tile size
grid[i][j].same=0; // and it shouldnt be sane as previous one
grid[i][j].var=255; //adjusting accordng to var
}


}

//scoredisp
for (int i=1;i<=8;i++)
for (int j=1;j<=8;j++)

if(grid[i][j].same)
{
score++;
ssScore.str("");
ssScore<<"Score "<<score;
lblScore.setString(ssScore.str());
}


//draw
app.draw(background); //this function draws or displays the background
app.draw(lblScore);   //this function displays the label score
for (int i=1;i<=8;i++) //leaving first and last element empty of grid so i starts from 1 and reaches till 8
for (int j=1;j<=8;j++)//leaving first and last element empty of grid so j starts from 1 and reaches till 8
{
	piece temp=grid[i][j]; //pc here means the ith and jth element 

	gems.setTextureRect( IntRect(temp.type*49,0,49,49));  //setTextureRect is used to set texture of the pieces
	gems.setColor(Color(255,255,255,temp.var));  //setColor is used to set color of the pieces
	gems.setPosition(temp.x,temp.y);     //setPosition is used to set position at which tile will appear
	gems.move(offset.x-tlsz, offset.y-tlsz);   //This function is used to move the sprites or pieces
	app.draw(gems); //this function draws or displays the sprites on tiles
}

app.display(); //this function displays the whole app or window

}
return 0;
}
