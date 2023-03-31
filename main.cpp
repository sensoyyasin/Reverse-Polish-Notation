/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:31:32 by ysensoy           #+#    #+#             */
/*   Updated: 2023/03/31 20:58:41 by yasinsensoy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;

    rpn.my_checker(argc, argv);

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
        {
            num += token;
            if (num.size() > 1)
            {
                std::cerr << "Numbers less than 10" << std::endl;
                exit(1);
            }
        }
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
            if (first == 0 && rpn.real_token == '/')
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
        std::cout << s.top() << std::endl;
    else
    {
        std::cerr << "Just 1 point" << std::endl;
        exit(1);
    }
    return 0;
}
