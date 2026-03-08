#ifndef ROBOTOMYREQUESTFORM_H_
#define ROBOTOMYREQUESTFORM_H_

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& right);
        ~RobotomyRequestForm(void);

        void execute(const Bureaucrat& executor) const;

    private:
        const std::string _target;

        RobotomyRequestForm& operator=(const RobotomyRequestForm& right);
};


#endif // ROBOTOMYREQUESTFORM_H_
