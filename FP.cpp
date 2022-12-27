#include <stdio.h>
#include <conio.h>
#include <string.h> 
#include <stdlib.h>
struct node {

	int nilai;
	char nama [50];
	int nomor;
	int rank;
    struct node *next;
};
typedef struct node node;



//Daftar Fungsi yang dibuat


void dequeue(node **head);
void enqueue(node **head, int total);
int traverse(node *head);
void input_nilai(node *head);
void mengurutkan(node **head);
void sisa (node **head, int total);
void numbering(node *head);
void show_all(node *head);
node* SortedMerge( node* a, node* b);
void MergeSort(node** head);
void rank (node *head);
void split( node* source ,  node** front,node** back);
//********************************************
//THE MAIN PROGRAM

int main()
{
  
  node *head;
  head = NULL;
  node *sort =NULL;
 
  
  char Menu1, Menu2, Menu3;
  int total;
  
  printf("PROGRAM SELEKSI PESERTA PELATIHAN \n\n");
  printf("Masukkan total peserta yang dapat pendaftar: ");
  scanf("%d", &total);
	
  do{

  system("cls");
  printf("PROGRAM SELEKSI PESERTA PELATIHAN \n\n");
  printf("Masukkan total peserta yang dapat pendaftar: %d", total);
  printf("\n\n 1. Seleksi Pendaftaran");
  printf("\n 2. Seleksi Nilai \n");
  printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
  fflush(stdin); scanf("%c", &Menu1);
	if(Menu1=='1') {
    do{
    
    system("cls");
    
	printf("Selesksi Pendaftaran : \n\n");
	printf("1. Masukkan nama peserta\n");
	printf("2. Menampilkan nama peserta \n");
	printf("3. Sisa Kuota\n");

	printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
	fflush(stdin);
	scanf("%c", &Menu2);
	if(Menu2=='1')
	enqueue(&head, total);
	else if (Menu2=='2')
	traverse(head);
	else if (Menu2=='3')
	sisa (&head,total);
		
  } while (Menu2 != 'q');
	
	}else if (Menu1=='2'){
	
	do{
	
    	system("cls");
  	printf("Seleksi Nilai: \n\n");
	printf("1. Memberi nomer peserta kepada setiap peserta \n");
	printf("2. Menginput nilai tes ke semua peserta\n");
	printf("3. Mengurutkan peserta berdasarkan nilai\n");
	printf("4. Tampilkan data peserta\n");

	printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
	fflush(stdin);
	scanf("%c", &Menu3);
	if(Menu3=='1')
	numbering(head);
	else if (Menu3=='2')
	input_nilai(head);
	else if (Menu3=='3')
	MergeSort(&head);
	else if (Menu3=='4')
	show_all(head);
	}while (Menu3 != 'q');
	
	}else{
    
       printf("Inputan Anda tidak ada dalam Menu");
  	}
  
	}while (Menu1 != 'q');
}

void enqueue(node **head, int total){
	char name[50];
  	node *pPre, *pNew, *pCur;
	int batas;
	
	system("cls");
	batas =traverse(*head);
	
	if (batas<=total){

	printf("\n Masukkan nama peserta: "); fflush(stdin);
	gets(name);

	pNew = (node *)malloc(sizeof(node));
	
	strcpy(pNew->nama, name);
	
	pPre=*head;
	if (pPre==NULL){
		pNew->next = NULL;
		*head=pNew;

	}
	else{
	
	while (pPre->next != NULL) { 
    pPre = pPre -> next;
	 }

		if (pPre->next != NULL){
	     printf("\nDATA NOT FOUND !");
	     getch();}	
		else if(pPre->next== NULL ) {
		pNew->next= NULL;
	    pPre->next=pNew;
		}
	}
	}else if (batas>=total){
		printf("\n===Maaf Kuota sudah penuh=== ");
		getch();
	}
}

void sisa (node **head,int total){
	int jum;
	int sisa;
	jum = traverse(*head);
	sisa = total-jum;
	printf("\nKuota yang tersisa: %d", sisa+1);
	getch();
}

int traverse(node *head){ 
	int i=1;
	node *pWalker;

    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%s->", pWalker -> nama);
   	pWalker = pWalker -> next; 
   	i++;
	}
   printf("END");
   getch();
	return i;
	
}

void numbering(node *head){
	node *pWalker;
	int nomer, i=1;
	nomer = 221200;
    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	pWalker->nomor = nomer+i;
   	pWalker = pWalker -> next; 
   	i++;
	}
	printf("Pemberian Nomer Peserta sudah selesai");
	getch();
}

void input_nilai(node *head){
	node *pWalker;
	
    system("cls");
	pWalker = head;
	while (pWalker != NULL){
		printf("\n Nama peserta: %s \n", pWalker->nama);
		printf("Nomer peserta: %i \n", pWalker->nomor);
		printf("Input nilai peserta: " );
		scanf("%i",&pWalker->nilai);
	
		pWalker = pWalker -> next; 
	}
	printf("END");
}
node* SortedMerge( node* a, node* b)
{
	 node* result;
	result = NULL;

	if(a==NULL)
		return(b);

	else if(b==NULL)
		return(a);

	if(a->nilai >= b->nilai)
	{
		result = a;
		result->next = SortedMerge(a->next,b);
	}

	else
	{
		result = b;
		result->next = SortedMerge(a,b->next);
	}

	return(result);
}

void split( node* source ,  node** front,node** back)
{
	node* slow;
	node* fast;

	if(source==NULL || source->next==NULL)
	{
		*front = source;
		*back = NULL;
	}

	else
	{
		slow = source;
		fast = source->next;

		while(fast!=NULL)
		{
			fast  = fast->next;
			if(fast!=NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front  = source;
		*back = slow->next;
		slow->next=NULL;
	}
}
void MergeSort(node** head)
{
	node* temphead = *head;
	node* a;
	node* b;

	if((temphead==NULL) || (temphead->next==NULL))
		return;

	split(temphead,&a,&b);

	MergeSort(&a);
	MergeSort(&b);

	*head = SortedMerge(a,b);
	
	rank(*head);
}

void rank (node *head){
	node *pWalker;
	int n=traverse(head);
	int i=1;
	system("cls");
	pWalker = head;
	while (pWalker != NULL){
		pWalker->rank=i;
		i++;
		pWalker=pWalker->next;
	}
}
			
void show_all(node *head){
	node *pWalker;
	system("cls");
	pWalker = head;
	while (pWalker != NULL){
		printf("\n Nama peserta: %s \n", pWalker->nama);
		printf("Nomer peserta: %i \n", pWalker->nomor);
		printf("Nilai peserta: %i \n", pWalker->nilai);
		printf("Ranking: %i \n", pWalker->rank);
		pWalker = pWalker -> next; 
	}
	printf("END");
	
	getch();
}

