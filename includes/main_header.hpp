/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:49:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/09 13:32:48 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_HPP
# define MAIN_HEADER_HPP

# include <SFML/Graphics.hpp>
# include <cstdlib>
# include <ctime> 
# include <iostream>
# include <string>
# include <vector>
# include <map>

# include "define_anime_time.hpp"
# include "../class/map/CaseMap.hpp"

# define DEBUG_INFO 1
# define COOR_INFO 1

# define RANDOM_LEVEL 150
# define WIDTH_WIN 1600
# define HEIGHT_WIN 800
# define WIDTH_MAP 500
# define HEIGHT_MAP 500
# define MOVE_SPEED 25
# define PROPAGATION 5
# define PROPAGATION_FLOWER 20

enum e_type 
{
	WATER,
	SAND,
	GRASS,
	WALL,
	SHADOW,
	DECORS
};

/* ================ FUNCTIONS ============== */

std::vector< std::vector<sf::Texture>> create_array_texture(void);


void add_shadow(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y);
std::vector < std::vector<CaseMap> > generate_map(std::vector< std::vector<sf::Sprite>> & img_array);



void	affiche_map(std::vector <std::vector <CaseMap>> & map, sf::RenderWindow & window, unsigned int xadd, unsigned int yadd);

#endif
