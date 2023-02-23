/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/23 13:10:24 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CASEMAP
# define CASEMAP
# include <SFML/Graphics.hpp>
# include <iostream>
# include <string>
class CaseMap 
{
private:

	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	std::string		type;
	sf::Sprite		*img;

protected:

	/* data */

public:

	CaseMap();
	CaseMap(unsigned int x, unsigned int y, unsigned int z, std::string type);					//constructor
	~CaseMap();							//destructor
	CaseMap (const CaseMap &obj);				//copie constructor
	CaseMap& operator=(const CaseMap& x);		//assignation constructor

	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getZ() const;
	void setZ(unsigned int z);
	const std::string & getType() const;
	sf::Sprite * getImg() const;
	void setImg(sf::Sprite &img);
	void draw(sf::RenderWindow & window, unsigned int xadd, unsigned int yadd);


 
};
#endif
