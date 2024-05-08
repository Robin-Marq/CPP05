/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:18 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/19 10:57:06 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;

	// First Test
    try
    {
        std::cout << YELLOW;
        Bureaucrat A("A", 5);
        std::cout << A << std::endl;
        A.incrementGrade();
        std::cout << A << std::endl;
        A.decrementGrade();
        std::cout << A << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << CYAN << e.what() << std::endl;
    }

	std::cout << std::endl;

	// Second Test
    try
    {
        std::cout << YELLOW;
        Bureaucrat B("B", 149);
        std::cout << B << std::endl;
        B.decrementGrade();
        std::cout << B << std::endl;
        B.decrementGrade();
        std::cout << B << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {

        std::cout << CYAN << e.what() << DEFAULT << std::endl;
    }

    std::cout << std::endl;

	// Third Test
    try
    {
        std::cout << YELLOW;
        Bureaucrat C("C", 0);
        std::cout << C << std::endl;
        C.incrementGrade();
        std::cout << C << std::endl;
        C.incrementGrade();
        std::cout << C << DEFAULT << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << CYAN << e.what() << std::endl;
    }

    return 0;
}