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

    std::string::iterator it = line.begin();
    std::string num = "";

    while (it != line.end())
    {
        char token = *it;
        //When the value of the token variable is a space character,
        //the number in the num variable is completely read and needs to be added to the stack.
        //Therefore, if there is a number in the num variable (if num is not empty),
        //we convert that number to an integer (std::stoi()) and add it to the stack. 
        //Before adding it to the stack, the num variable is reset, 
        //making the next number ready for reading.
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
            if (second == 0)
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

    std::cout << s.top() << std::endl;
    return 0;
}
