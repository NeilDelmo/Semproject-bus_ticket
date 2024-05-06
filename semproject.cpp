#include <iostream>
#include <map>
#include <iomanip>

const int ROWS=10;
const int COL=4;

struct Bus {
    char seat[ROWS][COL];
};

class Node {
public:
    std::string place_name;
    int value;
    Node*next;

    Node(std::string name, int val, Node* next) : place_name(name), value(val), next(next) {}
    ~Node() {
        delete next;
    }

};

void display_route(Node*n) {
    while(n!=NULL) {
        std::cout<<n->place_name<<" - ";
        std::cout<<n->value<<" km "<<'\n';
        n=n->next;
    }
}

void display_seat(Bus& bus) {
    int occupied = 0;
    std::cout << "Bus seat: \n";
    std::cout << "V=Vacant/X=Occupied\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (j % 2 == 0) {
                std::cout << "[";
            }
            std::cout << bus.seat[i][j] << "]";
            if (j % 2 == 1) {
                std::cout << " ";
            }
            if (bus.seat[i][j] == 'X') {
                occupied++;
            }
        }
        std::cout << "\n";
    }
    if (occupied == ROWS * COL) {
        std::cout << "Bus is full! Go to another bus\n";
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COL; ++j) {
                bus.seat[i][j] = 'V';
            }
        }
    }
}

bool select_seat(Bus& bus, int row, int col) {
    if (bus.seat[row][col] == 'V') {
        bus.seat[row][col] = 'X';
        std::cout << "Seat successfully reserved!\n";
        return true;
    } else {
        std::cout << "Seat already occupied. Please select another seat.\n";
        return false;
    }
}

void delete_seat(Bus&bus) {
    int row, col;
    std::cout << "Enter row and column for the seat \n";
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Column: ";
    std::cin >> col;

    if(row >0 && row <=ROWS && col >0 && col <= COL) {
        if(bus.seat[row-1][col-1] == 'X') {
            bus.seat[row-1][col-1] = 'V';
            std::cout<<"Seat "<<"r"<<row<<"c"<<col<<" has been Deleted.\n";

        } else {
            std::cout << "Seat already vacant!\n";
        }
    } else {
        std::cout<<"Invalid seat";
    }
}

void company() {
    std::cout<<"==============================";
    std::cout<<"|     DOWG'S BUS COMPANY     |";
    std::cout<<"==============================\n\n";
}

int main() {
    int row;
    int col;
    std::string from;
    std::string stop;
    int route;
    Bus buses[5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COL; k++) {
                buses[i].seat[j][k] = 'V';
            }
        }
    }

    do {
        company();

        std::cout<<"Select the Route(1-5): ";
        std::cin>>route;

        Node* head = nullptr;
        Node** current = &head;

        switch (route) {
        case 1:
            *current = new Node("Station", 0, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Uno", 3, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Dos", 10, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tres", 20, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Kuwatro", 30, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Singko", 40, nullptr);
            break;
        case 2:
            *current = new Node("Station", 0, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tinitigan", 3, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nakachat", 10, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Lambingan", 20, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagmahalan", 30, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagingsila", 40, nullptr);
            break;
        case 3:
            *current = new Node("Station", 0, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umibig", 3, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umasa", 10, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Pinaglalaruan", 20, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Iniwan", 30, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nasaktan", 40, nullptr);
            break;
        case 4:
            *current = new Node("Station", 0, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Bumangon", 3, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tumayo", 10, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Naglakad", 20, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umupo", 30, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagcode", 40, nullptr);
            break;
        case 5:
            *current = new Node("Station", 0, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Masaya", 3, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Malungkot", 10, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tamad", 20, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Takot", 30, nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Gutom", 40, nullptr);
            break;
        default:
            std::cout<<"Invalid route number!"<<std::endl;
        }
        std::string action;
        std::cout<< "what to do(add/delete/display): ";
        std::cin>>action;

        std::cout << std::fixed << std::setprecision(2);
        display_route(head);
        if(route==1 && action=="add") {

            std::map<std::string,float>bus_stops;
            bus_stops["Station"]=0.00;
            bus_stops["Uno"]=12.00;
            bus_stops["Dos"]=24.00;
            bus_stops["Tres"]=49.00;
            bus_stops["Kuwatro"]=70.00;
            bus_stops["Singko"]=90.00;

            do {
                std::cout<<"Select where from: ";
                std::cin>>from;
                std::cout<<"Select where to stop: Barangay ";
                std::cin>>stop;
            } while(bus_stops[from]>bus_stops[stop]);
            float price=bus_stops[stop]-bus_stops[from];

            display_seat(buses[route-1]);
            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route-1],row-1,col-1);


            std::cout<<"passenger type: \n";
            std::cout<<"[1] Regular \t [3] Student\n";
            std::cout<<"[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout<<"Enter the number: ";
            std::cin>>type;

            switch (type) {
            case 2:
            case 3:
            case 4:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Raulo\n";
                std::cout<<"Conductor: Raul\n";
                std::cout<<"Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The price of the ticket is "<<price*.90<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            case 1:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Raulo\n";
                std::cout<<"Conductor: Raul\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The regular price of the ticket is "<<price<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            default:
                std::cout<<"Error type! \n";
                break;
            }
        }

        if(route==2 && action=="add") {
            std::map<std::string, float>bus_stops;
            bus_stops["Station"]=0.00;
            bus_stops["Tinitigan"]=12.00;
            bus_stops["Nakachat"]=24.00;
            bus_stops["Lambingan"]=49.00;
            bus_stops["Nagmahalan"]=70.00;
            bus_stops["Nagingsila"]=90.00;

            do {
                std::cout<<"Select where from: ";
                std::cin>>from;
                std::cout<<"Select where to stop: Barangay ";
                std::cin>>stop;
            } while(bus_stops[from]>bus_stops[stop]);

            float price=bus_stops[stop]-bus_stops[from];
            display_seat(buses[route-1]);
            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route-1],row-1,col-1);

            std::cout<<"passenger type: \n";
            std::cout<<"[1] Regular \t [3] Student\n";
            std::cout<<"[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout<<"Enter the number: ";
            std::cin>>type;

            switch (type) {
            case 2:
            case 3:
            case 4:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Cigeh\n";
                std::cout<<"Conductor: Yosi\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The price of the ticket is "<<price*.90<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            case 1:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Cigeh\n";
                std::cout<<"Conductor: Yosi\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The regular price of the ticket is "<<price<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            default:
                std::cout<<"Error type! \n";
            }
        }
        if(route==3 && action=="add") {
            std::map<std::string, float>bus_stops;
            bus_stops["Station"]=0.00;
            bus_stops["Umibig"]=12.00;
            bus_stops["Umasa"]=24.00;
            bus_stops["Pinaglalaruan"]=49.00;
            bus_stops["Iniwan"]=70.00;
            bus_stops["Nasaktan"]=90.00;

            do {
                std::cout<<"Select where from: ";
                std::cin>>from;
                std::cout<<"Select where to stop: Barangay ";
                std::cin>>stop;
            } while(bus_stops[from]>bus_stops[stop]);

            float price=bus_stops[stop]-bus_stops[from];
            display_seat(buses[route-1]);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route-1],row-1,col-1);

            std::cout<<"passenger type: \n";
            std::cout<<"[1] Regular \t [3] Student\n";
            std::cout<<"[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout<<"Enter the number: ";
            std::cin>>type;

            switch (type) {
            case 2:
            case 3:
            case 4:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Jaja\n";
                std::cout<<"Conductor: Jeje\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The price of the ticket is "<<price*.90<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            case 1:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Jaja\n";
                std::cout<<"Conductor: Jeje\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The regular price of the ticket is "<<price<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            default:
                std::cout<<"Error type! \n";
            }
        }
        if(route==4 && action=="add") {
            std::map<std::string, float>bus_stops;
            bus_stops["Station"]=0.00;
            bus_stops["Bumangon"]=12.00;
            bus_stops["Tumayo"]=24.00;
            bus_stops["Naglakad"]=49.00;
            bus_stops["Umupo"]=70.00;
            bus_stops["Nagcode"]=90.00;

            do {
                std::cout<<"Select where from: ";
                std::cin>>from;
                std::cout<<"Select where to stop: Barangay ";
                std::cin>>stop;
            } while(bus_stops[from]>bus_stops[stop]);

            float price=bus_stops[stop]-bus_stops[from];
            display_seat(buses[route-1]);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route-1],row-1,col-1);

            std::cout<<"passenger type: \n";
            std::cout<<"[1] Regular \t [3] Student\n";
            std::cout<<"[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout<<"Enter the number: ";
            std::cin>>type;

            switch (type) {
            case 2:
            case 3:
            case 4:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Ger\n";
                std::cout<<"Conductor: Gar\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The price of the ticket is "<<price*.90<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            case 1:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Ger\n";
                std::cout<<"Conductor: Gar\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The regular price of the ticket is "<<price<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            default:
                std::cout<<"Error type! \n";
            }
        }
        if(route==5 && action=="add") {
            std::map<std::string, float>bus_stops;
            bus_stops["Station"]=0.00;
            bus_stops["Masaya"]=12.00;
            bus_stops["Malungkot"]=24.00;
            bus_stops["Tamad"]=49.00;
            bus_stops["Takot"]=70.00;
            bus_stops["Gutom"]=90.00;

            do {
                std::cout<<"Select where from: ";
                std::cin>>from;
                std::cout<<"Select where to stop: Barangay ";
                std::cin>>stop;
            } while(bus_stops[from]>bus_stops[stop]);

            float price=bus_stops[stop]-bus_stops[from];

            display_seat(buses[route-1]);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route-1],row-1,col-1);
            display_seat(buses[route-1]);

            std::cout<<"passenger type: \n";
            std::cout<<"[1] Regular \t [3] Student\n";
            std::cout<<"[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout<<"Enter the number: ";
            std::cin>>type;

            switch (type) {
            case 2:
            case 3:
            case 4:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Raulo\n";
                std::cout<<"Conductor: Raul\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The price of the ticket is "<<price*.90<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            case 1:
                company();
                std::cout<<"Route: "<<route<<"\n";
                std::cout<<"From: "<<from<<"\n";
                std::cout<<"Stop: "<<stop<<"\n";
                std::cout<<"Driver: Raulo\n";
                std::cout<<"Conductor: Raul\n";
                std::cout << "Seat: " <<"r"<< row << "c" << col<<"\n";
                std::cout<<"The regular price of the ticket is "<<price<<" pesos\n";
                std::cout<<"Ticket bought at "<<__DATE__<<" "<<__TIME__<<" \n"<<std::endl;
                std::cout<<"Thank you for riding with us! \n";
                std::cout<<"------------------------------\n";
                break;
            default:
                std::cout<<"Error type! \n";
            }
        }

        if(action=="delete") {
            display_seat(buses[route-1]);
            delete_seat(buses[route-1]);
            display_seat(buses[route-1]);

        }

        if(action=="display") {
            display_seat(buses[route-1]);

        }

        delete head;
    } while(true);
    return 0;

}
    