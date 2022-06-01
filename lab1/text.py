def create_first(path):
    with open(path, 'w') as file:
        line = input("Enter your strings. To finish entering go to a new line and press <Ctrl + S>.\n")
        while line != '&&':
            if line: 
                file.write(line + '\n')
            line = input()


def create_second(firstfile, secondfile):
    count = 0
    with open(firstfile, 'r') as file:
        strings = [string.rstrip('\n').split() for string in file.readlines()]
    with open(secondfile, 'w') as file:
        for string in strings:
            perfect = list()
            for element in string:
                if len(element) != 2:
                    perfect.append(element)
                else:
                    count += 1
            if perfect:
                file.write(' '.join(perfect) + '\n')
        file.write(str(count))


def read_file(path):
    with open(path, 'r') as file:
        print(''.join(file.readlines()))