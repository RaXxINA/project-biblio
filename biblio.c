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
	int id;
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
void utilisateurMode(int*,int*,int*);
void ownerMode(int*,int*,int*);
void displayUserMenu();
void displayOwnerMenu();
void modifyUserInfo(char[],int*);
void searchBooks(int*);
void displayUserInfo(int,int);
void removeUser(int,int*);
void addUser(char[],int*);
void addBook(int*);
void removeBook(int*,int*,int*);
void loadUsers();
void loadBooks();
void loadFeedbacks();
void saveUsers(int*);
void saveBooks(int*);
void saveFeedbacks(int*);
void utilisateurMenu(char username);
void openall(FILE*,FILE*,FILE*);
void freeall();
// Global variables
int main() {
system("color a");
	int numusers = 0;
int numbooks = 0;
int numfeedbacks = 0;
FILE *userFile = fopen("user.csv", "a");
	FILE *bookFile = fopen("book.csv", "a");
	FILE *feedbackFile = fopen("feedback.csv", "a");
	user=(User*)malloc(100*sizeof(User));	
	if(user!=NULL){
    book=(Book*)malloc(50*sizeof(Book));
	if(book!=NULL){
feedback=(Feedback*)malloc(100*sizeof(Feedback));
    if(feedback!=NULL){
openall(userFile,bookFile,feedbackFile);
int mode;
printf("                                 \xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Bonjour dans notre bibliotheque \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3\n");
    printf("Enter code : ");
    scanf("%d", &mode);
    if (mode ==1234) {
        ownerMode(&numbooks,&numusers,&numfeedbacks);
        	fclose(userFile);
     fclose(bookFile);
	 fclose(feedbackFile);
    } else {
        utilisateurMode(&numbooks,&numusers,&numfeedbacks);
        	fclose(userFile);
     fclose(bookFile);
	 fclose(feedbackFile);
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
void ownerMode(int *numbooks,int *numusers,int *numfeedbacks) {
    displayOwnerMenu();
    int c, i;
    scanf("%d", &c);
    char k[50];
    if(c==1){
       loadUsers();
        }
    if(c==2){
       printf("donner le nom d'utilisateur svp :");
        scanf("%s", k);
            for (i = 0; i < *numusers; i++) {
                if (strcmp(user[i].username, k)== 0) {
                    removeUser(i,numusers);
                }else{
                	printf("%s n'exist pas",k);
                	ownerMode(numbooks,numusers,numfeedbacks);
				}
            }
        }
    if(c==3){printf("donner username:");
	char f[50];
	scanf("%s",f)	;
	addUser(f,numusers);
        }
    if(c==4){
        addBook(numusers);}
    if(c==5){
        removeBook(numusers,numbooks,numfeedbacks);}
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
void utilisateurMode(int *numbooks,int *numusers,int *numfeedbacks) {
        char username[50];
        printf("Enter username: ");
        scanf("%s", username);

        // Check if user exists
        char userFound[4];
		strcpy(userFound,"No");
        int userIndex,k,i,j;
        for (i = 0;i <*numusers ;i++) {
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
       (numfeedbacks)++;
strcpy(feedback[(*numfeedbacks)-1].username,username);
    printf("Enter your feedback or book recommendation:\n");
    char text[200];
    scanf("%s", feedback[(*numfeedbacks)-1].text);
    saveFeedbacks(numfeedbacks);
	   }
    if(c==2){
	modifyUserInfo(username,numusers);
        }
    if(c==3){searchBooks(numbooks); 
        }
    if(c==4){printf("Merci pour utiliser notre application");
        freeall();
        		return;
        }
                } else {
                    attempts--;
                    printf("Incorrect password. %d attempts remaining.\n", attempts);
                }
            }
            if(attempts==0){
            	printf("You are now Blacklisted");
            	strcpy(user[userIndex].blacklisted,"Yes");
			}
        } else { // New user
            printf("User not found. Creating a new account.\n");
            addUser(username,numusers);
            displayUserMenu();
	int c;
    scanf("%d", &c);
    if(c==1){
    (*numfeedbacks)++;
strcpy(feedback[(*numfeedbacks)-1].username,username);
    printf("Enter your feedback or book recommendation:\n");
    char text[200];
    scanf("%s", feedback[(*numfeedbacks)-1].text);
    saveFeedbacks(numfeedbacks);}
    if(c==2){
	modifyUserInfo(username,numusers);
        }
    if(c==3){searchBooks(numbooks); 
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
void modifyUserInfo(char *username,int *numusers) {
    // Find the user index
 int i,userIndex = -1;
    for (i = 0; i < *numusers; i++) {
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
    printf("User info updated successfully.\n");}

    // Save users to file
    saveUsers(numusers);
}

// Function to search books
void searchBooks(int *numbooks) {
    // Implementation for searching books by title, category, or writer and sorting alphabetically
    // This can be done by reading the library array and sorting it accordingly
    // However, for simplicity, let's assume the library array is already sorted alphabetically
    // We can then implement searching based on title, category, or author using linear search
    int g,i,k=0;
printf("if u want to search by title enter 1 if by category enter 2:");
scanf("%d",&g);
char searchTerm[100];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
if(g==1){
	printf("Search Results:\n");
	printf("ID:      authur:       titre:       Description:              prix:              categorie:          disponible:\n");
    for (i = 0; i < *numbooks; i++) {
        if (strcmp(book[i].title, searchTerm)==0) {
           k++ ; printf("%d                 %s                %s                %s               %.2f             %s              %s\n",book[i].id, book[i].author, book[i].title, book[i].description, book[i].prix, book[i].category, book[i].disponible);
        }
    }
    if(k==0){
    	printf("ce titre %s n'est pas dans le biblio",searchTerm);
	}
}else{
	printf("Search Results:\n");
	printf("ID:      authur:       titre:       Description:              prix:              categorie:          disponible:\n");
    for (i = 0; i < *numbooks; i++) {
        if (strcmp(book[i].category, searchTerm)==0) {
           k++ ; printf("%d                 %s                %s                %s               %.2f             %s              %s\n",book[i].id, book[i].author, book[i].title, book[i].description, book[i].prix, book[i].category, book[i].disponible);
        }
    }
    if(k==0){
    	printf("cette categorie %s n'est pas dans le biblio",searchTerm);
	}
}
    

    
}

// Function to remove user
void removeUser(int index,int *numusers) {
    char username[50];int i;
    strcpy(username, user[index].username); // Copy username for printing
    // Shift remaining users to fill the gap
    for(i =index;i <(*numusers)-1;i++){
        user[i] = user[i+1];
    }
    numusers--;

    printf("User '%s' removed successfully.\n", username);

    // Save users to file
    saveUsers(numusers);
}

// Function to add user
void addUser(char user1[],int *numusers) {
User newUser;int i,k=0;
           for (i=0;i< *numusers;i++){
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
(*numusers)++;
    user[(*numusers)-1] =newUser;
    printf("User added successfully at index %d.\n",(*numusers)-1);

		}
    
        saveUsers(numusers);
 
    // Save users to file
    
	
}

// Function to add book to library
void addBook(int *numusers) {
    Book newBook;
    (*numusers)++;
    newBook.id=*numusers;
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
    book[*numusers]=newBook;
    printf("Book added successfully.\n");
    // Save books to file
    saveBooks(numusers);
}

// Function to remove book from library
void removeBook(int *numbooks,int *numusers,int *numfeedbacks) {
    char title[100];
    printf("Enter the title of the book to remove: ");
    scanf("%s", title);
int i;
    // Find the book index
    int bookIndex = -1;
    int l;
    for (i=0;i<*numbooks;i++) {
        if (strcmp(book[i].title, title) == 0) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex==-1) {
        printf("Book not found.\n");
        ownerMode(numbooks,numusers,numfeedbacks);
    }
    // Shift remaining books to fill the gap
    for (i=bookIndex;i<(*numbooks)-1;i++) {
        book[i]=book[i+1];
    }
    numbooks--;

    printf("Book '%s' removed successfully.\n", title);

    // Save books to file
    saveBooks(numbooks);
}

void openall(FILE *userFile,FILE *bookFile,FILE *feedbackFile){
    if (userFile == NULL) {
        printf("Error opening user file.\n");
        return;
    }
    if (bookFile == NULL) {
        printf("Error opening library file.\n");
        return;
    }
      
    if (feedbackFile == NULL) {
        printf("Error opening feedback file.\n");
        return;
    } 
     
}
// Function to load users from file
void loadUsers() {
    FILE *userFile = fopen("user.csv.xlsx", "r");
    if (userFile == NULL) {
        printf("Error opening user file.\n");
        return;
    }
    int id;
    char name[50];
    char score[50];
    char pass[50];
    char n[50];
    while (fscanf(userFile, "%d,%49[^,],%49[^,],%49[^,],%49[^,]\n", &id, name, score ,pass, n) == 5) {
        // Process the data (this is just an example, you can do anything with the data here)
        printf("ID: %d, username: %s, password: %s, membership: %s, blacklist: %s\n", id, name, score, pass, n);
    }

    fclose(userFile);
    
}

// Function to load books from file
void loadBooks() {
    FILE *bookFile = fopen("book.csv", "r");
    if (bookFile == NULL) {
        printf("Error opening library file.\n");
        return;
    }
  int id;
    char name[50];
    char score[50];
    char pass[50];
    char disponible[50];
    char ca[50];//categorie
    float p;//prix
    printf("ID:      authur:       titre:       Description:              prix:              categorie:          disponible:\n");
    while (fscanf(bookFile, "%d,%49[^,],%49[^,],%49[^,],%.2f,%49[^,],%49[^,]\n", &id, name, score ,pass, p, ca, disponible) == 7) {
        // Process the data (this is just an example, you can do anything with the data here)
        printf("%d                 %s                %s                %s               %.2f            %s              %s\n", id, name, score, pass, p, ca, disponible);
    }

    fclose(bookFile);
}

// Function to load feedbacks from file
void loadFeedbacks() {
    FILE *feedbackFile = fopen("feedback.csv", "r");
    if (feedbackFile == NULL) {
        printf("Error opening feedback file.\n");
        return;
    } 
    int id;
    char name[50];
    char score[50];
    printf("ID:      username:       feedback:\n");
    while (fscanf(feedbackFile, "%d,%49[^,],%49[^,]\n", &id, name, score) == 3) {
        // Process the data (this is just an example, you can do anything with the data here)
        printf("%d                 %s                %s\n", id, name, score);
    }

    fclose(feedbackFile);

}

// Function to save users to file
void saveUsers(int *numusers) {int i;
    FILE *userFile = fopen("users.csv", "w");
    if (userFile == NULL) {
        printf("Error opening user file for writing.\n");
        return;
    }

    for(i=0;i<*numusers;i++){
    fprintf(userFile, "%d, %s, %s, %s, %s\n",i+1,user[i].username,user[i].password,user[i].membership,user[i].blacklisted);
	}
    fclose(userFile);
}

// Function to save books to file
void saveBooks(int *numbooks) {int i;
    FILE *bookFile = fopen("library.csv", "w");
    if (bookFile == NULL) {
        printf("Error opening library file for writing.\n");
        return;
    }

   for(i=0;i<*numbooks;i++){
    fprintf(bookFile, "%d, %s, %s\n",i+1,book[i].author,book[i].title,book[i].category);
	}

    fclose(bookFile);
}
void saveFeedbacks(int *numfeedbacks) {int i;
    FILE *feedbackFile = fopen("feedbacks.csv", "w");
    if (feedbackFile == NULL) {
        printf("Error opening feedback file for writing.\n");
        return;
    }
    for(i=0;i<*numfeedbacks;i++){
    fprintf(feedbackFile, "%d, %s, %s\n",i+1,feedback[i].username,feedback[i].text);}
    fclose(feedbackFile);
}
void freeall(){
	free(user);free(book);free(feedback);
}
