#ifndef PRESIDENTIALPARDONFORM_H_
#define PRESIDENTIALPARDONFORM_H_

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& right);
        ~PresidentialPardonForm(void);

        void execute(const Bureaucrat& executor) const;

    private:
        const std::string _target;

        PresidentialPardonForm& operator=(const PresidentialPardonForm& right);
};


#endif // PRESIDENTIALPARDONFORM_H_
