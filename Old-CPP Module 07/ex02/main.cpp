#include "Array.tpp"

int main(){
	Array<int>	tab;
	Array<int>	arra[10];
	Array<char>	phrase[10];
	Array<int>	tabtab(*arra);

	try
	{
		std::cout << tab[0] << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		phrase[i] = 'a' + i;
	}
	tabtab[0] = 42;
	for (int i = 0; i < 10; i++)
	{
		std::cout << phrase[i] << std::endl;
		std::cout << arra[i] << std::endl;
		std::cout << tabtab[i] << std::endl;
	}
}