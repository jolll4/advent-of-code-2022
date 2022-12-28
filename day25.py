
def read_and_strip(file):
    return file.readline().rstrip()

def to_regular(string):
    sum = 0
    for j in range(len(string)):
        match string[j]:
            case "1":
                sum += 5**(len(string)-(j+1))*1
            case "2":
                sum += 5**(len(string)-(j+1))*2
            case "-":
                sum += 5**(len(string)-(j+1))*(-1)
            case "=":
                sum += 5**(len(string)-(j+1))*(-2)
    return sum

def summing(file):
    sum = 0
    i = read_and_strip(file)
    while i:
        print(i)
        sum += to_regular(i)
        i = read_and_strip(file)
    return sum

def to_snafu(number):
    print("to snafu")
    remaining = number
    largest_divider = 1
    size = 0
    while largest_divider*5 < number:
        largest_divider*=5
        size+=1

    snafu_number = ""
    divider = largest_divider
    i = size
    while i >= 0:
        times = 0
        if remaining > 0:
            if abs(remaining-divider*2) < abs(remaining-divider):
                times = 2
            elif abs(remaining-divider) < remaining:
                times = 1
            remaining -= divider*(times)
            snafu_number += str(times)
        elif remaining < 0:
            if abs(remaining+divider*2) < abs(remaining+divider):
                times = 2
                snafu_number += "="
            elif abs(remaining + divider) < abs(remaining):
                times = 1
                snafu_number += "-"
            else:
                snafu_number += "0"
            remaining += divider*times
        else:
            break
        i-=1
        divider/=5
        print("multiplier:", times)
        print(snafu_number, "\t", remaining)
    print(number)
    print(to_regular(snafu_number))
    return snafu_number


def main():
    file = open("day25-input.txt", 'r')
    sum = summing(file)
    snafu_sum = to_snafu(sum)
    print(sum, ", ", snafu_sum)

main()