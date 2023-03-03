/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_calcul.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:22:47 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/03 17:31:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_header.hpp"

static bool add_shadow_water(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	/*  triangle bas*/
	if (x + 2 < WIDTH_MAP && map[x][y].getImg() == &img_array[WATER][9])
	{
		map[x + 1][y].addDecors(img_array[SHADOW][6]);
		return (1);
	}
	/*  triangle haut*/
	else if (x + 1 < WIDTH_MAP && y != 0 && map[x][y].getImg() == &img_array[GRASS][26] && map[x][y].getZ() == map[x][y - 1].getZ() && map[x][y - 1].getType() == "water")
	{
		if (map[x - 1][y - 1].getType() != "grass")
			map[x][y - 1].addDecors(img_array[SHADOW][9]);
		return (1);
	}
	/*corner*/
	else if(x + 1 < WIDTH_MAP && y != 0 &&  map[x][y].getImg() == &img_array[GRASS][27] && map[x][y].getZ() == map[x][y - 1].getZ() && map[x][y - 1].getType() == "water"
			&& map[x][y].getZ() == map[x + 1][y].getZ() && map[x + 1][y].getType() == "water")
	{
		map[x][y - 1].addDecors(img_array[SHADOW][8]);
		if (map[x][y].getZ() == map[x + 1][y - 1].getZ() && map[x + 1][y - 1].getType() == "water")
		{
			map[x + 1][y].addDecors(img_array[SHADOW][7]);
			map[x + 1][y - 1].addDecors(img_array[SHADOW][11]);
		}
		else
		{
			map[x + 1][y].addDecors(img_array[SHADOW][5]);
		}
		
		return (1);
	}
	/*right*/
	else if (x + 2 < WIDTH_MAP && map[x][y].getImg() == &img_array[GRASS][29] && map[x][y].getZ() == map[x + 1][y].getZ() && map[x + 1][y].getType() == "water")
	{
		if (map[x][y].getZ() == map[x + 1][y + 1].getZ() && map[x + 1][y + 1].getType() == "grass")
		{
			map[x + 1][y].addDecors(img_array[SHADOW][10]);
		}
		else if (map[x][y].getZ() == map[x + 1][y - 1].getZ() && map[x + 1][y - 1].getType() == "water")
		{
			map[x + 1][y].addDecors(img_array[SHADOW][7]);
		}
		else
		{
			map[x + 1][y].addDecors(img_array[SHADOW][5]);
		}
		return (1);
	}
	/*top*/
	else if(x + 1 < WIDTH_MAP && y != 0 && map[x][y].getImg() == &img_array[GRASS][25] && map[x][y].getZ() == map[x][y - 1].getZ() && map[x][y - 1].getType() == "water")
	{
		if (!(map[x][y].getZ() == map[x - 1][y - 1].getZ() && map[x - 1][y - 1].getType() == "grass"))
			map[x][y - 1].addDecors(img_array[SHADOW][8]);
		return (1);
	}
	return (0);
}

void add_shadow(std::vector <std::vector <CaseMap>> & map, std::vector< std::vector<sf::Sprite>> & img_array, unsigned int x, unsigned int y)
{
	if (add_shadow_water(map, img_array, x, y))
	{
		return ;
	}
	/*spe 1*/
	if (x + 1 < WIDTH_MAP && y + 1 < HEIGHT_MAP && map[x][y + 1].getZ() > map[x + 1][y + 1].getZ() && 
		map[x][y].getZ() > map[x + 1][y + 1].getZ() && map[x + 1][y].getZ() > map[x + 1][y + 1].getZ() && map[x][y].getZ() == map[x + 1][y].getZ())
	{
		map[x + 1][y].addDecors(img_array[SHADOW][2]);
	}
	/*spe 2*/
	else if (x + 1 < WIDTH_MAP && y != 0  && map[x][y].getZ() > map[x + 1][y].getZ() && 
		map[x][y - 1].getZ() > map[x + 1][y].getZ() && map[x + 1][y - 1].getZ() > map[x + 1][y].getZ() && map[x][y - 1].getZ() == map[x + 1][y - 1].getZ())
	{
		map[x + 1][y].addDecors(img_array[SHADOW][3]);
	}
	/*  triangle bas*/
	else if (x + 2 < WIDTH_MAP && (map[x][y].getImg() == &img_array[SAND][21] || map[x][y].getImg() == &img_array[GRASS][21]))
	{
		if (y + 2 < HEIGHT_MAP)
		{
			if (map[x][y + 2].getZ() != 2)
			{
				map[x + 1][y].addDecors(img_array[SHADOW][1]);
			}
			if (y != 0 && map[x][y - 1].getZ() > map[x + 1][y].getZ() + 1)
			{
				map[x + 2][y - 1].addDecors(img_array[SHADOW][1]);
			}
		}
		else
		{
			map[x + 1][y].addDecors(img_array[SHADOW][1]);
			if (y != 0 && map[x][y - 1].getZ() > map[x + 1][y].getZ() + 1)
			{
				map[x + 2][y - 1].addDecors(img_array[SHADOW][1]);
			}
		}
	}
	/*  triangle haut*/
	else if (x + 1 < WIDTH_MAP && y != 0 && (map[x][y].getImg() == &img_array[SAND][26] || map[x][y].getImg() == &img_array[GRASS][26]))
	{
		if (x != 0 && map[x - 1][y].getZ() > map[x][y].getZ() - 2 && map[x][y - 1].getZ() <= map[x][y].getZ() - 2)
		{
			map[x + 1][y - 1].addDecors(img_array[SHADOW][0]);
		}
		else
			map[x + 1][y - 1].addDecors(img_array[SHADOW][4]);
		if (x + 2 < WIDTH_MAP && y != 0 && map[x][y].getZ() > map[x][y - 1].getZ() + 1 && map[x][y].getZ() > map[x + 2][y - 2].getZ() + 1)
		{
			map[x + 2][y - 2].addDecors(img_array[SHADOW][4]);
		}
	}
	/*corner*/
	else if(x + 1 < WIDTH_MAP && y != 0 &&  (map[x][y].getImg() == &img_array[SAND][27] || map[x][y].getImg() == &img_array[GRASS][27]))
	{
		map[x + 1][y - 1].addDecors(img_array[SHADOW][0]);
		map[x + 1][y].addDecors(img_array[SHADOW][0]);
		//map[x][y - 1].addDecors(img_array[SHADOW][0]);
		if (y != 0 && map[x][y].getZ() > map[x + 1][y].getZ() + 1)
		{
			map[x + 2][y - 1].addDecors(img_array[SHADOW][0]);
		}
		if (x + 3 < WIDTH_MAP && map[x][y].getZ() > map[x][y - 1].getZ() + 1 && map[x + 2][y - 2].getZ() < map[x][y].getZ() - 1)
		{
			map[x + 2][y - 2].addDecors(img_array[SHADOW][0]);
		}
	}
	/*right*/
	else if (x + 2 < WIDTH_MAP && (map[x][y].getImg() == &img_array[WALL][2] || 
		map[x][y].getImg() == &img_array[SAND][24] || map[x][y].getImg() == &img_array[GRASS][24] || 
		map[x][y].getImg() == &img_array[SAND][27] || map[x][y].getImg() == &img_array[GRASS][27] || 
		map[x][y].getImg() == &img_array[SAND][29] || map[x][y].getImg() == &img_array[GRASS][29]))
	{
		if (map[x][y].getImg() == &img_array[WALL][2] && (map[x + 1][y].getZ() == 1 || (y + 1 < HEIGHT_MAP && map[x][y + 1].getType() == "water" && map[x][y].getZ() == map[x][y + 1].getZ())))
		{
			map[x + 1][y].addDecors(img_array[SHADOW][1]);
			if (map[x][y + 1].getZ() == 1.5 && map[x + 2][y - 1].getZ() == 0 && map[x + 2][y - 1].getZ() == 0 && map[x + 2][y ].getZ() != 1)
				map[x + 2][y - 1].addDecors(img_array[SHADOW][1]);
		}
		else
			map[x + 1][y].addDecors(img_array[SHADOW][0]);
		if (y != 0 && map[x][y].getZ() > map[x + 1][y].getZ() + 1)
		{
			if (y != 1 && (map[x + 2][y - 1].getZ() < map[x + 2][y - 2].getZ() ))
			{
				map[x + 2][y - 1].addDecors(img_array[SHADOW][3]);
			}
			else if (y != 1 && (map[x + 2][y].getZ() < map[x + 2][y - 1].getZ() ))
			{
				map[x + 2][y - 1].addDecors(img_array[SHADOW][2]);
			}
			else
				map[x + 2][y - 1].addDecors(img_array[SHADOW][0]);
		}
	}
	/*top*/
	else if(x + 1 < WIDTH_MAP && y != 0 &&  (map[x][y].getImg() == &img_array[SAND][25] || map[x][y].getImg() == &img_array[GRASS][25]))
	{
		if (map[x][y].getZ() > map[x + 1][y - 1].getZ())
		{
			map[x + 1][y - 1].addDecors(img_array[SHADOW][0]);
			if (x + 2 < WIDTH_MAP && map[x][y].getZ() > map[x][y - 1].getZ() + 1 && map[x + 2][y - 2].getZ() < map[x][y].getZ() - 1)
			{
				map[x + 2][y - 2].addDecors(img_array[SHADOW][0]);
			}
		}
	}
}