#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "=== Test 0 ===" << std::endl;
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
    }
    {
        std::cout << "=== Test 1 ===" << std::endl;
        Form f1;

        std::cout << f1 << std::endl;
        Form f2 = f1;
        std::cout << f2 << std::endl;
        Form f3("useless formulary", false, 5, 10);
        std::cout << f3 << std::endl;

        try
        {
            Form f4("to high form", false, 0, 1);
        }
        catch (const Form::GradeToHighException& e)
        {
            std::cout << "Exception called: " << e.what() << std::endl;
        }
        try
        {
            Form f5("to low form", false, 151, 1);
        }
        catch (const Form::GradeToLowException& e)
        {
            std::cout << "Exception called: " << e.what() << std::endl;
        }

        Bureaucrat b1;
        Bureaucrat b2;
        Bureaucrat b3;
        b2.decrGrade();
        for (int i = 0; i < 6; i++)
            b3.decrGrade();

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        std::cout << "-----------------------------" << std::endl;
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        std::cout << "-----------------------------" << std::endl;
        b2.signForm(f1);
        b2.signForm(f2);
        b2.signForm(f3);

        std::cout << "-----------------------------" << std::endl;
        b3.signForm(f1);
        b3.signForm(f2);
        b3.signForm(f3);
        std::cout << "-----------------------------" << std::endl;
    }
    return 0;
}
