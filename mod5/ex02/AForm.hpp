/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:37:31 by jberay            #+#    #+#             */
/*   Updated: 2024/07/04 12:07:45 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeRequiredToSign;
        const int gradeRequiredToExecute;
    public:
        AForm();
        AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

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
        virtual void execute(Bureaucrat const & executor) const = 0;
        
};

std::ostream& operator<<(std::ostream& os, const AForm& F);

#endif