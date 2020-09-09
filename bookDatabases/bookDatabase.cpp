

#include "cmpt_error.h"    // These are the only permitted includes!
#include "rand_book.cpp"
#include <iostream>        // Don't include anything else.
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <cassert>
#include <fstream>

using namespace std;

// //
// // ... write your code here here ...
// //
// //-----------------------------------------------------


class bookDatabase{

private:
  string class_name;
  int size;
  int Capacity;
  vector<string>  Title ;
  vector<string>  Author ;
  vector<int>  Date  ;
  vector<string>  Booktype  ;
  vector<string>  ISBN  ;
  vector<int>  NumOfPages  ;
public:
    bookDatabase();
    void insert(Book b);
    vector<int> search(const string& s);
    vector<int> search(const int& s);
    void updateTitle(const string& s,const int& i);
    void updateAuthor(const string& s,const int& i);
    void updateBooktype(const string& s,const int& i);
    void updateISBN(const string& s,const int& i);
    void updateDate(const int& s,const int& i);
    void updateNumOfPages(const int& s,const int& i);
    void deletedd( Book b) ;
    void print_database()const;
    void output_database ()const;
    void output_database2 ()const;

    void print_search(const vector<int> it);

};

void bookDatabase::updateTitle(const string& s,const int& i){
  this->Title[i] = s;
}
void bookDatabase::updateAuthor(const string& s,const int& i){
  this->Author[i] = s;
      
}
void bookDatabase::updateBooktype(const string& s,const int& i){
  this->Booktype[i] = s;   
}
void bookDatabase::updateISBN(const string& s,const int& i){
  this->ISBN[i] = s;    
}
void bookDatabase::updateDate(const int& s,const int& i){
  this->Date[i] = s;  
}
void bookDatabase::updateNumOfPages(const int& s,const int& i){
  this->NumOfPages[i] = s;    
}

bookDatabase::bookDatabase(){
  class_name = "bookDatabase";
  size = 0;
  Capacity = 1000;

}
void bookDatabase::insert( Book b){
  if(size < Capacity){
    this->Title.push_back(b.title);
    this->Author.push_back(b.author);
    this->Date.push_back(b.year);
    this->Booktype.push_back(b.type);
    this->ISBN.push_back(b.isbn10);
    this->NumOfPages.push_back(b.pages);
    this->size++;
  }
}
void bookDatabase::deletedd(Book b){
  //vector<int>::iterator it = find(ISBN.begin(), ISBN.end(), b.isbn10);

  int it;
  for(int i = 0; i <ISBN.size();i++){
    if(ISBN[i] ==  b.isbn10)
      it = i;
  }

  //cout<<it<<endl;
  if(size < Capacity && size > 0){
      this->Title.erase(Title.begin()+it);
      this->Author.erase(Author.begin()+it);
      this->Date.erase(Date.begin()+it);
      this->Booktype.erase(Booktype.begin()+it);
      this->ISBN.erase(ISBN.begin()+it);
      this->NumOfPages.erase(NumOfPages.begin()+it);
      this->size--;
    
  }
}
vector<int> bookDatabase::search(const string& s){

   vector<int> it;
  for(int i = 0; i <ISBN.size();i++){
    if(ISBN[i] ==  s)
      it.push_back(i);
    else if(Title[i] ==  s)
      it.push_back(i);
    else if (Author[i] == s)
      it.push_back(i);
    else if(Booktype[i] ==  s)
      it.push_back(i);
  }
  return it;

}

vector<int> bookDatabase::search(const int& s){

   vector<int> it;
  for(int i = 0; i <NumOfPages.size();i++){
    if(Date[i] ==  s)
      it.push_back(i);
    else if(NumOfPages[i] ==  s)
      it.push_back(i);
  }
  return it;

}

void bookDatabase::print_search(const vector<int> it){
  cout << "========================================================================================================="<<endl;
  cout << "                    "<<"Title"<<"                      |   "<<"Author"<<"  |  "<<"Year"<< "  |  " << "Book type" << "  |  "<< "ISBN"<<"  |  "<<"Pages"<<endl<<endl;
  cout << "---------------------------------------------------------------------------------------------------------"<<endl;
  for(int i = 0;i < it.size();i++){
    if(this->Title[it[i]].size()<= 48){
    int l = 48- this->Title[it[i]].size();
    cout << this->Title[it[i]];
    for (int j = 0; j < l; ++j){
      cout << " ";
    }
  }
    if(this->Author[it[i]].size()<= 20){
      cout<<"| "<<this->Author[it[i]];
      int l = 20 - this->Author[it[i]].size();
    for (int j = 0; j < l; ++j)
      cout << " ";
    }
    cout<<"|"<< this->Date[it[i]]<< " | " ;
   if(this->Booktype[it[i]].size()<= 9){
    cout << this->Booktype[it[i]];
    int l = 9 - this->Booktype[it[i]].size();
    for (int j = 0; j < l; ++j)
      cout << " ";
  }
    cout<< "| "<< this->ISBN[it[i]]<<" | "<<this->NumOfPages[it[i]] << endl;
    cout << "---------------------------------------------------------------------------------------------------------"<<endl;
  }
  cout << "========================================================================================================="<<endl;
}


void bookDatabase::output_database ()const{
  ofstream outfile;
  outfile.open("search_and_update_demo.txt");
  outfile << "========================================================================================================="<<endl;
  outfile << "                    "<<"Title"<<"                      |   "<<"Author"<<"  |  "<<"Year"<< "  |  " << "Book type" << "  |  "<< "ISBN"<<"  |  "<<"Pages"<<endl<<endl;
  outfile << "---------------------------------------------------------------------------------------------------------"<<endl;
  for(int i = 0;i < size;i++){
    if(this->Title[i].size()<= 48){
    int l = 48- this->Title[i].size();
    outfile << this->Title[i];
    for (int j = 0; j < l; ++j){
      outfile << " ";
    }
  }
    if(this->Author[i].size()<= 20){
      outfile<<"| "<<this->Author[i];
      int l = 20 - this->Author[i].size();
    for (int j = 0; j < l; ++j)
      outfile << " ";
    }
    outfile<<"|"<< this->Date[i]<< " | " ;
   if(this->Booktype[i].size()<= 9){
    outfile << this->Booktype[i];
    int l = 9 - this->Booktype[i].size();
    for (int j = 0; j < l; ++j)
      outfile << " ";
  }
    outfile<< "| "<< this->ISBN[i]<<" | "<<this->NumOfPages[i] << endl;
    outfile << "---------------------------------------------------------------------------------------------------------"<<endl;
  }
  outfile << "========================================================================================================="<<endl;
  outfile.close();

}

void bookDatabase::output_database2 ()const{
  ofstream outfile;
  outfile.open("delete_demo.txt",ios::app);
  outfile << "========================================================================================================="<<endl;
  outfile << "                    "<<"Title"<<"                      |   "<<"Author"<<"  |  "<<"Year"<< "  |  " << "Book type" << "  |  "<< "ISBN"<<"  |  "<<"Pages"<<endl<<endl;
  outfile << "---------------------------------------------------------------------------------------------------------"<<endl;
  for(int i = 0;i < size;i++){
    if(this->Title[i].size()<= 48){
    int l = 48- this->Title[i].size();
    outfile << this->Title[i];
    for (int j = 0; j < l; ++j){
      outfile << " ";
    }
  }
    if(this->Author[i].size()<= 20){
      outfile<<"| "<<this->Author[i];
      int l = 20 - this->Author[i].size();
    for (int j = 0; j < l; ++j)
      outfile << " ";
    }
    outfile<<"|"<< this->Date[i]<< " | " ;
   if(this->Booktype[i].size()<= 9){
    outfile << this->Booktype[i];
    int l = 9 - this->Booktype[i].size();
    for (int j = 0; j < l; ++j)
      outfile << " ";
  }
    outfile<< "| "<< this->ISBN[i]<<" | "<<this->NumOfPages[i] << endl;
    outfile << "---------------------------------------------------------------------------------------------------------"<<endl;
  }
  outfile << "========================================================================================================="<<endl;
  outfile.close();

}

void bookDatabase::print_database()const{
  cout << "========================================================================================================="<<endl;
  cout << "                    "<<"Title"<<"                        |  "<<"Author"<<"  |  "<<"Year"<< "  |  " << "Book type" << "  |  "<< "ISBN"<<"  |  "<<"Pages"<<endl<<endl;
  cout << "---------------------------------------------------------------------------------------------------------"<<endl;
  for(int i = 0;i < size;i++){
    if(this->Title[i].size()<= 48){
    int l = 48- this->Title[i].size();
    cout << this->Title[i];
    for (int j = 0; j < l; ++j){
      cout << " ";
    }
  }
    if(this->Author[i].size()<= 20){
      cout<<"| "<<this->Author[i];
      int l = 20 - this->Author[i].size();
    for (int j = 0; j < l; ++j)
      cout << " ";
    }
    cout<<"|"<< this->Date[i]<< " | " ;
   if(this->Booktype[i].size()<= 9){
    cout << this->Booktype[i];
    int l = 9 - this->Booktype[i].size();
    for (int j = 0; j < l; ++j)
      cout << " ";
  }
    cout<< "| "<< this->ISBN[i]<<" | "<<this->NumOfPages[i] << endl;
    cout << "---------------------------------------------------------------------------------------------------------"<<endl;
  }
  cout << "========================================================================================================="<<endl;
}


int main() {
  cout << "----------------------------"<<endl;
  cout << "Please choose the demos" << endl;
  cout << "1. Delete demos."<<endl;
  cout << "2. Search and update demos." << endl;
  cout << "----------------------------"<<endl;
  cout << "Please enter 1 or 2:";

  string flag;
  getline(cin,flag);

  if(flag == "1"){

  cout << "-------------------------"<<endl;
  cout << "Delete demo: "<<endl;
  srand(time(NULL));
  Book a1 = rand_book();
  Book c1 = rand_book();
  bookDatabase b1;
  b1.insert(a1);
  b1.insert(c1);
  for(int i = 0; i < 1; i ++){
    b1.insert(rand_book());
  }
  b1.output_database2();
  b1.print_database();
  cout << "-------------------------"<<endl;
  cout << "\nDelete first one: "<<endl<<endl;
  b1.deletedd(a1);
  b1.output_database2();
  b1.print_database();
  cout << "-------------------------"<<endl;
  cout << "\nDelete second one: "<<endl<<endl;
  b1.deletedd(c1);
  b1.print_database();
  cout << "\n\nSaving the dateBase to txt file named (delete_demo.txt).\n\n"<<endl;
  b1.output_database2();


}


  else if(flag == "2"){



    srand(time(NULL));
    bookDatabase dateBase;
    int a = 0;
    string num;
    cout << endl<<endl<<endl;

    cout << "----------------------------"<<endl;
    cout << "Please create your dateBase."<<endl;
    cout <<"1.Insert 10 random books."<<endl;
    cout <<"2.Insert 100 random books."<<endl;
    cout << "3.Exit."<<endl;
    cout << "----------------------------"<<endl;
    cout << "Please input 1 , 2 or 3: ";


    getline(cin,num);

    if(num == "1")
    {
      a = 10;
 
    }
    else if(num == "2")
    {
      a = 100;
    
    }
    else if(num == "3")
    {
      return 0;
    }
    else{
      cout << "\n\n Please enter right number and run again."<<endl;
      return 0;
    }
    for(int i = 0; i < a; i ++){ 
      dateBase.insert(rand_book());
    }

    dateBase.print_database();
    dateBase.output_database();

    while(1){
      cout << "----------------------------"<<endl;
      cout << "What do you want yo do ?"<<endl;
      cout <<"1.Search somethings."<<endl;
      cout << "2.update somethings."<<endl;
      cout << "3.Cheackout dateBase so far."<<endl;
      cout << "4.Print the dateBase to txt file." << endl;
      cout << "----------------------------"<<endl;
      cout << "Input 1, 2, 3 or 4:" <<endl;

 

      getline(cin,num);
      if(num == "1")
      {
        cout << "What's your searching?"<< endl;
        cout << "1.searching by Title,Author,Book type or ISBN"<< endl;
        cout << "2.searching by Date or pages."<< endl;

        cout << "Input 1 or 2:";

        string num2;

        getline(cin,num2);
        if(num2 == "1"){

          cout << "Input your Title, Author ,Book type or ISBN:";

          string input;
          //cin>>input;
          getline(cin,input);
          //cout << input;
          vector<int> see = dateBase.search(input);
          if(see.size() == 0)

            {cout << "No results."<<endl;}
          else{
            cout <<endl;
            cout << "Find results!"<<endl;
            dateBase.print_search(see);
          }
        } 
          else if(num2 == "2"){


          cout << "Input your Date or pages:";
    
          int num3;
          cin >> num3;
          //cout << input;
          vector<int> see = dateBase.search(num3);
          if(see.size() == 0)
            {cout << "No results."<<endl;}
          else{

            cout <<endl;
            cout << "Find results!"<<endl;
            dateBase.print_search(see);
           }
          }       
        } 


  else if(num == "2"){

    cout << "What's your upadating?"<< endl;
    cout << "You need select one line by ISBN. "<< endl;

    
    cout << "Input your ISBN:";

    string input;
    //cin>>input;
    getline(cin,input);
    //cout << input;
    vector<int> see = dateBase.search(input);
    if(see.size() == 0)
      {cout << "No results."<<endl;}
    else{
      cout <<endl;
      cout << "Find result!"<<endl;
      dateBase.print_search(see);

      cout << "Which element do you want to update?"<<endl;
      cout << "Input your element(Title,Author,Year,Book type,ISBN,Pages): ";
      string input2;
      getline(cin,input2);
      if(input2 == "Title"){
        cout << "Input your new value: ";
        string input3;
        getline(cin,input3);
        dateBase.updateTitle(input3,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);
      }
      else if(input2 == "Author"){
        cout << "Input your new value: ";
        string input4;
        getline(cin,input4);
        dateBase.updateAuthor(input4,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);       
      }
      else if(input2 == "Book type"){
        cout << "Input your new value: ";
        string input5;
        getline(cin,input5);
        dateBase.updateBooktype(input5,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);       
      }
      else if(input2 == "ISBN"){
        cout << "Input your new value: ";
        string input6;
        getline(cin,input6);
        dateBase.updateISBN(input6,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);       
      }
      else if(input2 == "Year"){
        cout << "Input your new value: ";
        string input7;
        getline(cin,input7);
        int temp = std::stoi(input7);
        dateBase.updateDate(temp,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);       
      }
      else if(input2 == "Pages"){
        cout << "Input your new value: ";
        string input8;
        getline(cin,input8);
        int temp = std::stoi(input8);
        dateBase.updateNumOfPages(temp,see[0]);
        cout << "\nUpdate successfully!"<<endl;
        dateBase.print_search(see);       
      }
      else{
        cout << "\n\n Please enter right number and run again."<<endl;
        break;
      }


    }

  }

  else if(num == "3"){
    dateBase.print_database();

  }
   else if(num == "4"){
    cout << "Saving the dateBase to txt file(search_and_update_demo.txt)."<<endl;
    dateBase.output_database();
  }
  cout << "Continue? [N or Y]: ";
  string num4;
  getline(cin, num4);
  if(num4 != "Y")
    {break;}
}

}



return 0;


}