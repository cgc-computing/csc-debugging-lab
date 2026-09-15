// ticket.cpp
// Issues numbered help-desk tickets. Each new Ticket receives the next
// sequential ID, and the class keeps a running count of tickets issued.
#include <iostream>
#include <string>
using namespace std;

class Ticket {
private:
    int ticketsIssued = 0;
    int id;
    string subject;

public:
    Ticket(string subject) {
        ticketsIssued++;
        id = ticketsIssued;
        this->subject = subject;
    }

    int getId() { return id; }
    string getSubject() { return subject; }
    int getTicketsIssued() { return ticketsIssued; }
};

int main() {
    Ticket t1("Printer jam in room 204");
    Ticket t2("Password reset");
    Ticket t3("Monitor flickers");

    cout << "#" << t1.getId() << ": " << t1.getSubject() << endl;
    cout << "#" << t2.getId() << ": " << t2.getSubject() << endl;
    cout << "#" << t3.getId() << ": " << t3.getSubject() << endl;
    cout << "Tickets issued so far: " << t3.getTicketsIssued() << endl;
    return 0;
}
