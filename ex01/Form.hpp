/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:10 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 11:00:43 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _formIsSigned;

public:

    Form();
    Form(std::string name, int signGrade, int execGrade);
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();

    //getter functions
    std::string getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;

    //setter functions
    void beSigned(Bureaucrat &bureaucrat);

    //exception classes for Form
	//i include this class, because it is usefull to implement this things inside the Form class, because we are going to use it only in the Bureaucrat class
	//if we will need this exceptions for other classes, we can create a new file for it. But here it doesn't make sense to do it in this exercise.
	//from Robin Marquardt
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, Form &form);
