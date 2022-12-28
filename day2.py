
def read_and_strip(file):
    return file.readline().rstrip().rsplit(' ')

def total_score_1(file):
    row = read_and_strip(file)
    score = 0
    while row[0]:
        match row[1]:
            case "X":
                score += 1
                if row[0]=="A":
                    score+=3
                elif row[0]=="C":
                    score += 6
            case "Y":
                score += 2
                if row[0]=="A":
                    score+=6
                elif row[0]=="B":
                    score += 3
            case "Z":
                score += 3
                if row[0]=="B":
                    score+=6
                elif row[0]=="C":
                    score += 3
        row = read_and_strip(file)

    return score

def total_score_2(file):
    row = read_and_strip(file)
    score = 0
    while row[0]:
        match row[1]:
            case "X":
                if row[0]=="A":
                    score+= 3
                elif row[0]=="B":
                    score += 1
                elif row[0]=="C":
                    score += 2
            case "Y":
                score += 3
                if row[0]=="A":
                    score+= 1
                elif row[0]=="B":
                    score += 2
                elif row[0]=="C":
                    score += 3
            case "Z":
                score += 6
                if row[0]=="A":
                    score+= 2
                elif row[0]=="B":
                    score += 3
                elif row[0]=="C":
                    score += 1
        row = read_and_strip(file)

    return score

def main():
    file = open("day2-input.txt", 'r')
    print(total_score_1(file))
    file = open("day2-input.txt", 'r')
    print(total_score_2(file))

main()