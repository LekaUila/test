/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/22 19:16:33 by lflandri         ###   ########.fr       */
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
unsigned int CaseMap::getZ() const
{
	return (this->z);
}
const std::string & CaseMap::getType() const
{
	return (this->type);
}
const sf::Sprite & CaseMap::getImg() const
{
	return (this->img);
}

void CaseMap::setImg(sf::Texture &img)
{
	this->img = sf::Sprite(img);
	this->img.setPosition(sf::Vector2f(32 * x, 32 * y));
}