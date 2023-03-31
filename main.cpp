/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:31:32 by ysensoy           #+#    #+#             */
/*   Updated: 2023/03/31 15:31:33 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Arg error" << std::endl;
        return (1);
    }

    std::stack<int> s;
    std::string line = argv[1];

    int i = 1;
    int j = 0;

    int token_counter = 0;
    while(argv[i])
    {
        j = 0;
        while(argv[i][j])
       {
            if (argv[i][j] == '/' || argv[i][j] == '+' || argv[i][j] == '*' || argv[i][j] == '-')
                token_counter++;
            j++;
       } 
       i++;
    }

    if (token_counter == 0)
    {
        std::cerr << "There is no Operator" << std::endl;
        exit(1);
    }

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
    	std::cout << s.top() << std::endl;
	else
	{
		std::cerr << "Just 1 point" << std::endl;
		exit(1);
	}
    return 0;
}
