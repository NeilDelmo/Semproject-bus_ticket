#include <iostream>
#include <map>
#include <iomanip>

const int COL = 4;
const int ROWS = 2;

struct Bus
{
    char seat[ROWS][COL];
};

class Node
{
  public:
    std::string place_name;
    std::string time;
    Node *next;

    Node(std::string name, std::string time, Node *next) : place_name(name), time(time), next(next) {}
    ~Node()
    {
        delete next;
    }
};

void reset_counter(std::map<std::string, int> &stopCounter){
    stopCounter.clear();
}

void reset_count(std::map<std::string, int> &stopCounter, Bus &bus, std::string action, std::string stop, int &num_people) {
    
    if (stopCounter.find(stop)!= stopCounter.end()) {
        stopCounter[stop] = 0;
        num_people = stopCounter[stop]; //get the number of people who got off at the stop
        for (int i = 0; i < num_people; i++) {
            // free up seats on the bus
            for (int j = 0; j < ROWS; j++) {
                for (int k = 0; k < COL; k++) {
                    if (bus.seat[j][k] == 'X') {
                        bus.seat[j][k] = 'V';
                    }
                }
            }
        }
    }
}

int current_bus_number = 0;

void display_seat(Bus &bus, std::map<std::string, int> &stopCounter,std::string action)
{
    int occupied = 0;
    std::cout << "Bus " << current_bus_number + 1 << " seat: \n";
    std::cout << "V=Vacant/X=Occupied\n";
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (j % 2 == 0)
            {
                std::cout << "[";
            }
            std::cout << bus.seat[i][j] << "]";
            if (j % 2 == 1)
            {
                std::cout << " ";
            }
            if (bus.seat[i][j] == 'X')
            {
                occupied++;
            }
        }
        std::cout << "\n";
    }
    if (occupied == ROWS * COL)
    {
        ++current_bus_number;
        if (current_bus_number >= 5)
        {
            std::cout << "All buses are full. Cannot accommodate more passengers.\n";
            return;
        }
        std::cout << "Bus " << current_bus_number << " is full! Go to another bus\n";
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                bus.seat[i][j] = 'V';
            }
        }
        reset_counter(stopCounter);
        std::cout << "Bus " << current_bus_number + 1 << " seat: \n";
    }
}

bool select_seat(Bus &bus, int row, int col)
{
    if (bus.seat[row][col] == 'V')
    {
        bus.seat[row][col] = 'X';
        std::cout << "Seat successfully reserved!\n";
        return true;
    }
    else
    {
        std::cout << "Seat already occupied. Please select another seat.\n";
        return false;
    }
}

void delete_seat(Bus &bus)
{
    int row, col;
    std::cout << "Enter row and column for the seat \n";
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Column: ";
    std::cin >> col;

    if (row > 0 && row <= ROWS && col > 0 && col <= COL)
    {
        if (bus.seat[row - 1][col - 1] == 'X')
        {
            bus.seat[row - 1][col - 1] = 'V';
            std::cout << "Seat "
                      << "r" << row << "c" << col << " has been Deleted.\n";
        }
        else
        {
            std::cout << "Seat already vacant!\n";
        }
    }
    else
    {
        std::cout << "Invalid seat";
    }
}

void company()
{
    std::cout << "==============================";
    std::cout << "|     DOWG'S BUS COMPANY     |";
    std::cout << "==============================\n\n";
}

void menu(Node *head)
{
    Node *current = head;
    int i = 1;
    std::cout << "Choose your destination:\n";
    std::cout << "--------------------------------\n";
    std::cout << "Place\t\tEstimated Time of Arrival(Military time)\n";
    std::cout << "--------------------------------\n";
    while (current != nullptr)
    {
        std::cout << i << ". " << current->place_name << " \t       " << current->time << "\n";
        current = current->next;
        i++;
    }
    std::cout << "--------------------------------\n";
}

std::map<std::string, int> stopCounter;

void counter(std::string stop, int route, std::map<std::string, int> &stopCounter)
{
    switch (route)
    {
    case 1:
        std::cout << "Route 1 bus stops\n";
        std::cout << "Uno: " << stopCounter["Uno"] << "\n";
        std::cout << "Dos: " << stopCounter["Dos"] << "\n";
        std::cout << "Tres: " << stopCounter["Tres"] << "\n";
        std::cout << "Kuwatro: " << stopCounter["Kuwatro"] << "\n";
        std::cout << "Singko: " << stopCounter["Singko"] << "\n";
        break;
    case 2:
        std::cout << "Route 2 bus stops\n";
        std::cout << "Tinitigan: " << stopCounter["Tinitigan"] << "\n";
        std::cout << "Nakachat: " << stopCounter["Nakachat"] << "\n";
        std::cout << "Lambingan: " << stopCounter["Lambingan"] << "\n";
        std::cout << "Nagmahalan: " << stopCounter["Nagmahalan"] << "\n";
        std::cout << "Nagingsila: " << stopCounter["Nagingsila"] << "\n";
        break;
    case 3:
        std::cout << "Route 3 bus stops\n";
        std::cout << "Umibig: " << stopCounter["Umibig"] << "\n";
        std::cout << "Umasa: " << stopCounter["Umasa"] << "\n";
        std::cout << "Pinaglalaruan: " << stopCounter["Pinaglalaruan"] << "\n";
        std::cout << "Iniwan: " << stopCounter["Iniwan"] << "\n";
        std::cout << "Nasaktan: " << stopCounter["Nasaktan"] << "\n";
        break;
    case 4:
        std::cout << "Route 4 bus stops\n";
        std::cout << "Bumangon: " << stopCounter["Bumangon"] << "\n";
        std::cout << "Tumayo: " << stopCounter["Tumayo"] << "\n";
        std::cout << "Naglakad: " << stopCounter["Naglakad"] << "\n";
        std::cout << "Umupo: " << stopCounter["Umupo"] << "\n";
        std::cout << "Nagcode: " << stopCounter["Nagcode"] << "\n";
        break;
    case 5:
        std::cout << "Route 5 bus stops\n";
        std::cout << "Masaya: " << stopCounter["Masaya"] << "\n";
        std::cout << "Malungkot: " << stopCounter["Malungkot"] << "\n";
        std::cout << "Tamad: " << stopCounter["Tamad"] << "\n";
        std::cout << "Takot: " << stopCounter["Takot"] << "\n";
        std::cout << "Gutom: " << stopCounter["Gutom"] << "\n";
        break;
    }
}

int main()
{
    int row;
    int col;
    std::string from;
    std::string stop;
    std::string stp;
    int route;
    Bus buses[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            for (int k = 0; k < COL; k++)
            {
                buses[i].seat[j][k] = 'V';
            }
        }
    }

    std::map<std::string, int> stopCounter;

    do
    {
        company();

        std::cout << "Select the Route(1-5): ";
        std::cin >> route;

        Node *head = nullptr;
        Node **current = &head;

        switch (route)
        {
        case 1:
            *current = new Node("Station", "10:00", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Uno", "10:10", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Dos", "10:20", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tres", "10:30", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Kuwatro", "10:40", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Singko", "10:50", nullptr);
            break;
        case 2:
            *current = new Node("Station", "10:10", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tinitigan", "12:30", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nakachat", "12:40", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Lambingan", "12:50", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagmahalan", "13:00", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagingsila", "13:10", nullptr);
            break;
        case 3:
            *current = new Node("Station", "14:00", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umibig", "14:10", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umasa", "14:20", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Pinaglalaruan", "14:30", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Iniwan", "14:40", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nasaktan", "14:50", nullptr);
            break;
        case 4:
            *current = new Node("Station", "8:20", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Bumangon", "8:30", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tumayo", "8:40", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Naglakad", "8:50", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Umupo", "9:00", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Nagcode", "9:10", nullptr);
            break;
        case 5:
            *current = new Node("Station", "6:00", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Masaya", "6:10", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Malungkot", "6:20", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Tamad", "6:30", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Takot", "6:40", nullptr);
            current = &((*current)->next);
            *current = new Node("Barangay Gutom", "6:50", nullptr);
            break;
        default:
            std::cout << "Invalid route number!" << std::endl;
        }
        menu(head);
        std::string action;
        std::cout << "what to do(add/delete/display/stop): ";
        std::cin >> action;

        if (action == "display")
        {
            display_seat(buses[route - 1], stopCounter, action);
            std::cout << "Bus Stops:" << std::endl;
            counter(stop, route, stopCounter);
        }
        
        if (action == "stop")
        {
            std::cout << "Where to stop: ";
            std::cin >> stp;
            int num_people = stopCounter[stp];
reset_count(stopCounter, buses[route - 1], action, stp, num_people);
        }

        std::cout << std::fixed << std::setprecision(2);

        if (route == 1 && action == "add")
        {
            std::map<std::string, int> bus_stops;
            bus_stops["Station"] = 0;
            bus_stops["Uno"] = 12;
            bus_stops["Dos"] = 24;
            bus_stops["Tres"] = 49;
            bus_stops["Kuwatro"] = 70;
            bus_stops["Singko"] = 90;

            do
            {
                std::cout << "From: Station\n";
                std::cout << "Select where to stop: Barangay ";
                std::cin >> stop;
            } while (bus_stops["Station"] > bus_stops[stop]);
            if (stopCounter.find(stop) != stopCounter.end())
            {
                stopCounter[stop]++;
            }
            else
            {
                stopCounter[stop] = 1;
            }
            float price = bus_stops[stop] - bus_stops["Station"];
            display_seat(buses[route - 1], stopCounter, action);
            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route - 1], row - 1, col - 1);

            std::cout << "passenger type: \n";
            std::cout << "[1] Regular \t [3] Student\n";
            std::cout << "[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout << "Enter the number: ";
            std::cin >> type;

            switch (type)
            {
            case 2:
            case 3:
            case 4:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Raulo\n";
                std::cout << "Conductor: Raul\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The price of the ticket is " << price * .90 << " pesos\n";
                std::cout << "Estimated time: 10:50 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            case 1:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Raulo\n";
                std::cout << "Conductor: Raul\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "Estimated time: 10:50 \n";
                std::cout << "The regular price of the ticket is " << price << " pesos\n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << "Error type! \n";
                break;
            }
        }

        if (route == 2 && action == "add")
        {
            std::map<std::string, float> bus_stops;
            bus_stops["Station"] = 0.00;
            bus_stops["Tinitigan"] = 12.00;
            bus_stops["Nakachat"] = 24.00;
            bus_stops["Lambingan"] = 49.00;
            bus_stops["Nagmahalan"] = 70.00;
            bus_stops["Nagingsila"] = 90.00;

            do
            {
                std::cout << "From: Station\n";
                std::cout << "Select where to stop: Barangay ";
                std::cin >> stop;
            } while (bus_stops["Station"] > bus_stops[stop]);
            if (stopCounter.find(stop) != stopCounter.end())
            {
                stopCounter[stop]++;
            }
            else
            {
                stopCounter[stop] = 1;
            }
            float price = bus_stops[stop] - bus_stops["Station"];
            display_seat(buses[route - 1], stopCounter, action);
            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route - 1], row - 1, col - 1);

            std::cout << "passenger type: \n";
            std::cout << "[1] Regular \t [3] Student\n";
            std::cout << "[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout << "Enter the number: ";
            std::cin >> type;

            switch (type)
            {
            case 2:
            case 3:
            case 4:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Cigeh\n";
                std::cout << "Conductor: Yosi\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The price of the ticket is " << price * .90 << " pesos\n";
                std::cout << "Estimated time: 13:10 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            case 1:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Cigeh\n";
                std::cout << "Conductor: Yosi\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The regular price of the ticket is " << price << " pesos\n";
                std::cout << "Estimated time: 13:10 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << "Error type! \n";
            }
        }
        if (route == 3 && action == "add")
        {
            std::map<std::string, float> bus_stops;
            bus_stops["Station"] = 0.00;
            bus_stops["Umibig"] = 12.00;
            bus_stops["Umasa"] = 24.00;
            bus_stops["Pinaglalaruan"] = 49.00;
            bus_stops["Iniwan"] = 70.00;
            bus_stops["Nasaktan"] = 90.00;

            do
            {
                std::cout << "From: Station\n";
                std::cout << "Select where to stop: Barangay ";
                std::cin >> stop;
            } while (bus_stops["Station"] > bus_stops[stop]);
            if (stopCounter.find(stop) != stopCounter.end())
            {
                stopCounter[stop]++;
            }
            else
            {
                stopCounter[stop] = 1;
            }

            float price = bus_stops[stop] - bus_stops["Station"];
            display_seat(buses[route - 1], stopCounter, action);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route - 1], row - 1, col - 1);

            std::cout << "passenger type: \n";
            std::cout << "[1] Regular \t [3] Student\n";
            std::cout << "[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout << "Enter the number: ";
            std::cin >> type;

            switch (type)
            {
            case 2:
            case 3:
            case 4:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Jaja\n";
                std::cout << "Conductor: Jeje\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The price of the ticket is " << price * .90 << " pesos\n";
                std::cout << "Estimated time: 14:50 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            case 1:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Jaja\n";
                std::cout << "Conductor: Jeje\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The regular price of the ticket is " << price << " pesos\n";
                std::cout << "Estimated time: 14:50 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << "Error type! \n";
            }
        }
        if (route == 4 && action == "add")
        {
            std::map<std::string, float> bus_stops;
            bus_stops["Station"] = 0.00;
            bus_stops["Bumangon"] = 12.00;
            bus_stops["Tumayo"] = 24.00;
            bus_stops["Naglakad"] = 49.00;
            bus_stops["Umupo"] = 70.00;
            bus_stops["Nagcode"] = 90.00;

            do
            {
                std::cout << "From: Station\n";
                std::cout << "Select where to stop: Barangay ";
                std::cin >> stop;
            } while (bus_stops["Station"] > bus_stops[stop]);
            if (stopCounter.find(stop) != stopCounter.end())
            {
                stopCounter[stop]++;
            }
            else
            {
                stopCounter[stop] = 1;
            }
            float price = bus_stops[stop] - bus_stops["Station"];
            display_seat(buses[route - 1], stopCounter, action);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route - 1], row - 1, col - 1);

            std::cout << "passenger type: \n";
            std::cout << "[1] Regular \t [3] Student\n";
            std::cout << "[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout << "Enter the number: ";
            std::cin >> type;

            switch (type)
            {
            case 2:
            case 3:
            case 4:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Ger\n";
                std::cout << "Conductor: Gar\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The price of the ticket is " << price * .90 << " pesos\n";
                std::cout << "Estimated time: 9:10 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            case 1:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Ger\n";
                std::cout << "Conductor: Gar\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The regular price of the ticket is " << price << " pesos\n";
                std::cout << "Estimated time: 9:10 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << "Error type! \n";
            }
        }
        if (route == 5 && action == "add")
        {
            std::map<std::string, float> bus_stops;
            bus_stops["Station"] = 0.00;
            bus_stops["Masaya"] = 12.00;
            bus_stops["Malungkot"] = 24.00;
            bus_stops["Tamad"] = 49.00;
            bus_stops["Takot"] = 70.00;
            bus_stops["Gutom"] = 90.00;

            do
            {
                std::cout << "From: Station\n";
                std::cout << "Select where to stop: Barangay ";
                std::cin >> stop;
            } while (bus_stops["Station"] > bus_stops[stop]);
            if (stopCounter.find(stop) != stopCounter.end())
            {
                stopCounter[stop]++;
            }
            else
            {
                stopCounter[stop] = 1;
            }

            float price = bus_stops[stop] - bus_stops["Station"];

            display_seat(buses[route - 1], stopCounter, action);

            std::cout << "Enter row and column for the seat \n";
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> col;

            select_seat(buses[route - 1], row - 1, col - 1);
            display_seat(buses[route - 1], stopCounter, action);

            std::cout << "passenger type: \n";
            std::cout << "[1] Regular \t [3] Student\n";
            std::cout << "[2] Senior  \t [4] People with disabilities(PWD)\n";

            int type;
            std::cout << "Enter the number: ";
            std::cin >> type;

            switch (type)
            {
            case 2:
            case 3:
            case 4:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Raulo\n";
                std::cout << "Conductor: Raul\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The price of the ticket is " << price * .90 << " pesos\n";
                std::cout << "Estimated time: 6:50 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            case 1:
                company();
                std::cout << "Route: " << route << "\n";
                std::cout << "From: Station"
                          << "\n";
                std::cout << "Stop: " << stop << "\n";
                std::cout << "Driver: Raulo\n";
                std::cout << "Conductor: Raul\n";
                std::cout << "Seat: "
                          << "r" << row << "c" << col << "\n";
                std::cout << "The regular price of the ticket is " << price << " pesos\n";
                std::cout << "Estimated time: 6:50 \n";
                std::cout << "Ticket bought at " << __DATE__ << " " << __TIME__ << " \n"
                          << std::endl;
                std::cout << "Thank you for riding with us! \n";
                std::cout << "------------------------------\n";
                break;
            default:
                std::cout << "Error type! \n";
            }
        }

        if (action == "delete")
        {
            display_seat(buses[route - 1], stopCounter, action);
            delete_seat(buses[route - 1]);
            display_seat(buses[route - 1], stopCounter, action);
        }

        delete head;
    } while (true);
    return 0;
}
    