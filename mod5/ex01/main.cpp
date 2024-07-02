#include "Bureaucrat.hpp"

int main()
{	
	try
	{
		std::cout << "####################" << std::endl;
		std::cout << "Creating Bureaucrats" << std::endl;
		
		Bureaucrat jan("jan", 1);
		std::cout << jan << std::endl;
		Bureaucrat rau("rau", 150);
		std::cout << rau << std::endl;

		std::cout << "###############" << std::endl;
		std::cout << "increases grade error" << std::endl;
		try 
		{
			jan.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << jan << std::endl;

		std::cout <<  "###############" << std::endl;
		std::cout <<  "decreases grade error" << std::endl;
		try
		{
			rau.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << rau << std::endl;

		std::cout << "###############" << std::endl;
		std::cout << "increases grade good" << std::endl;
		try
		{
			rau.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << rau << std::endl << std::endl;

        std::cout <<  "###############" << std::endl;
		std::cout <<  "decreases grade good" << std::endl;
		try
		{
			jan.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << jan << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}