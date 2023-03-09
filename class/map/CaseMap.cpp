/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/09 13:22:43 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CaseMap.hpp"

CaseMap::CaseMap()
: x(0), y(0), z(1000), type("none")
{
}

CaseMap::CaseMap(unsigned int x, unsigned int y, unsigned int z, std::string type)
: x(x), y(y), z(z), type(type)
{
}

CaseMap::~CaseMap()
{
}

unsigned int CaseMap::getX() const
{
	return (this->x);
}
unsigned int CaseMap::getY() const
{
	return (this->y);
}

void CaseMap::setX(unsigned int x)
{
	this->x = x;
}
void CaseMap::setY(unsigned int y)
{
	this->y = y;
}

float CaseMap::getZ() const
{
	return (this->z);
}
void CaseMap::setZ(float z)
{
	this->z = z;
}

const std::string & CaseMap::getType() const
{
	return (this->type);
}
void CaseMap::setType(std::string type)
{
	this->type = type;
}

sf::Sprite * CaseMap::getImg() const
{
	if (this->img.size() == 0)
		return (NULL);
	return (this->img[0]);
}

sf::Sprite * CaseMap::getImg(int ind) const
{
	if (this->img.size() <= ind)
		return (NULL);
	return (this->img[ind]);
}

void CaseMap::setImg(sf::Sprite &img)
{
	if (this->img.size() <= 0)
		this->img.push_back(&img);
	else
		this->img[0] = &img;
}

void CaseMap::setImg(sf::Sprite &img, int ind)
{
	if (this->img.size() <= ind)
		this->img.push_back(&img);
	else
		this->img[ind] = &img;
}

void CaseMap::draw(sf::RenderWindow & window, unsigned int xadd, unsigned int yadd)
{
	this->img[this->anime_frame / FLOOR_T]->setPosition(sf::Vector2<float>((this->x * 32 + xadd) , (this->y * 32 + yadd)));
	window.draw(*this->img[this->anime_frame / FLOOR_T]);

	this->anime_frame = this->anime_frame + 1 >= this->img.size() * FLOOR_T ? 0 : this->anime_frame + 1;

	for (size_t i = 0; i < this->decors_add.size(); i++)
	{
		(*(this->decors_add[i])).setPosition(sf::Vector2<float>((this->x * 32 + xadd) , (this->y * 32 + yadd)));
		window.draw(*(this->decors_add[i]));
	}
	for (size_t i = 0; i < this->shadow_add.size(); i++)
	{
		(*(this->shadow_add[i])).setPosition(sf::Vector2<float>((this->x * 32 + xadd) , (this->y * 32 + yadd)));
		window.draw(*(this->shadow_add[i]));
	}
}

void CaseMap::addDecors(sf::Sprite &sp)
{
	this->decors_add.push_back(&sp);
}
int  CaseMap::asDecors() const
{
	return (this->decors_add.size());
}

void CaseMap::addShadow(sf::Sprite &sp)
{
	this->shadow_add.push_back(&sp);
}