#include <stdio.h>
#include <time.h>
#include <stdlib.h>




void printf_fancy(char x[])
{
printf("\n\n -------------\n\n");
printf(" %s",x);
printf("\n\n -------------\n\n");
}

int init_game_engine(int);

int parse_int(char string[])
{
if(string[2]=='\0') return string[0]-48;
else if(string[2]!='\0' && string[3]=='\0') return (10*(string[0]-48))+(string[1]-48);
else if(string[2]!='\0' && string[3]!='\0' && string[4]=='\0') return (100*(string[0]-48))+(10*(string[1]-48))+(string[2]-48);
}

int strleng(char string[])
{
int i = 0;
while(string[i]!='\0') i++;
return i;
}


int print_loser(int x)
{
	if(x==1 || x==2)
	{
	for(int i = 3;i>0;i--) printf("\n");
	printf(" #        \n");
	printf(" #        \n");
	printf(" #        \n");
	printf(" #        \n");
	printf(" #        \n");
	printf(" #        \n");
	printf(" #######  \n");
	for(int i = 3;i>0;i--) printf("\n");
	}

	else if(x==3 || x==4)
	{
	for(int i = 3;i>0;i--) printf("\n");
	printf(" #        #######  \n");
	printf(" #        #     #  \n");
	printf(" #        #     #  \n");
	printf(" #        #     #  \n");
	printf(" #        #     #  \n");
	printf(" #        #     #  \n");
	printf(" #######  #######  \n");
	for(int i = 3;i>0;i--) printf("\n");
	}

	else if(x==5 || x==6)
	{
	for(int i = 3;i>0;i--) printf("\n");
	printf(" #        #######   #####   \n");
	printf(" #        #     #  #     #  \n");
	printf(" #        #     #  #        \n");
	printf(" #        #     #   #####   \n");
	printf(" #        #     #        #  \n");
	printf(" #        #     #  #     #  \n");
	printf(" #######  #######   #####   \n");
	for(int i = 3;i>0;i--) printf("\n");
	}

	else if(x==7 || x==8)
	{
	for(int i = 3;i>0;i--) printf("\n");
	printf(" #        #######   #####   #######  \n");
	printf(" #        #     #  #     #  #        \n");
	printf(" #        #     #  #        #        \n");
	printf(" #        #     #   #####   #####    \n");
	printf(" #        #     #        #  #        \n");
	printf(" #        #     #  #     #  #        \n");
	printf(" #######  #######   #####   #######  \n");
	for(int i = 3;i>0;i--) printf("\n");
	}

	else if(x==9 || x==10)
	{
	for(int i = 3;i>0;i--) printf("\n");
	printf(" #        #######   #####   #######  ######  \n");
	printf(" #        #     #  #     #  #        #     # \n");
	printf(" #        #     #  #        #        #     # \n");
	printf(" #        #     #   #####   #####    ######  \n");
	printf(" #        #     #        #  #        #   #   \n");
	printf(" #        #     #  #     #  #        #    #  \n");
	printf(" #######  #######   #####   #######  #     # \n");
	for(int i = 3;i>0;i--) printf("\n");
	}
	

}


int start_game(int user_line)
{



	char database[256][256];
	FILE* file_to_test = fopen("words.txt", "r");
	int how_many_lines = 0;
	for(how_many_lines = 1;fgets(database[how_many_lines-1],sizeof(database),file_to_test);how_many_lines++);
	fclose(file_to_test);
	if(how_many_lines == 1) {printf_fancy("NO WORD EXISTS !");init_game_engine(user_line);return 0;}




printf_fancy("LET'S GO !\n TIP : YOU CAN GIVE AWAY 2 SCORE\n AND GET ONE LETTER BY ENTERING *");
int word_number = 0 , lost_num = 1 , chosen_i = 0;
char word[256] , chosen_letters[256];
char guessed_letter = '\0';
FILE* file_to_read = fopen("words.txt", "r");
while(fgets(word,sizeof(word),file_to_read)) word_number++;
fclose(file_to_read);

srand(time(NULL));
int r = rand()%word_number+1;

file_to_read = fopen("words.txt", "r");
for(int i = 1;fgets(word,sizeof(word),file_to_read);i++) if(i==r) break;
fclose(file_to_read);
word[strleng(word)-1] = '\0';
int letter_stats[strleng(word)];
int loser_jump = strleng(word)>8?1:2;
int guid_flag = 0;
for(int i = 0;i<strleng(word);i++) letter_stats[i] = 0;
for(int k = 0;;k++)
{
int win_stat = 1;
int repeated_letter_stat = 0;
getchar();
printf("\n\n");
for(int i = 0;i<strleng(word);i++) {if(letter_stats[i] == 0) printf(" __");else printf(" %c",word[i]);}
printf("\n\n");
scanf("%c",&guessed_letter);


if(guessed_letter=='*')
{

int wierd_flag = 1;
int wierd_flag_2 = 0;
char temp;

for(int i = 1;i<strleng(word);i++)
{
if(letter_stats[i] == 0 && wierd_flag) {temp = word[i];wierd_flag = 0;}
if(!wierd_flag) if(word[i] != temp && letter_stats[i] == 0) {wierd_flag_2 = 1;}
}

if(wierd_flag_2)
{
if(!guid_flag)
{
		int guide_permission = 1;
		char database[256][256];
		FILE* file_to_read = fopen("users.txt", "r");
		int how_many_lines = 0;
		for(how_many_lines = 1;fgets(database[how_many_lines-1],sizeof(database),file_to_read);how_many_lines++)
		{
			if(how_many_lines==user_line+2)
			{
			int primary_score = parse_int(database[how_many_lines-1]);
				if(primary_score<2)
				{
				guide_permission = 0;
				printf_fancy("NOT ENOUGH SCORE !");
				}
			}
		}
		fclose(file_to_read);
		
		if(guide_permission)
		{
		guid_flag = 1;
		FILE* file_to_write = fopen("users.txt", "w");
		fprintf(file_to_write,"");
		fclose(file_to_write);
		
		FILE* file_to_write2 = fopen("users.txt", "a");
		for(int i = 0;i<how_many_lines;i++)
		{
			if(i==user_line+1)
			{
			int primary_score = parse_int(database[i]);
			int secondary_score = primary_score - 2;
			fprintf(file_to_write2,"%d\n",secondary_score);
			}

			else fprintf(file_to_write2,"%s",database[i]);
		}
		fclose(file_to_write2);

		int guide_action = 0;
		for(int i = 0;guide_action==0;i++)
		{
		srand(time(NULL));
		int r2 = rand()%strleng(word);
			if(letter_stats[r2]==0) 
			{
			letter_stats[r2]=1;guide_action=1;
				for(int j = 0;j<strleng(word);j++)
				{
				if(word[r2]==word[j]) letter_stats[j] = 1;
				}
			chosen_letters[chosen_i++] = word[r2];
			}
		}

		}	
	}
	
	else
	{
	printf_fancy("YOU HAVE ALREADY ASKED FOR A HINT !");
	}

	}

	else
	{
	printf_fancy("YOU CANNOT ASK FOR THE LAST LETTER !");
	}

continue;
}






for(int i = 0;i<chosen_i;i++) if(guessed_letter == chosen_letters[i]) repeated_letter_stat = 1;
if(repeated_letter_stat){printf_fancy("LETTER ALREADY CHOSEN !");k-=1;continue;}
chosen_letters[chosen_i++] = guessed_letter;
int search_stat = 0;
for(int i = 0;i<strleng(word);i++) if(word[i]==guessed_letter) {letter_stats[i] = 1;search_stat = 1;}

	if(search_stat) 
	{
	printf_fancy("RIGHT !");
	for(int i = 0;i<strleng(word);i++) if(letter_stats[i]==0) win_stat = 0;
		if(win_stat)
		{
		for(int i = 3;i>0;i--) printf("\n");
		printf(" #     #  ###   #####   #######  #######  ######   #     # \n");
		printf(" #     #   #   #     #     #     #     #  #     #   #   #  \n");
		printf(" #     #   #   #           #     #     #  #     #    # #   \n");
		printf(" #     #   #   #           #     #     #  ######      #    \n");
		printf("  #   #    #   #           #     #     #  #   #       #    \n");
		printf("   # #     #   #     #     #     #     #  #    #      #    \n");
		printf("    #     ###   #####      #     #######  #     #     #    \n");
		for(int i = 3;i>0;i--) printf("\n");
		for(int i = 0;i<strleng(word);i++) {printf(" %c",word[i]);}
		printf("\n\n -=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf(" YOU GAINED %d SCORE !",strleng(word));
		printf("\n -=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		char database[256][256];
		FILE* file_to_read = fopen("users.txt", "r");
		int how_many_lines = 0;
		for(how_many_lines = 1;fgets(database[how_many_lines-1],sizeof(database),file_to_read);how_many_lines++);
		fclose(file_to_read);
		
		FILE* file_to_write = fopen("users.txt", "w");
		fprintf(file_to_write,"");
		fclose(file_to_write);
		
		FILE* file_to_write2 = fopen("users.txt", "a");
		for(int i = 0;i<how_many_lines;i++)
		{
			if(i==user_line+1)
			{
			int primary_score = parse_int(database[i]);
			int secondary_score = primary_score + strleng(word);
			fprintf(file_to_write2,"%d\n",secondary_score);
			}

			else fprintf(file_to_write2,"%s",database[i]);
		}

		fclose(file_to_write2);

		
		init_game_engine(user_line);break;
		}
	}

	else
	{
	printf_fancy("WRONG !");
	print_loser(lost_num);
	lost_num += loser_jump;
	if(lost_num == 10 || lost_num == 11) {printf("\n THE WORD WAS >>> ");for(int i = 0;i<strleng(word);i++) {printf(" %c",word[i]);}init_game_engine(user_line);break;}
	}


}

}












int string_equality(char x[],char y[])
{
int res = 1;
if(strleng(y) != strleng(x)-1) return 0;
for(int i = 0;i<strleng(y);i++) if(y[i] != x[i]) res = 0;
return res;
}





int regex_validate(char string[])
{

int regex_flag_1 = 0;
int regex_flag_2 = 0;
int regex_flag_3 = 0;
int regex_flag_4 = 0;

for(int i = 0;i<strleng(string);i++) if(string[i] >= 33 && string[i] <= 47 || string[i] >= 58 && string[i] <= 64 || string[i] >= 123 && string[i] <= 126 || string[i] >= 91 && string[i] <= 96) regex_flag_1 = 1;
for(int i = 0;i<strleng(string);i++) if(string[i] >= 65 && string[i] <= 90) regex_flag_2 = 1;
for(int i = 0;i<strleng(string);i++) if(string[i] >= 97 && string[i] <= 122) regex_flag_3 = 1;
for(int i = 0;i<strleng(string);i++) if(string[i] >= 48 && string[i] <= 57) regex_flag_4 = 1;

if(regex_flag_1 && regex_flag_2 && regex_flag_3 && regex_flag_4 && strleng(string)>= 8) return 1;
else return 0;

}




int menu_option = -1;

int main()
{

int username_existance = 0 ; 
char username[256] , password[256] , line[256];
FILE* file_to_read = fopen("users.txt", "r"); 

if(menu_option == -1)
{
for(int i = 4;i>0;i--) printf("\n");

printf("##      ##  ########  ##         ######    #######   ##     ##  ######## \n");
printf("##  ##  ##  ##        ##        ##    ##  ##     ##  ###   ###  ##       \n");
printf("##  ##  ##  ##        ##        ##        ##     ##  #### ####  ##       \n");
printf("##  ##  ##  ######    ##        ##        ##     ##  ## ### ##  ######   \n");
printf("##  ##  ##  ##        ##        ##        ##     ##  ##     ##  ##      \n");
printf("##  ##  ##  ##        ##        ##    ##  ##     ##  ##     ##  ##       \n");
printf(" ###  ###   ########  ########   ######    #######   ##     ##  ######## \n");

for(int i = 3;i>0;i--) printf("\n");

printf(" 1 ---> Login\n\n 2 ---> SignUp\n\n 3 ---> Exit\n\n");
scanf("%d",&menu_option);
}

if(menu_option == 1)
{
printf("ENTER USERNAME : ");scanf("%s",&username);printf("ENTER PASSWORD : ");
scanf("%s",&password);

int user_line_track = 1;

	while(fgets(line,sizeof(line),file_to_read))
	{
	if(string_equality(line,username)) {username_existance = 1;fgets(line,sizeof(line),file_to_read);break;}
	user_line_track++;
	}

	if(username_existance) 
	{
		if(string_equality(line,password))
		{
		printf_fancy("LOGIN SUCCESSFUL !");
		init_game_engine(user_line_track);
		}
		else {printf_fancy("INCORRECT PASSWORD !");main();}
	}

	else {printf_fancy("USER NOT FOUND !");main();}


	fclose(file_to_read);
}

else if(menu_option == 2)
{
printf("ENTER USERNAME : ");scanf("%s",&username);printf("ENTER PASSWORD : ");
scanf("%s",&password);



 int user_line_track = 1;
	while(fgets(line,sizeof(line),file_to_read))
	{
	if(string_equality(line,username)) {username_existance = 1;break;}
	user_line_track++;
	}
	fclose(file_to_read);

	if(username_existance) {printf_fancy("USERNAME ALREADY EXSITS !");main();}

	else
	{
		if(regex_validate(password))
		{
		FILE* file_to_write = fopen("users.txt", "a");
		fprintf(file_to_write,"%s\n",username);
		fprintf(file_to_write,"%s\n",password);
		fprintf(file_to_write,"0\n");
		fclose(file_to_write);
		printf_fancy("SIGN UP SUCCESSFUL !");
		init_game_engine(user_line_track);
		}
		
		else
		{
		printf_fancy("PASSWORD MUST BE AT LEAST 8 CHARACTERS\n INCLUDING SYMBOLS , LOWER CASE AND UPPER \n CASE LETTERS AND NUMBERS");
		main();
		}
	}



}

else if(menu_option == 3)
{
return 0;
}

else
{
printf_fancy("INVALID !");
}





return 0;
}



int init_game_engine(int user_line)
{
printf("\n\n 1 ---> Start Game\n\n 2 ---> Show Leaderboard\n\n 3 ---> New Word\n\n 4 ---> Change Password\n\n 5 ---> Exit\n\n");
int menu_option2 = -1;
char new_word[256];
scanf("%d",&menu_option2);

	if(menu_option2 == 5) return 0;

	else if(menu_option2 == 4)
	{
	char new_password[256];
	printf("ENTER NEW PASSWORD : ");
	scanf("%s",&new_password);
	

	
		if(regex_validate(new_password))
		{
				char database[256][256];
				FILE* file_to_read = fopen("users.txt", "r");
				int how_many_lines = 0;
				for(how_many_lines = 1;fgets(database[how_many_lines-1],sizeof(database),file_to_read);how_many_lines++);
				fclose(file_to_read);
				
				FILE* file_to_write = fopen("users.txt", "w");
				fprintf(file_to_write,"");
				fclose(file_to_write);
				
				FILE* file_to_write2 = fopen("users.txt", "a");
				for(int i = 0;i<how_many_lines;i++)
				{
					if(i==user_line) fprintf(file_to_write2,"%s\n",new_password);
					else fprintf(file_to_write2,"%s",database[i]);
				}
				fclose(file_to_write2);
			
			printf_fancy("PASSWORD CHANGED !");
			init_game_engine(user_line);
		}

		else
		{
		printf_fancy("PASSWORD MUST BE AT LEAST 8 CHARACTERS\n INCLUDING SYMBOLS , LOWER CASE AND UPPER \n CASE LETTERS AND NUMBERS");
		init_game_engine(user_line);
		}

	}

	else if(menu_option2 == 3)
	{
	printf(" Enter New Word : ");
	scanf("%s",new_word);
	char database[256][256];
	FILE* file_to_read = fopen("words.txt", "r");
	int how_many_lines = 0;

		for(how_many_lines = 1;fgets(database[how_many_lines-1],sizeof(database),file_to_read);how_many_lines++);
		fclose(file_to_read);
		int word_existance_flag = 0;
		for(int i = 0;i<how_many_lines;i++) if(string_equality(database[i],new_word)) word_existance_flag = 1;
		if(word_existance_flag) {printf_fancy("WORD ALREADY EXISTS !");init_game_engine(user_line);}

		else
		{
		FILE* file_to_write = fopen("words.txt", "a");
		fprintf(file_to_write,"%s\n",new_word);
		printf_fancy("NEW WORD ADDED !");
		fclose(file_to_write);
		init_game_engine(user_line);
		}
	}

	else if(menu_option2 == 2)
	{
	int score_arr[100] = {-1};
	int j = 0;
	char score[256];
	FILE* file_to_read = fopen("users.txt", "r"); 
		for(int i = 1;fgets(score,sizeof(score),file_to_read);i++)
		{
		if(i%3==0) {score_arr[j++]=parse_int(score);}
		}
	fclose(file_to_read);

	FILE* file_to_read2 = fopen("users.txt", "r");
	printf("\n*****************************\n");
	for(int k = 0;k<j;k++)
	{
	int max = -1;
	

	for(int i = 0;i<j;i++) if(score_arr[i]>max) {max = score_arr[i];}
	for(int i = 0;i<j;i++) if(score_arr[i]==max) {score_arr[i] = -1;}

	char score2[256];
	char user2[256];
	char dummy[256];
	
		for(int i = 1;fgets(i%3==1?user2:i%3==0?score2:dummy,sizeof(score2),file_to_read2);i++)
		{
			if(i%3==0) 
			{
			user2[strleng(user2)-1] = '\0'; 
			if(parse_int(score2)==max) {printf(" %s ------------- %d \n",user2,max);}
			}
		}
	
	file_to_read2 = fopen("users.txt", "r");
	}
	printf("*****************************\n");
	fclose(file_to_read2);

	init_game_engine(user_line);
	}

	else if(menu_option2 == 1) start_game(user_line);
	else {printf_fancy("INVALID !");init_game_engine(user_line);}
}
