#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1;

        std::cout << b1 << std::endl;
        b1.decrGrade();
        std::cout << b1 << std::endl;
        b1.incrGrade();
        std::cout << b1 << std::endl;
    try
    {
        b1.decrGrade();
        std::cout << b1 << std::endl;
        b1.incrGrade();
        std::cout << b1 << std::endl;
        b1.incrGrade();
        std::cout << b1 << std::endl;
        b1.incrGrade();
    }
    catch(const Bureaucrat::GradeToHighException& e)
    {
        std::cout << "exception called" << std::endl;
    }

    Bureaucrat b2;

    std::cout << b2 << std::endl;
    try {
        for (int i = 0; i < 200; i++ )
        {
            b2.decrGrade();
            std::cout << b2 << std::endl;
        }
    }
    catch(const Bureaucrat::GradeToLowException& e)
    {
        std::cout << "exception called: " << e.what() << std::endl;
    }
    return 0;
}
