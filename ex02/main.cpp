#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1;
    ShrubberyCreationForm sbf;
    ShrubberyCreationForm sbf2(sbf);
    RobotomyRequestForm rrf;
    PresidentialPardonForm ppf;

    b1.signForm(sbf);
    b1.executeForm(sbf);

    b1.signForm(sbf2);
    b1.executeForm(sbf2);

    b1.signForm(rrf);
    b1.executeForm(rrf);

    b1.signForm(ppf);
    b1.executeForm(ppf);
}
