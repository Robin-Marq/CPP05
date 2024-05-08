/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:52:12 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 11:59:34 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		_target = copy._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RED << "Robotomy Destructor called" << DEFAULT << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getExecGrade() || !getIsSigned())
		throw AForm::GradeTooLowException();

    srand((unsigned)time(NULL));

    int nbr = rand() % 2;

    (void)bureaucrat;

    if (nbr)
        std::cout << this->_target << " has been robotomized succesfully 50% of the time" << std::endl;
    else
        std::cout << "Robotomizing " << this->_target << " failed" << std::endl << std::endl;
}