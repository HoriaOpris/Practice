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

name_position_in_list = 0
for name in names:
    name_position_in_list += 1
    # print(name)

    if name == "COLIN":
        print(name + " " + str(name_position_in_list) + " " +
              str(ord(name[0])) + " " + str(ord(name[1])))
