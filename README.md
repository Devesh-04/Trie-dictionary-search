# 🧠 Trie-Based Dictionary Search with Fuzzy Matching

This project is a **C++ application** that implements an efficient dictionary search using a **Trie data structure**. It supports two powerful search capabilities:

- 🔍 **Prefix Matching (Autocomplete)**: Quickly finds all words that start with a given query.
- 🧠 **Fuzzy Matching (Spellcheck)**: Suggests closely related words based on edit (Levenshtein) distance, making it ideal for handling typos or misspellings.

The program loads a list of words from a file and builds a trie for fast and intelligent search.

---


## 📈 Project Objective

To create a console-based dictionary search program that not only finds exact word matches but also intelligently suggests words based on **prefixes** and **spelling similarity** using a **Trie and dynamic programming (Levenshtein Distance)**.

This is similar to how search engines and modern editors provide autocomplete and autocorrect suggestions.

---

## ✨ Features

- ✅ Load dictionary from a text file
- ✅ Build a Trie structure for fast word storage and prefix retrieval
- ✅ Prefix-based search (autocomplete)
- ✅ Fuzzy search (typo correction) using Levenshtein Distance (edit distance ≤ 2)
- ✅ Sort fuzzy matches based on how close they are (edit distance)

---

## ⚙️ How the Project Works

### 1. **Loading the Dictionary**
All words are read from a file called `dictionary.txt`. Each word is inserted into a Trie data structure. Create a file named dictionary.txt in the same directory. Each line should contain a single word:

Example content of dictionary.txt:
apple
application
applet
banana
battle
bat

### 2. **Trie Insertion**
Each node in the Trie contains:
- A character
- A flag indicating whether the node is terminal (end of a valid word)
- A map of children nodes

### 3. **Prefix Search**
Given a query like `"app"`, we traverse the Trie to reach the last character of the prefix. From there, a DFS is run to collect all valid words starting with that prefix.

### 4. **Fuzzy Search**
We collect all words from the Trie using a DFS, and then compute **Levenshtein Distance** between the query and each word.
If the distance is ≤ 2, the word is added to the result.
The results are sorted by how close they are (lower distance = better match).

---

Enter your search query: appl

Prefix Matches:
- apply
- applyment
- applyingly
- applot
- applotment
- applosive
- applosion
- applique
- applier
- applied
- appliedly
- applicator
- applicatory
- applicatorily
- applicative
- applicatively
- application
- applicate
- applicant
- applicancy
- applicably
- applicable
- applicableness
- applicability
- appliant
- appliance
- appliably
- appliable
- appliableness
- apple
- applesauce
- appleroot
- appleringy
- applenut
- applemonger
- applewoman
- applewife
- applejohn
- applejack
- applegrower
- appledrane
- applecart
- appleblossom
- appleberry
- applausive
- applausively
- applause
- applaud
- applaudingly
- applauder
- applaudably
- applaudable
- applanation
- applanate

Fuzzy Matches (Levenshtein ≤ 2):
- apple (distance: 1)
- apply (distance: 1)
- all (distance: 2)
- amyl (distance: 2)
- alp (distance: 2)
- al (distance: 2)
- ail (distance: 2)
- aiel (distance: 2)
- agal (distance: 2)
- acyl (distance: 2)
- aal (distance: 2)
- anil (distance: 2)
- anal (distance: 2)
- aptly (distance: 2)
- apt (distance: 2)
- apse (distance: 2)
- appall (distance: 2)
- appay (distance: 2)
- appeal (distance: 2)
- appet (distance: 2)
- Lapp (distance: 2)
- napal (distance: 2)
- nappe (distance: 2)
- nappy (distance: 2)
- mappy (distance: 2)
- lapel (distance: 2)
- kappa (distance: 2)
- kappe (distance: 2)
- kapp (distance: 2)
- Lappa (distance: 2)
- applot (distance: 2)
- ipil (distance: 2)
- happy (distance: 2)
- gappy (distance: 2)
- amil (distance: 2)
- ampul (distance: 2)
- ample (distance: 2)
- amply (distance: 2)
- amp (distance: 2)
- pol (distance: 2)
- capple (distance: 2)
- cappy (distance: 2)
- opal (distance: 2)
- pal (distance: 2)
- papal (distance: 2)
- pappi (distance: 2)
- pappy (distance: 2)
- pul (distance: 2)
- capel (distance: 2)
- rappel (distance: 2)
- rappe (distance: 2)
- sappy (distance: 2)
- tapul (distance: 2)
- tappa (distance: 2)
- Wappo (distance: 2)
- wapp (distance: 2)
- yappy (distance: 2)
- aril (distance: 2)
- apod (distance: 2)
- apii (distance: 2)
- apio (distance: 2)
- aper (distance: 2)
- apex (distance: 2)
- ape (distance: 2)
- apar (distance: 2)
- apa (distance: 2)
- yapp (distance: 2)
- aryl (distance: 2)
- asp (distance: 2)
- aval (distance: 2)
- awl (distance: 2)
- axal (distance: 2)
- axil (distance: 2)
- dapple (distance: 2)
- Eppy (distance: 2)
