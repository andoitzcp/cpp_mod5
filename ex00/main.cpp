#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1;

    try {
        b1.incrGrade();
    }
    catch(const Bureaucrat::GradeToHighException& e)
    {
        std::cout << "exception called" << std::endl;
    }
    return 0;
}
