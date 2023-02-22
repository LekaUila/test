/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaseMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:06:41 by lflandri          #+#    #+#             */
/*   Updated: 2023/02/21 12:19:06 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CASEMAP
# define CASEMAP
# include "../../includes/main_header.hpp"
class CaseMap 
{
private:

	const unsigned int	x;
	const unsigned int	y;
	const unsigned int	z;
	const sf::Image		&img;
	const std::string		type;

protected:

	/* data */

public:

	CaseMap(unsigned int x, unsigned int y, unsigned int z, sf::Image &img, std::string type);					//constructor
	~CaseMap();							//destructor
	CaseMap (const CaseMap &obj);				//copie constructor
	CaseMap& operator=(const CaseMap& x);		//assignation constructor

	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getZ() const;
	const std::string & getType() const;
	const sf::Image & getImg() const;


 
};
#endif
