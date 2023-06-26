// 1.b) Lexical Analyzer validating identifiers

#include<stdio.h>

#include<string.h>

void main()

{

	int len,i,cstate,error;

	char str[32],ch[4];

	enum states{

		q0,q1

	};

	do

	{

		i=0;cstate=q0;error=0;

		printf("\nEnter the string: ");

		fflush(stdin);		

		gets(str);

		len=strlen(str);

		if(len<=31)

		{

			while(i<len)

			{

				switch(cstate)

				{

					case q0:if((str[i]>='a'&&str[i]<='z')||

								(str[i]>='A'&&str[i]<='Z')||

								(str[i]=='_'))

							{

								cstate=q1;

							}

							else

								error=1;

							i++;

							break;

					case q1:if(!((str[i]>='a'&&str[i]<='z')||

								(str[i]>='A'&&str[i]<='Z')||

								(str[i]>='0'&&str[i]<='9')||

								(str[i]=='_')))

							{

								error=1;

							}

							i++;

							break;

					}

				}

				if(error==1)

					printf("\ninvalid identifier\n");

				else

					printf("\nvalid identifier\n");

			}

			else

				printf("\ninvalid identifier\n");

			printf("\ndo u want to continue to enter another string:(y/n): ");

			scanf("%s",&ch);

		}while(ch[0]=='y');

}



/* OUTPUT

 

Enter the string: var

valid identifier



do u want to continue to enter another string:y



Enter the string: Var

valid identifier



do u want to continue to enter another string:y



Enter the string: _as

valid identifier



do u want to continue to enter another string:y



Enter the string: _14

valid identifier



do u want to continue to enter another string:y



Enter the string: 3dsd

invalid identifier



do u want to continue to enter another string:y



Enter the string: _asd_142

valid identifier



do u want to continue to enter another string:
