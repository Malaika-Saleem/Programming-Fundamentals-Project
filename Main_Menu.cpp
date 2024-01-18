//Noor-ul-ain
//22i-0608
//AI-C
//Main Menu
#include <SFML/Graphics.hpp>//libraries
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
int main()//Main Menu
{
sf::RenderWindow window(sf::VideoMode(1200, 700), "Avengers Assemble",sf::Style::Default);//It will display the title of ourr game which is avengers assemble
	sf::Texture background;
	sf::Sprite backgroundImage;
	
	while (window.isOpen())
		{
			sf::Font arial;//This is the Font style of our Menu page
		        arial.loadFromFile("arial.ttf");
	 		
			sf::Text Text7;//declaring Text 7
			Text7.setFont(arial);
			Text7.setStyle(sf::Text::Bold);
			Text7.setString("#  NORMAL MODE");//Normal mode will be displayed in bold 
			Text7.setFillColor(sf::Color::Red);//Color of normal will be Red because it matches with our theme.
			Text7.setPosition(60, 400);
			sf::Text Text8;//declaring text 8
			Text8.setFont(arial);//arial is the font of 
			Text8.setStyle(sf::Text::Bold);//text is in bold font
			Text8.setString("#  TRAIL MODE");
			Text8.setFillColor(sf::Color::Red);
			Text8.setPosition(60, 450);
			sf::Text Text9;
			Text9.setFont(arial);//arial is the font 
			Text9.setStyle(sf::Text::Bold);
			Text9.setString("#  HIGHEST SCORE");
			Text9.setFillColor(sf::Color::Red);
			Text9.setPosition(70, 500);
			sf::Text Text0;//declaring text 0
			Text0.setFont(arial);
			Text0.setStyle(sf::Text::Bold);
			Text0.setString("#  HELP");
			Text0.setFillColor(sf::Color::Red);
			Text0.setPosition(70, 550);
			sf::Event Event;
			while (window.pollEvent(Event))
			{
				switch (Event.type)
				{
					case sf::Event::Closed:
						window.close();
						break;
					
                {
                    
                }
                break;
            }
            
        }
        window.clear();
 
       
        window.draw(Text7);
        window.draw(Text8);
        window.draw(Text9);
        window.draw(Text0);
        window.display();
    }
    
    
        
    return 0;
}
