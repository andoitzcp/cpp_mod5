#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(void):
    _name("Default Form"),
    _isSigned(false),
    _gradeReqSign(1),
    _gradeReqExec(1)
{
    std::cout << "Default form constructor called" << std::endl;
    return ;
}

Form::Form(std::string name,
           bool isSigned,
           int gradeReqSign,
           int gradeReqExec):
    _name(name),
    _isSigned(isSigned),
    _gradeReqSign(gradeReqSign),
    _gradeReqExec(gradeReqExec)
{
    std::cout << "Alternative form constructor called" << std::endl;
    if (gradeReqSign < 1 || gradeReqExec < 1)
        throw Form::GradeToHighException();
    if (gradeReqSign > 150 || gradeReqExec > 150)
        throw Form::GradeToLowException();
    return ;
}

Form::Form(const Form& right):
    _name(right._name),
    _isSigned(right._isSigned),
    _gradeReqSign(right._gradeReqSign),
    _gradeReqExec(right._gradeReqExec)
{
    std::cout << "Copy form constructor called" << std::endl;
    return ;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
    return ;
    
}

const char* Form::GradeToHighException::what(void) const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeToLowException::what(void) const throw()
{
    return "Grade is too low!";
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getIsSigned(void) const
{
    return this->_isSigned;
}

int Form::getGradeReqSign(void) const
{
    return this->_gradeReqSign;
}

int Form::getGradeReqExec(void) const
{
    return this->_gradeReqExec;
}

void Form::setIsSigned(bool isSigned)
{
    this->_isSigned = isSigned;
    return ;
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
    os << Form.getName()
       << " form:\n\tis Signed = "
       << (Form.getIsSigned()?"yes":"no")
       << "\n\tRequired grade to sign = "
       << Form.getGradeReqSign()
       << "\n\tRequiered grade to Execute = "
       << Form.getGradeReqExec()
       << std::endl;
    return os;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeReqSign())
        throw Form::GradeToLowException();
    this->_isSigned = true;
    return ;
}
