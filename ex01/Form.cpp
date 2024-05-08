/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:06 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 11:03:27 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(150), _execGrade(150), _formIsSigned(false)
{
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _formIsSigned(copy._formIsSigned)
{
}

// This function checks if the grade is within the range of 1 to 150. If it is not, it throws an exception.
Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _formIsSigned(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}


Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        _formIsSigned = copy._formIsSigned;
    }
    return *this;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << DEFAULT << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

bool Form::getIsSigned() const
{
    return _formIsSigned;
}

// This function checks if the bureaucrat has the required grade to sign the form. If the bureaucrat has the required grade, the form is signed( to true)
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _formIsSigned = true;
}

std::ostream &operator<<(std::ostream &output, Form &form)
{
    output << GREEN << form.getName() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ", Is it signed: " << (form.getIsSigned() ? "Yes" : "No") << DEFAULT;
    return output;
}

// This function's are for the Form exception class for the GradeTooHighException and GradeTooLowException.
// It returns a own specific message if the grade is too high.
// The "what" function (keyword) is a virtual function from the std::exception class. It is used to return a message when an exception is thrown.
// The keyword throw() is used to specify that the function does not throw any exceptions.
// From Robin Marquardt
const char *Form::GradeTooHighException::what() const throw()
{
    return "Message from Form: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Message from Form: Grade is too low!";
}