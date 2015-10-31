C++ Enigma Machine
==================

Introduction
--------------------------
This is a C++ implementation of the Enigma Machine used during WWII.
It was developed by Giacomo Guerci in October 2015 at Imperial College London.
The code is provided without a licence and all the rights are reserved.

Running Enigma
--------------------------
Clone the repository and run the makefile.
The resulting executable file is called 'enigma' and can be run as follows:
```
./enigma rotors/II.rot rotors/VI.rot plugboards/II.pb
```
There are sample rotor configuration files in rotors/
and plugboard configuration files in plugboards/.
The program requires zero or more rotors, but it needs exactly one plugboard,
which must be provided after the rotors, if any rotors are used.
The plugboard file plugboards/null.pb represents a plugboard with no effect 
on the encryption.

Plugboard Configuration
--------------------------
Here is how to write configuration files for the Enigma plugboard.
A configuration file consists in a line of integers from 0 to 25 included.
These numbers are read in pairs and the corresponding characters are swapped.

Here is an example from plugboards/II.pb:
```
25 10 22 9 21 4
```
This configuration tells the Enigma Machine to swap character 25 ('Z') with 
character 10 ('K'), to swap character 22 ('W') with character 9 ('J') 
and so on.

Rotors Configuration
--------------------------
Here is how to write configuration files for the Enigma rotors.
A configuration file consists in a line of all the integers from 0 to 25,
in any order.
The first number tells the Enigma Machine what character to map the first 
character ('A') to.
The second characters tells it what character to map 'B' to, and so on.

Here is an example from rotors/III.pb:
```
21 20 2 22 18 3 1 15 19 25 14 8 7 0 16 11 17 9 23 12 24 5 6 13 10 4
```
This configuration tells the Enigma Machine to map character 0 ('A') to character 
21 ('V'), to map the character 1 ('B') to the character 20 ('U'), and so on.

After each character is encoded, the first rotor is shifted by one place, 
so that a character which would have previously gone through the 'A' mapping 
will instead go through the 'B' mapping.

A complete rotation of the first rotor causes the second rotor to shift by one 
place and so on with the all the rotors in use.

Reflector Configuration
--------------------------
This Enigma Machine's reflector cannot be configured and it applies the 
following mapping function for an input character x: reflect(x) = (x + 13) % 26.

Final Notes
--------------------------
The message to be encrypted can only contain alphabetical uppercase characters.
Spaces will be stripped out by the encoding process.

A message encrypted using a given configuration can be decrypted by feeding it 
into the machine with the same configuration.
