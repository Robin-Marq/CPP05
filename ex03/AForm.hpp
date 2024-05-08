/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:10 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/22 10:36:28 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const int   _signGrade;
    const int   _execGrade;
    bool        _aFormIsSigned;

public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm &copy);

    AForm &operator=(const AForm &copy);
    virtual ~AForm();

    std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    virtual std::string const	&getTarget(void) const = 0;

    void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
    static AForm *makeForm(std::string const &type, std::string const &target);

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class InvalidFormException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

//This is the overload of the << operator, so we can print the form with cout
std::ostream &operator<<(std::ostream &output, AForm &form);
