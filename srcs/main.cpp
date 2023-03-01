/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:51:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/01 16:27:22 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WIDTH_WIN + 64, HEIGHT_WIN + 64), "My window");

    //window.setFramerateLimit(60);

    sf::Clock clock;

    std::vector< std::vector<sf::Texture>>	img_array = create_array_texture();

    std::vector< std::vector<sf::Sprite>>	sprite_array;
    for (size_t i = 0; i < 4; i++)
    {
        std::vector<sf::Sprite> lst_sprite;
        for (size_t j = 0; j < img_array[i].size(); j++)
        {
            sf::Sprite sp;
            sp.setTexture(img_array[i][j]);
            lst_sprite.push_back(sp);

        }
        sprite_array.push_back(lst_sprite);
    }
    std::vector <std::vector <CaseMap>> map = generate_map(sprite_array);
    std::vector<float> camera(2);
    camera[0] = (WIDTH_MAP * 32 / 2);
    camera[1] = (HEIGHT_MAP * 32 / 2);

  
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float delta = clock.restart().asSeconds();
        float fps = 1.0f / delta;
        std::string title(std::to_string(fps));
        window.setTitle(title);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && camera[0] - (WIDTH_WIN / 2) - MOVE_SPEED >= 0 )
        {
            camera[0]-= MOVE_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && camera[0] - (WIDTH_WIN / 2) + MOVE_SPEED < (WIDTH_MAP * 32) - (WIDTH_WIN))
        {
            camera[0]+= MOVE_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && camera[1] - (HEIGHT_WIN / 2) - MOVE_SPEED >= 0 )
        {
            camera[1]-= MOVE_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && camera[1] - (HEIGHT_WIN / 2) + MOVE_SPEED < (HEIGHT_MAP * 32) - (WIDTH_WIN))
        {
            camera[1]+= MOVE_SPEED;
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        //std::cout << sprite_array[0].size();
        affiche_map(map, window, camera[0] - (WIDTH_WIN / 2), camera[1] - (HEIGHT_WIN / 2));
        
        /*
        //affiche mem img
        for (size_t i = 0; i < sprite_array.size(); i++)
        {
            for (size_t j = 0; j < sprite_array[i].size(); j++)
            {
                sprite_array[i][j].setPosition(sf::Vector2f(i * 32, j * 32));
                window.draw(sprite_array[i][j]);
            }
            
        }*/
        

        // end the current frame
        window.display();
    }

    return 0;
}
