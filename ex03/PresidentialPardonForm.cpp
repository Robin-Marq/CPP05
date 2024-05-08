/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:52:33 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 10:30:03 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Request", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm::AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Presidential Destructor called" << DEFAULT << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm	*PresidentialPardonForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (form);
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
