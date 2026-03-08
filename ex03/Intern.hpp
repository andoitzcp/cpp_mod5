#ifndef INTERN_H_
#define INTERN_H_

#include <string>
#include "AForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& right);
        Intern& operator=(const Intern& right);
        ~Intern(void);

        AForm* makeForm(const std::string& formName, const std::string& formTarget);

    private:
        AForm *createShrubberyCreationForm(const std::string& target);
        AForm *createRobotomyRequestForm(const std::string& target);
        AForm *createPresidentialPardonForm(const std::string& target);
};


#endif // INTERN_H_
