
file = File.read("day4-input.txt").split

count1 = 0
count2 = 0
file.each do |row|
    row = row.split(/,/, 2)
    row1 = row[0].split(/-/,2)
    row2 = row[1].split(/-/,2)
    if (row1[0].to_i <= row2[0].to_i && row1[1].to_i >= row2[1].to_i) ||
        (row1[0].to_i >= row2[0].to_i && row1[1].to_i <= row2[1].to_i)
        count1+=1
    end
    if (row1[0].to_i >= row2[0].to_i && row1[0].to_i <= row2[1].to_i) ||
        (row1[1].to_i >= row2[0].to_i && row1[1].to_i <= row2[1].to_i) ||
        (row2[0].to_i >= row1[0].to_i && row2[0].to_i <= row1[1].to_i) ||
        (row2[1].to_i >= row1[0].to_i && row2[1].to_i <= row1[1].to_i)
        count2+=1
    end

end

p("part 1 solution")
p(count1)

p("part 2 solution")
p(count2)