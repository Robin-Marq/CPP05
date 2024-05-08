/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:51:43 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 11:58:30 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Shrubbery Destructor called" << DEFAULT << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		_target = copy._target;
	}
	return *this;
}

// In this function we are checking in execute if the form is signed and grades are ok
// From Robin Marquardt
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	if (executor.getGrade() > getExecGrade() || !getIsSigned())
		throw AForm::GradeTooLowException();

	std::ofstream outfile(_target.c_str()); // here we create a object called outfile, named _target and pump now everything with the outfile command into the _target

	if (!outfile.is_open())
	{
		std::cerr << "Error when try to open the file " << _target << std::endl;
		return;
	}
	outfile << "          --         \n";
	outfile << "        //--\\       \n";
	outfile << "       //----\\      \n";
    outfile << "      //--  --\\     \n";
	outfile << "     //--    --\\    \n";
	outfile << "    //--      --\\   \n";
	outfile << "   //--        --\\  \n";
	outfile << "  //--          --\\ \n";
	outfile << "     ------------    \n";
	outfile << "          ||         \n";
	outfile << "          ||         \n";
	outfile << "          ||         \n";
	outfile << "          ||         \n";
	outfile << "          ||         \n";
	outfile << " ~~~~~~~~~~~~~~~~~~~~\n";
    outfile.close();

	std::cout << YELLOW << "Shrubbery Creation Form has been executed" << DEFAULT << std::endl;

}
