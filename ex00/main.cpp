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
    return 0;
}
