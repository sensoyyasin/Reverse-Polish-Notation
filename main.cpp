/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:15:31 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/03/30 20:37:26 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Arg error" << std::endl;
        return (1);
    }

    std::stack<int> s;
    std::string line = argv[1];

    std::string::iterator it = line.begin();
    std::string num = "";

    while (it != line.end())
    {
		char token = *it;
        if (token == ' ')
        {
            if (!num.empty())
            {
                s.push(std::stoi(num));
                num = "";
            }
        }
        else if (isdigit(token))
            num += token;
        else
        {
            if (s.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            int first = s.top();
            s.pop();

            int second = s.top();
            s.pop();
            if (first == 0)
            {
                std::cerr << "Error: Divide by 0" << std::endl;
                exit(1);
            }
            switch (token)
            {
                case '+':
                    s.push(second + first);
                    break;
                case '-':
                    s.push(second - first);
                    break;
                case '*':
                    s.push(second * first);
                    break;
                case '/':
                    s.push(second / first);
                    break;
                default:
                    std::cerr << "Error: Invalid Operator" << std::endl;
				return (1);
			}
		}
		it++;
	}
	if (s.size() > 0)
	{
		std::cout << s.top() << std::endl;
    }
	else
	{
		std::cerr << "There is only 1 number" << std::endl;
		exit(1);
	}
    return 0;
}
