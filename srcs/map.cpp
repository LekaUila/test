/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:00:59 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/09 13:35:16 by lflandri         ###   ########.fr       */
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
		std::cout << x << "  ";
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
						std::cout << "~   ";
						break;
					case 1:
						std::cout << "=   ";
						break;
					case 2:
						std::cout << "#   ";
						break;				
					default:
						std::cout << "@   ";
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
		std::cout << x << "  ";
		if (x < 10)
			std::cout << " ";
	}
	std::cout << std::endl;std::cout << std::endl;

	for (size_t y = 0; y < HEIGHT_MAP; y++) 
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			if (map[x][y].getZ() != 1000)
			{
				std::cout << map[x][y].getZ() << " ";
				if (map[x][y].getZ() != 1.5)
					std::cout  << "  ";
			}
			else
				std::cout  << "    ";
		}
		std::cout << " " << y  << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}


/*==========================================================================================*/
									/*MAP ADD SPRITE*/
/*==========================================================================================*/

void add_grass_border(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	
	if ((y + 1 < HEIGHT_MAP && map[x][y + 1].getType() == "grass") && (x + 1 < WIDTH_MAP && map[x + 1][y].getType() == "grass") && 
		map[x + 1][y].getZ() == map[x][y].getZ() && map[x][y + 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][7]);
		return ;
	}
	else if ((y + 1 < HEIGHT_MAP && map[x][y + 1].getType() == "grass") && (x != 0 && map[x - 1][y].getType() == "grass") && 
		map[x - 1][y].getZ() == map[x][y].getZ() && map[x][y + 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][5]);
		return ;
	}
	else if ((y != 0 && map[x][y - 1].getType() == "grass") && (x + 1 < WIDTH_MAP && map[x + 1][y].getType() == "grass") && 
		map[x + 1][y].getZ() == map[x][y].getZ() && map[x][y - 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][11]);
		return ;
	}
	else if ((y != 0 && map[x][y - 1].getType() == "grass") && (x != 0 && map[x - 1][y].getType() == "grass") && 
		map[x - 1][y].getZ() == map[x][y].getZ() && map[x][y - 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][9]);
		return ;
	}
	else if ((y != 0 && map[x][y - 1].getType() == "grass") && 
		map[x][y - 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][3]);
		return ;
	}
	else if ((x + 1 < WIDTH_MAP && map[x + 1][y].getType() == "grass") && 
		map[x + 1][y].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][2]);
		return ;
	}
	else if ((x != 0 && map[x - 1][y].getType() == "grass") && 
		map[x - 1][y].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][1]);
		return ;
	}
	else if ((y + 1 < HEIGHT_MAP && map[x][y + 1].getType() == "grass") && 
		map[x][y + 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][4]);
		return ;
	}
	else if ((x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getType() == "grass") && 
		map[x + 1][y + 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][10]);
		return ;
	}
	else if ((x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getType() == "grass") && 
		map[x - 1][y + 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][12]);
		return ;
	}
	else if ((x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getType() == "grass") && 
		map[x + 1][y - 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][6]);
		return ;
	}
	else if ((x != 0 && y != 0 && map[x - 1][y - 1].getType() == "grass") && 
		map[x - 1][y - 1].getZ() == map[x][y].getZ())
	{
		map[x][y].addDecors(img_array[GRASS][8]);
		return ;
	}
}

static void associate_img(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	if (map[x][y].getImg() != NULL)
		return ;
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
			if (/*(x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() < map[x][y].getZ()) &&*/ /* inferieur droit */
					(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() < map[x][y].getZ()) && 
					(x + 1 < WIDTH_MAP && map[x + 1][y].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 5]); // 4
				map[x][y].setType("wall");
				return ;
			}
			else if (/*(x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() < map[x][y].getZ()) && *//* inferieur gauche */
						(x != 0 && map[x - 1][y].getZ() < map[x][y].getZ()) &&
						(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 4]); // 3
				map[x][y].setType("wall");
				return ;
			}
			else if (/*(x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() < map[x][y].getZ()) &&*/ /* superieur droit */
						(x + 1 < WIDTH_MAP && map[x + 1][y].getZ() < map[x][y].getZ()) &&
						(y != 0 && map[x][y - 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 8]); // 6
				return ;
			}
			else if (/*(x != 0 && y != 0 && map[x - 1][y - 1].getZ() < map[x][y].getZ()) &&*/ /* superieur gauche */
						(x != 0 && map[x - 1][y].getZ() < map[x][y].getZ()) &&
						(y != 0 && map[x][y - 1].getZ() < map[x][y].getZ())) 
			{
				map[x][y].setImg(img_array[typebis][19 + 7]); // 5
				return ;
			}


		case 2:
			if ((x + 1 < WIDTH_MAP && y != 0 && map[x + 1][y - 1].getZ() > map[x][y].getZ()) && /* superieur droit */
						(y != 0 && map[x][y - 1].getZ() != map[x][y].getZ()) &&
						(x != 0 && y != 0 && (int)map[x - 1][y - 1].getZ() != (int)map[x][y - 1].getZ()) &&
						(x != 0 && map[x - 1][y].getZ() <= map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 1]); // 6
				map[x][y].setType("wall");
				return ;
			}
			else if ((x != 0 && y != 0 && map[x - 1][y - 1].getZ() > map[x][y].getZ()) && /* superieur gauche */
						(y != 0 && map[x][y - 1].getZ() != map[x][y].getZ()) && 
						(x + 1 < WIDTH_MAP && y != 0 && (int)map[x + 1][y - 1].getZ() != (int)map[x][y - 1].getZ()) &&
						(x + 1 < WIDTH_MAP &&  map[x + 1][y].getZ() <= map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 2]); // 5
				map[x][y].setType("wall");
				return ;
			}

		case 1:
			//std::cout << "Enter lign" << std::endl;
			if ((x != 0 && map[x - 1][y].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 9]);
				return ;
			}
			else if ((x + 1 < WIDTH_MAP && map[x + 1][y].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 10]);
				return ;
			}
			else if ((y != 0 && map[x][y - 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 6]);
				return ;
			}
			else if ((y != 0 && map[x][y - 1].getZ() > map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19]);
				map[x][y].setType("wall");
				return ;
			}
			else if ((y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() < map[x][y].getZ()))
			{
				map[x][y].setImg(img_array[typebis][19 + 3]);
				map[x][y].setType("wall");
				return ;
			}
			if (need_a_wall == 1)
			{
			//std::cout << "Enter reverse corner" << std::endl;
			
				if ((x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x + 1][y + 1].getZ() < map[x][y].getZ()) /*&& // inferieur droit 
						(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() == map[x][y].getZ()) && 
						(x + 1 < WIDTH_MAP && map[x + 1][y].getZ() == map[x][y].getZ())*/)
				{
					map[x][y].setImg(img_array[typebis][19 + 10]); // 5
					return ;
				}	
				else if ((x != 0 && y + 1 < HEIGHT_MAP && map[x - 1][y + 1].getZ() < map[x][y].getZ()) /*&& // inferieur gauche 
							(x != 0 && map[x - 1][y].getZ() == map[x][y].getZ()) &&
							(y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() == map[x][y].getZ())*/)
				{
					map[x][y].setImg(img_array[typebis][19 + 9]); // 6
					return ;
				}
			}
			break;
		
		default:
			break;
		}
	}
}


/*==========================================================================================*/
									/*BIG WALL*/
/*==========================================================================================*/


static void vertical_decr(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y, float z )
{
	if (y != 0 && map[x][y].getZ() == z)
	{
		vertical_decr(map, img_array, x, y - 1, z);
		map[x][y].setZ(z - 1);
	}
	else if (y == 0 && map[x][y].getZ() == z)
	{
		map[x][y].setZ(z - 1);
	}
	if (x != 0 && map[x - 1][y].getZ() == 1.5 && map[x - 1][y + 1].getZ() == 1.5)
	{
		map[x - 1][y].setImg(img_array[WALL][2]);
	}
}

static int vertical_move(std::vector <std::vector <CaseMap>> & map, unsigned int x, unsigned int y, float z,  int count)
{
	if (y != 0 && map[x][y].getZ() == z)
	{
		if (vertical_move(map, x, y - 1, z, count + 1) == 0)
			return 0;
		map[x][y] = map[x][y + 1];
		map[x][y].setX(x);
		map[x][y].setY(y);
		map[x][y].setZ(z);
	}
	else if ( count < 4)
		return 0;
	return (1);
}

static void add_big_wall(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	if (y != 0 && map[x][y - 1].getZ() > map[x][y].getZ())
	{
		for (size_t i = map[x][y - 1].getZ() - map[x][y].getZ() - 1; i != 0 ; i--)
		{
			if (vertical_move(map, x, y - 2, map[x][y - 1].getZ(), 0))
			{
				if (x != 0 && map[x - 1][y - 1].getZ() < map[x][y - 1].getZ() - 0.5)
					map[x][y - 1].setImg(img_array[WALL][1]);
				else if (x + 1 < WIDTH_MAP && map[x + 1][y - 1].getZ() < map[x][y - 1].getZ() - 0.5)
					map[x][y - 1].setImg(img_array[WALL][2]);
				else
					map[x][y - 1].setImg(img_array[WALL][0]);
				map[x][y - 1].setType("wall");
				map[x][y - 1].setZ(1.5);
				
				vertical_move(map, x, y - 3, map[x][y - 1].getZ(), 0);
				if (x != 0 && map[x - 1][y - 2].getZ() < map[x][y - 2].getZ() - 0.5)
					map[x][y - 2].setImg(img_array[WALL][1]);
				else if (x + 1 < WIDTH_MAP && map[x + 1][y - 2].getZ() < map[x][y - 2].getZ() - 1)
					map[x][y - 2].setImg(img_array[WALL][2]);
				else
					map[x][y - 2].setImg(img_array[WALL][0]);
				map[x][y - 2].setType("wall");
				map[x][y - 2].setZ(1.5);
			}
			else
			{
				vertical_decr(map, img_array, x, y - 1, map[x][y - 1].getZ());
			}

		}

	} 
}

/*==========================================================================================*/
									/*BASSIC MAP GENERATING*/
/*==========================================================================================*/

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
	if ( x < WIDTH_MAP && x + 1 < WIDTH_MAP  && y < HEIGHT_MAP && y + 1 < HEIGHT_MAP &&  max && (force || std::rand() % 50 > PROPAGATION) && map[x][y].getType() == "none")
	{
		std::string type = getMyType(map, x, y);
		int			z    = getMyZ(map, x, y);
		map[x][y] = CaseMap(x, y, z, type);
		map[x + 1][y] = CaseMap(x + 1, y, z, type);
		map[x][y + 1] = CaseMap(x, y + 1, z, type);
		map[x + 1][y + 1] = CaseMap(x + 1, y + 1, z, type);
		recursive_generating(map, x + 2, y, max - 1, 0);
		recursive_generating(map, x - 2, y, max - 1, 0);
		recursive_generating(map, x, y + 2, max - 1, 0);
		recursive_generating(map, x, y - 2, max - 1, 0);
	}
	else if ( x < WIDTH_MAP && (x + 1 == WIDTH_MAP || y + 1 == HEIGHT_MAP)   && y < HEIGHT_MAP  &&  max && force && map[x][y].getType() == "none")
	{
		std::string type = getMyType(map, x, y);
		int			z    = getMyZ(map, x, y);
		map[x][y] = CaseMap(x, y, z, type);
	}
}

/*==========================================================================================*/
									/*WATER GENERATION*/
/*==========================================================================================*/

static void	generate_water(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y, unsigned int max);

static void	generate_waterfall_from_bottom(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	if (y < 8 || x < 4 || x > WIDTH_MAP - 4)
		return ;
	//std::cout << "test waterfall" << std::endl;
	if ((map[x][y - 2].getType() == "grass" || map[x][y - 2].getType() == "water")&& map[x - 2][y].getType() == "wall" && map[x + 2][y].getType() == "wall"
	&& (map[x][y - 4].getType() == "grass" || map[x][y - 4].getType() == "water") && map[x][y - 2].getZ() == map[x][y - 4].getZ())
	{
		if (DEBUG_INFO && COOR_INFO)
			std::cout << "\e[1;37m		generating waterfall : \e[1;33m" << x << "\e[1;37m | \e[1;33m" << y << "\e[0;m" << std::endl;
		map[x][y].setImg(img_array[WATER][19]);
		map[x + 1][y].setImg(img_array[WATER][19]);


		map[x][y + 1].setImg(img_array[WATER][21]);
		map[x + 1][y + 1].setImg(img_array[WATER][21]);
		map[x][y - 1].setImg(img_array[WATER][20]);
		map[x + 1][y - 1].setImg(img_array[WATER][20]);

		map[x][y + 1].setImg(img_array[WATER][23], 1);
		map[x + 1][y + 1].setImg(img_array[WATER][23], 1);
		map[x][y - 1].setImg(img_array[WATER][22], 1);
		map[x + 1][y - 1].setImg(img_array[WATER][22], 1);

		map[x][y + 1].setImg(img_array[WATER][25], 2);
		map[x + 1][y + 1].setImg(img_array[WATER][25], 2);
		map[x][y - 1].setImg(img_array[WATER][24], 2);
		map[x + 1][y - 1].setImg(img_array[WATER][24], 2);

		map[x][y + 1].setImg(img_array[WATER][27], 3);
		map[x + 1][y + 1].setImg(img_array[WATER][27], 3);
		map[x][y - 1].setImg(img_array[WATER][26], 3);
		map[x + 1][y - 1].setImg(img_array[WATER][26], 3);

		map[x][y - 2].setImg(img_array[WATER][0]);
		map[x + 1][y - 2].setImg(img_array[WATER][0]);
		map[x][y - 2].setType("water");
		map[x + 1][y - 2].setType("water");
		generate_water(map, img_array, x, y - 4, 15);
	}

}

static void	generate_water(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y, unsigned int max)
{
	if (x >= WIDTH_MAP || y >= HEIGHT_MAP || (map[x][y].getType() != "grass" && map[x][y].getType() != "wall") || std::rand() % 50 <= PROPAGATION || !max)
	{
		return ;
	}
	if (map[x][y].getType() == "wall")
	{
		int check = 0;
		check += (y + 2 < HEIGHT_MAP && (map[x][y + 2].getType() == "grass" || map[x][y + 2].getType() == "water") && map[x][y + 2].getZ() == map[x][y].getZ());
		check += (x + 2 < WIDTH_MAP && (map[x + 2][y + 1].getType() == "grass" || map[x + 2][y + 1].getType() == "water"));
		check += (x != 0 && (map[x - 1][y + 1].getType() == "grass" || map[x - 2][y + 1].getType() == "water"));
		if (check == 3)
		{
			map[x][y + 1].setImg(img_array[WATER][0]);
			map[x + 1][y + 1].setImg(img_array[WATER][0]);
			map[x][y + 1].setType("water");
			map[x + 1][y + 1].setType("water");
			generate_waterfall_from_bottom(map, img_array, x, y);
			generate_water(map, img_array, x - 2, y, max - 1);
			generate_water(map, img_array, x + 2, y, max - 1);
			generate_water(map, img_array, x, y + 2, max - 1);
		}
		return ;
	}
	int check = (x != 0 && (map[x - 1][y].getType() == "grass" || map[x - 1][y].getType() == "water") && map[x - 1][y].getZ() == map[x][y].getZ());
	check += (y != 0 && (map[x][y - 1].getType() == "grass" || map[x][y - 1].getType() == "water") && map[x][y - 1].getZ() == map[x][y].getZ());
	check += (y + 2 < HEIGHT_MAP && (map[x][y + 2].getType() == "grass" || map[x][y + 2].getType() == "water") && map[x][y + 2].getZ() == map[x][y].getZ());
	check += (x + 2 < WIDTH_MAP && (map[x + 2][y].getType() == "grass" || map[x + 2][y].getType() == "water") && map[x + 2][y].getZ() == map[x][y].getZ());
	check += (x + 2 < WIDTH_MAP && (map[x + 2][y + 1].getType() == "grass" || map[x + 2][y + 1].getType() == "water"));
	check += (x != 0 && (map[x - 2][y + 1].getType() == "grass" || map[x - 2][y + 1].getType() == "water"));

	if (check == 6)
	{
		map[x][y].setImg(img_array[WATER][0]);
		map[x + 1][y].setImg(img_array[WATER][0]);
		map[x][y + 1].setImg(img_array[WATER][0]);
		map[x + 1][y + 1].setImg(img_array[WATER][0]);
		map[x][y].setType("water");
		map[x + 1][y].setType("water");
		map[x][y + 1].setType("water");
		map[x + 1][y + 1].setType("water");
		generate_water(map, img_array, x - 2, y, max - 1);
		generate_water(map, img_array, x + 2, y, max - 1);
		generate_water(map, img_array, x, y - 2, max - 1);
		generate_water(map, img_array, x, y + 2, max - 1);
	}
}


static void change_water_border(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
		if (map[x][y - 1].getType() == "grass")
		{
			if (map[x + 1][y - 1].getType() == "water" && map[x + 1][y].getType() == "water")
				map[x][y].setImg(img_array[WATER][9]);
			else if (map[x - 1][y - 1].getType() == "water" && map[x - 1][y].getType() == "water")
				map[x][y].setImg(img_array[WATER][8]);
			else
				map[x][y].setImg(img_array[WATER][7]);
		}
		else if (map[x][y - 1].getType() == "wall" && map[x][y - 1].getImg() != &img_array[WATER][19])
		{
			map[x][y].setImg(img_array[WATER][10]);
			if (map[x - 1][y - 1].getType() != "wall" && map[x - 1][y - 1].getZ() == map[x][y - 1].getZ())
				map[x][y - 1].setImg(img_array[WALL][1]);
			else if (map[x + 1][y - 1].getType() != "wall" && map[x + 1][y - 1].getZ() == map[x][y - 1].getZ())
				map[x][y - 1].setImg(img_array[WALL][2]);
			else
				map[x][y - 1].setImg(img_array[WALL][0]);
		}
		if (map[x - 1][y].getType() == "grass")
		{
			if (map[x - 1][y].getImg() == &img_array[GRASS][25] || map[x - 1][y - 1].getType() == "water")
				map[x - 1][y].setImg(img_array[GRASS][27]);
			else
				map[x - 1][y].setImg(img_array[GRASS][29]);
		}
		if (map[x + 1][y].getType() == "grass")
		{
			if (map[x + 1][y].getImg() == &img_array[GRASS][25] || map[x + 1][y - 1].getType() == "water")
				map[x + 1][y].setImg(img_array[GRASS][26]);
			else
				map[x + 1][y].setImg(img_array[GRASS][28]);
		}
		if (map[x][y + 1].getType() == "grass" && map[x + 1][y + 1].getType() != "water" && map[x - 1][y + 1].getType() != "water")
		{
			map[x][y + 1].setImg(img_array[GRASS][25]);
		}
}

static void add_ocean_to_map(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array)
{
	int h_map = (HEIGHT_WIN / 32) / 2 + 1;
	int w_map = (WIDTH_WIN / 32) / 2 + 1;
	if (h_map % 2 != 0)
		h_map++;
	if (w_map % 2 != 0)
		w_map++;

	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < w_map; x++)
		{
			map[x][y].setImg(img_array[WATER][0]);
			map[x][y].setType("water");
			map[x][y].setZ(0);
			if (x + 1 == w_map)
			{
				map[x + 1][y].setType("grass");
				map[x + 1][y].setZ(0);
				map[x + 2][y].setType("grass");
				map[x + 2][y].setZ(0);
			}
		}
		for (size_t x = WIDTH_MAP - w_map; x < WIDTH_MAP; x++)
		{
			map[x][y].setImg(img_array[WATER][0]);
			map[x][y].setType("water");
			map[x][y].setZ(0);
			if (x == WIDTH_MAP - w_map)
			{
				map[x - 1][y].setType("grass");
				map[x - 1][y].setZ(0);
				map[x - 2][y].setType("grass");
				map[x - 2][y].setZ(0);
			}
		}
	}

	for (size_t x = 0; x < WIDTH_MAP; x++)
	{
		for (size_t y = 0; y < h_map; y++)
		{
			map[x][y].setImg(img_array[WATER][0]);
			map[x][y].setType("water");
			map[x][y].setZ(0);
			if (y + 1 == h_map && x >=  w_map && x < WIDTH_MAP - w_map)
			{
				map[x][y + 1].setType("grass");
				map[x][y + 1].setZ(0);
				map[x][y + 2].setType("grass");
				map[x][y + 2].setZ(0);
			}
		}
		for (size_t y = HEIGHT_MAP - h_map; y < HEIGHT_MAP; y++)
		{
			map[x][y].setImg(img_array[WATER][0]);
			map[x][y].setType("water");
			map[x][y].setZ(0);
			if (y == HEIGHT_MAP - h_map && x >=  w_map && x < WIDTH_MAP - w_map)
			{
				map[x][y - 1].setType("grass");
				map[x][y - 1].setZ(0);
				map[x][y - 2].setType("grass");
				map[x][y - 2].setZ(0);
			}
		}
	}


}

/*==========================================================================================*/
									/*DECORATION GENERATION*/
/*==========================================================================================*/

static void	generate_flower(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y, unsigned int max, int type_flower)
{
	if (x >= WIDTH_MAP || y >= HEIGHT_MAP || map[x][y].getType() != "grass")
	{
		return ;
	}

	int check = (x != 0 && (map[x - 1][y].getType() == "grass") && map[x - 1][y].getZ() == map[x][y].getZ());
	check += (y != 0 && (map[x][y - 2].getType() == "grass") && map[x][y - 1].getZ() == map[x][y].getZ());
	check += (y + 2 < HEIGHT_MAP && (map[x][y + 2].getType() == "grass") && map[x][y + 2].getZ() == map[x][y].getZ());
	check += (x + 2 < WIDTH_MAP && (map[x + 2][y].getType() == "grass") && map[x + 2][y].getZ() == map[x][y].getZ());

	if (!map[x][y].asDecors() && (y + 1 < HEIGHT_MAP && (map[x][y + 1].getType() == "grass")))
	{
		map[x][y].addDecors(img_array[DECORS][type_flower + 1]);
		map[x + 1][y].addDecors(img_array[DECORS][type_flower + 1]);
		map[x][y + 1].addDecors(img_array[DECORS][type_flower + 1]);
		map[x + 1][y + 1].addDecors(img_array[DECORS][type_flower + 1]);
	}
	if (check == 4 && max && std::rand() % 50 > PROPAGATION_FLOWER)
	{
		/*if (!map[x][y].asDecors())
		{
			map[x][y].addDecors(img_array[DECORS][type_flower]);
			map[x + 1][y].addDecors(img_array[DECORS][type_flower]);
			map[x][y + 1].addDecors(img_array[DECORS][type_flower]);
			map[x + 1][y + 1].addDecors(img_array[DECORS][type_flower]);
		}*/
		generate_flower(map, img_array, x - 2, y, max - 1, type_flower);
		generate_flower(map, img_array, x + 2, y, max - 1, type_flower);
		generate_flower(map, img_array, x, y - 2, max - 1, type_flower);
		generate_flower(map, img_array, x, y + 2, max - 1, type_flower);
	}
}


/*==========================================================================================*/
									/*GENERALL FUNCTION*/
/*==========================================================================================*/


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
	int z_first = std::rand() % 3;
	std::string type_first = type_tab[std::rand() % 2 + 1];
	map[0][0] = CaseMap(0, 0, z_first, type_first);
	map[1][0] = CaseMap(1, 0, z_first, type_first);
	map[0][1] = CaseMap(0, 1, z_first, type_first);
	map[1][1] = CaseMap(1, 1, z_first, type_first);


	if (DEBUG_INFO)
		std::cout << "\e[0;35mMAP VARIATION GENERATION\e[0;m" << std::endl;
	for (size_t i = 0; i < RANDOM_LEVEL; i++) /* (WIDTH_MAP * HEIGHT_MAP) / 1000*/
	{

		int x = 3;
		int y = 3;
		while (x % 2 != 0 || y % 2 != 0 )
		{
			x = std::rand() % (WIDTH_MAP - 1);
			y = std::rand() % (HEIGHT_MAP - 1);
		}
		int z = std::rand() % 3;
		std::string type_ = type_tab[std::rand() % 2 + 1];
		CaseMap casem1(x, y, z, type_);
		CaseMap casem2(x + 1, y, z, type_);
		CaseMap casem3(x, y + 1, z, type_);
		CaseMap casem4(x + 1, y + 1, z, type_);
		map[x][y] = casem1;
		map[x + 1][y] = casem2;
		map[x][y + 1] = casem3;
		map[x + 1][y + 1] = casem4;
		if (DEBUG_INFO && COOR_INFO)
			std::cout << "\e[1;37m	generating \e[0;36m" << type_ << "\e[1;37m : \e[1;33m" << x << "\e[1;37m | \e[1;33m" << y << "\e[0;m" << std::endl;
		if (x + 2 < WIDTH_MAP)
			recursive_generating(map, x + 2, y, 15, 1);
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mMAP FILLING\e[0;m" << std::endl;
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			if (map[x][y].getType() == "none")
			{
				recursive_generating(map, x, y, 20, 1);
			}
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mMAP OCEAN GENERATION\e[0;m" << std::endl;
	add_ocean_to_map(map, img_array);
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;


	if (DEBUG_INFO)
		std::cout << "\e[0;35mSIZE'S WALL CALCULATING\e[0;m" << std::endl;
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			add_big_wall(map, img_array, x, y);
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mBASIC TEXTURE APPLICATION\e[0;m" << std::endl;
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			associate_img(map, img_array, x, y);
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mWATER GENERATION\e[0;m" << std::endl;
	for (size_t i = 0; i < RANDOM_LEVEL; i++) 
	{

		int x = 3;
		int y = 3;
		while (x % 2 != 0 || y % 2 != 0 )
		{
			x = std::rand() % (WIDTH_MAP - 1);
			y = std::rand() % (HEIGHT_MAP - 1);
		}
		if (DEBUG_INFO && COOR_INFO)
			std::cout << "\e[1;37m	generating water : \e[1;33m" << x << "\e[1;37m | \e[1;33m" << y << "\e[0;m" << std::endl;
		generate_water(map, img_array, x , y, 15);
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mDECORATION GENERATION\e[0;m" << std::endl;
	for (size_t i = 0; i < RANDOM_LEVEL; i++) 
	{

		int x = 3;
		int y = 3;
		while (x % 2 != 0 || y % 2 != 0 )
		{
			x = std::rand() % (WIDTH_MAP - 1);
			y = std::rand() % (HEIGHT_MAP - 1);
		}
		if (map[x][y].getType() == "grass")
		{
			if (DEBUG_INFO && COOR_INFO)
				std::cout << "\e[1;37m	generating flower : \e[1;33m" << x << "\e[1;37m | \e[1;33m" << y << "\e[0;m" << std::endl;
			generate_flower(map, img_array, x , y, 6, (std::rand() % 3) * 2 + 4 );
		}
		if (map[x][y].getType() == "water")
		{
			if (DEBUG_INFO && COOR_INFO)
				std::cout << "\e[1;37m	generating water stone : \e[1;33m" << x << "\e[1;37m | \e[1;33m" << y << "\e[0;m" << std::endl;
			map[x][y].addDecors(img_array[DECORS][std::rand() % 4]);
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mBIOME BORDER MODIFICATIN\e[0;m" << std::endl;
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			if (map[x][y].getType() == "water" && x != 0 && y != 0 && y + 1 < HEIGHT_MAP && x + 1 < WIDTH_MAP) 
				change_water_border(map, img_array, x, y);
			if (map[x][y].getType() == "sand")
				add_grass_border(map, img_array, x, y);
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;

	if (DEBUG_INFO)
		std::cout << "\e[0;35mSHADOW CALCULATING\e[0;m" << std::endl;
	for (size_t y = 0; y < HEIGHT_MAP; y++)
	{
		for (size_t x = 0; x < WIDTH_MAP; x++)
		{
			add_shadow(map, img_array, x, y);
		}
	}
	if (DEBUG_INFO)
		std::cout << "\e[1;32m	\e[5mDone\e[25m\e[0;m" << std::endl;
	
	return (map);
}

void	affiche_map(std::vector<std::vector<CaseMap>> & map, sf::RenderWindow & window, unsigned int xadd, unsigned int yadd)
{
	
	for (size_t y = yadd / 32; y < yadd / 32 + HEIGHT_WIN  / 32 + 2 && y < HEIGHT_MAP; y++)
	{
		for (size_t x = xadd / 32; x < xadd / 32 + WIDTH_WIN / 32 + 2 && x < WIDTH_MAP; x++)
		{
			map[x][y].draw(window, -xadd + 32, -yadd + 32);
		}
	}	


	
	sf::RectangleShape rectangle(sf::Vector2f(64 + WIDTH_WIN, 32));


	
	rectangle.setFillColor(sf::Color(0, 0, 0));
	rectangle.setPosition(sf::Vector2f(0, 0));
	window.draw(rectangle);
	rectangle.setPosition(sf::Vector2f(0, 32 + HEIGHT_WIN + 1));
	window.draw(rectangle);
	rectangle.setSize(sf::Vector2f(32, 64 + HEIGHT_WIN));
	rectangle.setPosition(sf::Vector2f(0, 0));
	window.draw(rectangle);
	rectangle.setPosition(sf::Vector2f(32 + WIDTH_WIN, 0));
	window.draw(rectangle);


	/*tempo*/

	/*
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
	*/
}