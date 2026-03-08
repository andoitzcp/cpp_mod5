#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
    AForm("Shrubbery Creation Form", false, 145, 137),
    _target("home"),
    _index(0)
{
    std::cout << "Default ShrubberyCreationForm constructor called"
              << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
    AForm("Shrubbery Creation Form", false, 145, 137),
    _target(target),
    _index(0)
{
    std::cout << "Alternative ShrubberyCreationForm constructor called"
              << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& right): 
    AForm(right),
    _target(right._target),
    _index(0)
{
    std::cout << "Copy ShrubberyCreationForm constructor called"
              << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called"
              << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::string fileName = this->_target + "_shrubbery";
    std::fstream of(fileName.c_str(), std::ios::app);
    if (!of)
    {
        std::cerr << "Error, cannot open file" << std::endl;
        return ;
    }

    const char* asciiTrees[6] = {
    // Majestic Pine Tree
    "       *\n"
    "      ***\n"
    "     *****\n"
    "    *******\n"
    "   *********\n"
    "  ***********\n"
    " *************\n"
    "       *\n",
        
    // Christmas Tree with Decorations
    "        *\n"
    "       ***\n"
    "      *****\n"
    "     *o*****\n"
    "    *****o****\n"
    "   ************\n"
    "  ***************\n"
    " *****************\n"
    "        |\n"
    "       ===\n",
        
    // Giant Oak Tree
    "          /\\\n"
    "         /  \\\n"
    "        /    \\\n"
    "       /      \\\n"
    "      /        \\\n"
    "     /          \\\n"
    "    /            \\\n"
    "   /              \\\n"
    "  /                \\\n"
    " /                  \\\n"
    "/____________________\\\n"
    "         ||\n"
    "         ||\n",
    
    // Tropical Palm Tree
    "           /\\\n"
    "          /  \\\n"
    "         /    \\\n"
    "        /      \\\n"
    "       /        \\\n"
    "      /          \\\n"
    "     /            \\\n"
    "    /              \\\n"
    "   /                \\\n"
    "  /                  \\\n"
    " /                    \\\n"
    "/______________________\\\n"
    "           |\n"
    "           |\n"
    "          ~~~~~\n"
    "         ~~~~~~~\n"
    "        ~~~~~~~~~\n",
    
    // Bonsai Tree with Pot
    "          ^^^^^\n"
    "        ^^^    ^^^\n"
    "      ^^^          ^^^\n"
    "    ^^^                ^^^\n"
    "   ^^^^^^^^^^^^^^^^^^^^^^^^^\n"
    "         |||||||\n"
    "       ===========\n"
    "      |           |\n"
    "      |           |\n"
    "      |___________|\n",
        
    // Autumn Tree
    "          /\\\n"
    "         ///\\\n"
    "        ///\\\\\\\n"
    "       ////\\\\\\\\\n"
    "      /////\\\\\\\\\\\n"
    "     //////\\\\\\\\\\\\\n"
    "    ///////\\\\\\\\\\\\\\\n"
    "   ////////\\\\\\\\\\\\\\\\\n"
    "  /////////\\\\\\\\\\\\\\\\\\\n"
    "         |||\n"
    "         |||\n"
    "        ~~~~~\n"
};

    int i = rand() % 6;
    of << asciiTrees[i] << std::endl;
}

