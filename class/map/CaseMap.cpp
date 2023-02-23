/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/23 18:59:40 by lflandri         ###   ########.fr       */
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

CaseMap::CaseMap (const CaseMap &obj)
: x(obj.getX()), y(obj.getY()), z(obj.getZ()), img(obj.getImg()), type(obj.getType())
{
}
CaseMap& CaseMap::operator=(const CaseMap& x)
{
	this->x = x.getX();
	this->y = x.getY();
	this->z = x.getZ();
	this->type = x.getType();
	this->img = x.getImg();
	return (*this);
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

unsigned int CaseMap::getZ() const
{
	return (this->z);
}
void CaseMap::setZ(unsigned int z)
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
	return (this->img);
}

void CaseMap::setImg(sf::Sprite &img)
{
	this->img = &img;
}

void CaseMap::draw(sf::RenderWindow & window, unsigned int xadd, unsigned int yadd)
{
	this->img->setPosition(sf::Vector2<float>((this->x * 32 + xadd) , (this->y * 32 + yadd)));
	window.draw(*this->img);
}