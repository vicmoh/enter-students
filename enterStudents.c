/* Vicky Mohammad
 * February 10, 2017
 * This program will get the user info using struct */

/*import libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct student {
	int recordCount;
	char *firstName;
	char *lastName;
	char *id;
	char *email;
};/*end of struct*/

int main(){
	/*declare var*/
	char stringBuffer[99];
	int stringLength = 0;
	int exit = 0;
	int exitForId = 0;
	int studentCount = 0;
	int totalStudent = 0;
	int x = 0;
	int y = 0;
	struct student *info;
	info = malloc(sizeof(*info));
	info->recordCount = 0;
	
	/*loop until exit*/
	printf("\n");
	while (exit == 0){
		/*enter the inputs*/
		printf("Fist Name: ");
		fgets(stringBuffer, 51, stdin);
		stringLength = strlen(stringBuffer);
		/*alocate enough space and then copy the value to the struct*/
		info[studentCount].firstName = malloc(sizeof(char) * stringLength+1);
		strcpy(info[studentCount].firstName, stringBuffer);
		/*empty the buffers*/
		info[studentCount].firstName[stringLength-1] = '\0';
		*stringBuffer = '\0';
		stringLength = 0;
		
		/*exit if user input period*/
		if(info[studentCount].firstName[0] == '.'){
			exit = 1;
		} else {	
			/*enter the inputs*/
			printf("Last Name: ");
			fgets(stringBuffer, 99, stdin);
			stringLength = strlen(stringBuffer);
			/*alocate enough space and then copy the value to the struct*/
			info[studentCount].lastName = malloc(sizeof(char) * stringLength+1);
			strcpy(info[studentCount].lastName, stringBuffer);
			info[studentCount].lastName[stringLength-1] = '\0';
			/*empty the buffers*/
			*stringBuffer = '\0';
			stringLength = 0;
			
			/*enter the inputs*/
			printf("ID#: ");
			fgets(stringBuffer, 99, stdin);
			stringLength = strlen(stringBuffer);
			/*contraint until user input only number*/
			exitForId = 0;
			while (exitForId == 0){
				for (y=0;y<stringLength-1;y++) {
					/*printf("looped\n");*/
					if ((stringBuffer[y] >= 48) && (stringBuffer[y] <= 57) && 
						(stringLength == 10)){
						/*if its a number exit the for loop*/
						exitForId = 1;
						/*printf("%c a number\n", stringBuffer[y]);*/
					} else {
						/*if it's not a number do not exit*/
						exitForId = 0;
						y = 100;
						/*printf("%c not a number\n", stringBuffer[y]);*/
						/*empty the buffers*/
						*stringBuffer = '\0';
						stringLength = 0;
						/*enter the inputs*/
						printf("Invalid ID#, please re-enter: ");
						fgets(stringBuffer, 51, stdin);
						stringLength = strlen(stringBuffer);
					}/*end if*/
				}/*end for loop*/
			}/*end while loop*/
			/*alocate enough space and then copy the value to the struct*/
			info[studentCount].id = malloc(sizeof(char) * stringLength+1);
			strcpy(info[studentCount].id, stringBuffer);
			info[studentCount].id[stringLength-1] = '\0';
			/*empty the buffers*/
			*stringBuffer = '\0';
			stringLength = 0;
			
			/*enter the inputs*/
			printf("Email: ");
			fgets(stringBuffer, 99, stdin);
			stringLength = strlen(stringBuffer);
			/*alocate enough space and then copy the value to the struct*/
			info[studentCount].email = malloc(sizeof(char) * stringLength+1);
			strcpy(info[studentCount].email, stringBuffer);
			info[studentCount].email[stringLength-1] = '\0';
			/*empty the buffers*/
			*stringBuffer = '\0';
			stringLength = 0;
		}/*end else if*/
		
		/*counter to the next student and realocate a new struct*/
		printf("\n");
		studentCount = studentCount + 1;
		info = realloc(info, sizeof(*info) * (studentCount+1));
	}/*end of while loop*/
	
	/*declare var for sorting*/
	totalStudent = studentCount - 1;
	int rankSort[totalStudent];
	int idSort[totalStudent];
	/*put the original value of id number*/
	for(x=0;x<totalStudent;x++){
		rankSort[x] = x;
		idSort[x] = atoi(info[x].id); 
	}/*end for loop*/
	
	/*rank the value from smallest to largest*/
	int i, j, idTemp, rankTemp;
	for(i=1;i<=totalStudent-1;i++){
		for(j=1;j<=totalStudent-i;j++){
			if(idSort[j-1] >= idSort[j]){
				/*switch value for idSort*/
				idTemp = idSort[j-1];
				idSort[j-1] = idSort[j];
				idSort[j] = idTemp;
				/*switch value for ranSort*/
				rankTemp = rankSort[j-1];
				rankSort[j-1] = rankSort[j];
				rankSort[j] = rankTemp;
			}/*end if*/
		}/*end if*/
	}/*end loop*/
	
	/*print through sort*/
	for(x=0;x<studentCount-1;x++){
		printf("%s,%s,%s,%s", info[rankSort[x]].id,info[rankSort[x]].firstName,info[rankSort[x]].lastName,info[rankSort[x]].email);
		printf("\n");
	}/*end loop*/
	printf("\n");
	free(info);
	return(0);
}/*end of main*/
