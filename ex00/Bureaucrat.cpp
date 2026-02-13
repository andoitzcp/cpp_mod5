#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): _name("John Doe"), _grade(1)
{
    std::cout << "Bureaucrat (" << this->_name << ") default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& right): _name(right._name), _grade(right._grade)
{
    std::cout << "Bureaucrat (" << this->_name << ") copy constructor called" << std::endl;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat (" << this->_name << ") destructor called" << std::endl;
    return ;
}

const std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::incrGrade(void)
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeToHighException();
    this->_grade--;
    return ;
}

void Bureaucrat::decrGrade(void)
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeToLowException();
    this->_grade++;
    return ;
}

const char* Bureaucrat::GradeToHighException::what(void) const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeToLowException::what(void) const throw()
{
    return "Grade is too low!";
}
