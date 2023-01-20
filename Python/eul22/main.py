from alphabet import Alphabet
f = open("names.txt", "r")

names_raw = f.readline()
names = []

# Extract names
previous_name_index = 0
character_index = 0
for character in names_raw:
    if character == ',':
        names.append(names_raw[names_raw.find(
            "\"", previous_name_index) + 1:character_index - 1])
        previous_name_index = character_index

    character_index += 1

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
