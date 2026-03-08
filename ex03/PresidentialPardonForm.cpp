#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void):
    AForm("presidential pardon", false, 25, 5),
    _target("Jimmy")
{
    std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("presidential pardon", false, 25, 5),
    _target(target)
{
    std::cout << "Alternative PresidentialPardonForm constructor called" << std::endl;
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& right):
    AForm(right),
    _target(right._target)
{
    std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
    return ;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::cout << "Presidential Anouncement: " << this->_target
              << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}
