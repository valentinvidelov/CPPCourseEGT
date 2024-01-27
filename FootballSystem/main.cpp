#include "User.h"
#include "Teams.h"
#include "Administration.h"


int main(){

    User user1("user1 name", "pw123");
    cout << user1.getPW() << endl;
    Teams team1("los locos", "Mexico City");
    cout << team1.getPoints() << endl;
    Teams team2("united", "Manchester");
    Teams team3("Inter", "Milano");
    Teams t4("los locos", "Panama city");
    Administration a1("admname", "admPW");
    cout << a1.getTeams().size() << endl;
    a1.addTeam(team1);
    a1.addTeam(team2);
    a1.addTeam(team3);
    cout << a1.getTeams().size() << endl;

    a1.removeTeam(team2);
    cout << a1.getTeams().size() << endl;
    a1.updateTeam(t4);
    for (int i=0; i<a1.getTeams().size(); i++){
        cout << a1.getTeams().at(i).getName() << " " <<  a1.getTeams().at(i).getCity() << endl;
    }

    return 0;
}