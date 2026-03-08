#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <string>
#include <ostream>
#include <exception>
#include "AForm.hpp"


class Bureaucrat
{
    public:
        class GradeToHighException: public std::exception
        {
            public:
                const char* what(void) const throw();
        };

        class GradeToLowException: public std::exception
        {
            public:
                const char* what(void) const throw();
        };

        // Constructors & destructor
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat& right);
        ~Bureaucrat(void);

        // getters & setters
        const std::string getName(void) const;
        int getGrade(void) const;
        void incrGrade(void);
        void decrGrade(void);

        void signForm(AForm& form);
        void executeForm(const AForm& form) const;

    private:
        Bureaucrat& operator=(const Bureaucrat& right); //keep this private pls
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif // BUREAUCRAT_H_
