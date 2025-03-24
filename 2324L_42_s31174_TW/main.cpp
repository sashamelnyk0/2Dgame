#include <SFML/Graphics.hpp>
#include "StartMenu.h"
#include "Game.h"
int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");
    StartMenu startMenu(window);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            startMenu.handleEvent(event);
        }
        startMenu.render();
    }
    return 0;
}
