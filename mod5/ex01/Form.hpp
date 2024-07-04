/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:37:31 by jberay            #+#    #+#             */
/*   Updated: 2024/07/04 08:56:26 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
    public:
        Form();
        Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        std::string getName() const;
        int getGrade() const;
        bool getIsSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;

        void beSigned(const Bureaucrat& B);
        
};

std::ostream& operator<<(std::ostream& os, const Form& F);

#endif