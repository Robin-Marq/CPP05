/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:28:47 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 10:29:27 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern const	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm	*form;

	form = AForm::makeForm(type, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		std::cout << "Intern creates: " << form->getName() << " with target: " << form->getTarget() << std::endl;
	return (form);
}
