/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:15:28 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/03/31 20:59:23 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	this->token_counter = 0;
}

RPN::~RPN() {}

void	RPN::my_checker(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Arg error" << std::endl;
        exit(1);
    }

    int i = 1;
    int j = 0;

    while(argv[i])
    {
        j = 0;
        while(argv[i][j])
       {
            if (argv[i][j] == '/' || argv[i][j] == '+' || argv[i][j] == '*' || argv[i][j] == '-')
            {
                this->token_counter++;
                this->real_token = argv[i][j];
            }
            j++;
       }
       i++;
    }

    if (this->token_counter == 0)
    {
        std::cerr << "There is no Operator" << std::endl;
        exit(1);
    }
}
