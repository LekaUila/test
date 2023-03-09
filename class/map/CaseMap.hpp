/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/03/09 13:21:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CASEMAP
# define CASEMAP
# include <SFML/Graphics.hpp>
# include <iostream>
# include <string>
# include <vector>
# include "../includes/define_anime_time.hpp"
class CaseMap 
{
private:

	unsigned int	x;
	unsigned int	y;
	float	z;
	unsigned int anime_frame = 0;
	std::string		type;
	std::vector<sf::Sprite *>		img;
	std::vector<sf::Sprite *>		decors_add;
	std::vector<sf::Sprite *>		shadow_add;

protected:

	/* data */

public:

	CaseMap();
	CaseMap(unsigned int x, unsigned int y, unsigned int z, std::string type);					//constructor
	~CaseMap();							//destructor

	unsigned int getX() const;
	unsigned int getY() const;
	void setX(unsigned int x);
	void setY(unsigned int y);
	float getZ() const;
	void setZ(float z);
	const std::string & getType() const;
	void setType(std::string type);
	sf::Sprite * getImg() const;
	sf::Sprite * getImg(int ind) const;
	void setImg(sf::Sprite &img);
	void setImg(sf::Sprite &img, int ind);
	void draw(sf::RenderWindow & window, unsigned int xadd, unsigned int yadd);
	void addDecors(sf::Sprite &sp);
	int  asDecors() const;
	void addShadow(sf::Sprite &sp);


 
};
#endif
