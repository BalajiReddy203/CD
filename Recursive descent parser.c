//Program to construct a Recursive Descent Parser:



#include<stdio.h>

#include<string.h>

inti=0,e=0,n=0,j,l;

char str[50];

void E();

void F();

void E_();

void T();

void T_();

void ed();

int main()

{

	printf("Recursive Descent Parser\n\n");

	printf("\tE->TE'\n\tE'->+TE'/e\n\tT->FT'\n\tT'->*FT'/e\n\tF->(E)|id");

	printf("\nEnter the input exp:");

	scanf("%s",str);

	l=strlen(str);

	E();

	if(e>0)

		printf("String is not accepted");

	else

	{

		if(n==0 && e==0 &&i==1)

			printf("String is not ACCEPTED");

		else

		printf("String is ACCEPTED");

	}

}



void E()

{

	T();

	E_();

}



void T()

{

	F();

	T_();

}



void T_()

{

	if(str[i]=='*')

	{

		i++;

		F();

		T_();

	}

}



void E_()

{

	if(str[i]=='+')

	{

		i++;

		T();

		E_();

	}

              else

                    e++;

}



void F()

{

	if(str[i]=='i'&&str[i+1]=='d')

	i+=2;

	else if (str[i]=='(')

	{

		i++;

		n++;

		E();

		ed();

	}

	else

		e++;



}



void ed()

{

	if (str[i]==')')

	{

		i++;

		n--;

		T_();

		E_();

	}

	else

		e++;

}

/*output

Recursive Descent Parser



        E->TE'

        E'->+TE'/e

        T->FT'

        T'->*FT'/e

        F->(E)|id

Enter the input exp:id+id*id

String is ACCEPTED 
