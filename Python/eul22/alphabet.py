class Alphabet:
    def getIndexOfLetter(self, letter):
        letter_list = ['A', 'B', 'C', 'D', 'E',
                       'F', 'G', 'H', 'I', 'J',
                       'K', 'L', 'M', 'N', 'O',
                       'P', 'Q', 'R', 'S', 'T',
                       'U', 'V', 'W', 'X', 'Y', 'Z']

        index = 1
        for l in letter_list:
            if l == letter:
                return index

            index += 1

        return - 1
