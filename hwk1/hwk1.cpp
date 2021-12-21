/* ======================================================
File Name   : hwk1.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk1, movie theater application
Rev History : Initial hwk release
Date        : 01/xx/2021
Version     : 1.0
Comments    : 
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

using namespace std;

/////////////// Movie Class

class Movie {
    private:  
        string movie_name;
        int seats_available;
        double ticket_price;
        
    public:    
        static const string DEFAULT_MOVIE_NAME;
        static const int DEFAULT_SEATS;
        static const double DEFAULT_TICKET_PRICE;

    public:
        Movie ();
        Movie (string m_movie_name, int m_seats_available, double m_ticket_price);
        ~Movie ();
        // accessors
        string get_movie_name( ) const;
        int get_seats_available( ) const;
        double get_ticket_price( ) const;
        // mutators
        void set_movie_name(string m_movie_name);
        void set_seats_available(int m_seats_available);
        void set_ticket_price(double m_ticket_price);
        // Helpers
        void display( ) const;
};

// Variables
const string Movie::DEFAULT_MOVIE_NAME {"Mistery Movie"};
const int Movie::DEFAULT_SEATS {100};
const double Movie::DEFAULT_TICKET_PRICE {11.99};

// Constructors and destructor
Movie::Movie(string m_movie_name, int m_seats_available, double m_ticket_price): 
                    movie_name(m_movie_name), 
                    seats_available(m_seats_available), 
                    ticket_price(m_ticket_price) { }

Movie::Movie(): movie_name(DEFAULT_MOVIE_NAME),
                    seats_available(DEFAULT_SEATS),
                    ticket_price(DEFAULT_TICKET_PRICE) { }

Movie::~Movie() { } // Need to add message !!!

// Accessors
string Movie::get_movie_name( ) const {return movie_name;}
int Movie::get_seats_available( ) const {return seats_available;}
double Movie::get_ticket_price( ) const {return ticket_price;}

// Mutators
void Movie::set_movie_name(string m_movie_name) {movie_name = m_movie_name;}
void Movie::set_seats_available(int m_seats_available) {seats_available = m_seats_available;}
void Movie::set_ticket_price(double m_ticket_price) {ticket_price = m_ticket_price;}

// Helper functions
void Movie::display( ) const {
    cout << "Movie name: " << movie_name << endl
         << "Ticket price: $" << ticket_price << endl
         << "Seats available: " << seats_available << endl;
}

/////////////// Online MovieTicketMaster Class

class MovieTicketMaster {
    private:
        string theater_name;
        string theater_location;
        static const int k_max_movies = 32;
        Movie movie_list[k_max_movies];
        int movie_count;

        // Member functions
        int GetUserChoice();
        void Quit();
        void HandleInvalidInput(int selection);
        int FindMovie(string movie_name, int kSize);
        int SearchMovie(int kSize);
        int ViewMovies(int kSize);

    public:
        static const string DEFAULT_THEATER_NAME;
        static const string DEFAULT_THEATER_LOCATION;
        static const int DEFAULT_MOVIE_COUNT;

        // Constructor destructor
        MovieTicketMaster();
        MovieTicketMaster(string m_theater_name, string m_theater_location, int m_movie_count);
        ~MovieTicketMaster();

        // Accessors and mutators
        string get_theater_name() const;
        string get_theater_location() const;
        int get_movie_count() const;
        //static double get_tax_rate();
        void set_theater_name(string m_theater_name);
        void set_theater_location(string m_theater_location);
        void set_movie_count(int m_movie_count);

        // Public member functions
        void Init();
        void Menu();
        void Run();
        int FindMovie
    (string movie_name, double seats_available);
        int PurchaseTickets(int res, double seats_available);
};

// Variables ---------------------------------------
const string MovieTicketMaster::DEFAULT_THEATER_NAME {"AMC"};
const string MovieTicketMaster::DEFAULT_THEATER_LOCATION {"My City"};
const int MovieTicketMaster::DEFAULT_MOVIE_COUNT {0};

// Constructors and destructor ---------------------
MovieTicketMaster::MovieTicketMaster(): 
    theater_name(DEFAULT_THEATER_NAME), 
    theater_location(DEFAULT_THEATER_LOCATION),
    movie_count(DEFAULT_MOVIE_COUNT) { }

MovieTicketMaster::MovieTicketMaster(string m_theater_name, string m_theater_location, int m_movie_count):
    theater_name(m_theater_name), theater_location(m_theater_location), movie_count(m_movie_count) { }

MovieTicketMaster::~MovieTicketMaster() {
    cout << "Theater " << theater_name << "at "
         << theater_location << " is currently closed" << endl; 
}

// Accessors and mutators definitions ---------------
string MovieTicketMaster::get_theater_name() const {return theater_name;}
string MovieTicketMaster::get_theater_location() const {return theater_location;}
int MovieTicketMaster::get_movie_count() const {return movie_count;}
void  MovieTicketMaster::set_theater_name(string m_theater_name) {theater_name = m_theater_name;}
void MovieTicketMaster::set_theater_location(string m_theater_location) {theater_location = m_theater_location;}
void MovieTicketMaster::set_movie_count(int m_movie_count) {movie_count = m_movie_count;}

void MovieTicketMaster::Init() {
    const int kSize = 8;
    string movie_names[kSize] = {"Star Wars", "Toy Story", "Tarzan", "The Godfather", 
                                "Pulp Fiction", "Casablanca", "Vertigo", "Citizen Kane"};
    double movie_prices[kSize] = {11.99, 11.99, 15.99, 6.99, 11.99, 14.99, 11.99, 15.99};
    int movie_seats[kSize] = {100, 85, 80, 85, 100, 65, 75, 50};

    for (int i=0; i<kSize; i++) {
            movie_list[i].set_movie_name(movie_names[i]);
            movie_list[i].set_ticket_price(movie_prices[i]);
            movie_list[i].set_seats_available(movie_seats[i]);
    }
}


void MovieTicketMaster::Menu() {

    cout << "   *************************\n";
    cout << "      MOVIE TICKET MASTER\n";
    cout << "   *************************\n";
    cout << " Theater: " << theater_name << "at " << theater_location << endl;
    cout << "   *************************\n";
    cout << " 1. View all movies\n";
    cout << " 2. Search a movie\n";
    cout << " 3. Purchase tickets\n";
    cout << " 4. Quit\n";
    cout << "   *************************\n";
}

int MovieTicketMaster::GetUserChoice() {
    int selection;
    cout << "Please choose an option from the menu (1-4): ";
    cin >> selection;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << endl;
        return 0;
    }
    else{
        return selection;
    }
}

int MovieTicketMaster::SearchMovie(int kSize) {
    string movie_name;
    int kSize;
    cout << "Enter a movie name: ";
    getline (cin, movie_name);
    FindMovie(movie_name, int kSize);
}
int MovieTicketMaster::FindMovie(string movie_name, int kSize) {
    for (int i=0; i<kSize; i++) {  
        if (movie_name == movie_list[i].get_movie_name()) { 
            return i;
        }
    }
    return -1;
}

int MovieTicketMaster::ViewMovies(int kSize) {
    for (int i=0; i<kSize; i++) {  
        movie_list[i].display();
        cout << endl;
        }
    }
}

int MovieTicketMaster::PurchaseTickets(int res, double seats_available) {
    if(seats_available > movie_list[res].get_seats_available()) {
        cout << "We do not have enough " << movie_list[res].get_movie_name() 
             << " to fulfill your order";
        return -1;
    }
    else {
        double cost = seats_available * movie_list[res].get_ticket_price();
        cout << "Cost for " << seats_available << " of " 
             << movie_list[res].get_movie_name()
             << " is $" << cost << endl; 
        return 0;
    }
}

void MovieTicketMaster::Run() {
    int selection = 1;
    do
    {
        Menu();
        selection = GetUserChoice();
        switch (selection){
            case 1:
                ViewMovies();
                break;
            case 2:
                SearchMovie();
                break;
            case 3:
                PurchaseTicket();
                break;
            case 4:
                Quit();
                break;
            default: // Handles the '0' return
                HandleInvalidInput(selection);
                break;
        }
    }
    while (selection != 4);
}

void MovieTicketMaster::Quit() {
    cout << "Thanks for your visit and come again ...\n\n";
    exit(0);
}

void MovieTicketMaster::HandleInvalidInput(int selection) {
    cout << selection << " is an invalid input, please try again\n\n\n";
}


//---------------------------------------------------------------

int main() {

    MovieTicketMaster theater1("AMC Mercado", "Santa Clara", 100);
    cout << theater1.get_theater_name() << endl;
    cout << theater1.get_theater_location() << endl;
    cout << theater1.get_movie_count() << endl;
    cout << endl;

    theater1.Run();
}
