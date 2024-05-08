/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:54 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 12:10:25 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << GREEN << "Default Constructor called" << DEFAULT << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED;
    std::cout << "Default Destructor called for " << _name << std::endl;
    std::cout << DEFAULT;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Parameter constructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Assignment Operator = constructor called\n";
    if (this != &other)
    {
        this->_grade = other.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

// This function is the exception class for the GradeTooHighException
// from Robin Marquardt
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Sorry, Grade is too high";
}

// This function is the exception class for the GradeTooLowException
// from Robin Marquardt
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Sorry, Grade is too low";
}

// This function is used to overload the << operator
// It is used to print the object of the class
// from Robin Marquardt
std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
    output << bureaucrat.getName() << ", grade " << bureaucrat.getGrade() << std::endl;
    return output;
}

// This function is used to set the grade of the object
// from Robin Marquardt
void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getSignGrade() < this->getGrade())
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}