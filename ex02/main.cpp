/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:14 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 12:06:05 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << std::endl;

	//create 3 Bureaucrats
	Bureaucrat Boby("Boby", 145);
	Bureaucrat Harry("Harry", 72);
	Bureaucrat Robin("Robin", 25);
	Bureaucrat Daniel("Daniel", 137);
	Bureaucrat Sven("Sven", 45);
	Bureaucrat Michael("Michael", 5);

	std::cout << std::endl;

	//create 3 forms
	ShrubberyCreationForm shrubbery ("Home");
	RobotomyRequestForm robotomy("Home_of_Robotomy");
	PresidentialPardonForm pardon("Home_of_President");

	std::cout << Boby;
	std::cout << Harry;
	std::cout << Robin;
	std::cout << Daniel;
	std::cout << Sven;
	std::cout << Michael << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon << std::endl;

	{
		try
		{
			std::cout << YELLOW << "Now the Bureaucrats will try to execute the forms\n" << DEFAULT;
			std::cout << "------------------------------------------------\n" << std::endl;
			std::cout << Boby.getName() << " tries to sign the form shrubbery: " << std::endl;
			Boby.signForm(shrubbery);
			Boby.executeForm(shrubbery);
			std::cout << Boby.getName() << " tries to sign the form robotomy: " << std::endl;
			Boby.signForm(robotomy);
			Boby.executeForm(robotomy);
			std::cout << Boby.getName() << " tries to sign the form pardon: " << std::endl;
			Boby.signForm(pardon);
			Boby.executeForm(pardon);
			std::cout << std::endl;

			std::cout << Harry.getName() << " tries to sign the form shrubbery: " << std::endl;
			Harry.signForm(shrubbery);
			Harry.executeForm(shrubbery);
			std::cout << Harry.getName() << " tries to sign the form robotomy: " << std::endl;
			Harry.signForm(robotomy);
			Harry.executeForm(robotomy);
			std::cout << Harry.getName() << " tries to sign the form pardon: " << std::endl;
			Harry.signForm(pardon);
			Harry.executeForm(pardon);
			std::cout << std::endl;

			std::cout << Robin.getName() << " tries to sign the form shrubbery: " << std::endl;
			Robin.signForm(shrubbery);
			Robin.executeForm(shrubbery);
			std::cout << Robin.getName() << " tries to sign the form robotomy: " << std::endl;
			Robin.signForm(robotomy);
			Robin.executeForm(robotomy);
			std::cout << Robin.getName() << " tries to sign the form pardon: " << std::endl;
			Robin.signForm(pardon);
			Robin.executeForm(pardon);
			std::cout << std::endl;

			std::cout << Daniel.getName() << " tries to sign the form shrubbery: " << std::endl;
			Daniel.executeForm(shrubbery);
			std::cout << Daniel.getName() << " tries to sign the form robotomy: " << std::endl;
			Daniel.executeForm(robotomy);
			std::cout << Daniel.getName() << " tries to sign the form pardon: " << std::endl;
			Daniel.executeForm(pardon);
			std::cout << std::endl;

			std::cout << Sven.getName() << " tries to sign the form shrubbery: " << std::endl;
			Sven.executeForm(shrubbery);
			std::cout << Sven.getName() << " tries to sign the form robotomy: " << std::endl;
			Sven.executeForm(robotomy);
			std::cout << Sven.getName() << " tries to sign the form pardon: " << std::endl;
			Sven.executeForm(pardon);
			std::cout << std::endl;

			std::cout << Michael.getName() << " tries to sign the form shrubbery: " << std::endl;
			Michael.executeForm(shrubbery);
			std::cout << Michael.getName() << " tries to sign the form robotomy: " << std::endl;
			Michael.executeForm(robotomy);
			std::cout << Michael.getName() << " tries to sign the form pardon: " << std::endl;
			Michael.executeForm(pardon);
			std::cout << DEFAULT;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	//Try to sign the form and execute it with the correct grade to execute
	try
    {
		std::cout << GREEN;
		std::cout << "Daniel tries to sign the form shrubbery:" << std::endl;
        shrubbery.beSigned(Daniel);
		Daniel.executeForm(shrubbery);
		std::cout << "from Daniel\n" << std::endl;
		std::cout << YELLOW << shrubbery << std::endl;
    }

    catch (std::exception &failMessage)
	{
		std::cout << CYAN << failMessage.what() << std::endl;
		std::cout << YELLOW << shrubbery << std::endl;
	}

	std::cout << "\n --------------------- \n\n";

	//Try to sign the form and execute it with the correct grade to execute
	try
    {
		std::cout << GREEN;
		std::cout << "Sven tries to sign the form robotomy:" << std::endl;
		robotomy.beSigned(Sven);
		robotomy.execute(Sven);
		std::cout << "from Sven" << std::endl;
		std::cout << YELLOW << robotomy << std::endl;
    }


    catch (std::exception &failMessage)
	{
		std::cout << CYAN << failMessage.what() << std::endl;
		std::cout << YELLOW << shrubbery << std::endl;
	}

	std::cout << "\n --------------------- \n\n";

	//Try to sign the form and execute it with the correct grade to execute
	try
    {
		std::cout << GREEN;
		std::cout << "Michael tries to sign the form pardon:" << std::endl;
		pardon.beSigned(Michael);
		pardon.execute(Michael);
		std::cout << "from Michael" << std::endl;
		std::cout << YELLOW << pardon << std::endl;
    }

    catch (std::exception &failMessage)
	{
		std::cout << CYAN << failMessage.what() << std::endl;
		std::cout << YELLOW << shrubbery << std::endl;
	}

	std::cout << "\n --------------------- \n\n";

    return 0;
}
