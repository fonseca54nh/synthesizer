
const int unsigned samples = 44100;
const int unsigned sample_rate = 44100;
const int unsigned amplitude = 30000;


// const double PI = 3.14159;
const double TWO_PI = 6.28318;
const double increment = 440./44100;
double  x = 0;
int     y = 1;

bool flag;

//template <typename T> constexpr T sf::Keyboard;

std::vector <char> keyName =
//char keyName[13]
{
    sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S,
    sf::Keyboard::E, sf::Keyboard::D, sf::Keyboard::F,
    sf::Keyboard::T, sf::Keyboard::G, sf::Keyboard::Y,
    sf::Keyboard::H, sf::Keyboard::U, sf::Keyboard::J, 
    sf::Keyboard::K 

};

//char *ptr = &keyName[0];

//std::vector <double> frequencies[9] = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};

sf::Int16 raw[samples];
sf::SoundBuffer Buffer[13];
sf::Sound sound[13];

float frequencies[13] = {0.26163, 0.27718, 0.29366, 0.31113, 0.32963, 0.34923, 0.36999, 0.392, 0.41530, 0.440,
 0.46616, 0.49388, 0.52325};


int dBuffer()
{
    for (int i = 0; i < 13; ++i)
    {
        if(!Buffer[i].loadFromSamples(raw, samples, 1, sample_rate))
        {
            std::cerr << "Loading failed" << std::endl;
            return 1;
        }
    }
}

void oscPlay(int k)
{
    for (unsigned i = 0; i < samples; i++)
    {       
        raw[i] = amplitude * sin(frequencies[k] * x * TWO_PI);
        x += increment;
    }

    Buffer[k].loadFromSamples(raw, samples, 2, sample_rate);
    sound[k].setBuffer(Buffer[k]);
    sound[k].setLoop(true);
    //sf::sleep(sf::milliseconds(100));
    sound[k].play();
}

void oscStop(int i)
{
    for (int i = 0; i < 13; ++i)
    {
        sound[i].setBuffer(Buffer[i]);
        sound[i].setLoop(true);
        sound[i].stop();
    
    }
}


/*
real time input
if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
    // 'W' is currently pressed, do something...
}*/

