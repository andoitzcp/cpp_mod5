#ifndef AFORM_H_
#define AFORM_H_

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm
{
    public:
        class GradeToHighException: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class GradeToLowException: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        

        AForm(void);
        AForm(std::string name, bool isSigned, int gradeReqSign, int gradeReqExec);
        AForm(const AForm& right);
        virtual ~AForm(void);

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeReqSign(void) const;
        int getGradeReqExec(void) const;
        void setIsSigned(bool isSigned);

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;
    
    private:
        AForm& operator=(const AForm& right);  // keep this private pls
        const std::string _name;
        bool _isSigned;
        const int _gradeReqSign;
        const int _gradeReqExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);


#endif // AFORM_H_
