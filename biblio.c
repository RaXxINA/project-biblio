#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
// User structure
typedef struct {
	int id;
    char username[50];
    char password[50];
    char membership[20]; // Ultra, Gold, Silver
    char blacklisted[4];
} User;
User *user;
// Book structure
typedef struct {
    char title[100];
    char author[50];
    char category[50];
    char description[50];
    float prix;
    char disponible[50];
} Book;
Book *book;
// Feedback structure
typedef struct {
    char username[50];
    char text[200];
} Feedback;
Feedback *feedback;
// Function prototypes;
void utilisateurMode();
void ownerMode();
void displayUserMenu();
void displayOwnerMenu();
void modifyUserInfo(char[]);
void searchBooks();
void removeUser(int);
void addUser(char[]);
void addBook();
void removeBook();
void loadUsers();
void loadBooks();
void loadFeedbacks();
void saveUsers();
void saveBooks();
void saveFeedbacks();
void utilisateurMenu(char[]);
void openall(FILE*,FILE*,FILE*);
void freeall();
int main() {
system("color a");
	user=(User*)malloc(100*sizeof(User));	
	if(user!=NULL){
    book=(Book*)malloc(100*sizeof(Book));
	if(book!=NULL){
feedback=(Feedback*)malloc(100*sizeof(Feedback));
    if(feedback!=NULL){
int mode;
printf("                                 \xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Bonjour dans notre bibliotheque \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
    printf("Enter code : ");
    scanf("%d", &mode);
    if (mode ==1234) {
        ownerMode();
    } else {
        utilisateurMode();
    }
	}else{
		printf("feedback pas de allocation");
		return 0;
}
	}else{
		printf("book pas de allocation");
		return 0;
	}
	}else{
		printf("user pas de allocation");
		return 0;
	} 
    // Display menu based on mode (utilisateur or owner)
}
// Owner Mode
void ownerMode() {
    displayOwnerMenu();
    int c, i,j=0;
    scanf("%d", &c);
    char k[50];
    if(c==1){
       loadUsers();
        }
    if(c==2){
    	int numusers=0;
	FILE *userFile = fopen("users.csv", "w");
    if (userFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(userFile, "%s",n) == 1) {
	numusers++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numusers/=4;
       printf("donner le nom d'utilisateur svp :");
        scanf("%s", k);i=0;
            	while (fscanf(userFile, "%s",n) == 1) {
        char * strToken = strtok ( n, ";" );
        i++;
    while ( strToken != NULL ) { 
    if (strcmp(strToken, k)== 0) {
                    removeUser(i);j++;
                }
        strToken = strtok ( NULL, ";");
    }}if(j==0){
                	printf("%s n'exist pas",k);
                	ownerMode();
				}
	
    
                
            }
        
    if(c==3){printf("donner username:");
	char f[50];
	scanf("%s",f)	;
	addUser(f);
        }
    if(c==4){
        addBook();}
    if(c==5){
        removeBook();}
    if(c==6){
        loadFeedbacks();}
        if(c==7){
        	loadBooks();
		}
		if(c==8){
        	freeall();
        	return ;
		}
}
// Utilisateur Mode
void utilisateurMode() {
        char username[50];
        printf("Enter username: ");
        scanf("%s", username);

        // Check if user exists
        char userFound[4];
		strcpy(userFound,"No");
        int userIndex,k,i;
        int numusers=0;
	FILE *userFile = fopen("users.csv", "w");
    if (userFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(userFile, "%s",n) == 1) {
	numusers++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numusers/=4;
fclose(userFile);
        for (i = 0;i <numusers ;i++) {
            if (strcmp(user[i].username, username) == 0) {
                strcpy(userFound,"Yes");
                userIndex=i;
                break;
            }
        }
if(userFound == "Yes"){
            char password[50];
            int attempts = 5;
            while (attempts > 0) {
                printf("Enter password: ");
                scanf("%s", password);
                if (strcmp(user[userIndex].password, password) == 0) {
                    // Display user menu
                    displayUserMenu();
	int c;
    scanf("%d", &c);
    if(c==1){
    	int numfeedbacks=0;
    FILE *feedbackFile = fopen("feedbacks.csv", "w");
    if (feedbackFile == NULL) {
        printf("Error opening feedback file for writing.\n");
        return;
    }
char name[50];
    while (fscanf(feedbackFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
		numfeedbacks++;
    while ( strToken != NULL ) {
        strToken = strtok ( NULL, ";");
    } }
       (numfeedbacks)++;
strcpy(feedback[numfeedbacks-1].username,username);
    printf("Enter your feedback or book recommendation:\n");
    char text[200];
    scanf("%s", feedback[numfeedbacks-1].text);
    for(i=0;i<numfeedbacks;i++){
    fprintf(feedbackFile, "%d,%s,%s\n",i+1,feedback[i].username,feedback[i].text);}	
    fclose(feedbackFile);
	  } 
    if(c==2){
	modifyUserInfo(username);
        }
    if(c==3){searchBooks(); 
        }
    if(c==4){
printf("Merci pour utiliser notre application");
        freeall();return;}
        		
                } else {
                    attempts--;
                    printf("Incorrect password. %d attempts remaining.\n", attempts);
                } }
				if(attempts==0){
            	printf("You are now Blacklisted");
            	strcpy(user[userIndex].blacklisted,"Yes");
            	for(i=0;i<numusers;i++){
    fprintf(userFile, "%d, %s, %s, %s, %s\n",i+1,user[i].username,user[i].password,user[i].membership,user[i].blacklisted);
	}fclose(userFile);}
			
				}else { fclose(userFile);
            printf("User not found. Creating a new account.\n");
            addUser(username);
            displayUserMenu();
	int c;
    scanf("%d", &c);
    if(c==1){
    	int numfeedbacks=0;
    FILE *feedbackFile = fopen("feedbacks.csv", "w");
    if (feedbackFile == NULL) {
        printf("Error opening feedback file for writing.\n");
        return;
    }
char name[50];
    while (fscanf(feedbackFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
		numfeedbacks++;
    while ( strToken != NULL ) {
        strToken = strtok ( NULL, ";");
    } }
    (numfeedbacks)++;
strcpy(feedback[(numfeedbacks)-1].username,username);
    printf("Enter your feedback or book recommendation:\n");
    char text[200];
    scanf("%s", feedback[(numfeedbacks)-1].text);
    for(i=0;i<numfeedbacks;i++){
    fprintf(feedbackFile, "%d,%s,%s\n",i+1,feedback[i].username,feedback[i].text);}	
	fclose(feedbackFile);}
    if(c==2){
	modifyUserInfo(username);
        }
    if(c==3){searchBooks(); 
        }
    if(c==4){printf("Merci pour utiliser notre application");
        freeall();
        		return;
        }
        }

}


// Display menu for utilisateur
void displayUserMenu() {
    printf("\nUtilisateur Menu:\n");
    printf("1. Send Feedback\n");
    printf("2. Modify User Info\n");
    printf("3. Search Books by title or categorie\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
}

// Display menu for owner
void displayOwnerMenu() {
    printf("\nOwner Menu:\n");
    printf("1. Display Users Info\n");
    printf("2. Remove User\n");
    printf("3. Add User\n");
    printf("4. Add Book to Library\n");
    printf("5. Remove Book from Library\n");
    printf("6. Display Feedbacks\n");
    printf("7. Display library\n");
    printf("8. Quit\n");
    printf("Enter choice: ");
}

// Function to modify user info
void modifyUserInfo(char username[]) {
	int numusers=0;
	FILE *userFile = fopen("users.csv", "w");
    if (userFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(userFile, "%s",n) == 1) {
	numusers++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numusers/=4;
    
    // Find the user index
 int i,userIndex = -1;
    for (i = 0; i < numusers; i++) {
        if (strcmp(user[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("User not found.\n");
        return;
    }else{

    printf("Enter new password: ");
    scanf("%s", user[userIndex].password);
    fflush(stdin);
    printf("Enter type of membership : ");
    scanf("%s", user[userIndex].membership);
    printf("User info updated successfully.\n");
    // Save users to file
    for(i=0;i<numusers;i++){
    fprintf(userFile, "%d, %s, %s, %s, %s\n",i+1,user[i].username,user[i].password,user[i].membership,user[i].blacklisted);
	}fclose(userFile);
    ownerMode();
}}

// Function to search books
void searchBooks(){
    // Implementation for searching books by title, category, or writer and sorting alphabetically
    // This can be done by reading the library array and sorting it accordingly
    // However, for simplicity, let's assume the library array is already sorted alphabetically
    // We can then implement searching based on title, category, or author using linear search
    int numbooks=0;
	FILE *bookFile = fopen("library.csv", "w");
    if (bookFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(bookFile, "%s",n) == 1) {
	numbooks++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numbooks/=4;
    
    int g;
printf("if u want to search by title enter 1 if by category enter 2:");
scanf("%d",&g);
char searchTerm[100];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
if(g==1){
	printf("Search Results:\n");
    char name[50];int j;
    while (fscanf(bookFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
        
    while ( strToken != NULL ) {
	if(strToken==searchTerm){
	j=1;
	}
        printf ( "%s     ", strToken );
		
        strToken = strtok ( NULL, ";");
    }}
    printf("\n");
    if(j==1){
	printf("ce titre %s est disponible dans le biblio\n",searchTerm);
	}else{
    	printf("ce titre %s n'est pas dans le biblio",searchTerm);
	}
	
}else{
printf("Search Results:\n");
    char name[50];int j;
    while (fscanf(bookFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
        
    while ( strToken != NULL ) {
	if(strToken==searchTerm){
	int	j=1;
	}
        printf ( "%s     ", strToken );
		
        strToken = strtok ( NULL, ";");
    }}
    printf("\n");
    if(j==1){
	printf("cet auteur %s est disponible dans le biblio\n",searchTerm);
	}else{
    	printf("cet auteur %s n'est pas dans le biblio",searchTerm);
	}
    fclose(bookFile);
}
ownerMode();
}
// Function to remove user
void removeUser(int index) {
	int numusers=0;
	FILE *userFile = fopen("users.csv", "w");
    if (userFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(userFile, "%s",n) == 1) {
	numusers++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numusers/=4;
    char username[50];int i;
    strcpy(username, user[index].username); // Copy username for printing
    // Shift remaining users to fill the gap
    for(i =index;i <numusers-1;i++){
        user[i] = user[i+1];
    }
numusers--;
    printf("User '%s' removed successfully.\n", username);

    // Save users to file
    for(i=0;i<numusers;i++){
    fprintf(userFile, "%d, %s, %s, %s, %s\n",i+1,user[i].username,user[i].password,user[i].membership,user[i].blacklisted);
	}fclose(userFile);
    ownerMode();
}

// Function to add user
void addUser(char user1[]) {
	int numusers=0;
	FILE *userFile = fopen("users.csv", "w");
    if (userFile== NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }
    char n[50];
    while (fscanf(userFile, "%s",n) == 1) {
	numusers++;
        char * strToken = strtok ( n, ";" );
    while ( strToken != NULL ) { 
        strToken = strtok ( NULL, ";");
    }
	
    }
numusers/=4;
    
User newUser;int i,k=0;
           for (i=0;i<numusers;i++){
        if (strcmp(user[i].username,user1)==0){
            printf("Username already exists.\n");
            k++;}}
        if (k==0){
        	strcpy(newUser.username,user1);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter membership (Ultra, Gold, Silver): ");
    scanf("%s", newUser.membership);
    strcpy(newUser.blacklisted,"No");
(numusers)++;
    user[(numusers)-1] =newUser;
    printf("User added successfully at index %d.\n",(numusers)-1);

		}
    
        for(i=0;i<numusers;i++){
    fprintf(userFile, "%d, %s, %s, %s, %s\n",i+1,user[i].username,user[i].password,user[i].membership,user[i].blacklisted);
	}fclose(userFile);
    // Save users to file
	
}

// Function to add book to library
void addBook() {
		int i,numbooks=0;
    FILE *bookFile = fopen("library.csv", "r");
    if (bookFile == NULL) {
        printf("Error opening user file.\n");
        return;
    }
    
    char name[50];
    while (fscanf(bookFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
        numbooks++;
    while ( strToken != NULL ) {
        
		
        strToken = strtok ( NULL, ";");
    }
    
    
    } 
    
    Book newBook;
    numbooks/=4;
    (numbooks)++;
    printf("Enter title: ");
    scanf("%s", newBook.title);
    printf("Enter author: ");
    scanf("%s", newBook.author);
	fflush(stdin);
    printf("Enter Description: ");
    gets(newBook.description);
    fflush(stdin);
    printf("Enter prix: ");
    scanf("%f", newBook.prix);
    printf("Enter category: ");
    scanf("%s", newBook.category);
    printf("Enter disponible ou no: ");
    scanf("%s", newBook.disponible);
    book[numbooks-1]=newBook;
    printf("Book added successfully.\n");
    // Save books to file
    for(i=0;i<numbooks;i++){
    fprintf(bookFile, "%d, %s, %s\n",i+1,book[i].author,book[i].title,book[i].category);
	}

    fclose(bookFile);
    ownerMode();
}

// Function to remove book from library
void removeBook() {
		int numbooks=0;
    FILE *bookFile = fopen("library.csv", "r");
    if (bookFile == NULL) {
        printf("Error opening user file.\n");
        return;
    }
    
    char name[50];
    while (fscanf(bookFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
        numbooks++;
    while ( strToken != NULL ) {
        
		
        strToken = strtok ( NULL, ";");
    }
    
    
    } 
    char title[100];
    printf("Enter the title of the book to remove: ");
    scanf("%s", title);
int i;
    // Find the book index
    int bookIndex = -1;
    int l;
    for (i=0;i<numbooks/4;i++) {
        if (strcmp(book[i].title, title) == 0) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex==-1) {
        printf("Book not found.\n");
        ownerMode();
    }
    // Shift remaining books to fill the gap
    for (i=bookIndex;i<(numbooks/4)-1;i++) {
        book[i]=book[i+1];
    }
    numbooks--;

    printf("Book '%s' removed successfully.\n", title);

    // Save books to file
    for(i=0;i<numbooks/4;i++){
    fprintf(bookFile, "%d, %s, %s\n",i+1,book[i].author,book[i].title,book[i].category);
	}

    fclose(bookFile);
    ownerMode();
}

// Function to load users from file
void loadUsers() {
	int numusers=0;
    FILE *userFile = fopen("users.csv", "r");
    if (userFile == NULL) {
        printf("Error opening user file.\n");
        return;
    }
    
    char name[50];
    while (fscanf(userFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
    while ( strToken != NULL ) {
        printf ( "%s     ", strToken );
		
        strToken = strtok ( NULL, ";");
    }
    printf("\n");
    
    } 
    fclose(userFile);

}

// Function to load books from file
void loadBooks() {
    FILE *bookFile = fopen("library.csv", "r");
    if (bookFile == NULL) {
        printf("Error opening library file.\n");
        return;
    }
  
    char name[50];
    while (fscanf(bookFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
    while ( strToken != NULL ) {
        printf ( "%s     ", strToken );
		
        strToken = strtok ( NULL, ";");
    }}
    printf("\n");
    
    fclose(bookFile);
}

// Function to load feedbacks from file
void loadFeedbacks() {
    FILE *feedbackFile = fopen("feedbacks.csv", "r");
    if (feedbackFile == NULL) {
        printf("Error opening feedback file.\n");
        return;
    } 
    
    char name[50];
    while (fscanf(feedbackFile, "%s",name) == 1) {
        char * strToken = strtok ( name, ";" );
    while ( strToken != NULL ) {
        printf ( "%s     ", strToken );
		
        strToken = strtok ( NULL, ";");
    }
    printf("\n");
    
    } 

    fclose(feedbackFile);

}
void freeall(){
	free(user);free(book);free(feedback);
}
