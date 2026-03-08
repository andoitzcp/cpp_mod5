#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Intern I;
    Bureaucrat b1;
    AForm *f;

    f = I.makeForm("shrubbery creation", "home");
    b1.signForm(*f);
    b1.executeForm(*f);

    f = I.makeForm("robotomy request", "Neighbour");
    b1.signForm(*f);
    b1.executeForm(*f);

    f = I.makeForm("presidential pardon", "Jimmy");
    b1.signForm(*f);
    b1.executeForm(*f);
}
