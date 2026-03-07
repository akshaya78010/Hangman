#include<bits/stdc++.h>
using namespace std;
    
    vector<string>words = {"steveharrington"};

    void print_hangman(int state){
        if(state == 0){
            cout<<"You are still alive"<<'\n';
        }
        else if(state == 1){
            cout<<"4 takes to go.."<<'\n';
            cout<<"   |   "<<'\n';
            cout<<"   O   "<<'\n';
            cout<<"   |   "<<'\n';
        }
        else if(state == 2){
            cout<<"3 takes to go.."<<'\n';
            cout<<"   |   "<<'\n';
            cout<<"   O   "<<'\n';
            cout<<" \\\\    "<<'\n';
            cout<<"   |   "<<'\n';
        }
        else if(state == 3){
            cout<<"2 takes to go.."<<'\n';
            cout<<"   |   "<<'\n';
            cout<<"   O   "<<'\n';
            cout<<" \\\\ // "<<'\n';
            cout<<"   |   "<<'\n';
        }
        else if(state == 4){
            cout<<"1 takes to go.."<<'\n';
            cout<<"   |   "<<'\n';
            cout<<"   O   "<<'\n';
            cout<<" \\\\ // "<<'\n';
            cout<<"   |   "<<'\n';
            cout<<" //    "<<'\n';
        }
        else if(state == 5){
            cout<<"You lost.."<<'\n';
            cout<<"   |   "<<'\n';
            cout<<"   O   "<<'\n';
            cout<<" \\\\ // "<<'\n';
            cout<<"   |   "<<'\n';
            cout<<" // \\\\ "<<'\n';
        }
    }

    string give_word(){
        srand(time(0));
        int index = rand() % words.size();
        return words[index];
    }

int main(){
    int state = 0;
    string word_to_predict = give_word();
    string word_predicted_till_now = "";

    int current_index = 0;
    while(state < 5 && word_to_predict != word_predicted_till_now){
        cout<<"Guess an alphabet dude! : "<<'\n';
        char ch;
        cin>>ch;

        if(ch == word_to_predict[current_index]){
            word_predicted_till_now += ch;
        }
        else{
            state+=1;
            print_hangman(state);
        }
        current_index +=1;
    }
    
    if(word_to_predict == word_predicted_till_now){
    	cout<<"You got it Dude!"<<'\n';
	}
	if(word_to_predict != word_predicted_till_now && state == 5){
		cout<<word_to_predict<<'\n';
	}
}
