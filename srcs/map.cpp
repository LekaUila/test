/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:59 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/22 19:50:08 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"


static	void print_map(std::vector <std::vector <CaseMap>> & map)
{
	std::string	type_tab[4] = { "water", "sand", "grass", "wall"};
	std::cout << "MAP :" << std::endl;
	std::cout << std::endl;

	for (size_t x = 0; x < WIDTH_MAP; x++)
	{
		std::cout << x << " ";
		if (x < 10)
			std::cout << " ";
	}
	std::cout << std::endl;std::cout << std::endl;


	for (size_t y = 0; y < HEIGHT_MAP; y++) 
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			int boll = 0;
			for (size_t i = 0; i < 4; i++)
			{
				
				if (type_tab[i] == map[x][y].getType())
				{
					boll = 1;
					switch (i)
					{
					case 0:
						std::cout << "~  ";
						break;
					case 1:
						std::cout << "=  ";
						break;
					case 2:
						std::cout << "#  ";
						break;				
					default:
						std::cout << "@  ";
						break;
					}
				}

			}
			if (!boll)
				std::cout << "   ";
		}
		std::cout << " " << y  << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

static std::string	getMyType(std::vector <std::vector <CaseMap>> & map,  unsigned int x, unsigned int y)
{
	std::vector<std::string> tab;
	
	if (x != 0 && map[x - 1][y].getType() != "none")
		tab.push_back(map[x - 1][y].getType());
	if (x + 1 < WIDTH_MAP && map[x + 1][y].getType() != "none")
		tab.push_back(map[x + 1][y].getType());
	if (y != 0 && map[x][y - 1].getType() != "none")
		tab.push_back(map[x][y - 1].getType());
	if (y + 1 < HEIGHT_MAP && map[x][y + 1].getType() != "none")
		tab.push_back(map[x][y + 1].getType());
	if (tab.size() == 0)
	{
		std::cout << "tab NULL" << std::endl;
		return ("grass");
	}
	return (tab[std::rand() % tab.size()]);
}

static unsigned int	getMyZ(std::vector <std::vector <CaseMap>> & map,  unsigned int x, unsigned int y)
{
	std::vector<unsigned int> tab;
	
	if (x != 0 && map[x - 1][y].getZ() != 1000)
		tab.push_back(map[x - 1][y].getZ());
	if (x + 1 < WIDTH_MAP && map[x + 1][y].getZ() != 1000)
		tab.push_back(map[x + 1][y].getZ());
	if (y != 0 && map[x][y - 1].getZ() != 1000)
		tab.push_back(map[x][y - 1].getZ());
	if (y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() != 1000)
		tab.push_back(map[x][y + 1].getZ());
	if (tab.size() == 0)
		return (0);
	return (tab[std::rand() % tab.size()]);
}

static void	recursive_generating(std::vector <std::vector <CaseMap>> & map,  unsigned int x, unsigned int y, unsigned int max, int force)
{
	if ( x < WIDTH_MAP && y < HEIGHT_MAP && max && (force || std::rand() % 50 > 30) && map[x][y].getType() == "none")
	{
		std::string type = getMyType(map, x, y);
		int			z    = getMyZ(map, x, y);
		map[x][y] = CaseMap(x, y, z, type);
		recursive_generating(map, x + 1, y, max - 1, 0);
		recursive_generating(map, x - 1, y, max - 1, 0);
		recursive_generating(map, x, y + 1, max - 1, 0);
		recursive_generating(map, x, y - 1, max - 1, 0);
	}
}

std::vector<std::vector<CaseMap>> generate_map(std::vector< std::vector<sf::Texture>> & img_array)
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
	map[0][0] = first;
	for (size_t i = 0; i < 25; i++) /* (WIDTH_MAP * HEIGHT_MAP) / 1000*/
	{
		int x = std::rand() % WIDTH_MAP;
		int y = std::rand() % HEIGHT_MAP;
		CaseMap casem(x, y, std::rand() % 4, type_tab[std::rand() % 3]);
		map[x][y] = casem;
		recursive_generating(map, x - 1, y, 15, 1);
	}
	print_map(map);
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			if (map[x][y].getType() == "none")
			{
				//std::cout << x << " : " << y << std::endl;
				recursive_generating(map, x, y, 10, 1);
			}
		}
	}
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			for (size_t i = 0; i < 4; i++)
			{
				
				if (type_tab[i] == map[x][y].getType())
				{
					map[x][y].setImg(img_array[i][0]);
				}
			}
		}
	}
	print_map(map);
	
	return (map);
}

void	affiche_map(std::vector<std::vector<CaseMap>> & map, sf::RenderWindow & window)
{
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			window.draw(map[x][y].getImg());
		}
	}
}