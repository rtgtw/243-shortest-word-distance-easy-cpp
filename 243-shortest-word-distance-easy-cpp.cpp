/*
243.Shortest word distance


Vector of strings = dynamic array of strings
strings are an array of char

"Dog","cat"

Given an array of strings words and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Example 1:

Input: words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"], word1 = "fox", word2 = "dog"
Output: 5
Explanation: The distance between "fox" and "dog" is 5 words.
Example 2:

Input: words = ["a", "c", "d", "b", "a"], word1 = "a", word2 = "b"
Output: 1
Explanation: The shortest distance between "a" and "b" is 1 word. Please note that "a" appeared twice.




To solve this solution we are going to need
Vector - to represent the vector array of strings
string - to represent strings
algorithm - this is used for min and absolute but we can create an abs if statement


Steps
1. The goal here is to find the shortest distance between two words within an array
2. We have to iterate through the full length of the string array "words" 
3. We can use a pointer to iterate through it, this pointer will be looking for
the specific 2 words that we are looking for through each iteration 
4. If either of these words are found then we will make note of it
5. We know that if only one of these words are found then there is no distance
6. If both of the words are found we can take note of the position of both of them and 
take the absolute value of the two which is the answer to the solution

*/

#include <iostream>
#include <string>
#include <vector>



class Solution {
public:
	int shortestDistance(std::vector<std::string>& wordsDict, std::string &word1, std::string &word2);

};


int Solution::shortestDistance(std::vector<std::string>& wordsDict, std::string &word1, std::string &word2) {

	//We have to declare all of the variables that will keep track of things through each iteration of the array
	//Create a variable that will track the position of the first word when it is found within the array

	//Positon 1 can start by default at -1 to represent that it has not been found inside of the array
	int position1 = -1;

	//The same goes for position2
	int position2 = -1;

	//Create a variable that will keep track of the distance between positon1 and position2
	//We will use the absolute value in order to do this
	//We also need to compare this to if this value ever changes, we want the smallest answer (min)
	//We want to initialize shortestDistance with a large number, which is the size of the string array
	int shortestDistance = wordsDict.size();

	//create a shortestDistance temp to compare w/ shortestDistance 
	//This helps when iterating thru the array and finding a new shortestDistance value, before assigning shortestDistance it
	//edit: no need, this can done thru the if statement, no extra variable needed


	//With the variables created, now we can iterate through the string array with a for loop, since we have to visit each element
	for (int i = 0; i < wordsDict.size(); i++) {

		//At each visted element, we need to check if this element is word1, we can do this by creating an if statement
		if (wordsDict[i] == word1) {

			//If we are visiting word1 then we need to take note of the position of the index within the string array into position1
			//i represents the current index that we are at
			position1 = i;

		}

		//We need to do the same for word2 as well
		if (wordsDict[i] == word2) {

			position2 = i;
		}

		//Now we potentially have 2 valid positions for word1 and word2, if we do, we want to find the absolute difference between the two
		//If we dont then we move on
		//position1 and position2 were initialize with -1 so we can figure out if a positon was found if they are not -1
		//We just need to compare the absolute value of position1 and position2 to shortestDistance, and take the smallest one
		//At first I had position1 && position2 != -1,updated
		if (position1 != -1 && position2 != -1) {

			//if both positions are found then we need to find the absolute value of the two
			//if position1 is larger than position 2, we do p1-p2
			if (position1 > position2) {

				//absolute p1-p2
				//now we need to compare this value to shortestDistance, and give shortestDistance the smaller amount
				if ((position1 - position2) < shortestDistance) {
					shortestDistance = position1 - position2;
				}
					//If shortestDistance is the smaller value, then we do not need to do anything
					//we can just exit the if statement
					
					//Error with having break here as an else statement
					//it exited the for loop, no need for the break
					

			}//else meaning position2 is larger
			else {
				//do the same but if p2 was larger
				if ((position2 - position1) < shortestDistance) {
					shortestDistance = position2 - position1;
				}

					//Error with having break here as an else statement
					//it exited the for loop, no need for the break
					
				
			}

		}	
	}

	//After iterating through the full array string, we need to create an if statement to see
	//if both positons have been found, if both words have been found then we can return
	//shortestDistance, however if both words were not found then we have to return 0
	//Since there is no distance between the two words

	if (position1 != -1 && position2 != -1) {

		return shortestDistance;
	}
	else {
		shortestDistance = 0;
		return shortestDistance;
	}
}


int main() {

	Solution solution;

	std::vector<std::string> wordDict1 = { "a","c","b","b","a" };

	std::string word1 = "a";

	std::string word2 = "b";


	std::vector<std::string> wordDict2 = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
	
	std::string word3 = "fox";

	std::string word4 = "dog";



	//std::cout << solution.shortestDistance(wordDict1, word1, word2);

	std::cout << solution.shortestDistance(wordDict1, word1, word2);

	//Time complexity = O(n)
	//Space complexity = O(1)



	return 0;
}