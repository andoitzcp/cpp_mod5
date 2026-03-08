#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
    std::cout << "Default Intern constructor called" << std::endl;
    return ;
}

Intern::Intern(const Intern& right)
{
    (void)right;
    std::cout << "Copy Intern constructor called" << std::endl;
    return ;
}

Intern& Intern::operator=(const Intern& right)
{
    (void)right;
    std::cout << "Intern assigment operator called" << std::endl;
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
    return ;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*creators[3])(const std::string &target) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName != formNames[i])
            continue ;
        std::cout << "Intern created "  << formNames[i] << " form" << std::endl;
        return (this->*creators[i])(formTarget);
    }
    std::cerr << "Error: not  valid form!" << std::endl;
    return NULL;
}
