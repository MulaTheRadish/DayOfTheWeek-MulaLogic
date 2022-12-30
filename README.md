# Day Of The Week - Mula's Logic

## Challenge
Find which day of the week a given date lands on. 

### Input/ Output Examples:
```
$ Enter a date (dd/mm/yy): 13 / 12/ 2022
$ The day of the week on the given date is: Friday
```
```
$ Enter a date (dd/mm/yy): 15/4/2023
$ The day of the week on the given date is: Saturday
```

## Method
### 1. Parsing a String Input
First we have to parse the string input into its respective time components; dd, mm, yy. In order to do that, the code erases all the `' '` characters in the input and uses the `'/'` characters as a deliminator. The code expects **ONLY** 3 deliminators in the input. The code then turns the tokens generated from parsing the string into integers using the `.stoi` function. Afterwards, we have our required times under the variables `dd`, `mm`, `yy` representing the day, month and year respectively. 

### 2. Counting Days
We count the number of days from 0 A.D. to the date entered. We do the same with the second date, and find the difference between the two dates. That way we know the number of days between the 2 dates. 

#### Issue 1:
Considering the leap years and adding dates accordingly: 
Straightforward; add one day for every leap year counted when counting the number of days between 0 A.D. and the entered date. 

#### Issue 2: 
If the entered date is a leap year, however, the month is before the *leap day*, then do not add one. For example, do not add one if the date is 2/28/2020. 

### 3. Taking from the Indexed list
The difference between the 2 dates is used to come up with an index number between 0-6, each number used to represent Sun-Sat in a const array. The program works perfectly for all dates in the future. However, when the `new_date` predates the `current_date` then the index returns a negative number. C++ cannot use negative numbers in an array. This was solved by deducing the negative index from 7 if the index is negative. 
