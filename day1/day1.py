
def read_and_strip(file):
    return file.readline().rstrip()

def calories(file):
    totals = []
    empty_count = 0
    calories = 0
    while empty_count < 2:
        row = read_and_strip(file)
        if row:
            calories += int(row)
            empty_count = 0
        else:
            empty_count += 1
            totals.append(calories)
            calories = 0

    return totals

def top_three(calories):
    total = 0
    for i in range(3):
        total += max(calories)
        calories.remove(max(calories))
    return total

def main():
    file = open("day1-input.txt", 'r')
    totals = calories(file)
    print(max(totals))
    print(top_three(totals))

main()