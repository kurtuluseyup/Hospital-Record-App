 /* Name: Eyüp Hazar Kurtuluþ, Number: 200254056 Ders: COM 201_HW_1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct HospitalList {
    char firstLetter;
	struct Record * firstRecordPtr;
};

struct Record{
	char  name[50];
    char surname[50];
    char  polyclinic[50];
    struct Record *next;
};

struct Record * head = NULL;
struct Record * temp = NULL;
struct HospitalList hospitallist[26];

int c = 'a';
int i = 0;
	



void AddNew(char * name1, char * surname1, char * polyclinic1){
	int c = 'a';
	int i = 0;
	struct Record * node = (struct Record *)malloc(sizeof(struct Record));
	strcpy(node->name , name1);
	strcpy(node->surname , surname1);
	strcpy(node->polyclinic , polyclinic1);
	node->next = NULL;
	
	for(c='a';c<='z';c++,i++){
		if(name1[0] == hospitallist[i].firstLetter){
			head = hospitallist[i].firstRecordPtr;
			break;
		}	
    }
	
	if(head == NULL){
		head = node;
	}
	
	else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
	}
}

void Search(){
	char name1[50];
	char surname1[50];
	printf("\nWhat is your name? : ");
	scanf("%s", & name1);
	printf("\nWhat is your surname? : ");
	scanf("%s", & surname1);
	for(c='a';c<='z';c++,i++){
		if(name1[0] == hospitallist[i].firstLetter){
			head = hospitallist[i].firstRecordPtr;
			break;
		}	
    }
    temp = head;
	if(head == NULL){
		printf("Your list is empty.");
	}
	else{
		
		while(temp -> name !=  name1 && temp ->surname != surname1 ){
		
		printf("%s - %s\n\n\n",temp->name,temp->surname);
		temp = temp->next;
	}
	printf("That is your record: ");
	printf("\n Name: %s \n Surname: %s \n Polyclinic: %s", temp->name, temp->surname, temp->polyclinic);
	}
	
}



void Delete(char * name1, char * surname1){
	temp = head;
	if(head == NULL){
		printf("Your list is empty");
	}
	else if(temp->name == name1 ){
		head = NULL;
		free(temp);
	}
	else{
		while((temp->next->name[0] != name1[0]) && (temp->next->surname[0] != surname1[0])){
			temp = temp->next;
			printf("%s - %s", temp->next->name ,temp->next->surname);
		}
		struct Record * temp2 = (struct Record *)malloc(sizeof(struct Record));
		temp2 = temp->next;
		temp2 -> next = temp ->next ->next;
		temp->next = temp2 ->next;
		free(temp2);
	}
}

void Display(){
	char name1[1];
	printf("\nWhich letter do you want? : ");
	scanf("%s", & name1);
	for(c='a';c<='z';c++,i++){
		if(name1[0] == hospitallist[i].firstLetter){
			head = hospitallist[i].firstRecordPtr;
			break;
		}	
    }
	temp = head;
	if(head == NULL){
		printf("Your list is empty.");
	}
	else{
		while(temp->next != NULL){
			printf("\n Name: %s  \n Surname: %s  \n Polyclinic: %s  \n ",temp->name,temp->surname,temp->polyclinic);
			printf("------------------------------------------------------------------------");
			temp = temp->next;
		}printf("\n Name: %s  \n Surname: %s  \n Polyclinic: %s  \n \n",temp->name,temp->surname,temp->polyclinic);
	}
		
}



int main() {
	int choose=0;
	char name1[50];
	char polyclinic1[50];
	char surname1[50];
	
	int c = 'a';
	int i = 0;

	for(c='a';c<='z';c++,i++)

{

    hospitallist[i].firstLetter =c;

    hospitallist[i].firstRecordPtr = NULL;

}
	
	
	

	
	
	while(choose != 8){
		printf("\n\n ________Hospital Management System________ \n \n");
		printf("1-) Add New Record \n");
		printf("2-) Search Record \n");
		printf("3-) Delete Record \n");
		printf("4-) Sort Records By Name \n");
		printf("5-) Sort Records By Surname \n");
		printf("6-) Sort Records By Polyclinic Name \n");
		printf("7-) Print All Of The Patient \n");
		printf("8-) Exit \n");
		printf("\nWhat do you want to use? : ");
		scanf("%d",&choose);
		system("cls");
		switch(choose){
		case 1:
		printf("\nWhat is your name? : ");
		scanf("%s", &name1);
		printf("\nWhat is your surname? : ");
		scanf("%s", &surname1);
		printf("\nWhat is your polyclinic? : ");
		scanf("%s", &polyclinic1);
		system("cls");
		printf("\nName: %s \nSurname: %s \nPolyclinic: %s \n \n \n",name1,surname1,polyclinic1);
		AddNew(name1 , surname1, polyclinic1 );
		break; 
		case 2:
		Search();
		break;
		case 3:
		printf("\nWhat is your name? : ");
		scanf("%s", &name1);
		printf("\nWhat is your surname? : ");
		scanf("%s", &surname1);
		Delete(name1, surname1);
		break;
		case 4:
		case 5:
		case 6:
		case 7: 
		Display();
		break;
		case 8:
		return 0;
		break;
	
	}	
	}
	
	

	return 0;
}
