/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:59 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 11:00:41 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

#define DEFAULT "\033[0m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    //constructors and destructors
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    //getter functions
    std::string getName() const;
    int getGrade() const;
	void signForm(Form &form);

    //setter functions
    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();

    //exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {

    public:
        virtual const char *what() const throw();
    };

};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif