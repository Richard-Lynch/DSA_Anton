# Data Structures and Algorithms - Tutorial 2 - C, Complexity, and Hash Tables Discussion - Anton Gerdelan <gerdela@scss.tcd.ie>

Try to answer all questions then we will discuss them. Mostly test type questions but some are general talking points.

## Multiplayer Chat

We are creating a chat system for a popular online multiplayer game. Users type in a 'username'
string and a password. We do not know in advance which strings will be used. If username string is entered,
and the server doesn't find it, we will register a new user. If we already have that username we will
then check for a password match. Failing that we will tell the user that the password is incorrect
or ask to register a new name.

1. Is there a security flaw with sending the username and password as plain strings in a packet? Can you suggest a better idea? If you are familiar with network programming - what other unique information per-user might we have available to use?

2. Our game is written in C and our strings are char arrays. Some users are demanding unicode support so that they can write their names using a fada. Why don't char arrays support accented characters? How can we add support for this feature?

3. List 3 candidate data structures and appropriate algorithms for searching (and storing/retrieving) the users. Bullet advantages and disadvantages for each.

4. In our test build our 'massively multiplayer' game supports about 16 users. We are going to use a _linear probing_ hash table. Suggest a sensible table size, M.

5. Maximum username length is 16 characters. Write an algorithm (or code) for a suitable hash function. You may assume ASCII characters or some sort of unicode representation, as you prefer.

6. Start to construct a diagram of the linear probing hash table step-by-step to illustrate the following test usernames being stored, in order. Assume the hash table size has been set to M=8. You will need to make some hand calculations. You may simplify your hash function if you like. Beside each name below, write the table index and also count the number of 'probes' (investigations) required to store the names.

    "prince adam"
    "cringer"
    "teela"
    "aleet"
    "orko"
    "princess adora"

7. calculate the _load_ of the hash table. give 2 reasons why table load is useful information.

8. calculate average time complexity _T_ for the searches in Q(6).

9. if we are later searching for usernames that are _not_ in the table, and these have hash indices; 7, 3, 5, 1, 0 calculate the average time complexity _T_ for an _unsuccessful search_.

10. approximate big-o style average, best, and worst complexity for the hash table. consider the table being completely empty and completely full. note that successful and unsuccessful evaluations of complexity are usually done separately (have 2 sets of best/worst/average approximations).

11. how can we improve performance of the _worst_ unsuccessful search results in (9)? Refer to diagram.

12. If we later support any number of players, how (and why) might we consider modifying our hash table? Suggest possible changes to algorithm, type of hash table, and table size M. Is an altogether different sort of system more appropriate for very large sets of users - why?
