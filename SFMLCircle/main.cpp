#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
// done -- orbitting circle
// done - detects on spacebar whether it overlaps the rectangle
// todo : print out instructions for to press space over the circle
// todo: add sound on overlap success -- an engine, add points? , increase speed, put out a new skill check line ,put on appstore
// todo -- add checkpoints for when to keypress and make circle go faster

int defaultFrameRate = 144;

//todo
float  period_ms = 5000.f;
sf::Vector2f transform(float t)
{
    float const ellipse_width = 500.f;
    float const ellipse_height = 500.f;
    float const a = ellipse_width / 2.f;
    float const b = ellipse_height / 2.f;
    float const pi = 3.141592653589f;
    float tau = 2.f * pi;
    float const x = (std::fmodf(t, period_ms) / period_ms) * tau;
    return sf::Vector2f(a * std::cos(x), b * std::sin(x));
}
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000,1000), "SFML shapes", sf::Style::Default, settings);
    window.setFramerateLimit(defaultFrameRate);

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
    line.rotate(45.f);
    line.setPosition(600.f, 280.f);
    line.setRotation(100.f);
    //line white on top (skillcheck)
    sf::Clock clock;

    while (window.isOpen())
    {
       

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float const t = static_cast<float>(clock.getElapsedTime().asMilliseconds());
        shape.setPosition(sf::Vector2f(500.f, 500.f) + (transform(t)));
        int yCoord = shape.getPosition().y;
        int xCoord = shape.getPosition().x;

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            cout << fixed << setprecision(0) << "White circle position: " << shape.getPosition().x << " , " << fixed << setprecision(0) << shape.getPosition().y << "\n\n";
        }*/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (xCoord >= 570 && xCoord <= 590) && (yCoord >= 250 && yCoord <= 270))
        {

                window.clear(sf::Color::Black);
                period_ms = 4900.f;
                line.setPosition(670.f, 310.f);
                line.setRotation(125.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (xCoord >= 645 && xCoord <= 675) && (yCoord >= 290 && yCoord <= 310))
        {

            window.clear(sf::Color::Black);
            period_ms = 4800.f;
            line.setPosition(705.f, 340.f);
            line.setRotation(140.f);
        }
        
        window.clear();
        window.draw(shape);
        window.draw(shapeTwo);
        window.draw(line);
        window.display();

    }

    return 0;
}

