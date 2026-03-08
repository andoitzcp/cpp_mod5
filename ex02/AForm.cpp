#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void):
    _name("Default AForm"),
    _isSigned(false),
    _gradeReqSign(1),
    _gradeReqExec(1)
{
    std::cout << "Default form constructor called" << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
    return ;
}

AForm::AForm(std::string name,
           bool isSigned,
           int gradeReqSign,
           int gradeReqExec):
    _name(name),
    _isSigned(isSigned),
    _gradeReqSign(gradeReqSign),
    _gradeReqExec(gradeReqExec)
{
    std::cout << "Alternative form constructor called" << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
    if (gradeReqSign < 1 || gradeReqExec < 1)
        throw AForm::GradeToHighException();
    if (gradeReqSign > 150 || gradeReqExec > 150)
        throw AForm::GradeToLowException();
    return ;
}

AForm::AForm(const AForm& right):
    _name(right._name),
    _isSigned(right._isSigned),
    _gradeReqSign(right._gradeReqSign),
    _gradeReqExec(right._gradeReqExec)
{
    std::cout << "Copy form constructor called" << std::endl;
    srand(static_cast<unsigned int>(time(NULL)));
    return ;
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
    return ;
    
}

const char* AForm::GradeToHighException::what(void) const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeToLowException::what(void) const throw()
{
    return "Grade is too low!";
}

const char * AForm::FormNotSignedException::what(void) const throw()
{
    return "Form is not signed!";
}

std::string AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getIsSigned(void) const
{
    return this->_isSigned;
}

int AForm::getGradeReqSign(void) const
{
    return this->_gradeReqSign;
}

int AForm::getGradeReqExec(void) const
{
    return this->_gradeReqExec;
}

void AForm::setIsSigned(bool isSigned)
{
    this->_isSigned = isSigned;
    return ;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << AForm.getName()
       << " form:\n\tis Signed = "
       << (AForm.getIsSigned()?"yes":"no")
       << "\n\tRequired grade to sign = "
       << AForm.getGradeReqSign()
       << "\n\tRequiered grade to Execute = "
       << AForm.getGradeReqExec()
       << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeReqSign())
        throw AForm::GradeToLowException();
    this->_isSigned = true;
    return ;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (this->getGradeReqExec() < executor.getGrade())
        throw AForm::GradeToLowException();
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
}
