#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
#include "osc.h"

using namespace std;

int main()
{
	   
	dBuffer();

	sf::RenderWindow win( sf::VideoMode(600,600), "MY First Synth");

	win.setKeyRepeatEnabled(false);

	sf::Event e;

	while(win.isOpen())
	{
		while(win.pollEvent(e))
		{
			
			if(e.type == sf::Event::Closed) win.close();
	        for(int i = 0; i < 13; ++i)
	        {
	        	if(e.type == sf::Event::KeyPressed)
	        	{
		        	if(e.key.code == keyName[i])
		        	{
			            oscPlay(i);
			        }
			    }

			    if(e.type == sf::Event::KeyReleased)
    			{
        			if(e.key.code == keyName[i]) {oscStop(i);}
    			}
			}
			/*for(int i = 0; i < 13; ++i)
			{
				if (sf::Keyboard::isKeyPressed::keyName[i])
				{
	    			oscPlay(i);
				}
			}*/
	        

	    }

	    //sf::sleep(sf::milliseconds(500));
	}
	
}