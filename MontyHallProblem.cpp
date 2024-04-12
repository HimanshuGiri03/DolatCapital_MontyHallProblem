#include<bits/stdc++.h>
using namespace std;

pair<double,double> MontyHallProblemWithSimulation(int num_doors, int num_doors_opened_by_host, int num_simulations){
    int wins_by_staying_at_the_same_door=0;
    int wins_by_switching_the_door=0;
    
    //Random Number Generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,num_doors);

    for(int i=0;i<num_simulations;i++){
        //Randomly assigning prize behind one of the doors
        int prize_door=dis(gen);
        int initial_choice=dis(gen); 

        //Host Opens the doors revealing non prize doors
        vector<int> remaining_doors;
        for(int j=1;j<=num_doors;j++){
            if(j!=prize_door && j!=initial_choice){
                remaining_doors.push_back(j);
            }
        }
        shuffle(remaining_doors.begin(), remaining_doors.end(), gen);
        vector<int> doors_opened_by_host(remaining_doors.begin(),remaining_doors.begin()+num_doors_opened_by_host);

        //Contestant switches there choice
        remaining_doors.clear();

        for(int j=1;j<=num_doors;j++){
            if(j!=initial_choice && find(doors_opened_by_host.begin(),doors_opened_by_host.end(),j)==doors_opened_by_host.end()){
                remaining_doors.push_back(j);
            }
        }
        shuffle(remaining_doors.begin(), remaining_doors.end(), gen);

        int switched_choice=remaining_doors.front();

        //Checking if contestant wins by sticking or switching the door
        if(initial_choice==prize_door){
            wins_by_staying_at_the_same_door++;
        }
        if(switched_choice==prize_door){
            wins_by_switching_the_door++;
        }
    }

    //Calculating win percentages in both cases
    double win_percentage_by_staying_at_the_same_door=(static_cast<double>(wins_by_staying_at_the_same_door)/num_simulations)*100;
    double win_percentage_by_switching_the_door=(static_cast<double>(wins_by_switching_the_door)/num_simulations)*100;

    return {win_percentage_by_staying_at_the_same_door, win_percentage_by_switching_the_door};
}

int main(int argc, char* argv[]){
    int num_doors, num_doors_opened_by_host, num_simulations;
    cin>>num_doors>>num_doors_opened_by_host>>num_simulations;

    pair<double,double> answer=MontyHallProblemWithSimulation(num_doors, num_doors_opened_by_host, num_simulations);

    cout<<"Win percentage by staying at the same door: "<<answer.first<<"\n";
    cout<<"Win percentage by switching the door: "<<answer.second<<"\n";

    return 0;
}