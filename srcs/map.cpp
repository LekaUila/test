/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:59 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/23 16:14:43 by lflandri         ###   ########.fr       */
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
			std::cout << map[x][y].getZ() << "  ";
		}
		std::cout << " " << y  << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

static	int smoothing(std::vector <std::vector <CaseMap>> & map, unsigned int x, unsigned int y)
{
	int need_a_wall = (x != 0 && map[x - 1][y].getZ() != map[x][y].getZ());
	need_a_wall += (x != 0 && y != 0 && map[x - 1][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() != map[x][y].getZ());
	need_a_wall += (y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() != map[x][y].getZ());
	need_a_wall += (y != 0 && map[x][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && map[x + 1][y].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() != map[x][y].getZ());
	
	if (need_a_wall > 5)
	{
		unsigned int tabint[5] = {0, 0, 0, 0, 0 };

		std::cout << "x : " << x << " | y : " << y << " | actual : " << map[x][y].getZ() << std::endl;

		tabint[((x != 0) ? map[x - 1][y].getZ() : 4)]++;
		tabint[((x != 0 && y != 0) ? map[x - 1][y - 1].getZ() : 4)]++;
		tabint[((x != 0 && y + 1 < HEIGHT_MAP) ? map[x - 1][y + 1].getZ() : 4)]++;
		tabint[((y + 1 < HEIGHT_MAP) ? map[x][y + 1].getZ() : 4)]++;
		tabint[((y != 0) ? map[x][y - 1].getZ() : 4)]++;
		tabint[((x + 1 < WIDTH_MAP && y != 0) ? map[x + 1][y - 1].getZ() : 4)]++;
		tabint[((x + 1 < WIDTH_MAP) ? map[x + 1][y].getZ() : 4)]++;
		tabint[((x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP) ?map[x + 1][y + 1].getZ() : 4)]++;
		//std::cout << "0 : " << tabint[0] << "1 : " << tabint[1] << "2 : " << tabint[2] << "3 : " << tabint[3] << std::end;
		if (tabint[0] > tabint[1] && tabint[0] > tabint[2] && tabint[0] > tabint[3] && map[x][y].getZ() != 0)
			map[x][y].setZ(0);
		else if (tabint[1] > tabint[0] && tabint[1] > tabint[2] && tabint[1] > tabint[3] && map[x][y].getZ() != 1)
			map[x][y].setZ(1);
		else if (tabint[2] > tabint[1] && tabint[2] > tabint[0] && tabint[2] > tabint[3] && map[x][y].getZ() != 2)
			map[x][y].setZ(2);
		else if (tabint[3] > tabint[1] && tabint[3] > tabint[0] && tabint[3] > tabint[0] && map[x][y].getZ() != 3)
			map[x][y].setZ(3);
		else 
			map[x][y].setZ(std::rand() % 4);
		std::cout << "x : " << x << " | y : " << y << " | new : " << map[x][y].getZ() << std::endl << std::endl;
		return (1);
	}
	return (0);
}

static void associate_img(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	std::string	type_tab[3] = { "water", "sand", "grass"};
	int type = WATER;
	
	for (size_t i = 0; i < 3; i++)
	{
		if (type_tab[i] == map[x][y].getType())
		{
			type = i;
			map[x][y].setImg(img_array[type][0]);
		}
			
	}

	int need_a_wall = (x != 0 && map[x - 1][y].getZ() != map[x][y].getZ());
	need_a_wall += (x != 0 && y != 0 && map[x - 1][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() != map[x][y].getZ());
	need_a_wall += (y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() != map[x][y].getZ());
	need_a_wall += (y != 0 && map[x][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && map[x + 1][y].getZ() != map[x][y].getZ());
	need_a_wall += (x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() != map[x][y].getZ());

	//std::cout << "x : " << x << " | y : " << y << " | need : " << need_a_wall << std::endl;
 
	if (need_a_wall)
	{
		int typebis = type;
		type = WALL;
		switch (need_a_wall)
		{
		case 8:
		case 7:
		case 6:
			break;
		case 5:
		case 4:
		case 3:
			//std::cout << "Enter corner" << std::endl;
			if ((x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() < map[x][y].getZ()) && /* inferieur droit */
					(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() > map[x][y].getZ()) && 
					(x + 1 < WIDTH_MAP && map[x + 1][y].getZ() > map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[WALL][4 + typebis * 6]); // 4
				return ;
			}	
			else if ((x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() < map[x][y].getZ()) && /* inferieur gauche */
						(x != 0 && map[x - 1][y].getZ() > map[x][y].getZ()) &&
						(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() > map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[WALL][3 + typebis * 6]); // 3
				return ;
			}
			else if ((x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() != map[x][y].getZ()) && /* superieur droit */
						(x + 1 < WIDTH_MAP && map[x + 1][y].getZ() != map[x][y].getZ()) &&
						(y != 0 && map[x][y - 1].getZ() != map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[WALL][6 + typebis * 6]); // 6
				return ;
			}
			else if ((x != 0 && y != 0 && map[x - 1][y - 1].getZ() != map[x][y].getZ()) && /* superieur gauche */
						(x != 0 && map[x - 1][y].getZ() != map[x][y].getZ()) &&
						(y != 0 && map[x][y - 1].getZ() != map[x][y].getZ())) 
			{
				map[x][y].setImg(img_array[WALL][5 + typebis * 6]); // 5
				return ;
			}


		case 2:

		case 1:
			//std::cout << "Enter lign" << std::endl;
			if ((x != 0 && map[x - 1][y].getZ() != map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[WALL][1 + typebis * 6]);
				return ;
			}
			else if ((x + 1 < WIDTH_MAP && map[x + 1][y].getZ() != map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][1 + WALL * 6]);
				return ;
			}
			else if ((y != 0 && map[x][y - 1].getZ() != map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[WALL][2 + typebis * 6]);
				return ;
			}
			else if ((y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() < map[x][y].getZ())) /*ICI*/
			{
				map[x][y].setImg(img_array[typebis][2 + WALL * 6]);
				return ;
			}
			if (need_a_wall == 1)
			{
			//std::cout << "Enter reverse corner" << std::endl;
			if ((x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][5 + WALL * 6]); // 5
				return ;
			}	
			else if ((x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][6 + WALL * 6]); // 6
				return ;
			}	
			else if ((x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() != map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][3 + WALL * 6]); // 3
				return ;
			}
			else if ((x != 0 && y != 0 && map[x - 1][y - 1].getZ() != map[x][y].getZ())) 
			{
				map[x][y].setImg(img_array[typebis][4 + WALL * 6]); // 4
				return ;
			}
			}

			
					
		break;
		
		default:
			break;
		}
	}

	for (size_t i = 0; i < 3; i++)
	{		
		if (type_tab[i] == map[x][y].getType())
		{
			for (size_t j = 0; j < 3; j++)
			{
				
			}
		}
	}
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

std::vector<std::vector<CaseMap>> generate_map(std::vector< std::vector<sf::Sprite>> & img_array)
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
	//print_map(map);
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
	print_map(map);

	int smooth_check = 1;
	while (smooth_check)
	{
		smooth_check = 0;
		std::cout << "new smooth" << std::endl;
		for (size_t y = 0; y < HEIGHT_MAP; y++)
		{
			for (size_t x = 0; x < WIDTH_MAP; x++)
			{
				
				smooth_check += smoothing(map, x, y); 
				
			}
		}
		std::cout << std::endl << std::endl << std::endl;
	}
	
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			associate_img(map, img_array, x, y);
		}
	}
	print_map(map);
	
	return (map);
}

void	affiche_map(std::vector<std::vector<CaseMap>> & map, sf::RenderWindow & window, unsigned int xadd, unsigned int yadd)
{
	
	for (size_t y = yadd / 32; y < yadd / 32 + HEIGHT_WIN  / 32 + 2 && y < HEIGHT_MAP; y++)
	{
		//std::cout << yadd / 32 << "  " << y << "  "  << yadd / 32 + HEIGHT_WIN / 32<< std::endl;
		for (size_t x = xadd / 32; x < xadd / 32 + WIDTH_WIN / 32 + 2 && x < WIDTH_MAP; x++)
		{
			//std::cout << xadd / 32 << "  " << x << "  "  << xadd / 32 + WIDTH_WIN / 2 << std::endl;
			map[x][y].draw(window, -xadd + 32, -yadd + 32);
		}
	}	
	/*
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			map[x][y].draw(window, -xadd, -yadd);
		}
	}*/



	sf::RectangleShape rectangle(sf::Vector2f(64 + WIDTH_WIN, 32));
	rectangle.setFillColor(sf::Color(0, 0, 0));
	rectangle.setPosition(sf::Vector2f(0, 0));
	window.draw(rectangle);
	rectangle.setPosition(sf::Vector2f(0, 32 + HEIGHT_WIN));
	window.draw(rectangle);
	rectangle.setSize(sf::Vector2f(32, 64 + HEIGHT_WIN));
	rectangle.setPosition(sf::Vector2f(0, 0));
	window.draw(rectangle);
	rectangle.setPosition(sf::Vector2f(32 + WIDTH_WIN, 0));
	window.draw(rectangle);


	/*tempo*/
	rectangle.setFillColor(sf::Color(255, 0, 0));
	rectangle.setSize(sf::Vector2f(1, 64 + HEIGHT_WIN));
	for (size_t i = 0; i < WIDTH_WIN + 64; i += 32)
	{
			rectangle.setPosition(sf::Vector2f(i, 0));
			window.draw(rectangle);
	}
	rectangle.setSize(sf::Vector2f(64 + WIDTH_WIN, 1));
	for (size_t i = 0; i < HEIGHT_WIN + 64; i += 32)
	{
			rectangle.setPosition(sf::Vector2f(0, i));
			window.draw(rectangle);
	}
	
}