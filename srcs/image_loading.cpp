/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loading.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:48:28 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/22 15:33:32 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"

std::vector< std::vector<sf::Texture>> create_array_texture(void)
{
	std::string	type_tab[4] = { "water", "sand", "grass", "wall"};
	std::string	hight_tab[2] = {"_bottom", "_top"};
	std::string	width_tab[2] = {"_left", "_right"};
	std::vector< std::vector<sf::Texture>>	img_array;


	for (size_t i = 0; i < 4; i++)
	{	
        std::vector<sf::Texture> lst;
        sf::Texture texture;
		texture.loadFromFile("../img/sol/" + type_tab[i] + ".png");
        lst.push_back(texture);
		for (size_t j = 0; j < 4; j++)
		{
            sf::Texture texture1;
            sf::Texture texture2;
			if (i != j)
			{
				texture1.loadFromFile("../img/sol/" + type_tab[i]+ "_" + type_tab[j] + "_v.png");
				texture2.loadFromFile("../img/sol/" + type_tab[i]+ "_" + type_tab[j] + "_h.png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				for (size_t g = 0; g < 2; g++)
				{
					for (size_t h = 0; h < 2; h++)
					{
                        sf::Texture texture3;
						texture3.loadFromFile("../img/sol/" + type_tab[i] + hight_tab[g] + width_tab[h] + "_" + type_tab[j] + ".png");
                        lst.push_back(texture3);
					}
				}
			}
			else
			{
				texture1.loadFromFile("../img/sol/" + type_tab[i] + ".png");
				texture2.loadFromFile("../img/sol/" + type_tab[i] + ".png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				for (size_t g = 0; g < 2; g++)
				{
					for (size_t h = 0; h < 2; h++)
					{
                        sf::Texture texture3;
						texture3.loadFromFile("../img/sol/" + type_tab[i] + ".png");
                        lst.push_back(texture3);
					}
				}	
			}
		}
        img_array.push_back(lst);
	}
	return (img_array);
}
