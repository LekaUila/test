/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loading.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:48:28 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/09 13:14:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"

/*OLD FUNCTION*/

/*
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
		texture.loadFromFile("../img/old/" + type_tab[i] + ".png");
        lst.push_back(texture);
		for (size_t j = 0; j < 4; j++)
		{
            sf::Texture texture1;
            sf::Texture texture2;
			if (i != j)
			{
				texture1.loadFromFile("../img/old/" + type_tab[i]+ "_" + type_tab[j] + "_v.png");
				texture2.loadFromFile("../img/old/" + type_tab[i]+ "_" + type_tab[j] + "_h.png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				for (size_t g = 0; g < 2; g++)
				{
					for (size_t h = 0; h < 2; h++)
					{
                        sf::Texture texture3;
						texture3.loadFromFile("../img/old/" + type_tab[i] + hight_tab[g] + width_tab[h] + "_" + type_tab[j] + ".png");
                        lst.push_back(texture3);
					}
				}
			}
			else
			{
				texture1.loadFromFile("../img/old/" + type_tab[i] + ".png");
				texture2.loadFromFile("../img/old/" + type_tab[i] + ".png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				for (size_t g = 0; g < 2; g++)
				{
					for (size_t h = 0; h < 2; h++)
					{
                        sf::Texture texture3;
						texture3.loadFromFile("../img/old/" + type_tab[i] + ".png");
                        lst.push_back(texture3);
					}
				}	
			}
		}
        img_array.push_back(lst);
	}
	return (img_array);
}*/


std::vector< std::vector<sf::Texture>> create_array_texture(void)
{
	std::string	type_tab[4] = { "water", "sand", "grass", "wall"};
	std::string	hight_tab[2] = {"_bottom", "_top"};
	std::string	width_tab[2] = {"_left", "_right"};
	std::string	fb_tab[2] = {"_front", "_back"};
	std::vector< std::vector<sf::Texture>>	img_array;


	for (size_t i = 0; i < 4; i++)
	{	
        std::vector<sf::Texture> lst;
        sf::Texture texture;
		texture.loadFromFile("../img/sol/" + type_tab[i] + "/" +  type_tab[i] + ".png");
        lst.push_back(texture);
		for (size_t j = 0; j < 4; j++)
		{
            sf::Texture texture1;
            sf::Texture texture2;
			if (i == 3)
			{
				texture1.loadFromFile("../img/sol/wall/wall_left.png");
				texture2.loadFromFile("../img/sol/wall/wall_right.png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				break;
			}
			if (i != j)
			{
				if (j != 3)			// changer le contenue de cette condition
				{
					if (i == 2)
					{
						if (j == 1)
						{
							sf::Texture texture3;
          			  		sf::Texture texture4;
							texture1.loadFromFile("../img/sol/grass_transparent/grass_left.png");
							texture2.loadFromFile("../img/sol/grass_transparent/grass_right.png");
							texture3.loadFromFile("../img/sol/grass_transparent/grass_top.png");
							texture4.loadFromFile("../img/sol/grass_transparent/grass_bottom.png");
                			lst.push_back(texture1);
                			lst.push_back(texture2);
                			lst.push_back(texture3);
                			lst.push_back(texture4);
							for (size_t g = 0; g < 2; g++)
							{
								for (size_t h = 0; h < 2; h++)
								{
                	  	 	   		sf::Texture texture5;
									sf::Texture texture6;
									texture5.loadFromFile("../img/sol/grass_transparent/grass" + hight_tab[g] + width_tab[h] + ".png");
                 	  	  	  		lst.push_back(texture5);
									texture6.loadFromFile("../img/sol/grass_transparent/grass" + hight_tab[g] + width_tab[h] + "_reverse.png");
                 	  	    		lst.push_back(texture6);
								}
							}
						}
						else
						{
							
						}

					}
					else if (i == 0 && j == 1)
					{
						sf::Texture texture1w;
						sf::Texture texture2w;
						sf::Texture texture3w;
						sf::Texture texture4w;
						sf::Texture texture5w;
						sf::Texture texture6w;
						texture1w.loadFromFile("../img/sol/water/water_grass.png");
						texture2w.loadFromFile("../img/sol/water/water_grass_left.png");
						texture3w.loadFromFile("../img/sol/water/water_grass_right.png");
						texture4w.loadFromFile("../img/sol/water/water_wall.png");
						texture5w.loadFromFile("../img/sol/water/water_wall_left.png");
						texture6w.loadFromFile("../img/sol/water/water_wall_right.png");
						lst.push_back(texture1w);
						lst.push_back(texture2w);
						lst.push_back(texture3w);
						lst.push_back(texture4w);
						lst.push_back(texture5w);
						lst.push_back(texture6w);
					}
					else
					{
						//texture1.loadFromFile("../img/sol/" + type_tab[i]+ "_" + type_tab[j] + "_v.png");
						//texture2.loadFromFile("../img/sol/" + type_tab[i]+ "_" + type_tab[j] + "_h.png");
                		lst.push_back(texture1);
                		lst.push_back(texture2);
						for (size_t g = 0; g < 2; g++)
						{
							for (size_t h = 0; h < 2; h++)
							{
                	  	      sf::Texture texture3;
								//texture3.loadFromFile("../img/sol/" + type_tab[i] + hight_tab[g] + width_tab[h] + "_" + type_tab[j] + ".png");
                 	  	     lst.push_back(texture3);
							}
						}
					}


				}
				else if (i == 0) 
				{
					sf::Texture texture1w;
					texture1w.loadFromFile("../img/waterfall/waterfall.png");
					lst.push_back(texture1w);
					std::string	str_nb_tab[4] = {"1", "2", "3", "4"};
					for (size_t h = 0; h < 4; h++)
					{
						sf::Texture texture2w;
						sf::Texture texture3w;
						texture2w.loadFromFile("../img/waterfall/waterfall_top" + str_nb_tab[h] + ".png");
						texture3w.loadFromFile("../img/waterfall/waterfall_bottom" + str_nb_tab[h] + ".png");
						lst.push_back(texture2w);
						lst.push_back(texture3w);
					}
				}
				else
				{
					for (size_t h = 0; h < 2; h++)
					{
						sf::Texture texturew1;
						texturew1.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_h_front" + hight_tab[h]  + ".png");
						lst.push_back(texturew1);
						for (size_t t = 0; t < 2; t++)
						{
                		   	sf::Texture texturew2;
							texturew2.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_h_front" + hight_tab[h] + width_tab[t]  + ".png");
                 			lst.push_back(texturew2);
						}
					}
					sf::Texture texturew1;
                	sf::Texture texturew2;
					sf::Texture texturew3;
					texturew1.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_h_back"  + ".png");
					texturew2.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_h_back" + width_tab[0]  + ".png");
					texturew3.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_h_back" + width_tab[1]  + ".png");
                 	lst.push_back(texturew1);
					lst.push_back(texturew2);
					lst.push_back(texturew3);
					sf::Texture texturew4;
					sf::Texture texturew5;
					texturew4.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_v_left.png");
					texturew5.loadFromFile("../img/sol/" +   type_tab[i] + "/" + type_tab[i] + "_wall_v_right.png");
					lst.push_back(texturew4);
					lst.push_back(texturew5);
				}

			}
			else
			{
				//texture1.loadFromFile("../img/sol/" + type_tab[i] + ".png");
				//texture2.loadFromFile("../img/sol/" + type_tab[i] + ".png");
                lst.push_back(texture1);
                lst.push_back(texture2);
				for (size_t g = 0; g < 2; g++)
				{
					for (size_t h = 0; h < 2; h++)
					{
                        sf::Texture texture3;
						//texture3.loadFromFile("../img/sol/" + type_tab[i] + ".png");
                        lst.push_back(texture3);
					}
				}	
			}
		}
        img_array.push_back(lst);
	}
	{
		std::vector<sf::Texture> lst_shadow;
        sf::Texture texture1;
		sf::Texture texture2;
		sf::Texture texture3;
		sf::Texture texture4;
		sf::Texture texture5;
		texture1.loadFromFile("../img/shadow/shadow.png");
		texture2.loadFromFile("../img/shadow/shadow_start.png");
		texture3.loadFromFile("../img/shadow/shadow_spe1.png");
		texture4.loadFromFile("../img/shadow/shadow_spe2.png");
		texture5.loadFromFile("../img/shadow/shadow_start2.png");
        lst_shadow.push_back(texture1);
		lst_shadow.push_back(texture2);
		lst_shadow.push_back(texture3);
		lst_shadow.push_back(texture4);
		lst_shadow.push_back(texture5);
		sf::Texture texture6;
		sf::Texture texture7;
		sf::Texture texture8;
		sf::Texture texture9;
		sf::Texture texture0;
		sf::Texture texture10;
		sf::Texture texture11;
		texture6.loadFromFile("../img/shadow/shadow_water_end.png");
		texture7.loadFromFile("../img/shadow/shadow_water_start.png");
		texture8.loadFromFile("../img/shadow/shadow_water_right.png");
		texture9.loadFromFile("../img/shadow/shadow_water_bottom.png");
		texture0.loadFromFile("../img/shadow/shadow_water_start2.png");
		texture10.loadFromFile("../img/shadow/shadow_water_corner.png");
		texture11.loadFromFile("../img/shadow/shadow_water_corner_reverse.png");
        lst_shadow.push_back(texture6);
		lst_shadow.push_back(texture7);
		lst_shadow.push_back(texture8);
		lst_shadow.push_back(texture9);
		lst_shadow.push_back(texture0);
		lst_shadow.push_back(texture10);
		lst_shadow.push_back(texture11);
		img_array.push_back(lst_shadow);
	}
	{
		std::vector<sf::Texture> lst_decors;

		for (size_t i = 0; i < 4; i++)
		{
			sf::Texture texture1;
			texture1.loadFromFile("../img/floor_decoration/stone_" + std::to_string(i + 1) + ".png");
			lst_decors.push_back(texture1);
		}
		sf::Texture texture1;
		sf::Texture texture2;
		sf::Texture texture3;
		sf::Texture texture4;
		sf::Texture texture5;
		sf::Texture texture6;
		texture1.loadFromFile("../img/floor_decoration/flower_purple_full.png");
		texture2.loadFromFile("../img/floor_decoration/flower_purple.png");
		texture3.loadFromFile("../img/floor_decoration/flower_white_full.png");
		texture4.loadFromFile("../img/floor_decoration/flower_white.png");
		texture5.loadFromFile("../img/floor_decoration/flower_yellow_full.png");
		texture6.loadFromFile("../img/floor_decoration/flower_yellow.png");
        lst_decors.push_back(texture1);
		lst_decors.push_back(texture2);
		lst_decors.push_back(texture3);
		lst_decors.push_back(texture4);
		lst_decors.push_back(texture5);
		lst_decors.push_back(texture6);
		img_array.push_back(lst_decors);
	}

	return (img_array);
}