# Data Structure and Algorithms - Tutorial 2 - C, Complexity, and Hash Tables Discussion - Anton Gerdelan <gerdela@scss.tcd.ie>

Try to answer all questions then we will discuss them.

## Multiplayer Chat

We are creating a chat system for a popular online multiplayer game. Users type in a 'username'
string and a password. We do not know in advance which strings will be used. If username string is entered,
and the server doesn't find it, we will register a new user. If we already have that username we will
then check for a password match. Failing that we will tell the user that the password is incorrect
or ask to register a new name.

1. Is there a security flaw with sending the username and password as plain strings in a packet? Can you suggest a better idea?

2. Our game is written in C and our strings are char arrays. Some users are demanding unicode support so that they can write their names using a fada. Why don't char arrays support accented characters? How can we add support for this feature?

3. List 3 candidate data structures and appropriate algorithms for storing and searching the users. Bullet advantages and disadvantages for each.

4. Our massively-multiplayer game supports a maximum of 16 users. Construct a diagram step-by-step to illustrate the creation of a _linear probing_ hash table.
