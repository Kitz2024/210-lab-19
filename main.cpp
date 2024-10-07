#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Review {
    double rating;
    string comment;
};

class Movie {
public:
    Movie(const string& title, const string& reviewFile = "C:/Lab210/210lab19Review.txt") : title(title), reviewFile(reviewFile) {
        loadReviews();
    }

    void printReviews() const {
        cout << "Movie: " << title << endl;
        for (const Review& review : reviews) {
            cout << "Rating: " << review.rating << endl;
            cout << "Comment: " << review.comment << endl;
        }
    }
    
    void loadReviews() {
        ifstream infile(reviewFile);
        if (!infile) {
            cout << "Error opening review file: " << reviewFile << endl;
            return;
        }

        srand(time(nullptr));
        string line;
        while (getline(infile, line)) {
            if (line.empty()) {
                continue;
            }
            Review review;
            review.rating = 1.0 + double(rand() % 41)/ 10.0;
            review.comment = line;
            reviews.insert(reviews.begin(), review); // Add to the head
        }
    }

private:
    string title;
    string reviewFile;
    vector<Review> reviews;
};

int main() {
    vector<Movie> movies = {
        {"Avengers: End Game", "C:/Lab210/210lab19Review.txt"},
        {"The Wizard of OZ", "C:/Lab210/210lab19Review.txt"},
        {"Studio Ghibli: My Neighbor Totoro", "C:/Lab210/210lab19Review.txt"},
        {"Fareinheit", "C:/Lab210/210lab19Review.txt"}

    };

    for (const Movie& movie : movies) {
        movie.printReviews();
        cout << endl;
    }

    return 0;
}