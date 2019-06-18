#include <iostream>
#include <fstream>
#include <cstdlib> // for system
#include <vector>
#include <string> //toupper

using namespace std;

void display_score();
int highest_score();
void update_score(string name,int score);

int main(){

	//var

	char start_option;
	string name;
	cout<<"Enter your name"<<endl;
	cin>>name;

	

	Home:
	system("clear");
	cout<<"Welcome "<<name<<" to C++ Quiz\n"<<endl;
	cout<<"\n> RULES:-\n";
	cout<<">total of 10 questions. Each right answer will be awarded 20 points\n";
	cout<<">You will be given 4 options and you have to press A, B ,C or D.\n";
	cout<<">No negative marking for wrong answers!\n\n\n";

	

	cout<<"\n\t\t > Press S to start the game";
    cout<<"\n\t\t > Press V to view the highest score  ";
    cout<<"\n\t\t > press Q to quit          \n ";
    
    cin>>start_option;
    start_option = toupper(start_option);
    
    //"V" gives error
    if(start_option == 'V'){
    	display_score();
    	goto Home;
    }
    
    else if(start_option == 'S'){



		srand(time(0));
		vector<int> check_repeat(30,0);
		

		string question;
		string answer;
		string category;
		char user_asnwer;
		int sports=0;
		int gk=0;
		int current_affairs =0;






		
















		int counter = 0;
		int score = 0;
		char hold;


		while(counter<10){
			
			int line_counter = 0;
			int rand_line = rand()%24;
			if(check_repeat[rand_line]==0){

				check_repeat[rand_line]=1;

				
				ifstream file("at.txt");
				while(rand_line!=line_counter){
					getline(file,question);
					getline(file,answer);
					getline(file,category);
					line_counter++;
				}

				getline(file,question);
				getline(file,answer);
				getline(file,category);

				system("clear");
				cout<<"Question Category: "<<category<<"      "<<"Question Number: "<<counter+1<<endl;
				cout<<question<<endl;
				cin>>user_asnwer;
				user_asnwer = toupper(user_asnwer);
				if(answer[0]==user_asnwer){
					system("clear");
					cout<<"\t\t\t  Congratulation You Nailed it!!!"<<endl;
					score+=20;
					cin>>(hold);
					if (category=="SPORTS")
						sports++;
					else if (category=="GK")
						gk++;
					else
						current_affairs++;
				}
				else{
					system("clear");
					cout<<"Question Category: "<<category<<"      "<<"Question Number: "<<counter+1<<endl;
					cout<<question<<endl;
					cout<<"Correct Answer : "<<answer<<endl;
					cin>>(hold);
				}

			
			counter++;
			}

		}
		system("clear");
		cout<<"\t\tCongratulations . You have completed the quiz!!\n\n";
	    if(score>=highest_score()){
	    	cout<<"\t\tYeppi! You did it!! You are the highest Scorer!!\n"<<endl;
	    	update_score(name,score);
	    }
	    cout<<"Your Score is: "<<score<<endl;
	    cout<<"\n\n";
	    cout<<"Category Wise Score -:"<<endl;
	    cout<<"\tSports  : "<<sports*20<<endl;
	    cout<<"\tGK  : "<<gk*20<<endl;
	    cout<<"\tCurrent Affairs  : "<<current_affairs*20<<endl;

	    cout<<"To play again press S to Quit press anyother Key "<<endl;
	    cin>>start_option;
	    start_option = toupper(start_option);
	    if(start_option=='S'){
	    	goto Home;
	    }
	    else
	    	exit(1);


	}
	else
		exit(1);


	return 0;

}


void display_score()

{
	ifstream file("highest_c++_score.txt");
	string name;
	string ch;
	int score;
	
	file >>name >>score;
	system("clear");
	cout<<name<<" has the heighest Score of "<<score<<endl;
	

	
   cout<<"Enter any key and hit Enter !!\n";
   cin>>ch;// left a space in starting --otherwise it wasn't reading input

}

int highest_score()
{   
    int score;
    string name;
    ifstream file("highest_c++_score.txt");
    file>>name>>score;
    return score;
}

void update_score(string name,int score)
{
	ofstream file("highest_c++_score.txt");
	file<<name<<" "<<score;
	
}