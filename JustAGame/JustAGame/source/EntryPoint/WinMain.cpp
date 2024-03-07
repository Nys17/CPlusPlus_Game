#include <SFML/Graphics.hpp>
#include "../Game/GameManager.h"
#include <Windows.h>



int CALLBACK main(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Just a game"); /// add later sf::Style::Fullscreen
    window.setVerticalSyncEnabled(true);/// match fps with monitor refresh rate

    GameManager manager;



   if (manager.Load())
    {
       sf::Clock clock;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                sf::Time frameTime = clock.getElapsedTime();

                clock.restart();
                window.clear();

                manager.Update(frameTime.asSeconds());
                manager.Render();

                window.display();

                if (event.type == sf::Event::Closed)
                    window.close();
            }

           
          
           
        }

      
    }

   manager.ShutDown();
    return 0;
}