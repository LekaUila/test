/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:45 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/21 12:19:47 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CaseMap.hpp"

CaseMap::CaseMap(unsigned int x, unsigned int y, unsigned int z, sf::Image &img, std::string type)
: x(x), y(y), z(z), img(img), type(type)
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
const sf::Image & CaseMap::getImg() const
{
	return (this->img);
}