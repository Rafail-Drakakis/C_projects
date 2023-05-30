/*--------------------|Name: Mpersos Zafeirios|--------------------*/
/*-------------------------|A.M.: csd5106|-------------------------*/
/*---------------|Assignment 1: "Translate" Program|---------------*/
/*-----------------------|File name: main.c|-----------------------*/

#include<stdio.h>
#include<string.h>
#define SIZE 96

void initialization(char map[SIZE][4]){   /*this function initializes an int array map that will map each*/
			       	       	  /*ISO 8859-7 character to an ISO 8859-1 one*/

			/*the index of this array will be the ISO 8859-7 integer equivalent of a greek character*/
			/*as input and the content of this index will be output as an ISO 8859-1 character*/

	int i, j;
	for(i=0; i<SIZE; i++){	   /*Initializing map with \0 so that any string read from it will be*/
		for(j=0; j<4; j++){    /*terminated*/
			map[i][j] = '\0';
		}
	}

	/*Characters 160-255 from ISO 8859-7 / characters from 127 to 159 will be ignored*/

	map[0][0] = ' ';   /*No-break space*/
	map[1][0] = 39;   /*Left single quotation mark*/
	map[2][0] = 39;   /*Right single quotation mark*/
	map[3][0] = '$';   /*Pound sign*/

	map[4][0] = '\0';   /*UNUSED*/
	map[5][0] = '\0';   /*UNUSED*/

	map[6][0] = '|';   /*Broken bar*/
	strcpy(map[7], "*p\0");   /*Paragraph sign*/
	map[8][0] = '"';   /*Dialytika*/
	strcpy(map[9], "*c\0");   /*Copyright sign*/

	map[10][0] = '\0';   /*UNUSED*/

	strcpy(map[11], "<<\0");   /*Left angle quotation*/
	strcpy(map[12], "*n\0");   /*Not sign*/
	map[13][0] = ' ';   /*Soft hyphen*/

	map[14][0] = '\0';   /*UNUSED*/

	map[15][0] = '-';   /*Parenthetiki pavla*/
	strcpy(map[16], "*d\0");   /*Degree sign*/
	strcpy(map[17], "+-\0");   /*Plus-minus sign*/
	strcpy(map[18], "^2\0");   /*Superscript two*/
	strcpy(map[19], "^3\0");   /*Superscript three*/
	map[20][0] = 39;   /*Accent (tonos)*/

	map[21][0] = 39;   /*Dialytika and Tonos*/
	map[21][1] = '"';
	
	strcpy(map[22], "A'\0");   /*Alpha with accent*/
	map[23][0] = '.';   /*Middle dot (ano teleia)*/
	strcpy(map[24], "E'\0");   /*Epsilon with accent*/
	strcpy(map[25], "H'\0");   /*Eta with accent*/
	strcpy(map[26], "I'\0");   /*Iota with accent*/
	strcpy(map[27], ">>\0");   /*Right angle quotation*/
	strcpy(map[28], "O'\0");   /*Omicron with accent*/
	strcpy(map[29], "*h\0");   /*One half*/
	strcpy(map[30], "Y'\0");   /*Ypsilon with accent*/
	strcpy(map[31], "W'\0");   /*Omega with accent*/

	map[32][0] = 'i';   /*iota with dialytika and accent*/
	map[32][1] = 39;
	map[32][2] = '"';

	map[33][0] = 'A';   /*Alpha through Omega*/
	map[34][0] = 'V';
	map[35][0] = 'G';
	map[36][0] = 'D';
	map[37][0] = 'E';
	map[38][0] = 'Z';
	map[39][0] = 'H';
	map[40][0] = '8';
	map[41][0] = 'I';
	map[42][0] = 'K';
	map[43][0] = 'L';
	map[44][0] = 'M';
	map[45][0] = 'N';
	strcpy(map[46], "KS\0");
	map[47][0] = 'O';
	map[48][0] = 'P';
	map[49][0] = 'R';

	map[50][0] = '\0';   /*UNUSED*/

	map[51][0] = 'S';
	map[52][0] = 'T';
	map[53][0] = 'Y';
	map[54][0] = 'F';
	map[55][0] = 'X';
	strcpy(map[56], "PS\0");
	map[57][0] = 'W';

	map[58][0] = 'I';   /*Iota with dialytika*/
	map[58][1] = '"';	

	map[59][0] = 'Y';   /*Ypsilon with dialytika*/
	map[59][1] = '"';

	strcpy(map[60], "a'\0");   /*alpha with accent*/
	strcpy(map[61], "e'\0");   /*epsilon with accent*/
	strcpy(map[62], "h'\0");   /*eta with accent*/	
	strcpy(map[63], "i'\0");   /*iota with accent*/

	map[64][0] = 'y';   /*ypsilon with dialytika and accent*/
	map[64][1] = 39;
	map[64][2] = '"';

	map[65][0] = 'a';   /*alpha through omega*/
	map[66][0] = 'v';
	map[67][0] = 'g';
	map[68][0] = 'd';
	map[69][0] = 'e';
	map[70][0] = 'z';
	map[71][0] = 'h';
	map[72][0] = '8';
	map[73][0] = 'i';
	map[74][0] = 'k';
	map[75][0] = 'l';
	map[76][0] = 'm';
	map[77][0] = 'n';
	strcpy(map[78], "ks\0");
	map[79][0] = 'o';
	map[80][0] = 'p';
	map[81][0] = 'r';
	map[82][0] = 's';
	map[83][0] = 's';
	map[84][0] = 't';
	map[85][0] = 'y';
	map[86][0] = 'f';
	map[87][0] = 'x';
	strcpy(map[88], "ps\0");
	map[89][0] = 'w';

	map[90][0] = 'i';   /*iota with dialytika*/
	map[90][1] = '"';

	map[91][0] = 'y';   /*ypsilon with dialytika*/
	map[91][1] = '"';

	strcpy(map[92], "o'\0");   /*omicron with accent*/
	strcpy(map[93], "y'\0");   /*ypsilon with accent*/
	strcpy(map[94], "w'\0");   /*omega with accent*/

	map[95][0] = '\0';   /*UNUSED*/
}

void output(int element, char map[SIZE][4]){   /*This function checks if the element (character that is input) is*/
					       /*within the range 0-126 (so that it outputs an ASCII or ISO 8859-1*/
					       /*character) or if it is within the range 160-255 (so that it outputs*/
					       /*an ASCII or ISO 8859-1 character that is equivalent to it through*/
					       /*the map array). Characters out of this range will be ignored and*/
					       /*reported to sterr.*/

	if(element >= 0 && element <= 126){
		putchar(element);
	}
	else if(element >= 160 && element <= 255){
		int i;
		for(i=0; map[element-160][i]!='\0'; i++){
			putchar(map[element-160][i]);
		}
	}
	else fprintf(stderr, "Found non recognizable character\n");
}

enum state_t{Sc, Sn, SN, Sm, SM};

enum state_t check_state(int element){   /*This function checks if the current character is either nu, Nu, mu, Mu or*/
			                  /*any other and returns the next state of the FSM to Sn, SN, Sm, SM or Sc*/
					  /*accordingly*/
	enum state_t S;
	
	if(element == 237) S = Sn;
	else if(element == 205) S = SN;
	else if(element == 236) S = Sm;
	else if(element == 204) S = SM;
	else S = Sc;

	return S;
}

void FSM(int element, char map[SIZE][4], enum state_t previous_S, enum state_t current_S){

   /*This function represents an FSM made to choose whether the characters of the input will be displayed as one*/
   /*or two sets of characters in the output. There are 4 states: Sc (in which the input character is not nu, Nu, mu*/
   /*or Mu, and thus it is output), Sn and SN (in which d or D are output if the next input is tau or Tau), and*/
   /*Sm and SM (in which b or B are output if the next input is pi or Pi). It's parameters are the current input*/
   /*character, the ISO 8859-7 map array (which is fed to the output function), and two states of the FSM: the current*/
   /*and the previous one (given by the main function).*/

	if(current_S == Sc){
		if(previous_S == Sc) output(element, map);
		else if(previous_S == Sn){
			if(element == 244 || element == 212) putchar('d');   /*the element is tau or Tau*/	
			else{
				putchar('n');   /*print "n" and the element since it isn't tau or Tau*/
				output(element, map);
			}
		}
		else if(previous_S == SN){
			if(element == 244 || element == 212) putchar('D');   /*the element is tau or Tau*/
			else{
				putchar('N');   /*print "N" and the element since it isn't tau or Tau*/
				output(element, map);
			}
		}
		else if(previous_S == Sm){
			if(element == 240 || element == 208) putchar('b');   /*the element is pi or Pi*/
			else{
				putchar('m');   /*print "m" and the element since it isn't pi or Pi*/
				output(element, map);
			}
		}
		else if(previous_S == SM){
			if(element == 240 || element == 208) putchar('B');   /*the element is pi or Pi*/
			else{
				putchar('M');   /*print "M" and the element since it isn't pi or Pi*/
				output(element, map);
			}
		}
	}
	else{
		if(previous_S == Sn) putchar('n');	/*In this case, the FSM is changing state while the previous*/
		else if(previous_S == SN) putchar('N'); /*one is either Sc or any other of the remaining. In the first*/
		else if(previous_S == Sm) putchar('m'); /*case, the output will be nothing, whereas in the latter*/
		else if(previous_S == SM) putchar('M'); /*the letter that caused the FSM to enter the previous state*/
	}						/*will be output.*/
}

int main(void){   /*The main function reads input from stdin until the EOF character is found and manages the FSM*/
		  /*and check_state functions with the current and previous state of the FSM according to the*/
		  /*character that is read*/

	char map[SIZE][4];
	int element;
	enum state_t previous_S, current_S;
	initialization(map);

	element = getchar();
	previous_S = Sc;
	current_S = check_state(element);

	while(element != EOF){
		FSM(element, map, previous_S, current_S);
		previous_S = current_S;
		element = getchar();
		current_S = check_state(element);
	}

	return 0;
}
