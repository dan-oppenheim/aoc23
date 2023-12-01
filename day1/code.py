import re

def part1():
    with open("day1/input.txt") as in_file:
        sum = 0
        for line in in_file:
            num = 0
            for ch in line:
                if ch.isdigit():
                    num += 10 * int(ch)
                    break
            for ch in reversed(line):
                if ch.isdigit():
                    num += int(ch)
                    break
            sum += num
        print(sum)

def part1():
    with open("day1/input.txt") as in_file:
        sum = 0
        for line in in_file:
            num = 0
            m = re.findall("\d", line)
            num = int(m[0]) * 10 + int(m[-1])
            sum += num
        print(sum)

def part2():
    names = ["one","two","three","four","five","six","seven","eight","nine"]
    with open("day1/input.txt") as in_file:
        sum = 0
        for line in in_file:
            num = 0
            # it's possible for words to overlap, e.g. oneight, so need to use a positive
            # look-ahead to ensure we capture the actual last word, e.g. eight. (Positive 
            # look-ahead matches the string, but doesn't consume it, so will continue to 
            # look within the string.)
            m = re.findall("(?=(\d|one|two|three|four|five|six|seven|eight|nine))", line)
            if m[0].isdigit():
                num += int(m[0]) * 10
            else:
                num += (names.index(m[0]) + 1) * 10

            if m[-1].isdigit():
                num += int(m[-1])
            else:
                num += names.index(m[-1]) + 1
            sum += num
        print(sum)
            

    
    

    

part1()
part1_regex()
part2()
