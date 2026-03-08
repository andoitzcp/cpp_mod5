#ifndef SHRUBBERYCREATIONFORM_H_
#define SHRUBBERYCREATIONFORM_H_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& right);
        ~ShrubberyCreationForm(void);

        void execute(const Bureaucrat& executor) const;

    private:
        const std::string _target;
        int _index;

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);
    
};



#endif // SHRUBBERYCREATIONFORM_H_
