#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int r = 71, s = 71, h=1;                                                        //Global Variables

struct member_issue                                                             //structure for displaying members who issued books 
{
    char mem_name[50];
    char book_issued[50];
};

struct book_database                                                            //structure for keeping book database
{
  char book_name[50];
  char author[50];
  int issue_num;
  int num_of_books;
};

struct book_database_2                                                          //structure working as a temporary book database
{
  char book_name[50];
  char author[50];
  int issue_num;
  int num_of_books;
};

struct mem                                                                      //declaration of linklist 
{
    char name_id[50];
    struct mem *next;
};
struct mem *p;
struct mem *start;


struct book_database lib[500] = {                                               //structure declaration
  {"THE INDIAN STRUGGLE", "SUBHAS CHANDRA BOSE", 1942, 5},
  {"AN INDIAN PILGRIM", "SUBHAS CHANDRA BOSE", 1950, 5},
  {"WHY I AM AN ATHEIST", "BHAGAT SINGH", 1931, 5},
  {"GITANJALI", "RABINDRANATH TAGORE", 1910, 5},
  {"OPTICKS", "ISSAC NEWTON", 1704, 5},
  {"METHOD OF FLUXIONS", "ALBERT EINSTEIN", 1736, 5},
  {"KABULIWALA", "RABINDRANATH TAGORE", 1911, 5},
  {"NATIONALISM", "RABINDRANATH TAGORE", 1917, 5},
  {"GORA", "RABINDRANATH TAGORE", 1122, 4},
  {"THE GARDENER", "RABINDRANATH TAGORE", 1913, 5},
  {"THE THEORY OF EVERTHING", "STEPHEN HAWKING", 2002, 5},
  {"THE GRAND DESIGN", "STEPHEN HAWKING", 2010, 5},
  {"THE UNIVERSE IN A NUTSHELL", "STEPHEN HAWKING", 2001, 5},
  {"STRAY BIRDS", "RABINDRANATH TAGORE", 1916, 5},
  {"THE EVOLUTION OF PHYSICS", "ALBERT EINSTEIN", 1938, 5},
  {"THE MEANING OF RELATIVITY", "ALBERT EINSTEIN", 1922, 5},
  {"IDEAS AND OPINIONS", "ALBERT EINSTEIN", 1954, 5},
  {"RAJA YOGA", "SWAMI VIVEKANANDA", 1896, 5},
  {"DIVERGENT SERIES", "G.H.HARDY", 1222, 5},
  {"THE INTEGRATION OF FUNCTIONS OF SINGLE VARIABLES", "G.H.HARDY", 1905, 5},
  {"MATTHEW BOULTON", "JAMES WATT", 1850, 5},
  {"MEDICAL CASES AND SPECULATIONS", "JAMES WATT", 1796, 5},
  {"KARMA YOGA", "SWAMI VIVEKANANDA", 1895, 5},
  {"JNANA YOGA", "SWAMI VIVEKANANDA", 1899, 5},
  {"THE WORLD AS I SEE IT", "ALBERT EINSTEIN", 1934, 5},
  {"ON NATURAL SELECTION", "CHARLES DARWIN", 1894, 5},
  {"THE ORIGIN OF SPECIES", "CHARLES DARWIN", 1956, 5},
  {"THE POWERS OF THE MIND", "SWAMI VIVEKANANDA", 1901, 5},
  {"PRACTICAL VEDANTA", "SWAMI VIVEKANANDA", 1912, 5},
  {"OLIVER TWIST", "CHARLES DICKENS", 1838, 5},
  {"A CHRISTMAS CAROL", "CHARLES DICKENS", 1843, 5},
  {"GREAT EXPECTATIONS", "CHARLES DICKENS", 1861, 5},
  {"HARD TIMES", "CHARLES DICKENS", 1854, 5},
  {"LITTLE DORRIT", "CHARLES DICKENS", 1857, 5},
  {"LIFE ON THE MISSISSIPPI", "MARK TWAIN", 1883, 5},
  {"WHAT IS MAN?", "MARK TWAIN", 1906, 5},
  {"THE INNOCENTS ABROAD", "MARK TWAIN", 1869, 5},
  {"THE DIARIES OF ADAM AND EVE", "MARK TWAIN", 1342, 5},
  {"METAPHYSICS", "ARISTOTLE", 1970, 5},
  {"CORPUS ARISTOTELICUM", "ARISTOTLE", 1971, 5},
  {"THE VOYAGE OF BEAGLE", "CHARLES DARWIN", 1839, 5},
  {"ROUGHING IT", "MARK TWAIN", 1444, 5},
  {"A TRAMP ABROAD", "MARK TWAIN", 2491, 5},
  {"EMMA", "JANE AUSTEN", 1004, 5},
  {"TREATISE ON LIGHT", "CHRISTIAAN HUYGENS", 1690, 5},
  {"SPECIES PLANTARUM", "CARL LINNAEUS", 1753, 5},
  {"PRIDE AND PREJUDICE", "JANE AUSTEN", 2709, 5},
  {"ON MOTION", "GALILEO GALILEI", 1590, 5},
  {"PERSUASION", "JANE AUSTEN", 3112, 5},
  {"CONCEPT OF PHYSICS A", "H.C. VERMA", 3412, 5},
  {"CONCEPT OF PHYSICS B", "H.C. VERMA", 5648, 5},
  {"CALCULUS", "THOMAS", 1112, 5},
  {"DATASCIENCE", "JOEL", 9860, 5},
  {"CLEANCODE", "ROBERT", 4723, 5},
  {"SANDITON", "JANE AUSTEN", 1817, 5},
  {"LADY SUSAN", "JANE AUSTEN", 1871, 5},
  {"CONVERSATIONS WITH MYSELF", "NELSON MANDELA", 8888, 5},
  {"THE STRUGGLE IS MY LIFE", "NELSON MANDELA", 7777, 5},
  {"NO EASY WALK TO FREEDOM", "NELSON MANDELA", 1965, 5},
  {"A PRISONER IN THE GARDEN", "NELSON MANDELA", 2005, 5},
  {"LONG WALK TO FREEDOM", "NELSON MANDELA", 1994, 5},
  {"SRI RAMAKRISHNA", "SWAMI VIVEKANANDA", 4709, 5},
  {"PACKING FOR MARS", "MARY ROACH", 2357, 5},
  {"SPACE ACADEMY", "MARTIN BLOCK", 2110, 5},
  {"THE HUBBLE COSMOS", "ROBERT SMITH", 1708, 5},
  {"8000 THINGS YOU SHOULD KNOW", "BELINDA GALLAGHER", 3333, 5},
  {"A HISTORY OF CRICKET", "E.W. SWANTON", 9999, 5},
  {"LET US C", "YASHVANT KANETKAR", 2345, 4},
  {"TWO NEW SCIENCES", "GALILEO GALILEI", 1638, 5},
  {"OPERE", "GALILEO GALILEI", 1655, 4}
};

struct book_database_2 lib2[500] = {                                            //structure declaration
    {"THE INDIAN STRUGGLE","SUBHAS CHANDRA BOSE", 1942, 5},
    {"AN INDIAN PILGRIM", "SUBHAS CHANDRA BOSE", 1950, 5},
    {"WHY I AM AN ATHEIST","BHAGAT SINGH",1931,5},
    {"GITANJALI", "RABINDRANATH TAGORE", 1910, 5},
    {"OPTICKS","ISSAC NEWTON",1704,5}, 
    {"METHOD OF FLUXIONS","ALBERT EINSTEIN",1736 ,5},
    {"KABULIWALA", "RABINDRANATH TAGORE",1911,5},
    {"NATIONALISM","RABINDRANATH TAGORE",1917,5},
    {"GORA", "RABINDRANATH TAGORE", 1122,4},
    {"THE GARDENER", "RABINDRANATH TAGORE", 1913,5},
    {"THE THEORY OF EVERTHING", "STEPHEN HAWKING", 2002,5},
    {"THE GRAND DESIGN","STEPHEN HAWKING",2010,5},
    {"THE UNIVERSE IN A NUTSHELL","STEPHEN HAWKING",2001,5},
    {"STRAY BIRDS","RABINDRANATH TAGORE",1916,5},
    {"THE EVOLUTION OF PHYSICS","ALBERT EINSTEIN",1938,5},
    {"THE MEANING OF RELATIVITY","ALBERT EINSTEIN",1922,5},
    {"IDEAS AND OPINIONS","ALBERT EINSTEIN",1954,5},
    {"RAJA YOGA","SWAMI VIVEKANANDA",1896,5},
    {"DIVERGENT SERIES","G.H.HARDY",1222,5},
    {"THE INTEGRATION OF FUNCTIONS OF SINGLE VARIABLES","G.H.HARDY", 1905,5},
    {"MATTHEW BOULTON","JAMES WATT",1850,5},
    {"MEDICAL CASES AND SPECULATIONS","JAMES WATT",1796,5},
    {"KARMA YOGA","SWAMI VIVEKANANDA",1895,5},
    {"JNANA YOGA","SWAMI VIVEKANANDA",1899,5},
    {"THE WORLD AS I SEE IT", "ALBERT EINSTEIN",1934,5},
    {"ON NATURAL SELECTION", "CHARLES DARWIN",1894,5},
    {"THE ORIGIN OF SPECIES","CHARLES DARWIN",1956,5},
    {"THE POWERS OF THE MIND", "SWAMI VIVEKANANDA",1901,5},
    {"PRACTICAL VEDANTA","SWAMI VIVEKANANDA", 1912,5},
    {"OLIVER TWIST", "CHARLES DICKENS", 1838,5},
    {"A CHRISTMAS CAROL", "CHARLES DICKENS", 1843,5},
    {"GREAT EXPECTATIONS", "CHARLES DICKENS",1861,5},
    {"HARD TIMES", "CHARLES DICKENS", 1854,5},
    {"LITTLE DORRIT", "CHARLES DICKENS", 1857,5},
    {"LIFE ON THE MISSISSIPPI","MARK TWAIN",1883,5},
    {"WHAT IS MAN?","MARK TWAIN",1906,5},
    {"THE INNOCENTS ABROAD", "MARK TWAIN",1869,5},
    {"THE DIARIES OF ADAM AND EVE","MARK TWAIN",1342,5},
    {"METAPHYSICS","ARISTOTLE",1970,5},
    {"CORPUS ARISTOTELICUM", "ARISTOTLE", 1971,5},
    {"THE VOYAGE OF BEAGLE", "CHARLES DARWIN", 1839,5},
    {"ROUGHING IT", "MARK TWAIN",1444,5},
    {"A TRAMP ABROAD","MARK TWAIN",2491,5},
    {"EMMA","JANE AUSTEN", 1004,5},
    {"TREATISE ON LIGHT","CHRISTIAAN HUYGENS",1690,5},
    {"SPECIES PLANTARUM", "CARL LINNAEUS", 1753,5},
    {"PRIDE AND PREJUDICE","JANE AUSTEN",2709,5},
    {"ON MOTION","GALILEO GALILEI",1590,5},
    {"PERSUASION","JANE AUSTEN",3112,5},
    {"CONCEPT OF PHYSICS A", "H.C. VERMA", 3412,5},	
    {"CONCEPT OF PHYSICS B", "H.C. VERMA", 5648,5},
    {"CALCULUS", "THOMAS", 1112,5},
    {"DATASCIENCE", "JOEL", 9860,5},
    {"CLEANCODE", "ROBERT", 4723,5},
    {"SANDITON","JANE AUSTEN",1817,5},
    {"LADY SUSAN","JANE AUSTEN",1871,5},
    {"CONVERSATIONS WITH MYSELF","NELSON MANDELA",8888,5},
    {"THE STRUGGLE IS MY LIFE","NELSON MANDELA",7777,5},
    {"NO EASY WALK TO FREEDOM","NELSON MANDELA", 1965,5},
    {"A PRISONER IN THE GARDEN", "NELSON MANDELA",2005,5},
    {"LONG WALK TO FREEDOM", "NELSON MANDELA",1994,5},
    {"SRI RAMAKRISHNA","SWAMI VIVEKANANDA",4709,5},
    {"PACKING FOR MARS", "MARY ROACH", 2357,5},
    {"SPACE ACADEMY", "MARTIN BLOCK", 2110,5},
    {"THE HUBBLE COSMOS", "ROBERT SMITH", 1708,5},
    {"8000 THINGS YOU SHOULD KNOW", "BELINDA GALLAGHER", 3333,5},
    {"A HISTORY OF CRICKET","E.W. SWANTON", 9999,5},
    {"LET US C" , "YASHVANT KANETKAR", 2345,4},
    {"TWO NEW SCIENCES","GALILEO GALILEI",1638,5},
    {"OPERE", "GALILEO GALILEI", 1655,4}
    };

struct books_available_now                                                      //structure for displaying books available again
{
    char books_available[50];   
}now_books_available[50];

/*1*/ void display_books ();                              //function prototype declaration which display the current book info.
/*2*/ void display_books_author (char *);                 //function prototype declaration which display the book of given Author.
/*3*/ void display_books_book (char *);                   //function prototype declaration which display the book entered by user if available.
/*4*/ void display_books_issue_num (int);                 //function prototype declaration which display the book with given issue number.
/*5*/ void display_no_of_books (char *);                  //function prototype declaration which display no. of books left.
/*6*/ void issue_book (char *);                           //function to issue a specific book
/*7*/ void return_book (char *);                          //function to return a specific book
/*8*/ void display_books_2 ();                            //function prototype declaration which display the current book info.
/*9*/void order_available_books (char *);                 //function to order available books from vendor or request from libraries.
/*10*/void order_new_books();                             //function to order new books from vendors or request from libraries.
/*11*/void display_books_1 ();                            //funtion prototype declaration ehich display the current book info.
/*12*/void display_requests ();                           //function to accept the request of order of books using student menu.
/*13*/void add_start(char *r);                            //function to add a member at the starting of the list.
/*14*/void add_end(char *s);                              //function to add a member at the ending of the list.
/*15*/void display();                                     //function to display members of the library.
/*16*/void del_loc(struct mem **s, int loc);              //function to remove a member from the library.
/*17*/void add_to_issue_list(char *dk, char *mn);         //function to store details of members who have issued a book in the issuelist file.
/*18*/void display_members_issued();                      //function to display the members who have issued a book.
/*19*/void remove_from_issue_list(char *mn);              //function to remove details of members who have issued a book from the issuelist file.

int main ()
{
  char book_inp[50], author_inp[50], inputid[20], inputpwd[20], name_id_inp[50], member_name[50];
  int issue_inp, num_of_books_inp;
  int option, choose_bm, mainmenu, choose_bt, pick, pick_im, loc, t = 1, n = 1, m = 1, c = 1, f = 1;
  int option_vm, choose_student, choose_admin, b = 1, w = 1, y = 1;
  char admin_user[] = "adminuser", admin_pwd[] = "adminpwd", student_user[] = "studentuser", student_pwd[] = "studentpwd";  //default credentials for admin and user to access the vendor management menu.
  char adminid[20], adminpwd[20], studentid[20], studentpwd[20], book_inp1[50];
  char defid[] = "bitspilani", defpwd[] = "bitslms";	                        //default credentials for main login.
  char fname[] = {"issuelist.dat"};
  while (1)
    {
      printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
      printf ("::::::::            LIBRARY MANAGEMENT PORTAL           ::::::::\n");
      printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
      printf ("\n          Welcome to the library management portal\n");
      printf ("\n              * * * * * * * * * * * * * * * * *               \n");
      printf ("              *        NEWLY ADDED BOOKS      *               \n");
      printf ("              *                               *               \n");
      printf ("              * 1.OPERE                       *               \n");
      printf ("              * 2.TWO NEW SCIENCES            *               \n");
      printf ("              * 3.LET US C                    *               \n");
      printf ("              * 4.A HISTORY OF CRICKET        *               \n");
      printf ("              * 5.THE HUBBLE COSMOS           *               \n");
      printf ("              *                               *               \n");
      printf ("              * * * * * * * * * * * * * * * * *               \n");
      printf ("\n              * * * * * * * * * * * * * * * * *               \n");
      printf ("              *      BOOKS BACK IN STOCK      *               \n");
      for(int e=0; e<h-1; e++)
      { 
      printf ("              * %d. %s                        *                \n",e+1,now_books_available[e].books_available);
      }
      printf ("              * * * * * * * * * * * * * * * * *               \n");
      printf ("\n1. Login Page");
      printf ("\n2. Exit\n");
      printf("\n(Select a no. between 1&2 Only)\n");

      printf ("\n\nchoose any one of the above options : ");
      scanf ("%d", &option);
      switch (option)
	{
	case 1:
	  printf ("\nPlease fill in the login credentials to proceed\n");
	  printf ("\nUsername:");
	  scanf ("%s", inputid);
	  printf ("Password:");
	  scanf ("%s", inputpwd);
	  if (!strcmp (defid, inputid) && !strcmp (defpwd, inputpwd))
	    {
	      printf ("\nLogin successful!\n");
	      n--;
	      while (m)
		{
		  printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		  printf ("::::::::                    MAIN MENU                   ::::::::\n");
		  printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf ("\n      Welcome to the Library of ADHYAN AHUJA, BHAVYA PATEL\n");
		  printf ("                      and LAKSHIT GOEL                       \n");
		  printf ("\n1.Book Management");
		  printf ("\n2.Book Transaction");
		  printf ("\n3.Vendor Management");
		  printf ("\n4.Inventory Management");
		  printf ("\n5.User Management");
		  printf ("\n6.Exit LMS");
		  printf("\n(Select a no. between 1&6 Only)");
		  printf ("\n\nchoose any one of the above options : ");
		  scanf ("%d", &mainmenu);

		  switch (mainmenu)
		    {
		    case 1:                                                             //BOOK MANAGEMENT SYSTEM MENU

		      while (t)
			{
			  printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		      printf ("::::::::              BOOK MANAGEMENT MENU              ::::::::\n");
		      printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			  printf ("\n             Welcome to the book management system!\n");
			  printf ("\n1. Display Current Books.");
			  printf ("\n2. Search the book by Author Name.");
			  printf ("\n3. Search the book by Book name.");
			  printf ("\n4. Search the book by issue number.");
			  printf ("\n5. Exit Menu");
			  printf("\n(Select a no. between 1&5 Only)");
			  printf
			    ("\n\nchoose any one of the above options : ");
			  scanf ("%d", &choose_bm);
			  switch (choose_bm)
			    {


			    case 1:	                                                        //display Current books
			      display_books_1 ();
			      break;


			    case 2:	                                                        //searching the title using author name
			      printf ("Enter author name(IN CAPITALS) : ");
			      getchar ();
			      gets (author_inp);
			      display_books_author (author_inp);	                        //Passing character pointer to the function
			      break;


			    case 3:	                                                        //searching the title using book title
			      printf ("Enter Book name(IN CAPITALS): ");
			      getchar ();
			      gets (book_inp);
			      display_books_book (book_inp);	                            //Passing book name to the function.
			      break;


			    case 4:	                                                        //searching the title using issue number
			      printf ("Enter book issue number: ");
			      scanf ("%d", &issue_inp);
			      display_books_issue_num (issue_inp);
			      break;

			    case 5:
			      t--;
			      break;

			    default:
			      printf ("\n**Please select a valid option**\n");

			    }
			}
		      t++;
		      break;

		    case 2:                                                             //BOOK TRANSACTION MENU

		      while (t)
			{
			  printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		      printf ("::::::::             BOOK TRANSACTION MENU              ::::::::\n");
		      printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			  printf ("\n            Welcome to the book transaction system!\n");
			  printf ("\n1. Issue book by book name.");
			  printf ("\n2. Return book by book name.");
			  printf ("\n3. List of members who have issued a book");
			  printf ("\n4. Exit menu\n");
			  printf("\n(Select a no. between 1&4 Only)");
			  printf
			    ("\n\nchoose any one of the above options : ");
			  scanf ("%d", &choose_bt);
			  switch (choose_bt)
			    {

			    case 1:                                                         //issue book by book name
			      printf ("Enter Book name(IN CAPITAL): ");
			      getchar ();
			      gets (book_inp);
			      printf ("Enter member name(IN CAPITAL): ");
			      gets (member_name);
			      issue_book (book_inp);
			      add_to_issue_list(book_inp,member_name);
			      break;


			    case 2:                                                         //return book by book name
			      printf ("Enter Book name(IN CAPITAL): ");
			      getchar ();
			      gets (book_inp);
			      printf ("Enter member name(IN CAPITAL): ");
			      gets (member_name);
			      return_book (book_inp);
			      remove_from_issue_list(member_name);
			      break;
			      

                case 3:                                                         //display list of members who issued it
                display_members_issued();
                break;


			    case 4:
			      t--;
			      break;

			    default:
			      printf ("\n**Please select a valid option**\n");


			    }
			}
		      t++;
		      break;
		      
		      
		    case 3:                                                             //VENDOR MANAGEMENT MENU
		    while(b)
            {
               printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		       printf ("::::::::            VENDOR MANAGEMENT MENU              ::::::::\n");
		       printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
               printf ("\n           Welcome to the vendor management system\n");
               printf ("\n1.Login as student");                              //can be accessed by both admin and student credentials
               printf ("\n2.Login as admin (Restricted Access)");            //can be accessed by admin only
               printf ("\n3.Exit menu\n");
               printf("\n(Select a no. between 1&3 Only)");
               printf ("\n\nchoose any one of the above options : ");
               scanf ("%d", &option_vm);
               switch (option_vm)
               {
                  case 1: printf ("\nPlease fill in the login credentials as student to proceed\n");      //Login as student
	                      printf ("\nUsername:");
	                      scanf ("%s", studentid);
	                      printf ("Password:");
	                      scanf ("%s", studentpwd);
	                      if ((!strcmp (student_user, studentid) && !strcmp (student_pwd, studentpwd)) || (!strcmp(admin_user, studentid) && !strcmp (admin_pwd, studentpwd)))
	                      {
	                          printf ("\nLogin successful! Welcome to the Request for order placement menu\n");
	                          while(w)
                              {
                                  printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		                          printf ("::::::::      VENDOR MANAGEMENT: REQUEST FOR BOOKS      ::::::::\n");
		                          printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		                          printf ("\nPlace request to order a book of your choice.\n");
                                  printf ("\n1. Display Current books.");
	                              printf ("\n2. Request to Order available books by book name. ");
	                              printf ("\n3. Request to Order new books.");
	                              printf ("\n4. Exit menu\n");
	                              printf("\n(Select a no. between 1&4 Only)");
		
		                          printf ("\n\nchoose any one of the above options : ");
                                  scanf ("%d", &choose_student);
    
                                  switch (choose_student)
	                              {
	 
	                                 case 1:                                                                   //display Current books 
	                                 display_books_2 ();
	                                 break;
	 
	 
	                                 case 2:                                                                   //order available books
	                                 printf ("Enter book name(IN CAPITALS) : ");
	                                 getchar();
	                                 gets(book_inp1);
	                                 order_available_books (book_inp1);
 	                                 break;
	 
	 
	                                 case 3:	                                                                //order new books
                                     order_new_books ();                                          
                                     break;
      
      
                                     case 4:
	                                 w--;
	                                 break;
	                         
	                                 default: printf ("\n**Please select a valid option**\n");
                                   }
                              }
                              w++;
	                   
                           }
                           else
                           printf("\nInvalid credentials! You will be directed to the previous menu\n");
                           break;
                    
                    
                           case 2: printf ("\nPlease fill in the login credentials as admin to proceed\n");         //login as admin
	                       printf ("\nUsername:");
	                       scanf ("%s", adminid);
	                       printf ("Password:");
	                       scanf ("%s", adminpwd);
	                       if (!strcmp (admin_user, adminid) && !strcmp (admin_pwd, adminpwd))
	                       {
	                           printf ("\nLogin successful as admin!\n");
	                           while (y)
                               {
                                   printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		                           printf ("::::::::        VENDOR MANAGEMENT:ORDER PLACEMENT       ::::::::\n");
		                           printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		                           printf ("\nPlace orders to vendors and libraries as per the requests receieved.\n");
                                   printf ("\n1. Display books.");
                                   printf ("\n2. Accept requests to order to the vendor or request other libraries."); 
                                   printf ("\n3. Exit menu.\n");
                                   printf("\n(Select a no. between 1&3 Only)");
    
                                   printf ("\n\nchoose any one of the above options : ");
                                   scanf ("%d", &choose_admin);
                                   switch(choose_admin)    
                                   {
                                      case 1:
                                      display_books_1 ();                       //displays books in library
                                      break;
                             
                             
                                      case 2:                                                                   
	                                  display_requests ();                      //accepts the requests
	                                  break;  
	  
	  
	                                  case 3:
	                                  y--;
	                                  break;
	                         
	                                  default: printf ("\n**Please select a valid option**\n");
                                    }
                               }
                               y++;
	                       }   
                           else
                           printf("\nInvalid credentials! You will be directed to the previous menu\n");
                           break;
                       
                           case 3: b--;                                                        //Exit menu
                           break;
                    
                           default: printf ("\n**Please select a valid option**\n");
                    
	                   }
                    
                }
                b++;
                break;

		    case 4:                                                             //INVENTORY MANAGEMENT MENU
		    while(f)
	        { printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		      printf ("::::::::           INVENTORY MANAGEMENT MENU            ::::::::\n");
		      printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		      printf ("\n            Welcome to the inventory management menu\n");
		      printf ("\n1.Search the number of books in the library inventory for a particular title.\n");
		      printf ("2.Exit Menu\n");
		      printf ("\n(Select a number between 1&2 only)\n");
		      printf("\n\npick any one option from the following: ");
		      scanf ("%d",&pick_im);
		      switch(pick_im)
		      {
		            case 1:
		  	        printf ("\nEnter Book name(IN CAPITALS): ");
		            getchar ();
		            gets (book_inp);
		            display_no_of_books (book_inp);
		            break;
		            
		            case 2:
		            f--;
		            break;
		            
		            default: printf ("\n**Please select a valid option**\n");
		      }
	        }
	        f++;
	        break;

		    
		    case 5:                                                             //USER MANAGEMENT MENU
		    
		    start = NULL;
		    p = NULL;
		    add_start("LAKSHIT GOEL ");                                          //Existing members
            add_end("BHAVYA PATEL ");
            add_end("ADHYAN AHUJA ");
		    while(c)
		    {
		        printf ("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		        printf ("::::::::             USER MANAGEMENT MENU               ::::::::\n");
		        printf ("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		        printf ("\n            Welcome to the user management system\n");
		        printf("\n1.Display current members.\n");
		        printf("2.Add members to the library.\n");
                printf("3.Remove members from the library.\n");
                printf("4.Exit:\n");
                printf("\n(Select a no. between 1&4 Only)");
                printf("\n\npick any one option from the following: ");
                scanf("%d",&pick);
                
                switch(pick) 
                {
                    
                    case 1:
                    printf("\nHere is a list of all the members in the library\n");                 //displays current member
                    display();
                    break;
                    
                    case 2:
                    printf("\nEnter Name of the member to be added(IN CAPITALS): ");                //members needed to be added
                    getchar();
                    gets(name_id_inp);
                    add_end(name_id_inp);
                    printf("\nMember added successfully!\n");
                    break;
                    
                    
                    case 3:                                                                         //members needed to be removed
                    printf("\nEnter the serial number of the member to be removed(You can find the number by using display feature): ");
                    scanf("%d",&loc);
                    del_loc(&p,loc-1);
                    printf("\nMember removed successfully!\n");
                    break;
                    
                    case 4: c--;
                    break;
                    
                    default: printf("\n**Please choose a valid option**\n");
                    
                }
		    
		    }
		    c++;
		    break;
		    
		    
		    
		    case 6:                                                             //EXIT LMS
		      m--;
		      break;

		    default:
		      printf ("\n**Please select a valid option**\n");
		    }
		  
		}
		m++;
	    }
	  else
	    printf("\nInvalid credentials! You will be directed to the previous menu\n");//if invalid credentials
	  break;

	case 2:
	  printf ("Thank you for using the library management system");             // thank you note
	  exit (0);

	default:
	  printf ("\n**Please choose a valid option**\n");

	}

    }
  return 0;
}


/*1*/ void display_books ()		                                                //function which display the current book information
{
  static int i;
  for (i = 0; i < r - 1; i++)
    {
      printf ("\n%d. Book name: %s", i + 1, lib[i].book_name);
      printf ("\tAuthor name: %s", lib[i].author);
      printf ("\tIssue no.: %d", lib[i].issue_num);
      printf ("    No. of books: %d\n", lib[i].num_of_books);
    }
}



/*2*/ void display_books_author (char *at)                   //function to search the titles of all books written by that author
{
  static int i, k;
  int j = 0;
  char author_inp[50];

  for (k = 0; k < 50; k++)
    {
      author_inp[k] = *at;
      at++;
    }
  author_inp[k] = '\0';



  for (i = 0; i < r - 1; i++)
    {
      if (strcmp (author_inp, lib[i].author) == 0)
	{
	  printf ("\n%d. Book name: %s", i + 1, lib[i].book_name);
	  printf ("\tAuthor name: %s", lib[i].author);
	  printf ("\tIssue no.: %d", lib[i].issue_num);
	  printf ("    No. of books: %d\n", lib[i].num_of_books);
	  j = 1;
	}

    }

  if (j == 0)			                                                         // when book of input Author is not present.    
    printf ("Sorry! we don't have any book of %s", author_inp);
}

/*3*/ void display_books_book (char *bk)                    //function to display particular title by entering the books name
{
  static int i, k;
  int j = 0;
  char book_inp[50];

  for (k = 0; k < 50; k++)
    {
      book_inp[k] = *bk;
      bk++;
    }
  book_inp[k] = '\0';

  for (i = 0; i < r - 1; i++)
    {
      if (strcmp (book_inp, lib[i].book_name) == 0)
	{
	  printf ("\n%d. Book name: %s", i + 1, lib[i].book_name);
	  printf ("\tAuthor name: %s", lib[i].author);
	  printf ("\tIssue no.: %d", lib[i].issue_num);
	  printf ("    No. of books: %d\n", lib[i].num_of_books);
	  j = 1;
	}
    }

  if (j == 0)			                                                        // if searched book is not present
    printf ("Sorry! we don't have this(%s) book", book_inp);
}




/*4*/ void display_books_issue_num (int issue_inp)          //function to display book by searching using its issue number
{
  static int i;
  int j = 0;
  for (i = 0; i < r - 1; i++)
    {
      if (issue_inp == lib[i].issue_num)
	{
	  printf ("\n%d. Book name: %s", i + 1, lib[i].book_name);
	  printf ("\tAuthor name: %s", lib[i].author);
	  printf ("\tIssue no.: %d", lib[i].issue_num);
	  printf ("    No. of books: %d\n", lib[i].num_of_books);
	  j = 1;
	}
    }
  if (j == 0)
    printf ("Sorry! we don't have any book with this(%d) issue number",
	    issue_inp);
}


/*5*/ void display_no_of_books (char *ck)                   //function to count the total number of books of a particular title
{
  static int i, k;
  int j = 0;
  char book_inp[50];

  for (k = 0; k < 50; k++)
    {
      book_inp[k] = *ck;
      ck++;
    }
  book_inp[k] = '\0';

  for (i = 0; i < r - 1; i++)
    {
      if (strcmp (book_inp, lib[i].book_name) == 0)
	{
	  printf ("    No. of books: %d\n", lib[i].num_of_books);
	  j = 1;
	}
    }

  if (j == 0)			                                                        // if searched book is not present
    printf ("Sorry! we don't have this(%s) book", book_inp);
}

/*6*/ void issue_book (char *dk)                                                //function to issue a book 
{ 
  static int i, k;
  int j = 0, alert;
  char book_inp[50];

  for (k = 0; k < 50; k++)                                                      //book name input taken
    {
      book_inp[k] = *dk;
      dk++;
    }
  book_inp[k] = '\0';


  for (i = 0; i < r - 1; i++)
    {
      if (strcmp (book_inp, lib[i].book_name) == 0)                             //if the name entered matches any book in the database
	{
	  if (lib[i].num_of_books != 0)
	    {
	      lib[i].num_of_books = lib[i].num_of_books - 1;      //reduction in the value of number of copies in the book database
	      printf ("BOOK ISSUED!!\n");
	      printf ("\nPlease return the book in the next 15 days else you will have to pay a fine. You will be alerted a day before.\n");
	      printf ("\nNo. of books left: %d\n", lib[i].num_of_books);
	    }
	  else
	    {
	      printf("Sorry! book is currently unavailable!!\n",book_inp);
	      printf("\nDo you wish to be alerted when the book is available?\n");     //alert option
	      printf("\n1.Yes\n");
	      printf("2.No\n");
	      printf("\nChoose an option:");
	      scanf("%d",&alert);
	      switch(alert)
	      {
	          case 1: printf("\nYou will alerted when the book is available and it will also be displayed on the portal main page\n");
	                  break;
	                  
	          case 2: break;
	          
	          default : printf("\n**Choose a valid option\n**");
	      }
	    }

	  j = 1;
	}
    }

  if (j == 0)			                                                        // if searched book is not present
    printf ("Sorry! we don't have this(%s) book", book_inp);
}


/*7*/ void return_book (char *ek)                                               //function to return the issued book
{
  static int i, k;
  int j = 0;
  char book_inp[50];

  for (k = 0; k < 50; k++)                                                      //book name input taken
    {
      book_inp[k] = *ek;
      ek++;
    }
  book_inp[k] = '\0';

  for (i = 0; i < r - 1; i++)
    {
      if (strcmp (book_inp, lib[i].book_name) == 0)                             //if the name entered matches any book in the database
	{
	  lib[i].num_of_books = lib[i].num_of_books + 1;                            //addition of the book back in the database
	  printf ("No. of books: %d\n", lib[i].num_of_books);
	  j = 1;
	}
    }

  if (j == 0)			                                                        // if searched book is not present
    printf ("Sorry! we don't have this(%s) book", book_inp);
}

/*8*/ void display_books_2 ()                                                   //function to display book database after modification from the temporary database lib2                          
{
    static int i;
    for(i=0;i<s-1;i++)
    {
        printf("\n%d. Book name: %s",i+1,lib2[i].book_name);
        printf("\tAuthor name: %s",lib2[i].author);
        printf("\tIssue no.: %d",lib2[i].issue_num);
        printf("    No. of books: %d\n",lib2[i].num_of_books);
    }
}


/*9*/ void order_available_books (char *fk)                     //function to place request to order an existing book in the library if it is out of stock
{
   static int i,k,l,f;
    int j=0;
    char book_inp[50];
        for(k=0;k<50;k++)                                                       //book name input taken
    {
        book_inp[k]=*fk;
        fk++;
    }
    book_inp[k]='\0';
    
    for(i=0;i<s-1;i++)
    {
        if(strcmp(book_inp,lib2[i].book_name)==0)
        {
           for(f=h-1; f<h; f++)
           {
	            strcpy(now_books_available[f].books_available,book_inp);
            }
           h++;
           printf("Enter no. of books needed: ");
           scanf("%d",&l);
           lib2[i].num_of_books=lib2[i].num_of_books+l;
           printf("Request for no. of books: %d of %s is successfully recorded!!!\n",l,lib2[i].book_name);
           j=1;
        }
    }
    
    if(j==0)                                                // if searched book is not present
    printf("Sorry! we don't have this(%s) book",book_inp); 
}


/*10*/ void order_new_books()                //function to add a new book which previously did not exist in the database
{
     static int i;
        for(i=s-1;i<s;i++)
    {
        
    
            printf("Enter Book Name: (IN CAPITAL): ");
            getchar();
            gets(lib2[i].book_name);
            
        
            printf("Enter Author of %s (IN CAPITAL):",lib2[i].book_name);
            gets(lib2[i].author);
            
            
            printf("Enter issue No of %s:",lib2[i].book_name);                  //user should enter any 3 digit number so that it stays unique
            scanf(" %d",&lib2[i].issue_num);
            
            printf("No. of books %s:",lib2[i].book_name);
            scanf(" %d",&lib2[i].num_of_books);
            
            printf("Request for no. of books: %d of %s is successfully recorded!!!\n",lib2[i].num_of_books,lib2[i].book_name);
            
    }
         s++;
}

/*11*/ void display_books_1 ()               //function to display book database after modification from the main database lib                    
{
    static int i;
    for(i=0;i<r-1;i++)
    {
        printf("\n%d. Book name: %s",i+1,lib[i].book_name);
        printf("\tAuthor name: %s",lib[i].author);
        printf("\tIssue no.: %d",lib[i].issue_num);
        printf("    No. of books: %d\n",lib[i].num_of_books);
    }
}


/*12*/ void display_requests()                                 //function which accept the request of students and places the order to vendor 
{
    r=s;
    int z;
    for(z=0; z<70; z++)
    {
        lib[z].num_of_books=lib2[z].num_of_books ;  
    }
    if(r>71)
    {
        for(z=70;z<r-1; z++)
        {
            strcpy(lib[z].book_name,lib2[z].book_name);                 //book is added into the main database or if existing then the number of copies is modified
            strcpy(lib[z].author,lib2[z].author);
            lib[z].issue_num=lib2[z].issue_num;
            lib[z].num_of_books=lib2[z].num_of_books;
        }
    }
    else
    {
        return 0;
    }
    printf("Requested to other libraries and ordered from vendors.\nBooks successfully added to the library!!! ");
}

/*13*/void add_start(char *r)                                            //function to add an entry at the start of the linked list used in user management menu
{
    char str[50];
    int i=0;
    while(*r!='\0')
    {
        str[i]=*r;
        r++;
        i++;
    }
    struct mem *q=(struct mem *)malloc(sizeof(struct mem));
    strcpy(q->name_id,str);
    q->next=NULL;
    
    if(p==NULL)
    p=q;
    
    else
    {
        q->next=p;
        p=q;
    }
}

/*14*/void add_end(char *s)                           //function to add a member at the end of the linked list in user management
{
    char str[50];
    int i=0;
    while(*s!='\0')
    {
        str[i]=*s;
        s++;
        i++;
    }
     struct mem *q=(struct mem *)malloc(sizeof(struct mem));
     struct mem*w=p;
    strcpy(q->name_id,str);
    q->next=NULL;
    
    if(p==NULL)
    {
    p=q;
    start=q;
    }
    
    
    
      else
    {
        while(w->next!=NULL)
        w=w->next;
        w->next=q;
    
    }
    
    
}


/*15*/void display()                                          //function to display the linked list in user management
{
    struct mem *q;
    q=p;
    int i=0;
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            printf("\n%d.%s\n",i+1,q->name_id);
            q=q->next;
            i++;
        }
    }
    else
    {
        printf("The list is empty");
    }
}

/*16*/void del_loc(struct mem **s, int loc)                                //function to delete any member from the linked list in user management 
{ 
    
   if (*s == NULL)                                                         //if the linked list has no member
   return; 
  
    
   struct mem* temp = *s; 
  
     
   if (loc == 0)                                                           //to remove the first entry
    { 
        *s = temp->next;                                                   //first entry changed to next
        free(temp);                                                        //free older first entry                
        return; 
    } 
  
     
    for (int i=0; temp!=NULL && i<loc-1; i++)                              //searches for the node just previous to the node that is to be deleted
    temp = temp->next; 
  
    if (temp == NULL || temp->next == NULL)                                //incase the entry selected is greater than the total number of entries
    return; 
  

    struct mem *next = temp->next->next;                                   //temp->next is to be deleted 
    free(temp->next);                                                      //free the deleted entry from the memory
  
    temp->next = next;                                                     //deleted node is unlinked   
}

/*17*/void add_to_issue_list(char *dk, char *mn)                       //function to store the record of members along with book issued in a file
{
    static int k,j,i;
    char book_inp[50];
    for (k = 0; k < 50; k++)                                           //book issued record taken
    {
      book_inp[k] = *dk;
      dk++;
    }
    book_inp[k] = '\0';
  
    char member_name[50];
    for (j = 0; j < 50; j++)                                           //member name record taken
    {
      member_name[j] = *mn;
      mn++;
    }
    member_name[k] = '\0';
    
    char fname[] = {"issuelist.dat"};                                  //file used to store the record of issue of books
    
    FILE *fp;
    struct member_issue m1;
    for(i=0; i < r - 1; i++)
    {
        if(strcmp(book_inp,lib[i].book_name)==0)                       //to check if the book is present in the library
        {
        fp = fopen(fname ,"ab");                                       //file opened to store the data of the book and member
        strcpy(m1.mem_name,member_name);
        strcpy(m1.book_issued,book_inp);
        fwrite(&m1,sizeof(m1),1,fp);
        fclose(fp);                                                    //file closed
        break;
        }
    }
    return 0;
}

/*18*/ void display_members_issued()                                   //function to display the record of all people who have issued a book along with the book name
{
    char fname[] = {"issuelist.dat"};                                  //file in which data is stored
    FILE *fp;
    struct member_issue m2;
    fp = fopen(fname,"rb");                                            //file opened for reading
    if(fp==NULL)
    {
        printf("\nNo one has issued a book\n");
        return;
    }
    printf("\nList of all members who have issued\n");
    printf("Name            Book issued\n\n");
    
    while(1)                                                           //list of all members displayed
    {
        fread(&m2,sizeof(m2),1,fp);
        if(feof(fp))                                                   //loop will continue until it reaches the end of file and will break after that
        {
            break;
        }
        printf("%s\t",m2.mem_name);
        printf("%s\n\n",m2.book_issued);
    }
    fclose(fp);                                                        //file closed
}

/*19*/ void remove_from_issue_list(char *mn)                          //function to remove a member from the issue list once they have returned the book
{
    static int j;
    char member_name[50];
    for (j = 0; j < 50; j++)                                          //member name input taken
    {
      member_name[j] = *mn;
      mn++;
    }
    member_name[j] = '\0';
    
    char fname[]= {"issuelist.dat"};                                  //file in which data is stored
    FILE *fp,*fp1;                                                    //two files created as the new data will be saved in a temporary file and later copied back into the main file
    struct member_issue m1,m2;
    int check = 0, count = 0;
    
    fp=fopen(fname,"rb");
    fp1=fopen("temporary.dat","wb");
    if(fp==NULL)                                                     //if no one has issued a book
    {
        printf("\nNo one has issued a book at the moment\n");
        return;
    }
    while(1)
    {
        fread(&m1,sizeof(m1),1,fp);                                   //reading main file
        if(feof(fp))                                                  //loop continues till the end of the main file
        {
            break;
        }
        if(strcmp(m1.mem_name,member_name)==0)                        //if the name entered matches with a name in the issue list
        {
            check = 1;
        }
        else
        {
            fwrite(&m1,sizeof(m1),1,fp1);                             //new data with the removed entry moved to temporary file
        }
    }
    fclose(fp);
    fclose(fp1);
    if(check==0)                                                       //if the name entered doesnt match with a name in the issue list
    {
        printf("\nNo member with this name has issued a book\n");      //if the name entered does not match with the issued
        return 0;
    }
    else
    {
        fp=fopen(fname,"wb");
        fp1=fopen("temporary.dat","rb");
        while(1)
        {
            fread(&m1,sizeof(m1),1,fp1);
            if(feof(fp1))                                             //read till the end of file
            {
                break;
            }
            fwrite(&m1,sizeof(m1),1,fp);                              //data from the temporary file copied back into the main file
        }
    }
    fclose(fp);
    fclose(fp1);
}

