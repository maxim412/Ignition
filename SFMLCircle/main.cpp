#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

using namespace std;
// done -- orbitting circle
// done - detects on spacebar whether it overlaps the rectangle
// done -- plays sound when pressed space on overlapped crcle
// todo : print out instructions for to press space over the circle
// todo: add score
// todo -- add flames in backround on overlap spacebar success
// todo-- add more skillchecks
//todo, add rev soon

float timeFactor = 1.0f;
float accTime = 0.0f;
//todo

sf::Vector2f transform(float t)
{
    float const ellipse_width = 500.f;
    float const ellipse_height = 500.f;
    float const a = ellipse_width / 2.f;
    float const b = ellipse_height / 2.f;
    float const pi = 3.141592653589f;
    float  period_ms = 5000.f;
    float tau = 2.f * pi;
    float const x = (std::fmodf(t, period_ms) / period_ms) * tau;
    return sf::Vector2f(a * std::cos(x), b * std::sin(x));
}
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML shapes", sf::Style::Default, settings);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("snd.wav"))
    {
        cout << "error";
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setPlayingOffset(sf::seconds(.8f));


    window.setFramerateLimit(30);

    //orbitter white
    sf::CircleShape shape(28.f);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(5);
    //orbitter white

     //center red circle
    sf::CircleShape shapeTwo(208.f);
    shapeTwo.setFillColor(sf::Color::Red);
    shapeTwo.setOutlineThickness(5);
    shapeTwo.setOutlineColor(sf::Color(250, 150, 100));
    shapeTwo.setPosition(325.00, 320.00);
    //center red circle

    //line white on top (skillcheck)
    sf::RectangleShape line(sf::Vector2f(30.f, 5.f));
    line.setPosition(535.f, 260.f);
    line.setRotation(90.f);
    //line white on top (skillcheck)
    sf::Clock clock;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            int yCoord = shape.getPosition().y;
            int xCoord = shape.getPosition().x;

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                cout << fixed << setprecision(0) << "White circle position: " << shape.getPosition().x << " , " << fixed << setprecision(0) << shape.getPosition().y << "\n\n";
            }
            //spawn seconds (3pm)
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (xCoord >= 470 && xCoord <= 580 && yCoord >= 210 && yCoord <= 310))
            {
                sound.stop();
                sound.setPlayingOffset(seconds(.8f));
                sound.setVolume(40);
                sound.play();
                timeFactor = 2.0f;
                line.setPosition(790.f, 500.f);
                line.setRotation(178.f);
            }
            //spawn 3rd (6pm)
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (xCoord >= 730 && xCoord <= 810 && yCoord >= 430 && yCoord <= 530))
            {
                sound.stop();
                sound.setPlayingOffset(seconds(.8f));
                sound.setVolume(60);
                sound.play();
                timeFactor = 3.0f;
                line.setPosition(535.f, 755.f);
                line.setRotation(90.f);
            }
            //spawn 4th (9pm)
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (xCoord >= 490 && xCoord <= 580 && yCoord >= 710 && yCoord <= 790))
            {
                sound.stop();
                sound.setPlayingOffset(seconds(.8f));
                sound.setVolume(80);
                sound.play();
                timeFactor = 4.0f;
                line.setPosition(275.f, 495.f);
                line.setRotation(.1f);
            }
            //reset (12pm)
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (xCoord >= 225 && xCoord <= 325 && yCoord >= 445 && yCoord <= 545))
            {
                sound.stop();
                sound.setPlayingOffset(seconds(.8f));
                sound.setVolume(100);
                sound.play();
                timeFactor = 5.0f;
                line.setPosition(535.f, 260.f);
                line.setRotation(90.f);
            }

            /*if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) && (xCoord >= 702 && xCoord <= 782 && yCoord >= 402 && yCoord <= 482))
            {
                sound.setPlayingOffset(sf::seconds(.8f));
                sound.play();
                timeFactor = 2.0f;
                line.setPosition(780.f, 480.f);
                line.setRotation(174.f);
            }*/
            

        }
        float const dt = static_cast<float>(clock.getElapsedTime().asMilliseconds());
        accTime += dt * timeFactor;
        shape.setPosition(sf::Vector2f(500.f, 500.f) + (transform(accTime)));
        clock.restart();


        window.clear();
        window.draw(shape);
        window.draw(shapeTwo);
        window.draw(line);
        window.display();

    }

    return 0;
}

