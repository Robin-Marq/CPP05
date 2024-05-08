/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:06 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/10 14:56:39 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(150), _execGrade(150), _aFormIsSigned(false) {}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _aFormIsSigned(copy._aFormIsSigned) {}

// This function checks if the grade is within the range of 1 to 150. If it is not, it throws an exception.
AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _aFormIsSigned(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}


AForm &AForm::operator=(const AForm &copy)
{

    if (this != &copy)
    {
        _aFormIsSigned = copy._aFormIsSigned;
    }
    return *this;
}

AForm::~AForm()
{
	std::cout << RED << "-> AForm Destructor called" << DEFAULT << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

bool AForm::getIsSigned() const
{
    return _aFormIsSigned;
}

// This function checks if the bureaucrat has the required grade to sign the AForm. If the bureaucrat has the required grade, the AForm is signed( to true)
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _aFormIsSigned = true;
}

std::ostream &operator<<(std::ostream &output, AForm &AForm)
{
    output << GREEN << AForm.getName() << ", sign grade: " << AForm.getSignGrade() << ", exec grade: " << AForm.getExecGrade() << ", Is it signed: " << (AForm.getIsSigned() ? "Yes" : "No") << DEFAULT << std::endl;;
    return output;
}

// This function's are for the AForm exception class for the GradeTooHighException and GradeTooLowException.
// It returns a own specific message if the grade is too high.
// The "what" function (keyword) is a virtual function from the std::exception class. It is used to return a message when an exception is thrown.
// The keyword throw() is used to specify that the function does not throw any exceptions.
// From Robin Marquardt
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

// This function checks if the form is signed and if the grade is ok
// From Robin Marquardt
void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!_aFormIsSigned)
	{
		std::cout << "The form is not signed" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() > _execGrade) // here we check if the grade of the bureaucrat is high enough to execute the form
	{
		std::cout << "The grade is too low to execute the form" << std::endl;
		return;
	}
	std::cout << "The form is executed" << std::endl;
}
