#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

int main() {
    // Sample sentences for the typing test
    string sentence = "The quick brown fox jumps over the lazy dog.";
    
    // Display instructions
    cout << "Typing Speed Test!" << endl;
    cout << "You will be given a sentence to type." << endl;
    cout << "Try to type it as fast as you can!" << endl << endl;
    
    // Display the sentence
    cout << "Your sentence: " << sentence << endl << endl;
    
    // Wait for the user to press enter before starting
    cout << "Press Enter to start typing..." << endl;
    cin.get();
    
    // Start measuring time
    auto start = high_resolution_clock::now();
    
    // Get the user's typed sentence
    string userInput;
    cout << "Start typing: ";
    getline(cin, userInput);
    
    // Stop measuring time
    auto end = high_resolution_clock::now();
    
    // Calculate the time taken
    auto duration = duration_cast<milliseconds>(end - start);
    
    // Check if the user typed correctly
    if (userInput == sentence) {
        cout << "\nCongratulations! You typed the sentence correctly." << endl;
    } else {
        cout << "\nOops! You didn't type the sentence correctly." << endl;
    }
    
    // Calculate typing speed (words per minute)
    int wordsTyped = userInput.size() / 5; // Rough estimation of words (average 5 characters per word)
    double timeTakenInSeconds = duration.count() / 1000.0;
    double wordsPerMinute = (wordsTyped / timeTakenInSeconds) * 60;
    
    cout << "\nTime taken: " << duration.count() / 1000.0 << " seconds." << endl;
    cout << "Your typing speed is: " << wordsPerMinute << " words per minute." << endl;
    
    return 0;
}
