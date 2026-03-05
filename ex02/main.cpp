#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1;
    ShrubberyCreationForm sbf;
    b1.signAForm(sbf);

    sbf.execute(b1);
    sbf.execute(b1);
    sbf.execute(b1);
}
