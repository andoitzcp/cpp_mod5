#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <unistd.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void):
    AForm("robotomy creation", false, 72, 45),
    _target("Annoying Neighbourg")
{
    std::cout << "Default RobotomyRequestForm constructor called"
              << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
    AForm("robotomy creation", false, 72, 45),
    _target(target)
{
    std::cout << "Alternative RobotomyRequestForm constructor called"
              << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& right):
    AForm(right),
    _target(right._target)
{
    std::cout << "Copy RobotomyRequestForm constructor called"
              << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestFrom destructor called" << std::endl;
    return ;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::cout << "[ Drilling noises... ]" << std::endl;
    usleep(1000000);
    std::cout << "[ More Drilling noises... ]" << std::endl;
    usleep(1000000);
    std::cout << "[ ... ]" << std::endl;
    usleep(1000000);
    if (rand() % 2)
        std::cout << this->_target << "'s robotomy is succesfully completed" << std::endl;
    else
        std::cout << this->_target << "'s robotomy has failed" << std::endl;
}
