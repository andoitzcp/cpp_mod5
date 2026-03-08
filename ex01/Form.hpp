#ifndef FORM_H_
#define FORM_H_

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class Form
{
    public:
        class GradeToHighException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };

        class GradeToLowException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        

        Form(void);
        Form(std::string name, bool isSigned, int gradeReqSign, int gradeReqExec);
        Form(const Form& right);
        ~Form(void);

        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeReqSign(void) const;
        int getGradeReqExec(void) const;
        void setIsSigned(bool isSigned);

        void beSigned(Bureaucrat& bureaucrat);

    private:
        Form& operator=(const Form& right);  // keep this private pls
        const std::string _name;
        bool _isSigned;
        const int _gradeReqSign;
        const int _gradeReqExec;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);


#endif // FORM_H_
