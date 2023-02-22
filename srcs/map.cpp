/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:59 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/22 17:06:42 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"

static void	recursive_generating(std::vector <std::vector <CaseMap>> & map, std::string	type_tab[4], unsigned int x, unsigned int y, unsigned int max)
{
	if (map[x][y].getType() != "none" && x > WIDTH_MAP && y > HEIGHT_MAP)
	{
		
	}
}

void generate_map(void /*std::vector< std::vector<sf::Texture>>*/)
{
	std::vector <std::vector <CaseMap>>	map;
	std::srand((unsigned)time(0));
	std::string	type_tab[4] = { "water", "sand", "grass", "wall"};

	for (size_t i = 0; i < HEIGHT_MAP; i++)
	{
		std::vector <CaseMap> vect;
		for (size_t j = 0; j < WIDTH_MAP; j++)
		{
			CaseMap casem;
			vect.push_back(casem);
		}
		map.push_back(vect);
	}
	CaseMap first(0, 0, std::rand() % 4, type_tab[std::rand() % 3]);
	




/*std::rand()*/
}