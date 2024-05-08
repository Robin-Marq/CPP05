/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:14 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/22 11:08:51 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
    Intern      internObject;
    AForm       *form;
    Bureaucrat  robin("Robin", 100);
	Bureaucrat	jens("Jens", 1);

	std::cout << std::endl;

    try
    {
        form = internObject.makeForm("robotomy", "Jan");
		delete form;
		form = NULL;
        form = internObject.makeForm("shrubbery", "Steven");
		delete form;
		form = NULL;
        form = internObject.makeForm("presidential", "Daniel");
        form = internObject.makeForm("thisIsaWrongExampel", "Alex");
    }
    catch (std::exception &failMessage)
    {
        std::cout << "exception error from first test: " << failMessage.what() << std::endl;
		delete form;
    }

    std::cout << "------------------------------------" << std::endl;

	try
    {
        form = internObject.makeForm("shrubbery", "Florian");
        form->beSigned(robin);
        robin.executeForm(*form);
        delete form;
    }
    catch (std::exception &failMessage)
    {
        std::cout << "exception error from Florian test: " << failMessage.what() << std::endl;
		// delete form;
    }

    std::cout << "------------------------------------" << std::endl;
    try
    {
        form = internObject.makeForm("presidential", "Diana");
        robin.signForm(*form);
        robin.executeForm(*form);
        delete form;
    }
    catch (std::exception &failMessage)
    {
        std::cout << "exception error from Diana test: " << failMessage.what() << std::endl;
		delete form;
    }

	std::cout << "------------------------------------" << std::endl;

	try
	{
		form = internObject.makeForm("robotomy", "Jan");
		robin.signForm(*form);
		robin.executeForm(*form);
		delete form;
	}
	catch (std::exception &failMessage)
	{
		std::cout << "exception error from Jan test: " << failMessage.what() << std::endl;
		delete form;
	}

	std::cout << "------------------------------------" << std::endl;

	 try
    {
        form = internObject.makeForm("presidential", "Diana");
        jens.signForm(*form);
        jens.executeForm(*form);
        delete form;
    }
    catch (std::exception &failMessage)
    {
        std::cout << "exception error from Jens test: " << failMessage.what() << std::endl;
		delete form;
    }

	std::cout << "------------------------------------" << std::endl;

	 try
    {
        form = internObject.makeForm("robotomy", "Pascal");
        jens.signForm(*form);
        jens.executeForm(*form);
        delete form;
    }
    catch (std::exception &failMessage)
    {
        std::cout << "exception error from Pascal test: " << failMessage.what() << std::endl;
		delete form;
    }

    return 0;
}
