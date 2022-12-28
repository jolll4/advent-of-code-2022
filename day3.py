import string

def key_values(values):
    total = 0
    letters = list(string.ascii_lowercase) + list(string.ascii_uppercase)
    for i in values:
        total += letters.index(i)+1
    return total

def read_and_strip(file):
    return file.readline().rstrip()

def priorities(file):
    letters = []
    rows = file.readlines()
    for row in rows:
        row = row.rstrip()
        print(row)
        part1 = row[:len(row)//2]
        part2 = row[len(row)//2:]
        for i in part1:
            if i in part2:
                letters.append(i)
                break

    return key_values(letters)

def team_tags(file):
    letters = []
    row = read_and_strip(file)
    while row:
        row2 = read_and_strip(file)
        row3 = read_and_strip(file)
        for i in row:
            if i in row2:
                if i in row3:
                    letters.append(i)
                    break
        row = read_and_strip(file)

    return key_values(letters)

def main():
    file = open("day3-input.txt", 'r')
    print(priorities(file))
    file = open("day3-input.txt", 'r')
    print(team_tags(file))

main()