/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:14 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 10:58:54 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;

    Form formA("FormA", 5, 6);
    Bureaucrat A("A", 10);


    std::cout << YELLOW << formA << std::endl;
    std::cout << GREEN << A << std::endl;
    std::cout << DEFAULT << std::endl;

	A.signForm(formA);
    try
    {
        formA.beSigned(A);

        std::cout << YELLOW << formA << std::endl;
    }


    catch (std::exception &failMessage)
	{
		std::cout << CYAN << failMessage.what() << std::endl;
		std::cout << YELLOW << formA << std::endl;
	}


	std::cout << std::endl;

    Form formB("FormB", 5, 6);
    Bureaucrat B("B", 5);


    std::cout << YELLOW << formB << std::endl;
    std::cout << GREEN << B << std::endl;
    std::cout << DEFAULT << std::endl;

    try
    {
		B.signForm(formB);
        std::cout << YELLOW << formB << std::endl;
    }


    catch (std::exception &failMessage)
	{
		std::cout << CYAN << failMessage.what() << std::endl;
		std::cout << YELLOW << formB << std::endl;
	}

    return 0;
}
