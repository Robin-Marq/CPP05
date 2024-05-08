/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:52:09 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 10:42:06 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class Bureacrat; // Forward declaration, we need this for the execute method, so that the compiler knows that Bureaucrat is a class

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &bureaucrat) const;
	static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);
	std::string const	&getTarget(void) const;
};
