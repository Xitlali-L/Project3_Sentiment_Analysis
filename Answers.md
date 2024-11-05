# Assignment 2: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Xitlali Lopez

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[ ] Early submission (48 hrs)

[X] Bonus work. Describe: Accuracy is 72%

Place [x] for what applies.


## UML Diagram

Add your UML class diagram here.

Replace the following image with your diagram. You can draw it by hand and take a photo.
![UML Class Diagram](UML_class.png)

## Answers

1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.

    > You first read the txt file with the tweets and sentiment values. then breakdown each tweet into words
   and change the words to lowercase, to then filter out short and irrelevant words.
   Update a count each time a word shows up as a positive or negative tweet. Lastly, storing the words sentiment
   value based on the probability of the word being positive. Ex. 60% positive

2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Remember that training includes reading the tweets, breaking it into words, counting, ... Explain why you get this complexity (e.g., what does `N` stand for and how do your data structures/algorithms affect the complexity).

   > It took us a week to create the training section. The time complexity of our training section is O(N * M) where
   N is the number of tweets and M is the average numbers of words per tweet. Each word is checked and updates the sentCount map
   which takes O(1) for each word.

3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.

>  It took us a week to create the classification. The time complexity of the classification is O(N * M) where N is the number of tweets
   because during the classification its O(M) ,for each tweet, while each tweet is spilt into words.

4. What accuracy did your algorithm achieve on the provides training and test data? 

   > My accuracy: 72%

   The TA will run your code on Linux and that accuracy value will be used to determine your grade.

5. What were the changes that you made that improved the accuracy the most?
   
   > Changing the number of times a word needs to appear before it can be classified as either a positive or negative 
    helps the accuracy improve. As well as changing the probability threshold for a word to be classified as either a 
positive or negative sentiment.

6. How do you know that you use proper memory management? I.e., how do you know that you do not have
   a memory leak?

   > I know I used proper memory management because I implemented and used the rule of three when allocating memory.

7. What was the most challenging part of the assignment?

   > Trying to figure out where to start and how to compare the classified words with the testing dataset.