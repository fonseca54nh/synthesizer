//
//  main.cpp
//  sfml_test
//
//  Created by Bruno on 8/18/18.
//  Copyright © 2018 Bruno. All rights reserved.
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow win( sf::VideoMode(600,600), "MY First Synth");
    
    const int unsigned samples = 44100;
    const int unsigned sample_rate = 44100;
    const int unsigned amplitude = 30000;
    
    sf::Int16 raw[samples];
    
    // const double PI = 3.14159;
    const double TWO_PI = 6.28318;
    const double increment = 440./44100;
    double x = 0;
    int y = 1;
    for (unsigned i = 0; i < samples; i++)
    {
        raw[i] = amplitude * sin( y * x * TWO_PI);
        x += increment;
    }
    
    sf::SoundBuffer Buffer;
    
    if(!Buffer.loadFromSamples(raw, samples, 1, sample_rate))
    {
        std::cerr << "Loading failed" << std::endl;
        return 1;
    }
    
    /* sf::Sound sound;
     
     sound.setBuffer(Buffer);
     sound.setLoop(true);
     
     */
    
    sf::Sound sound;
    
    while(win.isOpen())
    {
        sf::Event e;
        
        while(win.pollEvent(e))
        {
            switch(e.type)
            {
                case sf::Event::Closed:
                    win.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    std::cout << "A Key was pressed" << std::endl;
                    
                    switch (e.key.code)
                {
                    case sf::Keyboard::A :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 1 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::S :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 1.5 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::D :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.4 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::F :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.5 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::G :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.6 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::H :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.7 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::J :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.8 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::K :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 0.9 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                        
                    case sf::Keyboard::L :
                        for (unsigned i = 0; i < samples; i++)
                        {
                            raw[i] = amplitude * sin( 1 * x * TWO_PI);
                            x += increment;
                        }
                        Buffer.loadFromSamples(raw, samples, 1, sample_rate);
                        
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.play();
                        break;
                }
                    break;
                    
                case sf::Event::KeyReleased:
                    std::cout << "Key released" << std::endl;
                    switch(e.key.code)
                {
                    case sf::Keyboard::A:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::S:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::D:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::F:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::G:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::H:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::J:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::K:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                        
                    case sf::Keyboard::L:
                        sound.setBuffer(Buffer);
                        sound.setLoop(true);
                        sound.stop();
                        break;
                }
            }
        }
        
        
        sf::sleep(sf::milliseconds(100));
    }
    
    return 0;
}


