/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/22 16:36:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CASEMAP
# define CASEMAP
# include "../../includes/main_header.hpp"
class CaseMap 
{
private:

	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	std::string	type;
	sf::Sprite			img;

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
	const std::string & getType() const;
	const sf::Sprite & getImg() const;
	void setImg(sf::Texture &img);


 
};
#endif
