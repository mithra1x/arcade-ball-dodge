#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arcade Oyun: Top və Bloklar");
    window.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(0)));


    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(390.f, 500.f);
    float speed = 7.f;

   
    std::vector<sf::RectangleShape> blocks;
    float blockSpeed = 3.f;
    int spawnCounter = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            ball.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            ball.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ball.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ball.move(speed, 0);

        
        spawnCounter++;
        if (spawnCounter > 30) {
            sf::RectangleShape block(sf::Vector2f(100.f, 20.f));
            block.setPosition(static_cast<float>(rand() % 700), -20.f);
            block.setFillColor(sf::Color::Blue);
            blocks.push_back(block);
            spawnCounter = 0;
        }

        
        for (auto& block : blocks)
            block.move(0, blockSpeed);

        
        window.clear();
        window.draw(ball);
        for (const auto& block : blocks)
            window.draw(block);
        window.display();
    }
    return 0;
}
