#include <iostream>
#include <regex>
#include <string>

using namespace std;

struct Review {
private:
    string author;
    string reviewText;
    int rating;
public:
    Review(string a, string rText, int r) : author(a), reviewText(rText), rating(r) {}
    string getAuthor() const {
        return author;
    }
    string getReviewText() const {
        return reviewText;
    }
    int getRating() const {
        return rating;
    }
    bool if_its_valid() const {
        regex pattern("^[1-5]$");
        return regex_match(to_string(rating), pattern);
    }

    int convert_rate_in_percent() const {
        if (if_its_valid()) {
            return static_cast<int>((rating / 5.0) * 100);
        } else {
            return -1;
        }
    }
};
int main() {
    string author;
    string reviewText;
    int rating;
    cout << "Author: ";
    getline(cin, author);
    cout << "Comment(our company don*t care): ";
    getline(cin, reviewText);
    cout << "Type rating from 1 to 5(pls 5): ";
    cin >> rating;
    Review review(author, reviewText, rating);
    if (review.if_its_valid()) {
        cout << "Rating " << review.getRating() << " is valid." << endl;
        cout << "Rating in %: " << review.convert_rate_in_percent() << "%" << endl;
    } else {
        cout << "Rating is invalid." << endl;
    }

    return 0;
}
