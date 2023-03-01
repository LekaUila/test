/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:49:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/01 17:01:28 by lflandri         ###   ########.fr       */
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
# include "../class/map/CaseMap.hpp"
# define WIDTH_MAP 30
# define HEIGHT_MAP 30
# define RANDOM_LEVEL 10
# define WIDTH_WIN 800
# define HEIGHT_WIN 800
# define MOVE_SPEED 1

enum e_type 
{
	WATER,
	SAND,
	GRASS,
	WALL
};

/* ================ FUNCTIONS ============== */

std::vector< std::vector<sf::Texture>> create_array_texture(void);

std::vector < std::vector<CaseMap> > generate_map(std::vector< std::vector<sf::Sprite>> & img_array);
void	affiche_map(std::vector <std::vector <CaseMap>> & map, sf::RenderWindow & window, unsigned int xadd, unsigned int yadd);

#endif
