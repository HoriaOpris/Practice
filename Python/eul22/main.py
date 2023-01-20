from alphabet import Alphabet
f = open("names.txt", "r")

# Extract names
names = f.read().replace('"','').split(',')

# Sort names
names.sort()

# What is the total of all the name scores in the file?
alphabet = Alphabet()

total_score = 0
name_position_in_list = 0
for name in names:
    name_score = 0
    name_position_in_list += 1

    for character in name:
        name_score += alphabet.getIndexOfLetter(character)

    name_score *= name_position_in_list
    total_score += name_score

print("Total name scores: " + str(total_score))
